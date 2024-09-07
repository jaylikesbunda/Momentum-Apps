import flipperzero as f0
import time

signal = f0.infrared_receive()

value = '{value} #'.format(value=len(signal))

f0.canvas_clear()

f0.canvas_set_text(64, 32, value)

f0.canvas_update()

time.sleep(5)
