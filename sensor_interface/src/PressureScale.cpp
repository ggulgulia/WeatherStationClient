#include "PressureScale.hpp"

namespace WS{

    /* PressureScale class implementation: START */
    PressureScale::PressureScale(double pressure): pressure_{pressure}
    {   }

    void PressureScale::updateValue(const double newVal)noexcept{
        pressure_  = newVal;
    }

    std::ostream& operator<< (std::ostream& os, const PressureScale& obj){
        return obj.format(os);
    }
    /* PressureScale class implementation: END */

    /* Pascal (pressure scale) class implementation: START */
    double Pascal::getValue()const noexcept{
        return pressure_;
    }

    std::ostream& Pascal::format(std::ostream& os)const{
        os << this->getValue() << " pascals\n";
        return os;
    }

    double Bar::getValue()const noexcept{
        auto result = pressure_/1e5;
        return result;
    }

    std::ostream& Bar::format(std::ostream& os) const{
        os << this->getValue() << " Bars\n";
        return os;
    }

}