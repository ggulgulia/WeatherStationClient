#include <gtest/gtest.h>
#include "../../headers/mqtt_client.hpp"
#include <typeinfo>

using namespace WS;

//Test fixture
class MqttClientFixture : public testing::Test{
    public:
    std::unique_ptr<MQTTClient> mqtt_client_;

    MqttClientFixture(): 
    mqtt_client_{std::make_unique<MQTTClient>("198.168.0.226", "test_id")}
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

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}