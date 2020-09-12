#include <gtest/gtest.h>
#include "../../headers/TemperatureSensor.h"

using namespace WS;

class ReadTemperature : public testing::Test{
    public:
        double temp;
        std::unique_ptr<TemperatureSensor> temp_sensor_;

        ReadTemperature(): temp{0}, 
                         temp_sensor_{std::make_unique<TemperatureSensor>()}{

        }

        ~ReadTemperature(){

        }
};

TEST_F(ReadTemperature, initialize){

}


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}