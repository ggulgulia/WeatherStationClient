
add_executable(read_temperature_test
                read_temperature_test.cpp
                )
target_link_libraries(read_temperature_test gtest)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/unit_tests")

add_test(NAME test COMMAND read_temperature_test)