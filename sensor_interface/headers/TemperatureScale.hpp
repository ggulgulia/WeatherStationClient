#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>

namespace WS{

    class TemperatureScale{
        public:
            TemperatureScale() = default;
            TemperatureScale(double temp): temperature_{temp}
            {   }
            virtual ~TemperatureScale() = default;
            void updateValue(const double newVal) noexcept{
                temperature_ = newVal;
            }

            virtual double getValue() const noexcept = 0;
        protected:
            double temperature_{0.0};
    };

    class Celcius : public TemperatureScale{
        public:
            double getValue()const noexcept override{
                return temperature_;
            }

            virtual ~Celcius() = default;
            friend std::ostream& operator<<(std::ostream& os, const Celcius obj){
                os << obj.getValue() << " Celciu\n";
                return os;
            } 
    };

    class Fahrenheit : public TemperatureScale{
        public:
            double getValue()const noexcept override{
                return (9.0/5.0*temperature_) + 32.0;
            }

            virtual ~Fahrenheit() = default;
            friend std::ostream& operator<<(std::ostream& os, const Fahrenheit obj){
                os << obj.getValue() << " Fahrenheit\n";
                return os;
            } 
    };

    class Kelvin : public TemperatureScale{
        public:
            double getValue()const noexcept override{
                return temperature_ + 273.15;
            }

            virtual ~Kelvin() = default;

            friend std::ostream& operator<<(std::ostream& os, const Kelvin obj){
                os << obj.getValue() << " Kelvin\n";
                return os;
            }     

    };
}
#endif //TEMPERATURE_H