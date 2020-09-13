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
            
            state is_on() const noexcept override {
                return state_;
            }

            void update_temperature_sensor_power_status() noexcept(false) {
                std::string line, result;
                state sensor_state;
                std::ifstream myfile;
                try{
                    myfile.open(power_status_filepath);
                    if(!myfile){
                        std::stringstream str{power_status_filepath};
                        str << "cannot open file: " << power_status_filepath << "\n";
                        throw std::runtime_error(str.str()); 
                    }
                    else{
                        std::cout << "Successfully opened the power status file\n";
                        while (std::getline(myfile,line)){
                          result = line;
                        }
                        myfile.close();
                    }
                }
                catch(std::exception& e){
                    std::cerr << e.what() << "\n";

                }
                auto pair = state_map.find(result);
                sensor_state = pair != state_map.end()? pair->second : state::unknown;
                state_ = sensor_state;
            }
            
        private:
            state state_;

    };

} //namespace WS
#endif  //TEMPERATURE_SENSOR_H