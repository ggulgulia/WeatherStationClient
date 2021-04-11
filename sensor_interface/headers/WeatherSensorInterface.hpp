#ifndef WEATHER_SENSOR_INTERFACE_H
#define WEATHER_SENSOR_INTERFACE_H

#include <iostream>
#include "enums.hpp"
namespace WS{

    class WeatherSensorInterface{
        public:
            WeatherSensorInterface() = default;
            ~WeatherSensorInterface() = default;
            WeatherSensorInterface(const WeatherSensorInterface&) = delete;
            WeatherSensorInterface& operator=(const WeatherSensorInterface&) = delete;
            
            virtual state is_on() const noexcept = 0;
            virtual void update_sensor_power_status() noexcept(false) = 0;
        
    };
}
#endif
