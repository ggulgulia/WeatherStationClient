#include "TemperaturePublisher.hpp"

namespace WS {
    TemperaturePublisher::TemperaturePublisher(std::shared_ptr<MQTTClient> client) : mqttClient_{client}
    {
        if (!mqttClient_) {
            throw std::runtime_error("TemperaturePublisher::TemperaturePublisher(std::shared_ptr<MQTTClient> called with nullptr");
        }

        if (!mqttClient_->IsConnected()) {
            mqttClient_->Connect();
        }
        temperatureSensor_ = std::make_unique<TemperatureSensor>();
    }

    double TemperaturePublisher::publish() const
    {
        double temperature = temperatureSensor_->check_temperature();
        //TODO instead of returning temperature value, check if publish was success
        mqttClient_->PublishMessage("Temperature", static_cast<float>(temperature));
	std::cout << "Temp: " << static_cast<float>(temperature) << "\n";
        return temperature;
    }

    auto TemperaturePublisher::get_client() -> std::shared_ptr<MQTTClient> const
    {
        return mqttClient_;
    }

} // namespace WS
