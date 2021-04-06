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
        TemperatureSensor(std::unique_ptr<TemperatureScale>& temp);
        //avoid creating copies of sensor
        TemperatureSensor(const TemperatureSensor&) = delete;
        TemperatureSensor& operator=(const TemperatureSensor&) = delete;
        virtual ~TemperatureSensor() = default;
        state is_on() const noexcept override;
        void update_temperature_sensor_power_status() noexcept(false);
        float check_temperature() const noexcept(false);
        
    private:
        state state_;
        std::unique_ptr<TemperatureScale> temperature_{nullptr};
    };

} //namespace WS
#endif //TEMPERATURE_SENSOR_H
