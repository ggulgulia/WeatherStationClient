#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "WeatherSensorInterface.h"
namespace WS{

    class TemperatureSensor : public WeatherStationInterface{
        public:
            state is_on() override {
                return state_;
            }
            
        private:
            state state_;

    };



} //namespace WS
#endif  //TEMPERATURE_SENSOR_H