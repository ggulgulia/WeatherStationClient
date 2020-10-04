#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <fstream>
#include <sstream>
#include <unordered_map>
#include "sensor_data_paths.h"
#include "WeatherSensorInterface.h"



namespace WS{

    using TempSensorPowerMap = std::unordered_map<std::string, state>;

    class TemperatureSensor : public WeatherSensorInterface{
        public:
            
            const TempSensorPowerMap state_map{ {"0", state::off}, {"1", state::on}, {"-19", state::ground_disconnected}};
            
            state is_on() const noexcept override;
            void update_temperature_sensor_power_status() noexcept(false);
            float check_temperature() const noexcept(false);
            
        private:
            state state_;

    };

} //namespace WS
#endif  //TEMPERATURE_SENSOR_H
