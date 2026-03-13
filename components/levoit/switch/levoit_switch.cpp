#include "levoit_switch.h"
#include "../levoit.h"
#include "esphome/core/log.h"

namespace esphome
{
  namespace levoit
  {
    static const char *const TAG = "levoit.switch";
    void LevoitSwitch::setup()
    {
      switch (this->type_)
      {
      case SwitchType::DISPLAY:
        this->set_icon("mdi:brightness-7");
        break;
      case SwitchType::CHILD_LOCK:
        this->set_icon("mdi:lock-outline");
        break;
      case SwitchType::LIGHT_DETECT:
        this->set_icon("mdi:lightbulb-auto-outline");
        break;
      case SwitchType::AUTO_DRY_POWER_OFF:
        this->set_icon("mdi:fan-auto");
        break;
      case SwitchType::AUTO_DRY_WATER_EMPTY:
        this->set_icon("mdi:fan-auto");
        break;
      default:
        break;
      }
      this->set_entity_category(EntityCategory::ENTITY_CATEGORY_CONFIG);
    }
    void LevoitSwitch::write_state(bool state)
    {
      // Optimistic update for HA UI
      this->publish_state(state);

      if (!parent_)
      {
        ESP_LOGW(TAG, "No parent set for switch");
        return;
      }

      parent_->on_switch_command(this->type_, state);
    }
    void LevoitSwitch::dump_config() { LOG_SWITCH("", "Levoit Switch", this); }
  } // namespace levoit
} // namespace esphome
