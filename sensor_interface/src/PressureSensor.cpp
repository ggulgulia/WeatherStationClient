#include "PressureSensor.hpp"

namespace WS{

    PressureSensor::PressureSensor(): pressure_{std::make_unique<Pascal>()}
    {   }

    PressureSensor::PressureSensor(std::unique_ptr<PressureScale>& prScle):
    pressure_{std::move(prScle)}
    {   }

    state PressureSensor::is_on() const noexcept{
        return state_;
    }
    double PressureSensor::check_pressure() const noexcept(false){
        auto currPressure = PressureHelper();
        pressure_->updateValue(currPressure);
        return currPressure;
    }
}