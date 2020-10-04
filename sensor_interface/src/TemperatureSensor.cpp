#include "TemperatureSensor.hpp"

namespace WS{

    state TemperatureSensor::is_on() const noexcept
    {
                return state_;
    }

    void TemperatureSensor::update_temperature_sensor_power_status() noexcept(false)
    {
        std::string line, result;
        state sensor_state;
        std::ifstream power_status_file;
        try{
            power_status_file.open(power_status_filepath);
            std::cout << "power status file path" << power_status_filepath << "\n";
            if(!power_status_file){
                std::stringstream str{power_status_filepath};
                str << "cannot open file: " << power_status_filepath << "\n";
                throw std::runtime_error(str.str()); 
            }
            else{
                std::cout << "Successfully opened the power status file\n";
                while (std::getline(power_status_file,line)){
                    result = line;
                }
                power_status_file.close();
            }
        }
        catch(std::exception& e){
            std::cerr << e.what() << "\n";

        }
        auto pair = state_map.find(result);
        sensor_state = pair != state_map.end()? pair->second : state::unknown;
        state_ = sensor_state;
    }

    float TemperatureSensor::check_temperature() const noexcept(false)
    {
        std::string line;
        float temperature;
        std::ifstream temperature_file;
        try{
            temperature_file.open(temperature_filepath);
            if(!temperature_file){
                std::stringstream str{temperature_filepath};
                str << "cannot open file: " << temperature_filepath << "\n";
                throw std::runtime_error(str.str()); 
            }
            else{
                std::cout << "Successfully opened the temperature file\n";
                while (std::getline(temperature_file,line)){
                    temperature = std::stof(line)*0.001;
                }
                temperature_file.close();
            }
        }
        catch(std::exception& e){
            std::cerr << e.what() << "\n";
        }
        return temperature;
    }

}//namespace WS