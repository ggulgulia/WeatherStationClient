#ifndef PRESSURESCALE_H
#define PRESSURESCALE_H

#include <iostream>
#include <memory>
namespace WS{

    class PressureScale{
        public:
            PressureScale() = default;
            PressureScale(double temp);
            virtual ~PressureScale() = default;
            void updateValue(const double newVal) noexcept;
            virtual double getValue() const noexcept = 0;
        protected:
            double pressure_{0.0};
            virtual std::ostream&  format(std::ostream& os) const = 0;    
            friend std::ostream& operator << (std::ostream& os, const PressureScale& obj);
    };

    class Pascal : public PressureScale{
        public:
            Pascal() = default;
            Pascal(const Pascal&) = default;
            virtual ~Pascal() = default;
            double getValue()const noexcept override final;
            std::ostream&  format(std::ostream& os) const override final;
    };

    class Bar : public PressureScale{
        public:
            Bar() = default;
            Bar(const Bar&) = default;
            virtual ~Bar() = default;
            double getValue()const noexcept override final;
            std::ostream&  format(std::ostream& os) const override final;
    };


} //namespace WS
#endif //PRESSURESCALE_H