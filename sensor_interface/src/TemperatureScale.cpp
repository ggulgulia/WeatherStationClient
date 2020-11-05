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

/* Fahrenheit class implementation : START*/
double Fahrenheit::getValue()const noexcept{
    return (9.0/5.0*temperature_) + 32.0;
}

std::ostream&  Fahrenheit::format(std::ostream& os) const{
    os << this->getValue() << " degrees Fahrenheit\n";
    return os;
}
/* Fahrenheit class implementation : END*/

/* Kelvin class implementation : START*/
double Kelvin::getValue()const noexcept{
    return temperature_ + 273.15;
}
std::ostream&  Kelvin::format(std::ostream& os) const {
    os << this->getValue() << " degrees Kelvin\n";
    return os;
}
/* Kelvin class implementation : END*/

} //namespace WS