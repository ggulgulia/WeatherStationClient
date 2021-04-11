cmake_minimum_required(VERSION 3.5)

## project name
project("paho-mqtt-cpp" 
    VERSION "1.2.0"
    LANGUAGES CXX
)

## --- Build options ---

option(PAHO_BUILD_STATIC "Build static library" FALSE)
option(PAHO_BUILD_SHARED "Build shared library" TRUE)
option(PAHO_WITH_SSL "Build SSL-enabled library" TRUE)
option(PAHO_BUILD_DEB_PACKAGE "Build debian package" FALSE)

option(PAHO_BUILD_SAMPLES "Build sample programs" FALSE)
option(PAHO_BUILD_TESTS "Build tests" FALSE)
option(PAHO_BUILD_DOCUMENTATION "Create and install the API documentation (requires Doxygen)" FALSE)

## --- C++11 build flags ---

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate position-independent code (-fPIC on UNIX)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# --- System Libraries ---

include(GNUInstallDirs)

set(LIBS_SYSTEM c stdc++)

## --- Build directories ---

# For the paho_mqtt_c module
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
add_subdirectory(src)

# --- Documentation ---

if(PAHO_BUILD_DOCUMENTATION)
    add_subdirectory(doc)
endif()

# --- Default library for samples and unit tests ---

if(PAHO_BUILD_SHARED)
    set(PAHO_CPP_LIB paho-mqttpp3)
else()
    set(PAHO_CPP_LIB paho-mqttpp3-static)
endif()

# --- Sample Apps ---

if(PAHO_BUILD_SAMPLES)
    add_subdirectory(src/samples)
endif()

# --- Unit Tests ---

if(PAHO_BUILD_DEB_PACKAGE)
    set(CPACK_GENERATOR "DEB")
    include(cmake/CPackDebConfig.cmake)
else()
    set(CPACK_GENERATOR "TGZ")
endif()

add_subdirectory(cmake)


