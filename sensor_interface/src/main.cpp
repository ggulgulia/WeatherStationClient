#include <iostream>
#include "TemperaturePublisher.hpp"
#include "PressurePublisher.hpp"
#include <pthread.h>
#include <thread>
#include <stdio.h>
#include <sys/ioctl.h> // For FIONREAD
#include <termios.h>
#include <stdbool.h>
#include <PressureHelper.hpp>

using namespace WS;

static bool keep_running = true;

static int kbhit(void) {
    static bool initflag = false;
    static const int STDIN = 0;
    if (!initflag) {
        // Use termios to turn off line buffering
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initflag = true;
    }
    int nbbytes;
    ioctl(STDIN, FIONREAD, &nbbytes);  // 0 is STDIN
    return nbbytes;
}

static void userInput_thread(){
    char keyboard_input;
    while(!kbhit()) {
        keyboard_input = getchar();
        if (keyboard_input == 'q')
        {
            std::this_thread::sleep_for(500ms);
            std::cout << "\n";
            std::cout << "keyboard interrupt: \"q\" received.\n"
                      << "stopping program!\n";
            keep_running = false;
            break;
        }
    }
}

int main(){
    
    //launch a separate thread to listen keyboard interrupt
    std::thread key_board_listen_thread(userInput_thread);

    std::cout << "Hello Weather Station\n";
    std::shared_ptr<MQTTClient> client = std::make_shared<MQTTClient>("localhost", "main");
    TemperaturePublisher temp_publisher{client};
    PressurePublisher pressure_publisher{client};
    while(keep_running)
    {
        temp_publisher.publish();
        pressure_publisher.publish();
        std::this_thread::sleep_for(1s);
    }
    key_board_listen_thread.join();
    return 0;
}
