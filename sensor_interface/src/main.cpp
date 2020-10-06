#include <iostream>
#include "TemperaturePublisher.hpp"

using namespace WS;

int main(){
    std::cout << "Hello Weather Station\n";
    std::shared_ptr<MQTTClient> client = std::make_shared<MQTTClient>("localhost", "main");
    TemperaturePublisher temp_publisher{client};
    std::string input;
    while (std::getline(std::cin, input) && input != "q"){
        temp_publisher.publish();
    }
    return 0;
}