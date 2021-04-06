#ifndef PRESSURE_HELPER
#define PRESSURE_HELPER


#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <thread>
#include <iostream>

using namespace std::literals::chrono_literals;

double PressureHelper();

#endif /* ifndef PRESSURE_HELPER*/
