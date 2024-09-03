#pragma once

#include <stdint.h>
#include <stdbool.h>

#define MP_FLIPPER_LED_RED (1 << 0)
#define MP_FLIPPER_LED_GREEN (1 << 1)
#define MP_FLIPPER_LED_BLUE (1 << 2)
#define MP_FLIPPER_LED_BACKLIGHT (1 << 3)

#define MP_FLIPPER_COLOR_BLACK (1 << 0)
#define MP_FLIPPER_COLOR_WHITE (1 << 1)

#define MP_FLIPPER_INPUT_BUTTON_UP (1 << 0)
#define MP_FLIPPER_INPUT_BUTTON_DOWN (1 << 1)
#define MP_FLIPPER_INPUT_BUTTON_RIGHT (1 << 2)
#define MP_FLIPPER_INPUT_BUTTON_LEFT (1 << 3)
#define MP_FLIPPER_INPUT_BUTTON_OK (1 << 4)
#define MP_FLIPPER_INPUT_BUTTON_BACK (1 << 5)
#define MP_FLIPPER_INPUT_BUTTON ((1 << 6) - 1)

#define MP_FLIPPER_INPUT_TYPE_PRESS (1 << 6)
#define MP_FLIPPER_INPUT_TYPE_RELEASE (1 << 7)
#define MP_FLIPPER_INPUT_TYPE_SHORT (1 << 8)
#define MP_FLIPPER_INPUT_TYPE_LONG (1 << 9)
#define MP_FLIPPER_INPUT_TYPE_REPEAT (1 << 10)
#define MP_FLIPPER_INPUT_TYPE ((1 << 11) - 1 - MP_FLIPPER_INPUT_BUTTON)

#define MP_FLIPPER_ALIGN_BEGIN (1 << 0)
#define MP_FLIPPER_ALIGN_CENTER (1 << 1)
#define MP_FLIPPER_ALIGN_END (1 << 2)

#define MP_FLIPPER_FONT_PRIMARY (1 << 0)
#define MP_FLIPPER_FONT_SECONDARY (1 << 1)

void mp_flipper_light_set(uint8_t raw_light, uint8_t brightness);
void mp_flipper_light_blink_start(uint8_t raw_light, uint8_t brightness, uint16_t on_time, uint16_t period);
void mp_flipper_light_blink_set_color(uint8_t raw_light);
void mp_flipper_light_blink_stop();

void mp_flipper_vibro(bool state);

/*
Python script for notes generation

# coding: utf-8
# Python script for notes generation

from typing import List

note_names: List = ['C', 'CS', 'D', 'DS', 'E', 'F', 'FS', 'G', 'GS', 'A', 'AS', 'B']
base_note: float = 16.3515979
cf: float = 2 ** (1.0 / 12)

note: float = base_note
for octave in range(9):
    for name in note_names:
        print(f"#define MP_FLIPPER_SPEAKER_NOTE_{name}{octave} {round(note, 2)}")
        note = note * cf
*/

