
add_executable(read_temperature_test
              read_temperature_test.cpp
              )
target_link_libraries(read_temperature_test gtest)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/unit_tests")

add_test(NAME test1 COMMAND read_temperature_test)
##################
add_executable(mqtt_client_test
              mqtt_client_test.cpp
              )

target_link_libraries(mqtt_client_test ws_mqtt_client paho-mqtt3c paho-mqttpp3 gtest)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/unit_tests")

add_test(NAME test2 COMMAND mqtt_client_test)