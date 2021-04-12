#include "TemperatureSensor.hpp"
#include "TemperatureSensorMock.hpp"
#include <gtest/gtest.h>

using namespace WS;
using ::testing::AtLeast;
using ::testing::Return;


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

TEST(SensorTest, checkCallToUpdateValue) {
  std::unique_ptr<TemperatureScaleMock> temperatureScaleMock = std::make_unique<TemperatureScaleMock>();
  EXPECT_CALL(*temperatureScaleMock, updateValue(27.55))
  .Times(testing::AtLeast(1));              
  TemperatureSensor sensor(std::move(temperatureScaleMock)); 
  ASSERT_EQ(sensor.check_temperature("../test/unit_tests/TemperatureTest"), 0.0f);
}

TEST(SensorTest, checkCallToGetValue) {
  std::unique_ptr<TemperatureScaleMock> temperatureScaleMock = std::make_unique<TemperatureScaleMock>();
  EXPECT_CALL(*temperatureScaleMock, getValue())
  .Times(testing::AtLeast(1))
  .WillOnce(Return(27.55f));
  TemperatureSensor sensor(std::move(temperatureScaleMock)); 
  ASSERT_EQ(sensor.check_temperature("../test/unit_tests/TemperatureTest"),27.55f);
}

TEST_F(ReadTemperature, is_on_ReturnsOffStateAtStart)
{
    ASSERT_EQ(temp_sensor_->is_on(), state::off);
}

TEST_F(ReadTemperature, is_on_ReturnsUnknownStateWithWrongInputFile)
{
    temp_sensor_->update_sensor_power_status("some random file");
    ASSERT_EQ(temp_sensor_->is_on(), state::unknown);
}


TEST_F(ReadTemperature, is_on_ReturnsOnStateWithDummyInputFile)
{
    temp_sensor_->update_sensor_power_status("../test/unit_tests/TemperaturePowerStatus");
    ASSERT_EQ(temp_sensor_->is_on(), state::on);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
