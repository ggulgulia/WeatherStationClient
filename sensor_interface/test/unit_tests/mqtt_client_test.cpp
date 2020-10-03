#include <gtest/gtest.h>
#include "mqtt_client.hpp"
#include <typeinfo>
#include <chrono>

using namespace WS;

//Test fixture
class MqttClientFixture : public testing::Test{
    public:
    std::unique_ptr<MQTTClient> mqtt_client_;

    MqttClientFixture(): 
    mqtt_client_{std::make_unique<MQTTClient>("localhost", "test_id")}
    {}
};

TEST_F(MqttClientFixture, Initialization){
    ASSERT_NE(mqtt_client_, nullptr);
}

TEST(MqttClientTest, ConnectionFails){
  MQTTClient mqtt_client{"fake_ip", "fake_client"};
  EXPECT_THROW( mqtt_client.Connect();, mqtt::exception );
  ASSERT_EQ(mqtt_client.IsConnected(), false);
}

TEST_F(MqttClientFixture, ConnectionSuccessful){
    mqtt_client_->Connect();
    ASSERT_EQ(mqtt_client_->IsConnected(), true);
}

TEST_F(MqttClientFixture, PublishMessageSucceeds){
    mqtt_client_->Connect();
    Result ret = mqtt_client_->PublishMessage("Topic1", "Payload 1");
    ASSERT_EQ(ret, Result::Successful);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}