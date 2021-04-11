#ifndef TEMPERATURESENSOR_MOCK_H
#define TEMPERATURESENSOR_MOCK_H

#include "TemperatureSensor.hpp"
#include <gmock/gmock.h>

using namespace WS;

class TemperatureScaleMock : public TemperatureScale{
    public:
        MOCK_METHOD(void, updateValue, (const double), (noexcept));
        MOCK_METHOD(double, getValue, (), (const, noexcept));
    private:
        MOCK_CONST_METHOD1(format, std::ostream&(std::ostream& os));
};

#endif //TEMPERATURESENSOR_MOCK_H