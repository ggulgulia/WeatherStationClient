#include "TemperaturePublisher.hpp"
#include "mqtt_client.hpp"
#include <gtest/gtest.h>

using namespace WS;


class TemperaturePublisherFixture : public testing::Test{
    public:
    std::shared_ptr<MQTTClient> client = std::make_shared<MQTTClient>("localhost", "Rpi");
    std::unique_ptr<TemperaturePublisher> temperaturePublisher_;
    TemperaturePublisherFixture(): temperaturePublisher_{std::make_unique<TemperaturePublisher>(client)}
    {           }

    ~TemperaturePublisherFixture(){}
};

TEST_F(TemperaturePublisherFixture, IsInitialized){
    EXPECT_NE(temperaturePublisher_, nullptr);
}

TEST_F(TemperaturePublisherFixture, IsClientConnected){
    auto client = temperaturePublisher_->get_client();
    ASSERT_EQ(client->IsConnected(), true);
}

TEST_F(TemperaturePublisherFixture, PublishesHardcodedTemperature){
    ASSERT_GT(temperaturePublisher_->publish(), 10.0);
    ASSERT_LT(temperaturePublisher_->publish(), 30);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}