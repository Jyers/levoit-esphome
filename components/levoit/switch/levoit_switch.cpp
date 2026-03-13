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
        break;
      case SwitchType::CHILD_LOCK:
        break;
      case SwitchType::LIGHT_DETECT:
        break;
      case SwitchType::AUTO_DRY_POWER_OFF:
        break;
      case SwitchType::AUTO_DRY_WATER_EMPTY:
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
