#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "WeatherSensorInterface.hpp"
#include "TemperatureScale.hpp"
#include "sensor_data_paths.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <memory>

namespace WS {

    using TempSensorPowerMap = std::unordered_map<std::string, state>;

    class TemperatureSensor : public WeatherSensorInterface {
    public:
        const TempSensorPowerMap state_map{{"0", state::off}, {"1", state::on}, {"-19", state::ground_disconnected}};
        TemperatureSensor();
        TemperatureSensor(TemperatureScale* temp);
        //avoid creating copies of sensor
        TemperatureSensor(const TemperatureSensor&) = delete;
        TemperatureSensor& operator=(const TemperatureSensor&) = delete;
        virtual ~TemperatureSensor() = default;
        state is_on() const noexcept override;
        void update_sensor_power_status() noexcept(false);
        virtual float check_temperature();
        
    private:
        state state_;
        TemperatureScale* temperatureScale_;
    };

} //namespace WS
#endif //TEMPERATURE_SENSOR_H
