#pragma once
#include <cstdint>

namespace esphome
{
    namespace levoit
    {

        enum ModelType : uint8_t
        {
            VITAL100S = 0,
            VITAL200S = 1,
            CORE300S = 2,
            CORE400S = 3,
            SUPERIOR6000S = 4,
        };

        enum class SwitchType : uint8_t
        {
            DISPLAY = 0,
            CHILD_LOCK = 1,
            LIGHT_DETECT = 2,        // Vital only
            AUTO_DRY_POWER_OFF = 3,  // Superior only
            AUTO_DRY_WATER_EMPTY = 4 // Superior only
        };
        static constexpr SwitchType DISPLAY = SwitchType::DISPLAY;
        static constexpr SwitchType CHILD_LOCK = SwitchType::CHILD_LOCK;
        static constexpr SwitchType LIGHT_DETECT = SwitchType::LIGHT_DETECT;
        static constexpr SwitchType AUTO_DRY_POWER_OFF = SwitchType::AUTO_DRY_POWER_OFF;
        static constexpr SwitchType AUTO_DRY_WATER_EMPTY = SwitchType::AUTO_DRY_WATER_EMPTY;

        enum class NumberType : uint8_t
        {
            TIMER = 0,
            EFFICIENCY_ROOM_SIZE = 1,
            FILTER_LIFETIME_MONTHS = 2,
            HUMIDITY_TARGET = 3, // Superior only
        };
        static constexpr NumberType TIMER = NumberType::TIMER;
        static constexpr NumberType EFFICIENCY_ROOM_SIZE = NumberType::EFFICIENCY_ROOM_SIZE;
        static constexpr NumberType FILTER_LIFETIME_MONTHS = NumberType::FILTER_LIFETIME_MONTHS;
        static constexpr NumberType HUMIDITY_TARGET = NumberType::HUMIDITY_TARGET;

        enum class SensorType : uint8_t
        {
            AQI = 0,
            PM25 = 1,
            TIMER_CURRENT = 2,
            EFFICIENCY_COUNTER = 3, // Vital only
            CURRENT_CADR = 4,
            FILTER_LIFE_LEFT = 5,
            HUMIDITY = 6,           // Superior only
            TEMPERATURE = 7,        // Superior only
            FILTER_LIFE_MCU = 8,    // Superior only
            DRY_TIME_REMAINING = 9, // Superior only
        };
        static constexpr SensorType AQI = SensorType::AQI;
        static constexpr SensorType PM25 = SensorType::PM25;
        static constexpr SensorType TIMER_CURRENT = SensorType::TIMER_CURRENT;
        static constexpr SensorType EFFICIENCY_COUNTER = SensorType::EFFICIENCY_COUNTER;
        static constexpr SensorType CURRENT_CADR = SensorType::CURRENT_CADR;
        static constexpr SensorType FILTER_LIFE_LEFT = SensorType::FILTER_LIFE_LEFT;
        static constexpr SensorType HUMIDITY = SensorType::HUMIDITY;
        static constexpr SensorType TEMPERATURE = SensorType::TEMPERATURE;
        static constexpr SensorType FILTER_LIFE_MCU = SensorType::FILTER_LIFE_MCU;
        static constexpr SensorType DRY_TIME_REMAINING = SensorType::DRY_TIME_REMAINING;

        enum class BinarySensorType : uint8_t
        {
            FILTER_LOW = 0,
            COVER_REMOVED = 1,    // Superior only
            WATER_TANK_EMPTY = 2, // Superior only
            DRY_ACTIVE = 3,       // Superior only
            HUMIDIFYING = 4,      // Superior only
            ERROR_STATE = 5,
        };
        static constexpr BinarySensorType FILTER_LOW = BinarySensorType::FILTER_LOW;
        static constexpr BinarySensorType COVER_REMOVED = BinarySensorType::COVER_REMOVED;
        static constexpr BinarySensorType WATER_TANK_EMPTY = BinarySensorType::WATER_TANK_EMPTY;
        static constexpr BinarySensorType DRY_ACTIVE = BinarySensorType::DRY_ACTIVE;
        static constexpr BinarySensorType HUMIDIFYING = BinarySensorType::HUMIDIFYING;
        static constexpr BinarySensorType ERROR_STATE = BinarySensorType::ERROR_STATE;

        enum class ButtonType : uint8_t
        {
            RESET_FILTER_STATS = 0,
        };
        static constexpr ButtonType RESET_FILTER_STATS = ButtonType::RESET_FILTER_STATS;

