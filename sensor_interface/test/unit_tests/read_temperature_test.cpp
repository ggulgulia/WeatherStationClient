#include "TemperatureSensor.hpp"
#include "TemperatureSensorMock.hpp"
#include <gtest/gtest.h>

using namespace WS;
using ::testing::AtLeast;
using ::testing::Return;

TEST(SensorTest, check_temperature) {
  TemperatureSensorMock temperatureSensorMock; 
  EXPECT_CALL(temperatureSensorMock, check_temperature);              
  temperatureSensorMock.check_temperature();
  TemperatureSensor sensor;                    
  //EXPECT_TRUE(sensor.check_temperature());   
  testing::Mock::VerifyAndClearExpectations(&temperatureSensorMock);
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
