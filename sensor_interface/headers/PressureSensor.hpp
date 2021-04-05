#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

#include "WeatherSensorInterface.hpp"

namespace WS
{
    class PressureSensor : public WeatherSensorInterface {
        public:
            //const TempSensorPowerMap state_map{{"0", state::off}, {"1", state::on}, {"-19", state::ground_disconnected}};
            PressureSensor() = default;
            //PressureSensor(std::unique_ptr<PressureScale>& pressure);
            //avoid creating copies of sensor
            PressureSensor(const PressureSensor&) = delete;
            PressureSensor& operator=(const PressureSensor&) = delete;
            virtual ~PressureSensor() = default;
            state is_on() const noexcept override;
            //void update_pressure_sensor_power_status() noexcept(false);
            double check_pressure() const noexcept(false);

        private:
            state state_;
            //std::unique_ptr<TemperatureScale> temperature_{nullptr};
    };
} // namespace WS


#endif //PRESSURE_SENSOR