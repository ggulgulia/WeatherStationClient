
find_package(PkgConfig REQUIRED)
pkg_check_modules(gtest REQUIRED gtest>=1.8.1)
include_directories(${gtest_INCLUDE_DIRS})

add_executable(read_temperature_test
                read_temperature_test.cpp
                )
target_link_libraries(read_temperature_test ${gtest_LIBRARIES})
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/unit_tests")

cmake_minimum_required(VERSION 3.2.3)
project(VBF_iwb_TUM CXX) 
enable_testing()
################

add_test(NAME test COMMAND read_temperature_test)