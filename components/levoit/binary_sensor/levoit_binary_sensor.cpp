#include "levoit_binary_sensor.h"
#include "esphome/core/log.h"
#include "../levoit.h"

namespace esphome
{
    namespace levoit
    {

        static const char *const TAG = "levoit.binary_sensor";

        void LevoitBinarySensor::setup()
        {
            ESP_LOGD(TAG, "Setting up Levoit Binary Sensor");
            switch (this->type_)
            {
            case BinarySensorType::FILTER_STATE:
                break;
            case BinarySensorType::COVER_REMOVED:
                break;
            case BinarySensorType::DRY_ACTIVE:
                break;
            case BinarySensorType::HUMIDIFYING:
                break;
            case BinarySensorType::WATER_TANK_EMPTY:
                break;
            case BinarySensorType::ERROR_STATE:
                this->set_entity_category(EntityCategory::ENTITY_CATEGORY_DIAGNOSTIC);
                break;
            default:
                break;
            }
        }

        void LevoitBinarySensor::dump_config()
        {
            LOG_BINARY_SENSOR("", "Levoit Binary Sensor", this);
        }

        void LevoitBinarySensor::loop()
        {
            if (this->parent_ == nullptr)
                return;

            bool desired = this->parent_->get_binary_sensor_state(this->type_);
            if (!this->has_state() || this->state != desired)
            {
                this->publish_state(desired);
            }
        }

    } // namespace levoit
} // namespace esphome
