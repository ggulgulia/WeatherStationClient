#include "PressureSensor.hpp"

namespace WS{

    state PressureSensor::is_on() const noexcept{
        return state_;
    }
    double PressureSensor::check_pressure() const noexcept(false){
        return PressureHelper();
    }
}