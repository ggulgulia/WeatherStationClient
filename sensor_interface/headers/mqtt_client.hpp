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
    
            MQTTClient(const std::string& ipAddress, const std::string& clientId):
            client_{std::make_unique<mqtt::async_client>(ipAddress, clientId)}
            {}

            void Connect(){
                try{
                    mqtt::connect_options connOpts;
                    connOpts.set_clean_session(true);
                    auto token = client_->connect(connOpts);
                    token->wait_for(400ms);
                }
                catch(std::exception& e){
                    std::cerr << "Connect method threw: " << e.what() << "\n";
                }
            }

            bool IsConnected() noexcept {
                return client_->is_connected();
            }

        private:
            std::unique_ptr<mqtt::async_client> client_;

    };

} //namespace WS
#endif //MQTT_CLIENT_H