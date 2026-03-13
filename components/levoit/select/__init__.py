import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import select
from esphome.const import CONF_ICON, CONF_ID, CONF_OPTIONS

from .. import CONF_LEVOIT_ID, Levoit, levoit_ns

CONF_TYPE = "type"

LevoitSelect = levoit_ns.class_("LevoitSelect", select.Select, cg.Component)

SelectType = levoit_ns.enum("SelectType")

TYPE_MAP = {
    "auto_mode": SelectType.AUTO_MODE,
    # Superior only
    "auto_profile": SelectType.AUTO_PROFILE,
    "humidity_subtype": SelectType.HUMIDITY_SUBTYPE,
    "dry_level": SelectType.DRY_LEVEL,
}

TYPE_DEFAULTS = {
    "auto_mode": {
        CONF_ICON: "mdi:fan-auto",
    },
    "auto_profile": {
        CONF_ICON: "mdi:home-account",
    },
    "humidity_subtype": {
        CONF_ICON: "mdi:cloud-percent",
    },
    "dry_level": {
        CONF_ICON: "mdi:fan",
    },
}

CONFIG_SCHEMA = select.select_schema(LevoitSelect).extend(
    {
        cv.Required(CONF_LEVOIT_ID): cv.use_id(Levoit),
        cv.Required(CONF_TYPE): cv.one_of(*TYPE_MAP.keys(), lower=True),
        cv.Optional(CONF_ICON): cv.icon,
    }
)


async def to_code(config):
    parent = await cg.get_variable(config[CONF_LEVOIT_ID])
    ntype = config[CONF_TYPE]

    config = dict(config)
    for key, value in TYPE_DEFAULTS.get(ntype, {}).items():
        config.setdefault(key, value)

    var = cg.new_Pvariable(config[CONF_ID])

    await select.register_select(var, config, options=["Default"])
    await cg.register_component(var, config)

    cg.add(var.set_parent(parent))

    st = TYPE_MAP[ntype]
    cg.add(var.set_type(st))
    cg.add(parent.register_select(st, var))
