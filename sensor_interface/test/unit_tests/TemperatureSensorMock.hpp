#ifndef TEMPERATURESENSOR_MOCK_H
#define TEMPERATURESENSOR_MOCK_H

#include "TemperatureSensor.hpp"
#include <gmock/gmock.h>

using namespace WS;

class TemperatureSensorMock : public TemperatureSensor{
    public:
        MOCK_METHOD0(check_temperature, float()) ;
};

#endif //TEMPERATURESENSOR_MOCK_H