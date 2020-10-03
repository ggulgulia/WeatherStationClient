#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <iostream>
#include <mqtt/async_client.h>
#include <memory>
#include <exception>
#include "enums.hpp"

using namespace std::literals::chrono_literals;

namespace WS{

    class MQTTClient {
        public:
    
            MQTTClient(const std::string& ipAddress, const std::string& clientId);
            void Connect();
            bool IsConnected() const noexcept;

            Result PublishMessage(const std::string& topic, const std::string& payload){
                Result retval = Result::Successful;
                mqtt::message_ptr pubmsg = mqtt::make_message(topic, payload);
                pubmsg->set_qos(1);
                auto pubtok = client_->publish(pubmsg)->wait_for(500ms);
                if(!pubtok){
                    retval = Result::Unsuccessful; 
                }
                
                return retval;
            }

        private:
            std::unique_ptr<mqtt::async_client> client_;
    };

} //namespace WS
#endif //MQTT_CLIENT_H