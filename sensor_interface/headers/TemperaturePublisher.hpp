#ifndef TEMPERATURE_PUBLISHER_H
#define TEMPERATURE_PUBLISHER_H

#include "TemperatureSensor.hpp"
#include "mqtt_client.hpp"

namespace WS{

    class IWeatherPublisher{
        public:
            virtual double publish() const  = 0;
    };

    class TemperaturePublisher : public IWeatherPublisher{
        public:

            TemperaturePublisher(MQTTClient& client):mqttClient_{client}
            {

            }

            double publish() const override{
              double temperature = temperatureSensor_.check_temperature();
              return temperature;  
            }
        private:
            MQTTClient&        mqttClient_;
            TemperatureSensor temperatureSensor_;
            

    };

}//namespace


#endif //TEMPERATURE_PUBLISHER_H