        enum class TextSensorType : uint8_t
        {
            MCU_VERSION = 0,
            ESP_VERSION = 1,
        };
        static constexpr TextSensorType MCU_VERSION = TextSensorType::MCU_VERSION;
        static constexpr TextSensorType ESP_VERSION = TextSensorType::ESP_VERSION;

        enum class SelectType : uint8_t
        {
            AUTO_MODE = 0,
            AUTO_PROFILE = 1,     // Superior only
            HUMIDITY_SUBTYPE = 2, // Superior only
            DRY_LEVEL = 3,        // Superior only
        };
        static constexpr SelectType AUTO_MODE = SelectType::AUTO_MODE;
        static constexpr SelectType AUTO_PROFILE = SelectType::AUTO_PROFILE;
        static constexpr SelectType HUMIDITY_SUBTYPE = SelectType::HUMIDITY_SUBTYPE;
        static constexpr SelectType DRY_LEVEL = SelectType::DRY_LEVEL;

        typedef enum
        {
            ack,
            setDeviceON,
            setDeviceOFF,
            setDeviceFanLvl1,
            setDeviceFanLvl2,
            setDeviceFanLvl3,
            setDeviceFanLvl4,
            setDisplayLockOn,
            setDisplayLockOff,
            setDisplayOn,
            setDisplayOff,
            setAutoModeQuiet,
            setAutoModeDefault,
            setAutoModeEfficient,
            setTimerMinutes,
            requestTimerStatus,
            setFanModeManual,
            setFanModeAuto,
            setFanModeSleep,
            resetFilter,
            setWifiLedOn,
            setWifiLedOff,
            setWifiLedBlinking,
            setFilterLedOn,
            setFilterLedOff,
            // Vital only
            setLightDetectOn,
            setLightDetectOff,
            setFanModePet,
            // Superior only
            setDeviceFanLvl5,
            setDeviceFanLvl6,
            setDeviceFanLvl7,
            setDeviceFanLvl8,
            setDeviceFanLvl9,
            setFanModeHumidity,
            setAutoProfileHome,
            setAutoProfileAway,
            setHumiditySubtypeSmart,
            setHumiditySubtypeFan,
            setHumidityTarget,
            setDryLevelLow,
            setDryLevelHigh,
            setAutoDryPowerOffOn,
            setAutoDryPowerOffOff,
            setAutoDryWaterEmptyOn,
            setAutoDryWaterEmptyOff,
            COMMAND_TYPE_MAX
        } CommandType;

        static const char *command_type_to_string(CommandType cmd)
        {
            static const char *const names[] = {
                "ack",
                "setDeviceON",
                "setDeviceOFF",
                "setDeviceFanLvl1",
                "setDeviceFanLvl2",
                "setDeviceFanLvl3",
                "setDeviceFanLvl4",
                "setDisplayLockOn",
                "setDisplayLockOff",
                "setDisplayOn",
                "setDisplayOff",
                "setAutoModeQuiet",
                "setAutoModeDefault",
                "setAutoModeEfficient",
                "setTimerMinutes",
                "requestTimerStatus",
                "setFanModeManual",
                "setFanModeAuto",
                "setFanModeSleep",
                "resetFilter",
                "setWifiLedOn",
                "setWifiLedOff",
                "setWifiLedBlinking",
                "setFilterLedOn",
                "setFilterLedOff",
                "setLightDetectOn",
                "setLightDetectOff",
                "setFanModePet",
                "setDeviceFanLvl5",
                "setDeviceFanLvl6",
                "setDeviceFanLvl7",
                "setDeviceFanLvl8",
                "setDeviceFanLvl9",
                "setFanModeHumidity",
                "setAutoProfileHome",
                "setAutoProfileAway",
                "setHumiditySubtypeSmart",
                "setHumiditySubtypeFan",
                "setHumidityTarget",
                "setDryLevelLow",
                "setDryLevelHigh",
                "setAutoDryPowerOffOn",
                "setAutoDryPowerOffOff",
                "setAutoDryWaterEmptyOn",
                "setAutoDryWaterEmptyOff",
            };
            static_assert(
                sizeof(names) / sizeof(names[0]) == COMMAND_TYPE_MAX,
                "CommandType string table out of sync");
            if (cmd < 0 || cmd >= COMMAND_TYPE_MAX)
                return "UNKNOWN_COMMAND";

            return names[cmd];
        }

    } // namespace levoit
} // namespace esphome
