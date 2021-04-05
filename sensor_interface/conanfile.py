from conans import ConanFile, CMake, tools

class WeatherStation(ConanFile):
    name = "WeatherStation"
    version = "1.0.0"
    description = "C++ Weather Station Project"
    settings = "cppstd", "os", "compiler", "build_type", "arch"
    requires = "paho-mqtt-cpp/1.2.0", "paho-mqtt-c/1.3.8"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
