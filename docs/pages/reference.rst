Reference
=========

This page contains the API documentation of the ``flipperzero`` module and some built-in functions.

Vibration
---------

Control the vibration motor of your Flipper.

.. autofunction:: flipperzero.vibro_set

Light
-----

Control the RGB LED and display backlight of your Flipper.

.. autodata:: flipperzero.LIGHT_RED
.. autodata:: flipperzero.LIGHT_GREEN
.. autodata:: flipperzero.LIGHT_BLUE
.. autodata:: flipperzero.LIGHT_BACKLIGHT
.. autofunction:: flipperzero.light_set
.. autofunction:: flipperzero.light_blink_start
.. autofunction:: flipperzero.light_blink_set_color
.. autofunction:: flipperzero.light_blink_stop

Speaker
-------

Full control over the built-in speaker module.

..
   for octave in range(9):
      for name in ['C', 'CS', 'D', 'DS', 'E', 'F', 'FS', 'G', 'GS', 'A', 'AS', 'B']:
         print(f'.. autodata:: flipperzero.SPEAKER_NOTE_{name}{octave}')

.. autodata:: flipperzero.SPEAKER_NOTE_C0
.. autodata:: flipperzero.SPEAKER_NOTE_CS0
.. autodata:: flipperzero.SPEAKER_NOTE_D0
.. autodata:: flipperzero.SPEAKER_NOTE_DS0
.. autodata:: flipperzero.SPEAKER_NOTE_E0
.. autodata:: flipperzero.SPEAKER_NOTE_F0
.. autodata:: flipperzero.SPEAKER_NOTE_FS0
.. autodata:: flipperzero.SPEAKER_NOTE_G0
.. autodata:: flipperzero.SPEAKER_NOTE_GS0
.. autodata:: flipperzero.SPEAKER_NOTE_A0
.. autodata:: flipperzero.SPEAKER_NOTE_AS0
.. autodata:: flipperzero.SPEAKER_NOTE_B0
.. autodata:: flipperzero.SPEAKER_NOTE_C1
.. autodata:: flipperzero.SPEAKER_NOTE_CS1
.. autodata:: flipperzero.SPEAKER_NOTE_D1
.. autodata:: flipperzero.SPEAKER_NOTE_DS1
.. autodata:: flipperzero.SPEAKER_NOTE_E1
.. autodata:: flipperzero.SPEAKER_NOTE_F1
.. autodata:: flipperzero.SPEAKER_NOTE_FS1
.. autodata:: flipperzero.SPEAKER_NOTE_G1
.. autodata:: flipperzero.SPEAKER_NOTE_GS1
.. autodata:: flipperzero.SPEAKER_NOTE_A1
.. autodata:: flipperzero.SPEAKER_NOTE_AS1
.. autodata:: flipperzero.SPEAKER_NOTE_B1
.. autodata:: flipperzero.SPEAKER_NOTE_C2
.. autodata:: flipperzero.SPEAKER_NOTE_CS2
.. autodata:: flipperzero.SPEAKER_NOTE_D2
.. autodata:: flipperzero.SPEAKER_NOTE_DS2
.. autodata:: flipperzero.SPEAKER_NOTE_E2
.. autodata:: flipperzero.SPEAKER_NOTE_F2
.. autodata:: flipperzero.SPEAKER_NOTE_FS2
.. autodata:: flipperzero.SPEAKER_NOTE_G2
.. autodata:: flipperzero.SPEAKER_NOTE_GS2
.. autodata:: flipperzero.SPEAKER_NOTE_A2
.. autodata:: flipperzero.SPEAKER_NOTE_AS2
.. autodata:: flipperzero.SPEAKER_NOTE_B2
.. autodata:: flipperzero.SPEAKER_NOTE_C3
.. autodata:: flipperzero.SPEAKER_NOTE_CS3
.. autodata:: flipperzero.SPEAKER_NOTE_D3
.. autodata:: flipperzero.SPEAKER_NOTE_DS3
.. autodata:: flipperzero.SPEAKER_NOTE_E3
.. autodata:: flipperzero.SPEAKER_NOTE_F3
.. autodata:: flipperzero.SPEAKER_NOTE_FS3
.. autodata:: flipperzero.SPEAKER_NOTE_G3
.. autodata:: flipperzero.SPEAKER_NOTE_GS3
.. autodata:: flipperzero.SPEAKER_NOTE_A3
.. autodata:: flipperzero.SPEAKER_NOTE_AS3
.. autodata:: flipperzero.SPEAKER_NOTE_B3
.. autodata:: flipperzero.SPEAKER_NOTE_C4
.. autodata:: flipperzero.SPEAKER_NOTE_CS4
.. autodata:: flipperzero.SPEAKER_NOTE_D4
.. autodata:: flipperzero.SPEAKER_NOTE_DS4
.. autodata:: flipperzero.SPEAKER_NOTE_E4
.. autodata:: flipperzero.SPEAKER_NOTE_F4
.. autodata:: flipperzero.SPEAKER_NOTE_FS4
.. autodata:: flipperzero.SPEAKER_NOTE_G4
.. autodata:: flipperzero.SPEAKER_NOTE_GS4
.. autodata:: flipperzero.SPEAKER_NOTE_A4
.. autodata:: flipperzero.SPEAKER_NOTE_AS4
.. autodata:: flipperzero.SPEAKER_NOTE_B4
.. autodata:: flipperzero.SPEAKER_NOTE_C5
.. autodata:: flipperzero.SPEAKER_NOTE_CS5
.. autodata:: flipperzero.SPEAKER_NOTE_D5
.. autodata:: flipperzero.SPEAKER_NOTE_DS5
.. autodata:: flipperzero.SPEAKER_NOTE_E5
.. autodata:: flipperzero.SPEAKER_NOTE_F5
.. autodata:: flipperzero.SPEAKER_NOTE_FS5
.. autodata:: flipperzero.SPEAKER_NOTE_G5
.. autodata:: flipperzero.SPEAKER_NOTE_GS5
.. autodata:: flipperzero.SPEAKER_NOTE_A5
.. autodata:: flipperzero.SPEAKER_NOTE_AS5
.. autodata:: flipperzero.SPEAKER_NOTE_B5
.. autodata:: flipperzero.SPEAKER_NOTE_C6
.. autodata:: flipperzero.SPEAKER_NOTE_CS6
.. autodata:: flipperzero.SPEAKER_NOTE_D6
.. autodata:: flipperzero.SPEAKER_NOTE_DS6
.. autodata:: flipperzero.SPEAKER_NOTE_E6
.. autodata:: flipperzero.SPEAKER_NOTE_F6
.. autodata:: flipperzero.SPEAKER_NOTE_FS6
.. autodata:: flipperzero.SPEAKER_NOTE_G6
.. autodata:: flipperzero.SPEAKER_NOTE_GS6
.. autodata:: flipperzero.SPEAKER_NOTE_A6
.. autodata:: flipperzero.SPEAKER_NOTE_AS6
.. autodata:: flipperzero.SPEAKER_NOTE_B6
.. autodata:: flipperzero.SPEAKER_NOTE_C7
.. autodata:: flipperzero.SPEAKER_NOTE_CS7
.. autodata:: flipperzero.SPEAKER_NOTE_D7
.. autodata:: flipperzero.SPEAKER_NOTE_DS7
.. autodata:: flipperzero.SPEAKER_NOTE_E7
.. autodata:: flipperzero.SPEAKER_NOTE_F7
.. autodata:: flipperzero.SPEAKER_NOTE_FS7
.. autodata:: flipperzero.SPEAKER_NOTE_G7
.. autodata:: flipperzero.SPEAKER_NOTE_GS7
.. autodata:: flipperzero.SPEAKER_NOTE_A7
.. autodata:: flipperzero.SPEAKER_NOTE_AS7
.. autodata:: flipperzero.SPEAKER_NOTE_B7
.. autodata:: flipperzero.SPEAKER_NOTE_C8
.. autodata:: flipperzero.SPEAKER_NOTE_CS8
.. autodata:: flipperzero.SPEAKER_NOTE_D8
.. autodata:: flipperzero.SPEAKER_NOTE_DS8
.. autodata:: flipperzero.SPEAKER_NOTE_E8
.. autodata:: flipperzero.SPEAKER_NOTE_F8
.. autodata:: flipperzero.SPEAKER_NOTE_FS8
.. autodata:: flipperzero.SPEAKER_NOTE_G8
.. autodata:: flipperzero.SPEAKER_NOTE_GS8
.. autodata:: flipperzero.SPEAKER_NOTE_A8
.. autodata:: flipperzero.SPEAKER_NOTE_AS8
.. autodata:: flipperzero.SPEAKER_NOTE_B8

