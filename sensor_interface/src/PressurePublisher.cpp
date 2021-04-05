#include "PressurePublisher.hpp"

namespace WS {
    PressurePublisher::PressurePublisher(std::shared_ptr<MQTTClient> client) : mqttClient_{client}
    {
        if (!mqttClient_) {
            throw std::runtime_error("PressurePublisher::PressurePublisher(std::shared_ptr<MQTTClient> called with nullptr");
        }

        if (!mqttClient_->IsConnected()) {
            mqttClient_->Connect();
        }
        pressureSensor_ = std::make_unique<PressureSensor>();
    }

    double PressurePublisher::publish() const
    {
        double pressure = pressureSensor_->check_pressure();
        //TODO instead of returning pressure value, check if publish was success
        mqttClient_->PublishMessage("Pressure", pressure);
        return pressure;
    }

    auto PressurePublisher::get_client() -> std::shared_ptr<MQTTClient> const
    {
        return mqttClient_;
    }

} // namespace WS