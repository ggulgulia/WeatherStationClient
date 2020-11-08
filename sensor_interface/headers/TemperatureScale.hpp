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
            Celcius() = default;
            Celcius(const Celcius&) = default;
            virtual ~Celcius() = default;
            double getValue()const noexcept override final;
            std::ostream&  format(std::ostream& os) const override final;
    };

    class Fahrenheit : public TemperatureScale{
        public:
            Fahrenheit() = default;
            Fahrenheit(const Fahrenheit&) = default;
            virtual ~Fahrenheit() = default;
            double getValue()const noexcept override final;
            std::ostream&  format(std::ostream& os) const override final;
    };

    class Kelvin : public TemperatureScale{
        public:
            Kelvin() = default;
            Kelvin(const Kelvin&) = default;
             virtual ~Kelvin() = default;
            double getValue()const noexcept override final;
            std::ostream&  format(std::ostream& os) const override final;
    };
}
#endif //TEMPERATURE_H