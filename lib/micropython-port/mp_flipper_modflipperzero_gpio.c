#include <furi_hal.h>

#include <mp_flipper_modflipperzero.h>

static const GpioPin* decode_pin(uint8_t pin) {
    switch(pin) {
    case MP_FLIPPER_GPIO_PIN_PC0:
        return &gpio_ext_pc0;
    case MP_FLIPPER_GPIO_PIN_PC1:
        return &gpio_ext_pc1;
    case MP_FLIPPER_GPIO_PIN_PC3:
        return &gpio_ext_pc3;
    case MP_FLIPPER_GPIO_PIN_PB2:
        return &gpio_ext_pb2;
    case MP_FLIPPER_GPIO_PIN_PB3:
        return &gpio_ext_pb3;
    case MP_FLIPPER_GPIO_PIN_PA4:
        return &gpio_ext_pa4;
    case MP_FLIPPER_GPIO_PIN_PA6:
        return &gpio_ext_pa6;
    case MP_FLIPPER_GPIO_PIN_PA7:
        return &gpio_ext_pa7;
    default:
        furi_crash("unknown GPIO pin");
    }
}

static inline const GpioMode decode_mode(uint8_t mode) {
    switch(mode) {
    case MP_FLIPPER_GPIO_MODE_INPUT:
        return GpioModeInput;
    case MP_FLIPPER_GPIO_MODE_OUTPUT_PUSH_PULL:
        return GpioModeOutputPushPull;
    case MP_FLIPPER_GPIO_MODE_OUTPUT_OPEN_DRAIN:
        return GpioModeOutputOpenDrain;
    case MP_FLIPPER_GPIO_MODE_ANALOG:
        return GpioModeAnalog;
    case MP_FLIPPER_GPIO_MODE_INTERRUPT_FALL:
        return GpioModeInterruptFall;
    case MP_FLIPPER_GPIO_MODE_INTERRUPT_RISE:
        return GpioModeInterruptRise;
    }

    if((mode & MP_FLIPPER_GPIO_MODE_INTERRUPT_FALL) &&
       (mode & MP_FLIPPER_GPIO_MODE_INTERRUPT_RISE)) {
        return GpioModeInterruptRiseFall;
    }

    furi_crash("unknown GPIO mode");
}

static inline const GpioPull decode_pull(uint8_t pull) {
    switch(pull) {
    case MP_FLIPPER_GPIO_PULL_NO:
        return GpioPullNo;
    case MP_FLIPPER_GPIO_PULL_UP:
        return GpioPullUp;
    case MP_FLIPPER_GPIO_PULL_DOWN:
        return GpioPullDown;
    default:
        furi_crash("unknown GPIO pull");
    }
}

static inline const GpioSpeed decode_speed(uint8_t speed) {
    switch(speed) {
    case MP_FLIPPER_GPIO_SPEED_LOW:
        return GpioSpeedLow;
    case MP_FLIPPER_GPIO_SPEED_MEDIUM:
        return GpioSpeedMedium;
    case MP_FLIPPER_GPIO_SPEED_HIGH:
        return GpioSpeedHigh;
    case MP_FLIPPER_GPIO_SPEED_VERY_HIGH:
        return GpioSpeedVeryHigh;
    default:
        furi_crash("unknown GPIO speed");
    }
}

inline void mp_flipper_gpio_init_pin(
    uint8_t raw_pin,
    uint8_t raw_mode,
    uint8_t raw_pull,
    uint8_t raw_speed) {
    const GpioPin* pin = decode_pin(raw_pin);
    const GpioMode mode = decode_mode(raw_mode);
    const GpioPull pull = decode_pull(raw_pull);
    const GpioSpeed speed = decode_speed(raw_speed);

    furi_hal_gpio_init(pin, mode, pull, speed);

    if(raw_mode & (MP_FLIPPER_GPIO_MODE_INTERRUPT_FALL | MP_FLIPPER_GPIO_MODE_INTERRUPT_RISE)) {
        furi_hal_gpio_add_int_callback(pin, mp_flipper_on_gpio, (void*)raw_pin);
        furi_hal_gpio_enable_int_callback(pin);
    } else {
        furi_hal_gpio_disable_int_callback(pin);
        furi_hal_gpio_remove_int_callback(pin);
    }
}

inline void mp_flipper_gpio_set_pin(uint8_t raw_pin, bool state) {
    const GpioPin* pin = decode_pin(raw_pin);

    furi_hal_gpio_write(pin, state);
}

inline bool mp_flipper_gpio_get_pin(uint8_t raw_pin) {
    const GpioPin* pin = decode_pin(raw_pin);

    return furi_hal_gpio_read(pin);
}
