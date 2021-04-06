#ifndef PRESSURE_PUBLISHER_H
#define PRESSURE_PUBLISHER_H

#include "PressureSensor.hpp"
#include "mqtt_client.hpp"
#include <exception>
namespace WS {

    class PressurePublisher {
    public:
        PressurePublisher(std::shared_ptr<MQTTClient> client);
        double publish() const;
        auto get_client() -> std::shared_ptr<MQTTClient> const;

    private:
        std::shared_ptr<MQTTClient> mqttClient_;
        std::unique_ptr<PressureSensor> pressureSensor_{nullptr};
    };

} // namespace WS

#endif //PRESSURE_PUBLISHER_H