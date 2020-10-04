#include "TemperaturePublisher.hpp"
#include <gtest/gtest.h>

using namespace WS;


class TemperaturePublisherFixture : public testing::Test{
    public:
    std::unique_ptr<TemperaturePublisher> temperaturePublisher_;

    TemperaturePublisherFixture():
    temperaturePublisher_{std::make_unique<TemperaturePublisher>()}
    {           }
};

TEST_F(TemperaturePublisherFixture, IsInitialized){
    EXPECT_NE(temperaturePublisher_, nullptr);
}

TEST_F(TemperaturePublisherFixture, PublishesHardcodedTemperature){
    ASSERT_EQ(temperaturePublisher_->publish(), 25.1);
}
int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}