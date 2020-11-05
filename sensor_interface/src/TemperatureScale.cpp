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

/* Celcius class implementation : START*/
double Celcius::getValue()const noexcept{
    return temperature_;
}

std::ostream&  Celcius::format(std::ostream& os) const {
    os << this->getValue() << " degrees celcius\n";
    return os;
}
/* Celcius class implementation : END*/

} //namespace WS