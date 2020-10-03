#include <gtest/gtest.h>
#include "../../headers/mqtt_client.hpp"
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

TEST_F(MqttClientFixture, initialization){
    ASSERT_NE(mqtt_client_, nullptr);
}

TEST(MqttClientTest, client_does_not_connect_to_fake_ip){
  MQTTClient mqtt_client{"fake_ip", "fake_client"};
  mqtt_client.Connect();
  ASSERT_EQ(mqtt_client.IsConnected(), false);
}

TEST_F(MqttClientFixture, ConnectionSuccessful){
    mqtt_client_->Connect();
    ASSERT_EQ(mqtt_client_->IsConnected(), true);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}