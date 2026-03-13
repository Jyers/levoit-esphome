import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_DEVICE_CLASS, CONF_ICON, CONF_ID

from .. import CONF_LEVOIT_ID, Levoit, levoit_ns

CONF_TYPE = "type"

LevoitSensor = levoit_ns.class_("LevoitSensor", sensor.Sensor, cg.Component)
SensorType = levoit_ns.enum("SensorType")

TYPE_MAP = {
    "aqi": SensorType.AQI,
    "pm25": SensorType.PM25,
    "timer_current": SensorType.TIMER_CURRENT,
    "efficiency_counter": SensorType.EFFICIENCY_COUNTER,
    "current_cadr": SensorType.CURRENT_CADR,
    "filter_life_left": SensorType.FILTER_LIFE_LEFT,
    # Superior only below
    "humidity": SensorType.HUMIDITY,
    "temperature": SensorType.TEMPERATURE,
    "filter_life_mcu": SensorType.FILTER_LIFE_MCU,
    "dry_time_remaining": SensorType.DRY_TIME_REMAINING,
}

TYPE_DEFAULTS = {
    "efficiency_counter": {
        CONF_DEVICE_CLASS: "duration",
        CONF_ICON: "mdi:counter",
    },
    "timer_current": {
        CONF_DEVICE_CLASS: "duration",
        CONF_ICON: "mdi:timer-outline",
    },
    "pm25": {
        CONF_DEVICE_CLASS: "pm25",
    },
    "aqi": {
        CONF_DEVICE_CLASS: "aqi",
        CONF_ICON: "mdi:molecule",
    },
    "current_cadr": {
        CONF_DEVICE_CLASS: "volume_flow_rate",
        CONF_ICON: "mdi:air-filter",
    },
    "filter_life_left": {
        CONF_ICON: "mdi:air-filter",
    },
    "filter_life_mcu": {
        CONF_ICON: "mdi:air-filter",
    },
    "temperature": {
        CONF_DEVICE_CLASS: "temperature",
    },
    "humidity": {
        CONF_DEVICE_CLASS: "humidity",
    },
    "dry_time_remaining": {
        CONF_DEVICE_CLASS: "duration",
        CONF_ICON: "mdi:timer-sand",
    },
}


CONFIG_SCHEMA = sensor.sensor_schema(LevoitSensor).extend(
    {
        cv.Required(CONF_LEVOIT_ID): cv.use_id(Levoit),
        cv.Required(CONF_TYPE): cv.one_of(*TYPE_MAP.keys(), lower=True),
    }
)


async def to_code(config):
    parent = await cg.get_variable(config[CONF_LEVOIT_ID])
    sensor_type = config[CONF_TYPE]

    config = dict(config)
    for key, value in TYPE_DEFAULTS.get(sensor_type, {}).items():
        config.setdefault(key, value)

    var = cg.new_Pvariable(config[CONF_ID])
    await sensor.register_sensor(var, config)
    await cg.register_component(var, config)

    # parent pointer for write_state -> send UART command
    cg.add(var.set_parent(parent))

    # set enum type and register into parent
    st = TYPE_MAP[sensor_type]
    cg.add(var.set_type(st))
    cg.add(parent.register_sensor(st, var))
