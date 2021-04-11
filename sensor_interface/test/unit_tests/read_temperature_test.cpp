#include "TemperatureSensor.hpp"
#include "TemperatureSensorMock.hpp"
#include <gtest/gtest.h>

using namespace WS;
using ::testing::AtLeast;
using ::testing::Return;

TEST(SensorTest, check_temperature) {
  TemperatureScaleMock temperatureScaleMock;
  EXPECT_CALL(temperatureScaleMock, getValue());              
  //temperatureSensorMock.check_temperature();
  TemperatureSensor sensor(&temperatureScaleMock); 
  sensor.check_temperature();
}



class ReadTemperature : public testing::Test {
public:
    double temp;
    std::unique_ptr<TemperatureSensor> temp_sensor_;

    ReadTemperature() : temp{0},
                        temp_sensor_{std::make_unique<TemperatureSensor>()}
    {
    }

    ~ReadTemperature()
    {
    }
};

TEST_F(ReadTemperature, check_is_on)
{
    temp_sensor_->update_sensor_power_status();
    ASSERT_EQ(temp_sensor_->is_on(), state::on);
}

TEST_F(ReadTemperature, check_current_temperature)
{
    ASSERT_GT(temp_sensor_->check_temperature(), 0.0);
}

int main(int argc, char** argv)
{
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
