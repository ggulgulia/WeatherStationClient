add_library(ws_mqtt_client
            TemperatureSensor.cpp
            mqtt_client.cpp
            TemperaturePublisher.cpp)

target_include_directories(ws_mqtt_client
                            PUBLIC
                            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/headers>
                            $<INSTALL_INTERFACE:headers>
                           )

add_executable(weather_station
                main.cpp 
                )

target_link_libraries(weather_station ws_mqtt_client)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build")