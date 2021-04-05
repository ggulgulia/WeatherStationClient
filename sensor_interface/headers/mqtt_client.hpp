#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include "enums.hpp"
#include <exception>
#include <iostream>
#include <memory>
#include <mqtt/async_client.h>
#include <type_traits>
#include <utility>

using namespace std::literals::chrono_literals;

namespace WS {

    class MQTTClient {
    public:
        MQTTClient() = delete;
        MQTTClient(const std::string& ipAddress, const std::string& clientId);
        void Connect();
        bool IsConnected() const noexcept;
        template <typename Topic, typename Payload>
        Result PublishMessage(Topic&& topic, Payload&& payload);

    private:
        std::unique_ptr<mqtt::async_client> client_;
    };

    //Implementation of perfect forwarding PublishMessage
    template <typename Topic, typename Payload>
    Result MQTTClient::PublishMessage(Topic&& topic, Payload&& payload)
    {
        Result retval = Result::Successful;
        if constexpr (std::is_arithmetic_v<Payload>) {
            try {
                mqtt::message_ptr pubmsg = mqtt::make_message(std::forward<Topic>(topic),
                    std::forward<std::string>(std::to_string(payload)));
                pubmsg->set_qos(1);
               // auto pubtok = client_->publish(pubmsg)->wait_for(500ms);
            }
            catch (std::exception& e) {
                std::cerr << "MQTTClient::Publish threw: " << e.what() << "\n";
                retval = Result::Unsuccessful;
            }
        }
        return retval;
    } // namespace WS
} //namespace WS
#endif //MQTT_CLIENT_H
