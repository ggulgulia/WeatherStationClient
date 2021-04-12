cmake_minimum_required(VERSION 3.1)
project(sensor_interface VERSION 1.0.0 LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++17")
add_subdirectory(externalLib)
IF(CMAKE_BUILD_TYPE MATCHES Release)
	message("Building project Sensor Interface ${VERSION}")
	message(STATUS "CXX Flags used: ${CMAKE_CXX_FLAGS_RELEASE}")
	add_subdirectory(src)
ELSEIF(CMAKE_BUILD_TYPE MATCHES Debug)
	message("Building project Sensor Interface with tests")
	set(CMAKE_CXX_FLAGS "-g -fprofile-arcs -ftest-coverage")
	add_subdirectory(src)
	enable_testing()
	add_subdirectory(test/googletest)
	add_subdirectory(test/unit_tests)
	IF(COVERAGE)
	include("CMakeModules/CodeCoverage.cmake")
	setup_target_for_coverage_gcovr_html(NAME coverage
							           	EXECUTABLE ctest -VV
										EXCLUDE "${PROJECT_SOURCE_DIR}/test"
								        )
	message("Building project Sensor Interface test coverage")
	ENDIF()
ELSE()
 	 message("Some other build type.")
ENDIF()

message(STATUS "c++ flags : ${CMAKE_CXX_FLAGS}")
