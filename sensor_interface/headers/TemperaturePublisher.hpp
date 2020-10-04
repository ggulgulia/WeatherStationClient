#ifndef TEMPERATURE_PUBLISHER_H
#define TEMPERATURE_PUBLISHER_H

#include "TemperatureSensor.hpp"
#include "mqtt_client.hpp"
#include <exception>
namespace WS{



    class TemperaturePublisher{
        public:
            TemperaturePublisher(std::shared_ptr<MQTTClient> client);
            double publish() const;
            auto get_client() -> std::shared_ptr<MQTTClient> const;

        private:
            std::shared_ptr<MQTTClient>   mqttClient_;
            TemperatureSensor temperatureSensor_;

    };

}//namespace

#endif //TEMPERATURE_PUBLISHER_H