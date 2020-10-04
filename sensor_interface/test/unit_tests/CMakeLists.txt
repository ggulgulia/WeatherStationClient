
############################# TEST 1 #############################
add_executable(read_temperature_test
              read_temperature_test.cpp
              )
target_link_libraries(read_temperature_test ws_mqtt_client gtest)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/unit_tests")
add_test(NAME test1 COMMAND read_temperature_test)
############################## END ##############################


############################# TEST 2 ############################
add_executable(mqtt_client_test
              mqtt_client_test.cpp
              )
target_link_libraries(mqtt_client_test ws_mqtt_client paho-mqtt3c paho-mqttpp3 gtest)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/unit_tests")
add_test(NAME test2 COMMAND mqtt_client_test)
############################## END ##############################


############################# TEST 2 ############################
add_executable(temperature_publisher_test
               temperature_publisher_test.cpp
              )
target_link_libraries(temperature_publisher_test ws_mqtt_client paho-mqtt3c paho-mqttpp3 gtest)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/unit_tests")
add_test(NAME test3 COMMAND temperature_publisher_test)
############################## END ##############################