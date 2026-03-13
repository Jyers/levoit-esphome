import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import switch
from esphome.const import CONF_ICON, CONF_ID

from .. import CONF_LEVOIT_ID, Levoit, levoit_ns

CONF_TYPE = "type"

LevoitSwitch = levoit_ns.class_("LevoitSwitch", switch.Switch, cg.Component)
SwitchType = levoit_ns.enum("SwitchType")

TYPE_MAP = {
    "display": SwitchType.DISPLAY,
    "child_lock": SwitchType.CHILD_LOCK,
    "light_detect": SwitchType.LIGHT_DETECT,
    "auto_dry_power_off": SwitchType.AUTO_DRY_POWER_OFF,
    "auto_dry_water_empty": SwitchType.AUTO_DRY_WATER_EMPTY,
}

TYPE_DEFAULTS = {
    "display": {
        CONF_ICON: "mdi:brightness-7",
    },
    "child_lock": {
        CONF_ICON: "mdi:lock-outline",
    },
    "light_detect": {
        CONF_ICON: "mdi:lightbulb-auto-outline",
    },
    "auto_dry_power_off": {
        CONF_ICON: "mdi:fan-auto",
    },
    "auto_dry_water_empty": {
        CONF_ICON: "mdi:fan-auto",
    },
}

CONFIG_SCHEMA = switch.switch_schema(LevoitSwitch).extend(
    {
        cv.Required(CONF_LEVOIT_ID): cv.use_id(Levoit),
        cv.Required(CONF_TYPE): cv.one_of(*TYPE_MAP.keys(), lower=True),
        cv.Optional(CONF_ICON): cv.icon,
    }
)


async def to_code(config):
    parent = await cg.get_variable(config[CONF_LEVOIT_ID])

    switch_type = config[CONF_TYPE]

    config = dict(config)
    for key, value in TYPE_DEFAULTS.get(switch_type, {}).items():
        config.setdefault(key, value)

    var = cg.new_Pvariable(config[CONF_ID])
    await switch.register_switch(var, config)
    await cg.register_component(var, config)

    # parent pointer for write_state -> send UART command
    cg.add(var.set_parent(parent))

    # set enum type and register into parent
    st = TYPE_MAP[switch_type]
    cg.add(var.set_type(st))
    cg.add(parent.register_switch(st, var))
