#ifndef SENSOR_DATA_PATH_H
#define SENSOR_DATA_PATH_H

#include <string>

const std::string sensor_filepath{"~/home/gajendra/sensordata"};
const std::string power_status_filepath{"/sys/bus/w1/devices/28-00000b65fafc/ext_power"};
const std::string temperature_filepath{"/sys/bus/w1/devices/28-00000b65fafc/temperature"};



#endif //SENSOR_DATA_PATH_H
