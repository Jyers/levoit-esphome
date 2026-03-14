#include "levoit_sensor.h"
#include "../levoit.h"
#include "esphome/core/entity_base.h"

namespace esphome
{
  namespace levoit
  {

    static const char *const TAG = "levoit.sensor";

    void LevoitSensor::setup()
    {
      // pick default
      // this->traits.set_mode(sensor::SensorMode::NUMBER_MODE_AUTO);

      switch (this->type_)
      {
      case SensorType::EFFICIENCY_COUNTER:
        this->set_unit_of_measurement("s");
        this->set_entity_category(EntityCategory::ENTITY_CATEGORY_DIAGNOSTIC);
        break;
      case SensorType::TIMER_CURRENT:
        this->set_unit_of_measurement("h");
        this->set_accuracy_decimals(2);
        break;
      case SensorType::PM25:
        this->set_unit_of_measurement("µg/m³");
        this->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
        break;
      case SensorType::AQI:
        this->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
        break;
      case SensorType::AIR_QUALITY_PERCENT:
        this->set_unit_of_measurement("%");
        this->set_accuracy_decimals(0);
        this->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
        break;
      case SensorType::CURRENT_CADR:
        this->set_entity_category(EntityCategory::ENTITY_CATEGORY_DIAGNOSTIC);
        this->set_unit_of_measurement("m³/h");
        this->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
        break;
      case SensorType::FILTER_LIFE_LEFT:
        this->set_unit_of_measurement("%");
        this->set_accuracy_decimals(1);
        break;
      case SensorType::FILTER_LIFE_MCU:
        this->set_unit_of_measurement("%");
        this->set_accuracy_decimals(0);
        break;
      case SensorType::TEMPERATURE:
        this->set_unit_of_measurement("°C");
        this->set_accuracy_decimals(1);
        this->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
        break;
      case SensorType::HUMIDITY:
        this->set_unit_of_measurement("%");
        this->set_accuracy_decimals(0);
        this->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
        break;
      case SensorType::DRY_TIME_REMAINING:
        this->set_unit_of_measurement("h");
        this->set_accuracy_decimals(2);
        break;
      default:
        break;
      }
    }
    void LevoitSensor::dump_config() { LOG_SENSOR("", "Levoit Sensor", this); }

  } // namespace levoit
} // namespace esphome
