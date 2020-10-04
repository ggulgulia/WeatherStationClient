#ifndef TEMPERATURE_PUBLISHER_H
#define TEMPERATURE_PUBLISHER_H

#include "TemperatureSensor.hpp"
namespace WS{

    class IWeatherPublisher{
        public:
            virtual double publish() const = 0;
    };

    class TemperaturePublisher : public IWeatherPublisher{
        public:
            double publish() const override{
              return 25.1;  
            }
        private:
            TemperatureSensor temperatureSensor_;

    };

}//namespace


#endif //TEMPERATURE_PUBLISHER_H