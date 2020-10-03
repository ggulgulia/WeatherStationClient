#include "mqtt_client.hpp"

namespace WS{

    MQTTClient::MQTTClient(const std::string& ipAddress, const std::string& clientId):
            client_{std::make_unique<mqtt::async_client>(ipAddress, clientId)}
            {}

    void MQTTClient::Connect(){
                try{
                    mqtt::connect_options connOpts;
                    connOpts.set_clean_session(true);
                    auto token = client_->connect(connOpts);
                    token->wait_for(2s);
                }
                catch(std::exception& e){
                    std::cerr << "Connect method threw: " << e.what() << "\n";
                    throw;
                    
                }
            }

    bool MQTTClient::IsConnected() const noexcept {
                return client_->is_connected();
            }

}//namespace WS