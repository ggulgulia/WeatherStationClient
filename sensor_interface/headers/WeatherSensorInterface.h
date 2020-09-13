#ifndef WEATHER_SENSOR_INTERFACE_H
#define WEATHER_SENSOR_INTERFACE_H

#include <iostream>
namespace WS{
enum class state{off, on, ground_disconnected, unknown};

    class WeatherSensorInterface{
        public:
            WeatherSensorInterface() = default;
            ~WeatherSensorInterface() = default;
            WeatherSensorInterface(const WeatherSensorInterface&) = delete;
            WeatherSensorInterface& operator=(const WeatherSensorInterface&) = delete;
            
            virtual state is_on() const noexcept = 0;
        
    };
}
#endif