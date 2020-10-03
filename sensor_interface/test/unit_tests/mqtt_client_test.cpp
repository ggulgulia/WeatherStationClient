#include <gtest/gtest.h>
#include "../../headers/mqtt_client.hpp"

using namespace WS;

//Test fixture
class MqttClientFixture : public testing::Test{
    public:
    std::unique_ptr<MQTTClient> mqtt_client_;

    MqttClientFixture(): 
    mqtt_client_{std::make_unique<MQTTClient>()}
    {}
};

TEST_F(MqttClientFixture, initialization){
    ASSERT_NE(mqtt_client_, nullptr);
} 


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}