#define MP_FLIPPER_SPEAKER_NOTE_C0 16.35
#define MP_FLIPPER_SPEAKER_NOTE_CS0 17.32
#define MP_FLIPPER_SPEAKER_NOTE_D0 18.35
#define MP_FLIPPER_SPEAKER_NOTE_DS0 19.45
#define MP_FLIPPER_SPEAKER_NOTE_E0 20.6
#define MP_FLIPPER_SPEAKER_NOTE_F0 21.83
#define MP_FLIPPER_SPEAKER_NOTE_FS0 23.12
#define MP_FLIPPER_SPEAKER_NOTE_G0 24.5
#define MP_FLIPPER_SPEAKER_NOTE_GS0 25.96
#define MP_FLIPPER_SPEAKER_NOTE_A0 27.5
#define MP_FLIPPER_SPEAKER_NOTE_AS0 29.14
#define MP_FLIPPER_SPEAKER_NOTE_B0 30.87
#define MP_FLIPPER_SPEAKER_NOTE_C1 32.7
#define MP_FLIPPER_SPEAKER_NOTE_CS1 34.65
#define MP_FLIPPER_SPEAKER_NOTE_D1 36.71
#define MP_FLIPPER_SPEAKER_NOTE_DS1 38.89
#define MP_FLIPPER_SPEAKER_NOTE_E1 41.2
#define MP_FLIPPER_SPEAKER_NOTE_F1 43.65
#define MP_FLIPPER_SPEAKER_NOTE_FS1 46.25
#define MP_FLIPPER_SPEAKER_NOTE_G1 49.0
#define MP_FLIPPER_SPEAKER_NOTE_GS1 51.91
#define MP_FLIPPER_SPEAKER_NOTE_A1 55.0
#define MP_FLIPPER_SPEAKER_NOTE_AS1 58.27
#define MP_FLIPPER_SPEAKER_NOTE_B1 61.74
#define MP_FLIPPER_SPEAKER_NOTE_C2 65.41
#define MP_FLIPPER_SPEAKER_NOTE_CS2 69.3
#define MP_FLIPPER_SPEAKER_NOTE_D2 73.42
#define MP_FLIPPER_SPEAKER_NOTE_DS2 77.78
#define MP_FLIPPER_SPEAKER_NOTE_E2 82.41
#define MP_FLIPPER_SPEAKER_NOTE_F2 87.31
#define MP_FLIPPER_SPEAKER_NOTE_FS2 92.5
#define MP_FLIPPER_SPEAKER_NOTE_G2 98.0
#define MP_FLIPPER_SPEAKER_NOTE_GS2 103.83
#define MP_FLIPPER_SPEAKER_NOTE_A2 110.0
#define MP_FLIPPER_SPEAKER_NOTE_AS2 116.54
#define MP_FLIPPER_SPEAKER_NOTE_B2 123.47
#define MP_FLIPPER_SPEAKER_NOTE_C3 130.81
#define MP_FLIPPER_SPEAKER_NOTE_CS3 138.59
#define MP_FLIPPER_SPEAKER_NOTE_D3 146.83
#define MP_FLIPPER_SPEAKER_NOTE_DS3 155.56
#define MP_FLIPPER_SPEAKER_NOTE_E3 164.81
#define MP_FLIPPER_SPEAKER_NOTE_F3 174.61
#define MP_FLIPPER_SPEAKER_NOTE_FS3 185.0
#define MP_FLIPPER_SPEAKER_NOTE_G3 196.0
#define MP_FLIPPER_SPEAKER_NOTE_GS3 207.65
#define MP_FLIPPER_SPEAKER_NOTE_A3 220.0
#define MP_FLIPPER_SPEAKER_NOTE_AS3 233.08
#define MP_FLIPPER_SPEAKER_NOTE_B3 246.94
#define MP_FLIPPER_SPEAKER_NOTE_C4 261.63
#define MP_FLIPPER_SPEAKER_NOTE_CS4 277.18
#define MP_FLIPPER_SPEAKER_NOTE_D4 293.66
#define MP_FLIPPER_SPEAKER_NOTE_DS4 311.13
#define MP_FLIPPER_SPEAKER_NOTE_E4 329.63
#define MP_FLIPPER_SPEAKER_NOTE_F4 349.23
#define MP_FLIPPER_SPEAKER_NOTE_FS4 369.99
#define MP_FLIPPER_SPEAKER_NOTE_G4 392.0
#define MP_FLIPPER_SPEAKER_NOTE_GS4 415.3
#define MP_FLIPPER_SPEAKER_NOTE_A4 440.0
#define MP_FLIPPER_SPEAKER_NOTE_AS4 466.16
#define MP_FLIPPER_SPEAKER_NOTE_B4 493.88
#define MP_FLIPPER_SPEAKER_NOTE_C5 523.25
#define MP_FLIPPER_SPEAKER_NOTE_CS5 554.37
#define MP_FLIPPER_SPEAKER_NOTE_D5 587.33
#define MP_FLIPPER_SPEAKER_NOTE_DS5 622.25
#define MP_FLIPPER_SPEAKER_NOTE_E5 659.26
#define MP_FLIPPER_SPEAKER_NOTE_F5 698.46
#define MP_FLIPPER_SPEAKER_NOTE_FS5 739.99
#define MP_FLIPPER_SPEAKER_NOTE_G5 783.99
#define MP_FLIPPER_SPEAKER_NOTE_GS5 830.61
#define MP_FLIPPER_SPEAKER_NOTE_A5 880.0
#define MP_FLIPPER_SPEAKER_NOTE_AS5 932.33
#define MP_FLIPPER_SPEAKER_NOTE_B5 987.77
#define MP_FLIPPER_SPEAKER_NOTE_C6 1046.5
#define MP_FLIPPER_SPEAKER_NOTE_CS6 1108.73
#define MP_FLIPPER_SPEAKER_NOTE_D6 1174.66
#define MP_FLIPPER_SPEAKER_NOTE_DS6 1244.51
#define MP_FLIPPER_SPEAKER_NOTE_E6 1318.51
#define MP_FLIPPER_SPEAKER_NOTE_F6 1396.91
#define MP_FLIPPER_SPEAKER_NOTE_FS6 1479.98
#define MP_FLIPPER_SPEAKER_NOTE_G6 1567.98
#define MP_FLIPPER_SPEAKER_NOTE_GS6 1661.22
#define MP_FLIPPER_SPEAKER_NOTE_A6 1760.0
#define MP_FLIPPER_SPEAKER_NOTE_AS6 1864.66
#define MP_FLIPPER_SPEAKER_NOTE_B6 1975.53
#define MP_FLIPPER_SPEAKER_NOTE_C7 2093.0
#define MP_FLIPPER_SPEAKER_NOTE_CS7 2217.46
#define MP_FLIPPER_SPEAKER_NOTE_D7 2349.32
#define MP_FLIPPER_SPEAKER_NOTE_DS7 2489.02
#define MP_FLIPPER_SPEAKER_NOTE_E7 2637.02
#define MP_FLIPPER_SPEAKER_NOTE_F7 2793.83
#define MP_FLIPPER_SPEAKER_NOTE_FS7 2959.96
#define MP_FLIPPER_SPEAKER_NOTE_G7 3135.96
#define MP_FLIPPER_SPEAKER_NOTE_GS7 3322.44
#define MP_FLIPPER_SPEAKER_NOTE_A7 3520.0
#define MP_FLIPPER_SPEAKER_NOTE_AS7 3729.31
#define MP_FLIPPER_SPEAKER_NOTE_B7 3951.07
#define MP_FLIPPER_SPEAKER_NOTE_C8 4186.01
#define MP_FLIPPER_SPEAKER_NOTE_CS8 4434.92
#define MP_FLIPPER_SPEAKER_NOTE_D8 4698.64
#define MP_FLIPPER_SPEAKER_NOTE_DS8 4978.03
#define MP_FLIPPER_SPEAKER_NOTE_E8 5274.04
#define MP_FLIPPER_SPEAKER_NOTE_F8 5587.65
#define MP_FLIPPER_SPEAKER_NOTE_FS8 5919.91
#define MP_FLIPPER_SPEAKER_NOTE_G8 6271.93
#define MP_FLIPPER_SPEAKER_NOTE_GS8 6644.88
#define MP_FLIPPER_SPEAKER_NOTE_A8 7040.0
#define MP_FLIPPER_SPEAKER_NOTE_AS8 7458.62
#define MP_FLIPPER_SPEAKER_NOTE_B8 7902.13

