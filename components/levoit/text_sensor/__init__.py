import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor
from esphome.const import CONF_ICON, CONF_ID

from .. import CONF_LEVOIT_ID, Levoit, levoit_ns

CONF_TYPE = "type"

LevoitTextSensor = levoit_ns.class_(
    "LevoitTextSensor", text_sensor.TextSensor, cg.Component
)
TextSensorType = levoit_ns.enum("TextSensorType")

TYPE_MAP = {
    "mcu_version": TextSensorType.MCU_VERSION,
    "esp_version": TextSensorType.ESP_VERSION,
    "error_message": TextSensorType.ERROR_MESSAGE,
}


CONFIG_SCHEMA = text_sensor.text_sensor_schema(LevoitTextSensor).extend(
    {
        cv.Required(CONF_LEVOIT_ID): cv.use_id(Levoit),
        cv.Required(CONF_TYPE): cv.one_of(*TYPE_MAP.keys(), lower=True),
        cv.Optional(CONF_ICON): cv.icon,
    }
)


async def to_code(config):
    parent = await cg.get_variable(config[CONF_LEVOIT_ID])
    sensor_type = config[CONF_TYPE]

    var = cg.new_Pvariable(config[CONF_ID])
    await text_sensor.register_text_sensor(var, config)
    await cg.register_component(var, config)

    # parent pointer for write_state
    cg.add(var.set_parent(parent))

    # set enum type and register into parent
    st = TYPE_MAP[sensor_type]
    cg.add(var.set_type(st))
    cg.add(parent.register_text_sensor(st, var))
