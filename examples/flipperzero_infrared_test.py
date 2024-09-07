import flipperzero as f0
import time

signal = f0.infrared_receive()

durations = map(lambda v:str(v), signal)
value = ','.join(durations)

f0.canvas_clear()

f0.canvas_set_text(10, 32, value)

f0.canvas_update()

time.sleep(5)