.. autodata:: flipperzero.SPEAKER_VOLUME_MIN
.. autodata:: flipperzero.SPEAKER_VOLUME_MAX

.. autofunction:: flipperzero.speaker_start
.. autofunction:: flipperzero.speaker_set_volume
.. autofunction:: flipperzero.speaker_stop

Input
-----

Make your application interactive with full control over the Flipper's hardware buttons.

.. autodata:: flipperzero.INPUT_BUTTON_UP
.. autodata:: flipperzero.INPUT_BUTTON_DOWN
.. autodata:: flipperzero.INPUT_BUTTON_RIGHT
.. autodata:: flipperzero.INPUT_BUTTON_LEFT
.. autodata:: flipperzero.INPUT_BUTTON_OK
.. autodata:: flipperzero.INPUT_BUTTON_BACK
.. autodata:: flipperzero.INPUT_TYPE_PRESS
.. autodata:: flipperzero.INPUT_TYPE_RELEASE
.. autodata:: flipperzero.INPUT_TYPE_SHORT
.. autodata:: flipperzero.INPUT_TYPE_LONG
.. autodata:: flipperzero.INPUT_TYPE_REPEAT
.. autodecorator:: flipperzero.on_input

Canvas
------

Write text and draw dots and shapes on the the display.

.. autofunction:: flipperzero.canvas_update
.. autofunction:: flipperzero.canvas_clear
.. autofunction:: flipperzero.canvas_width
.. autofunction:: flipperzero.canvas_height
.. autodata:: flipperzero.COLOR_BLACK
.. autodata:: flipperzero.COLOR_WHITE
.. autofunction:: flipperzero.canvas_set_color
.. autodata:: flipperzero.ALIGN_BEGIN
.. autodata:: flipperzero.ALIGN_END
.. autodata:: flipperzero.ALIGN_CENTER
.. autofunction:: flipperzero.canvas_set_text_align
.. autodata:: flipperzero.FONT_PRIMARY
.. autodata:: flipperzero.FONT_SECONDARY
.. autofunction:: flipperzero.canvas_set_font
.. autofunction:: flipperzero.canvas_set_text
.. autofunction:: flipperzero.canvas_draw_dot
.. autofunction:: flipperzero.canvas_draw_box
.. autofunction:: flipperzero.canvas_draw_frame
.. autofunction:: flipperzero.canvas_draw_line
.. autofunction:: flipperzero.canvas_draw_circle
.. autofunction:: flipperzero.canvas_draw_disc

Dialog
------

Display message dialogs on the display for user infos and confirm actions.

.. autofunction:: flipperzero.dialog_message_set_header
.. autofunction:: flipperzero.dialog_message_set_text
.. autofunction:: flipperzero.dialog_message_set_button
.. autofunction:: flipperzero.dialog_message_show

Built-In
--------

The functions in this section are `not` part of the ``flipperzero`` module.
They're members of the global namespace instead.

.. py:function:: print(*objects, sep=' ', end='\n', file=None, flush=False) -> None

   The standard Python `print <https://docs.python.org/3/library/functions.html#print>`_ function.

   :param objects: The objects to print (mostly a single string).
   :param sep: The separator to use between the objects.
   :param end: The line terminator character to use.

   .. versionadded:: 1.0.0

   .. attention::
      
      This function prints to the internal log buffer.
      Check out the `Flipper Zero docs <https://docs.flipper.net/development/cli#_yZ2E>`_ on how to reveal them in the CLI interface.

