#include "PressureSensor.hpp"

namespace WS{

    state PressureSensor::is_on() const noexcept{
        int file;
        std::string bus{"/dev/i2c-1"};
	    file = open(bus.c_str(), O_RDWR);
        state_ = file < 0? state::unknown : state::on;
        return state_;
    }
    double PressureSensor::check_pressure() const noexcept(false){
        return PressureHelper();
    }
}