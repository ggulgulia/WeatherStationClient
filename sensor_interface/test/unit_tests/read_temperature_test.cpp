#include "TemperatureSensor.hpp"
#include <gtest/gtest.h>

using namespace WS;

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
    temp_sensor_->update_temperature_sensor_power_status();
    ASSERT_EQ(temp_sensor_->is_on(), state::on);
}

TEST_F(ReadTemperature, check_current_temperature)
{
    ASSERT_GT(temp_sensor_->check_temperature(), 0.0);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}