#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <iostream>
#include <mqtt/async_client.h>
#include <memory>
#include <exception>

using namespace std::literals::chrono_literals;

namespace WS{
    class MQTTClient {
        public:
    
            MQTTClient(const std::string& ipAddress, const std::string& clientId);
            void Connect();
            bool IsConnected() const noexcept;

        private:
            std::unique_ptr<mqtt::async_client> client_;
    };

} //namespace WS
#endif //MQTT_CLIENT_H