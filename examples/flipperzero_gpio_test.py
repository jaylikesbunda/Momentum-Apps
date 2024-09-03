import flipperzero as f0
import time

f0.gpio_init_pin(f0.GPIO_PIN_PC3, f0.GPIO_MODE_OUTPUT_PUSH_PULL)

f0.gpio_set_pin(f0.GPIO_PIN_PC3, True)
time.sleep(1)
f0.gpio_set_pin(f0.GPIO_PIN_PC3, False)
time.sleep(1)
f0.gpio_set_pin(f0.GPIO_PIN_PC3, True)
time.sleep(1)
f0.gpio_set_pin(f0.GPIO_PIN_PC3, False)