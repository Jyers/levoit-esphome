import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import fan
from esphome.components.fan import validate_preset_modes
from esphome.const import CONF_PRESET_MODES, CONF_SPEED_COUNT, CONF_ICON

from .. import CONF_LEVOIT_ID, Levoit, levoit_ns

CODEOWNERS = ["@tuct"]

LevoitFan = levoit_ns.class_("LevoitFan", cg.Component, fan.Fan)


CONFIG_SCHEMA = (
    fan.fan_schema(LevoitFan)
    .extend({cv.Required(CONF_LEVOIT_ID): cv.use_id(Levoit)})
    .extend(cv.COMPONENT_SCHEMA)
    .extend({
        cv.Optional(CONF_ICON): cv.icon,
    })
)


async def to_code(config):
    # Add default icon for fan
    if CONF_ICON not in config:
        config[CONF_ICON] = "mdi:fan"

    var = await fan.new_fan(config)
    await cg.register_component(var, config)

    parent = await cg.get_variable(config[CONF_LEVOIT_ID])
    cg.add(var.set_parent(parent))
    cg.add(parent.set_fan(var))
