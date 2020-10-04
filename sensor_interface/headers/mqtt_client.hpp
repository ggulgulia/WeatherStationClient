#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <iostream>
#include <mqtt/async_client.h>
#include <memory>
#include <utility>
#include <exception>
#include "enums.hpp"

using namespace std::literals::chrono_literals;

namespace WS{

    class MQTTClient {
        public:
            MQTTClient() = delete;
            MQTTClient(const std::string& ipAddress, const std::string& clientId);
            void Connect();
            bool IsConnected() const noexcept;
            template<typename Topic, typename Payload>
            Result PublishMessage(Topic&& topic, Payload&& payload);

        private:
            std::unique_ptr<mqtt::async_client> client_;
    };

//Implementation of perfect forwarding PublishMessage
Result MQTTClient::PublishMessage(Topic&& topic, Payload&& payload)
{
    Result retval = Result::Successful;
    try{
        mqtt::message_ptr pubmsg = mqtt::make_message(std::forward<Topic>(topic), 
                                            std::forward<Payload>(payload));
        pubmsg->set_qos(1);
        auto pubtok = client_->publish(pubmsg)->wait_for(500ms);

    }
    catch(std::exception& e){
        std::cerr << "MQTTClient::Publish threw: " << e.what() << "\n";
        retval = Result::Unsuccessful;   
    }

    return retval;
}
} //namespace WS
#endif //MQTT_CLIENT_H