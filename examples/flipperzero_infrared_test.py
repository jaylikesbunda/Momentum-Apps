import flipperzero as f0
import time

raw_signal = f0.infrared_receive()

signal = map(lambda v: int(v / 100), raw_signal)

level = False

i = -1
x = 0
y_low = 32
y_high = 40
y_level = y_low

f0.canvas_clear()

for duration in signal:
    i += 1

    if i < 10:
        continue

    if level:
        f0.canvas_draw_line(x, y_low, x, y_high)
        y_level = y_high
    else:
        f0.canvas_draw_line(x, y_high, x, y_low)
        y_level = y_low

    f0.canvas_draw_line(x, y_level, x + duration, y_level)

    x += duration

    level = not level

    if x > f0.canvas_width():
        break

f0.canvas_update()

time.sleep(5)

f0.infrared_transmit(raw_signal)