bool mp_flipper_speaker_start(float frequency, float volume);
bool mp_flipper_speaker_set_volume(float volume);
bool mp_flipper_speaker_stop();

uint8_t mp_flipper_canvas_width();
uint8_t mp_flipper_canvas_height();
uint8_t mp_flipper_canvas_text_width(const char* text);
uint8_t mp_flipper_canvas_text_height();
void mp_flipper_canvas_draw_dot(uint8_t x, uint8_t y);
void mp_flipper_canvas_draw_box(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r);
void mp_flipper_canvas_draw_frame(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t r);
void mp_flipper_canvas_draw_line(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
void mp_flipper_canvas_draw_circle(uint8_t x, uint8_t y, uint8_t r);
void mp_flipper_canvas_draw_disc(uint8_t x, uint8_t y, uint8_t r);
void mp_flipper_canvas_set_font(uint8_t font);
void mp_flipper_canvas_set_color(uint8_t color);
void mp_flipper_canvas_set_text(uint8_t x, uint8_t y, const char* text);
void mp_flipper_canvas_set_text_align(uint8_t x, uint8_t y);
void mp_flipper_canvas_update();
void mp_flipper_canvas_clear();

void mp_flipper_on_input(uint16_t button, uint16_t type);

void mp_flipper_dialog_message_set_text(const char* text, uint8_t x, uint8_t y, uint8_t h, uint8_t v);
void mp_flipper_dialog_message_set_header(const char* text, uint8_t x, uint8_t y, uint8_t h, uint8_t v);
void mp_flipper_dialog_message_set_button(const char* text, uint8_t button);
uint8_t mp_flipper_dialog_message_show();
void mp_flipper_dialog_message_clear();
