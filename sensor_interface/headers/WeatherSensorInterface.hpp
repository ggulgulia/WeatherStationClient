#ifndef WEATHER_SENSOR_INTERFACE_H
#define WEATHER_SENSOR_INTERFACE_H

#include <iostream>
#include "enums.hpp"
#include <experimental/filesystem>
#include <fstream>
#include <sstream>

namespace fs = std::experimental::filesystem;
namespace WS{

    class WeatherSensorInterface{
        public:
            WeatherSensorInterface() = default;
            ~WeatherSensorInterface() = default;
            WeatherSensorInterface(const WeatherSensorInterface&) = delete;
            WeatherSensorInterface& operator=(const WeatherSensorInterface&) = delete;
            void openFile(std::ifstream& fileStream, const std::string& filePath){
                std::stringstream str;
                if(!fs::exists(filePath)){
                    str << "File path doesn't refer to a valid file\n" ;
                    str << "Please check the path: " << filePath << "\n";
                    throw std::runtime_error(str.str());
                }
                    fileStream.open(filePath);
                    if(!fileStream.is_open()){
                        str << "could not open the file\n";
                        str << "please check file permissions for " <<  filePath << "\n";
                        throw std::runtime_error(str.str());
                    }

            }
            virtual state is_on() const noexcept = 0;
            virtual void update_sensor_power_status(const std::string& power_status_filepath) noexcept(false) = 0;
    };
}
#endif
