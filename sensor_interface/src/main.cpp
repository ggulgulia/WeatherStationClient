#include <iostream>
#include "TemperaturePublisher.hpp"
#include <pthread.h>
#include <thread>
#include <stdio.h>
#include <sys/ioctl.h> // For FIONREAD
#include <termios.h>
#include <stdbool.h>
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

static void userInput_thread()
{
    std::string name;
    char c;
    while(!kbhit()) {
        c = getchar();
        if (c == 'q')
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

    pthread_t tId;
    //(void) pthread_create(&tId, 0, userInput_thread, 0);
    std::thread key_board_listen(userInput_thread);

    std::cout << "Hello Weather Station\n";
    std::shared_ptr<MQTTClient> client = std::make_shared<MQTTClient>("localhost", "main");
    TemperaturePublisher temp_publisher{client};

    while(keep_running)
    {
        temp_publisher.publish();
        std::this_thread::sleep_for(1s);
    }
    key_board_listen.join();
    //(void) pthread_join(tId, NULL);
    return 0;
}