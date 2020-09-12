#include <gtest/gtest.h>

class ReadTemperature : public testing::Test{
    public:

        ReadTemperature(){
        temp = 0;

        }
        int temp;
        ~ReadTemperature(){

        }

    private:

};

TEST_F(ReadTemperature, initialize){
    ASSERT_EQ(1,1);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}