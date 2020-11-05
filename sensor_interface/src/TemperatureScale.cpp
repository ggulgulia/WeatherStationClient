#include "TemperatureScale.hpp"

namespace WS{

/* TemperatureScale class implementation: START */
TemperatureScale::TemperatureScale(double temp): temperature_{temp}
{   }

void TemperatureScale::updateValue(const double newVal) noexcept{
    temperature_ = newVal;
}

std::ostream& operator << (std::ostream& os, const TemperatureScale& obj){
    return obj.format(os);
}  
/* TemperatureScale class implementation : END*/


} //namespace WS