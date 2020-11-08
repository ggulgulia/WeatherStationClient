#include "TemperatureScale.hpp"
#include <gtest/gtest.h>

class TemperatureScaleTest : public testing::Test {
public:
    double temp;
    std::unique_ptr<WS::TemperatureScale> tempScale_{nullptr};
};

TEST_F(TemperatureScaleTest, checkTemperatureScaleCelcius)
{
    tempScale_ = std::make_unique<WS::Celcius>();
    tempScale_->updateValue(25.0);
    ASSERT_DOUBLE_EQ(tempScale_->getValue(), 25.0);
}

TEST_F(TemperatureScaleTest, PrintsTemperatureInCelcius)
{
    tempScale_ = std::make_unique<WS::Celcius>();
    tempScale_->updateValue(32.0);
    std::cout << *tempScale_;
}

TEST_F(TemperatureScaleTest, checkTemperatureScaleFahrenheit)
{
    tempScale_ = std::make_unique<WS::Fahrenheit>();
    tempScale_->updateValue(25.0);
    ASSERT_DOUBLE_EQ(tempScale_->getValue(), (25.0*9.0/5.0 + 32.0));

}

TEST_F(TemperatureScaleTest, PrintsTemperatureFahrenheit)
{
    tempScale_ = std::make_unique<WS::Fahrenheit>();
    tempScale_->updateValue(32.0);
    std::cout << *tempScale_;
}

TEST_F(TemperatureScaleTest, checkTemperatureScaleKelvin)
{
    tempScale_ = std::make_unique<WS::Kelvin>();
    tempScale_->updateValue(25.0);
    ASSERT_DOUBLE_EQ(tempScale_->getValue(), 25.0 + 273.15);
}

TEST_F(TemperatureScaleTest, PrintsTemperatureKelvin)
{
    tempScale_ = std::make_unique<WS::Kelvin>();
    tempScale_->updateValue(32.0);
    std::cout << *tempScale_;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}