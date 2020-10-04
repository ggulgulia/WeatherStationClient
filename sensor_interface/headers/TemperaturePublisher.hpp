#ifndef TEMPERATURE_PUBLISHER_H
#define TEMPERATURE_PUBLISHER_H

#include "TemperatureSensor.hpp"
#include "mqtt_client.hpp"
#include <exception>
namespace WS{



    class TemperaturePublisher{
        public:

            //TemperaturePublisher(const std::string& ip, const std::string id):
            //mqttClient_{std::make_shared<MQTTClient>(ip, id)}
            //{
            //    mqttClient_->Connect();
            //}

            TemperaturePublisher(std::shared_ptr<MQTTClient> client):
            mqttClient_{client}
            {
                if(!mqttClient_){
                    throw std::runtime_error("TemperaturePublisher::TemperaturePublisher(std::shared_ptr<MQTTClient> called with nullptr");
                }

                if(!mqttClient_->IsConnected()){
                    mqttClient_->Connect();
                }
            }

            double publish() const{
              double temperature = temperatureSensor_.check_temperature();
              return temperature;  
            }

            auto get_client() -> std::shared_ptr<MQTTClient> const {
                return mqttClient_;
            }

        private:
            std::shared_ptr<MQTTClient>   mqttClient_;
            TemperatureSensor temperatureSensor_;

    };

}//namespace

#endif //TEMPERATURE_PUBLISHER_H