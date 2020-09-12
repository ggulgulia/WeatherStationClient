#ifndef WEATHER_SENSOR_INTERFACE_H
#define WEATHER_SENSOR_INTERFACE_H

#include <iostream>
namespace WS{
enum class state{on, off};

    class WeatherStationInterface{
        public:
            WeatherStationInterface() = default;
            ~WeatherStationInterface() = default;
            WeatherStationInterface(const WeatherStationInterface&) = delete;
            WeatherStationInterface& operator=(const WeatherStationInterface&) = delete;
            
            virtual state is_on() = 0;
        

    };
}
#endif