add_library(ws_mqtt_client
            mqtt_client.cpp)

target_include_directories(ws_mqtt_client
                            PUBLIC
                            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/headers>
                            $<INSTALL_INTERFACE:headers>
                           )
