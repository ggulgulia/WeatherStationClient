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

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}