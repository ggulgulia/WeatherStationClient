#include "TemperatureSensor.hpp"

namespace WS {

    TemperatureSensor::TemperatureSensor():WeatherSensorInterface{}, 
    temperatureScale_{ new Celcius()}, state_{state::off}
    {
    }

    TemperatureSensor::TemperatureSensor(std::unique_ptr<TemperatureScale> temp)
    :temperatureScale_{std::move(temp)}, state_{state::off}
    {
    }

    state TemperatureSensor::is_on() const noexcept
    {
        return state_;
    }

    void TemperatureSensor::update_sensor_power_status(const std::string& power_status_filepath) noexcept(false)
    {
        std::string line, result;
        state sensor_state;
        std::ifstream power_status_file;
        try {
            openFile(power_status_file, power_status_filepath);
            if (!power_status_file) {
                std::cerr << "could not open file\n";
            }
            else {
                std::cout << "Successfully opened the power status file\n";
                while (std::getline(power_status_file, line)) {
                    result = line;
                }
                power_status_file.close();
            }
        }
        catch (std::exception& e) {
            std::cerr << e.what() << "\n";
        }
        auto pair = state_map.find(result);
        sensor_state = pair != state_map.end() ? pair->second : state::unknown;
        state_ = sensor_state;
    }

    float TemperatureSensor::check_temperature(const std::string& temperatureFilePath)
    {
        std::string line;
        std::ifstream temperature_file;
        try {
            openFile(temperature_file, temperatureFilePath);
            if (!temperature_file) {

                std::cerr << "cannot open file: " << temperatureFilePath << "\n";
            }
            else {
                std::cout << "Successfully opened the temperature file\n";
                while (std::getline(temperature_file, line)) {
                    temperatureScale_->updateValue(std::stod(line) * 0.001);
                }
                temperature_file.close();
            }
        }
        catch (std::exception& e) {
            std::cerr << e.what() << "\n";
        }
        return temperatureScale_->getValue();
    }

} //namespace WS
