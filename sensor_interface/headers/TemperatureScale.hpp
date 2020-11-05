#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>

namespace WS{

    class TemperatureScale{
        public:
            TemperatureScale() = default;
            TemperatureScale(double temp);
            virtual ~TemperatureScale() = default;
            void updateValue(const double newVal) noexcept;
            virtual double getValue() const noexcept = 0;
        protected:
            double temperature_{0.0};
            virtual std::ostream&  format(std::ostream& os) const = 0;    
            friend std::ostream& operator << (std::ostream& os, const TemperatureScale& obj);
    };

    class Celcius : public TemperatureScale{
        public:
            double getValue()const noexcept override;
            virtual ~Celcius() = default;
            std::ostream&  format(std::ostream& os) const override;
    };

    class Fahrenheit : public TemperatureScale{
        public:
            double getValue()const noexcept override{
                return (9.0/5.0*temperature_) + 32.0;
            }

            virtual ~Fahrenheit() = default;
            std::ostream&  format(std::ostream& os) const override {
                os << this->getValue() << " degrees Fahrenheit\n";
                return os;
            }
    };

    class Kelvin : public TemperatureScale{
        public:
            double getValue()const noexcept override{
                return temperature_ + 273.15;
            }

            virtual ~Kelvin() = default;
            std::ostream&  format(std::ostream& os) const override {
                os << this->getValue() << " degrees Kelvin\n";
                return os;
            }

    };
}
#endif //TEMPERATURE_H