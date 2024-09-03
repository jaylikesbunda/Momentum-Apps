#include <stdio.h>

#include "py/objint.h"
#include "py/objfun.h"
#include "py/obj.h"
#include "py/runtime.h"

#include "mp_flipper_modflipperzero.h"

typedef struct {
    uint8_t button;
    uint8_t type;
} on_input_arg_t;

static void* mp_flipper_on_input_callback = NULL;

static mp_obj_t flipperzero_light_set(mp_obj_t light_obj, mp_obj_t brightness_obj) {
    mp_int_t light = mp_obj_get_int(light_obj);
    mp_int_t brightness = mp_obj_get_int(brightness_obj);

    mp_flipper_light_set(light, brightness);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_2(flipperzero_light_set_obj, flipperzero_light_set);

static mp_obj_t flipperzero_light_blink_start(size_t n_args, const mp_obj_t* args) {
    if(n_args != 4) {
        return mp_const_none;
    }

    mp_int_t light = mp_obj_get_int(args[0]);
    mp_int_t brightness = mp_obj_get_int(args[1]);
    mp_int_t on_time = mp_obj_get_int(args[2]);
    mp_int_t period = mp_obj_get_int(args[3]);

    mp_flipper_light_blink_start(light, brightness, on_time, period);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(flipperzero_light_blink_start_obj, 4, 4, flipperzero_light_blink_start);

static mp_obj_t flipperzero_light_blink_stop() {
    mp_flipper_light_blink_stop();

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_0(flipperzero_light_blink_stop_obj, flipperzero_light_blink_stop);

static mp_obj_t flipperzero_light_blink_set_color(mp_obj_t light_obj) {
    mp_int_t light = mp_obj_get_int(light_obj);

    mp_flipper_light_blink_set_color(light);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_1(flipperzero_light_blink_set_color_obj, flipperzero_light_blink_set_color);

static mp_obj_t flipperzero_vibro_set(mp_obj_t state) {
    bool state_bool = mp_obj_is_true(state);

    mp_flipper_vibro(state_bool);

    return state_bool ? mp_const_true : mp_const_false;
}
static MP_DEFINE_CONST_FUN_OBJ_1(flipperzero_vibro_set_obj, flipperzero_vibro_set);

/*
Python script for notes generation

# coding: utf-8
# Python script for notes generation

from typing import List

note_names: List = ['C', 'CS', 'D', 'DS', 'E', 'F', 'FS', 'G', 'GS', 'A', 'AS', 'B']

for octave in range(9):
    for name in note_names:
        print("const mp_obj_t flipperzero_speaker_note_%s%s = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_%s%s};" % (name.lower(),octave,name,octave))
*/

const mp_obj_t flipperzero_speaker_note_c0 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_C0};
const mp_obj_t flipperzero_speaker_note_cs0 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_CS0};
const mp_obj_t flipperzero_speaker_note_d0 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_D0};
const mp_obj_t flipperzero_speaker_note_ds0 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_DS0};
const mp_obj_t flipperzero_speaker_note_e0 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_E0};
const mp_obj_t flipperzero_speaker_note_f0 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_F0};
const mp_obj_t flipperzero_speaker_note_fs0 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_FS0};
const mp_obj_t flipperzero_speaker_note_g0 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_G0};
const mp_obj_t flipperzero_speaker_note_gs0 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_GS0};
const mp_obj_t flipperzero_speaker_note_a0 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_A0};
const mp_obj_t flipperzero_speaker_note_as0 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_AS0};
const mp_obj_t flipperzero_speaker_note_b0 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_B0};
const mp_obj_t flipperzero_speaker_note_c1 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_C1};
const mp_obj_t flipperzero_speaker_note_cs1 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_CS1};
const mp_obj_t flipperzero_speaker_note_d1 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_D1};
const mp_obj_t flipperzero_speaker_note_ds1 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_DS1};
const mp_obj_t flipperzero_speaker_note_e1 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_E1};
const mp_obj_t flipperzero_speaker_note_f1 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_F1};
const mp_obj_t flipperzero_speaker_note_fs1 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_FS1};
const mp_obj_t flipperzero_speaker_note_g1 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_G1};
const mp_obj_t flipperzero_speaker_note_gs1 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_GS1};
const mp_obj_t flipperzero_speaker_note_a1 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_A1};
const mp_obj_t flipperzero_speaker_note_as1 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_AS1};
const mp_obj_t flipperzero_speaker_note_b1 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_B1};
const mp_obj_t flipperzero_speaker_note_c2 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_C2};
const mp_obj_t flipperzero_speaker_note_cs2 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_CS2};
const mp_obj_t flipperzero_speaker_note_d2 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_D2};
const mp_obj_t flipperzero_speaker_note_ds2 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_DS2};
const mp_obj_t flipperzero_speaker_note_e2 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_E2};
const mp_obj_t flipperzero_speaker_note_f2 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_F2};
const mp_obj_t flipperzero_speaker_note_fs2 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_FS2};
const mp_obj_t flipperzero_speaker_note_g2 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_G2};
const mp_obj_t flipperzero_speaker_note_gs2 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_GS2};
const mp_obj_t flipperzero_speaker_note_a2 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_A2};
const mp_obj_t flipperzero_speaker_note_as2 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_AS2};
const mp_obj_t flipperzero_speaker_note_b2 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_B2};
const mp_obj_t flipperzero_speaker_note_c3 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_C3};
const mp_obj_t flipperzero_speaker_note_cs3 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_CS3};
const mp_obj_t flipperzero_speaker_note_d3 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_D3};
const mp_obj_t flipperzero_speaker_note_ds3 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_DS3};
const mp_obj_t flipperzero_speaker_note_e3 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_E3};
const mp_obj_t flipperzero_speaker_note_f3 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_F3};
const mp_obj_t flipperzero_speaker_note_fs3 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_FS3};
const mp_obj_t flipperzero_speaker_note_g3 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_G3};
const mp_obj_t flipperzero_speaker_note_gs3 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_GS3};
const mp_obj_t flipperzero_speaker_note_a3 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_A3};
const mp_obj_t flipperzero_speaker_note_as3 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_AS3};
const mp_obj_t flipperzero_speaker_note_b3 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_B3};
const mp_obj_t flipperzero_speaker_note_c4 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_C4};
const mp_obj_t flipperzero_speaker_note_cs4 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_CS4};
const mp_obj_t flipperzero_speaker_note_d4 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_D4};
const mp_obj_t flipperzero_speaker_note_ds4 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_DS4};
const mp_obj_t flipperzero_speaker_note_e4 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_E4};
const mp_obj_t flipperzero_speaker_note_f4 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_F4};
const mp_obj_t flipperzero_speaker_note_fs4 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_FS4};
const mp_obj_t flipperzero_speaker_note_g4 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_G4};
const mp_obj_t flipperzero_speaker_note_gs4 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_GS4};
const mp_obj_t flipperzero_speaker_note_a4 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_A4};
const mp_obj_t flipperzero_speaker_note_as4 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_AS4};
const mp_obj_t flipperzero_speaker_note_b4 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_B4};
const mp_obj_t flipperzero_speaker_note_c5 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_C5};
const mp_obj_t flipperzero_speaker_note_cs5 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_CS5};
const mp_obj_t flipperzero_speaker_note_d5 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_D5};
const mp_obj_t flipperzero_speaker_note_ds5 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_DS5};
const mp_obj_t flipperzero_speaker_note_e5 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_E5};
const mp_obj_t flipperzero_speaker_note_f5 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_F5};
const mp_obj_t flipperzero_speaker_note_fs5 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_FS5};
const mp_obj_t flipperzero_speaker_note_g5 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_G5};
const mp_obj_t flipperzero_speaker_note_gs5 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_GS5};
const mp_obj_t flipperzero_speaker_note_a5 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_A5};
const mp_obj_t flipperzero_speaker_note_as5 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_AS5};
const mp_obj_t flipperzero_speaker_note_b5 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_B5};
const mp_obj_t flipperzero_speaker_note_c6 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_C6};
const mp_obj_t flipperzero_speaker_note_cs6 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_CS6};
const mp_obj_t flipperzero_speaker_note_d6 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_D6};
const mp_obj_t flipperzero_speaker_note_ds6 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_DS6};
const mp_obj_t flipperzero_speaker_note_e6 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_E6};
const mp_obj_t flipperzero_speaker_note_f6 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_F6};
const mp_obj_t flipperzero_speaker_note_fs6 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_FS6};
const mp_obj_t flipperzero_speaker_note_g6 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_G6};
const mp_obj_t flipperzero_speaker_note_gs6 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_GS6};
const mp_obj_t flipperzero_speaker_note_a6 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_A6};
const mp_obj_t flipperzero_speaker_note_as6 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_AS6};
const mp_obj_t flipperzero_speaker_note_b6 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_B6};
const mp_obj_t flipperzero_speaker_note_c7 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_C7};
const mp_obj_t flipperzero_speaker_note_cs7 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_CS7};
const mp_obj_t flipperzero_speaker_note_d7 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_D7};
const mp_obj_t flipperzero_speaker_note_ds7 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_DS7};
const mp_obj_t flipperzero_speaker_note_e7 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_E7};
const mp_obj_t flipperzero_speaker_note_f7 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_F7};
const mp_obj_t flipperzero_speaker_note_fs7 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_FS7};
const mp_obj_t flipperzero_speaker_note_g7 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_G7};
const mp_obj_t flipperzero_speaker_note_gs7 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_GS7};
const mp_obj_t flipperzero_speaker_note_a7 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_A7};
const mp_obj_t flipperzero_speaker_note_as7 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_AS7};
const mp_obj_t flipperzero_speaker_note_b7 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_B7};
const mp_obj_t flipperzero_speaker_note_c8 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_C8};
const mp_obj_t flipperzero_speaker_note_cs8 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_CS8};
const mp_obj_t flipperzero_speaker_note_d8 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_D8};
const mp_obj_t flipperzero_speaker_note_ds8 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_DS8};
const mp_obj_t flipperzero_speaker_note_e8 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_E8};
const mp_obj_t flipperzero_speaker_note_f8 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_F8};
const mp_obj_t flipperzero_speaker_note_fs8 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_FS8};
const mp_obj_t flipperzero_speaker_note_g8 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_G8};
const mp_obj_t flipperzero_speaker_note_gs8 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_GS8};
const mp_obj_t flipperzero_speaker_note_a8 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_A8};
const mp_obj_t flipperzero_speaker_note_as8 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_AS8};
const mp_obj_t flipperzero_speaker_note_b8 = {{&mp_type_float}, (mp_float_t)MP_FLIPPER_SPEAKER_NOTE_B8};

static mp_obj_t flipperzero_speaker_start(mp_obj_t frequency_obj, mp_obj_t volume_obj) {
    mp_float_t frequency = mp_obj_get_float(frequency_obj);
    mp_float_t volume = mp_obj_get_float(volume_obj);

    return mp_flipper_speaker_start(frequency, volume) ? mp_const_true : mp_const_false;
}
static MP_DEFINE_CONST_FUN_OBJ_2(flipperzero_speaker_start_obj, flipperzero_speaker_start);

static mp_obj_t flipperzero_speaker_set_volume(mp_obj_t volume_obj) {
    mp_float_t volume = mp_obj_get_float(volume_obj);

    return mp_flipper_speaker_set_volume(volume) ? mp_const_true : mp_const_false;
}
static MP_DEFINE_CONST_FUN_OBJ_1(flipperzero_speaker_set_volume_obj, flipperzero_speaker_set_volume);

static mp_obj_t flipperzero_speaker_stop() {
    mp_flipper_speaker_stop();

    return mp_flipper_speaker_stop() ? mp_const_true : mp_const_false;
}
static MP_DEFINE_CONST_FUN_OBJ_0(flipperzero_speaker_stop_obj, flipperzero_speaker_stop);

static mp_obj_t flipperzero_canvas_width() {
    uint8_t width = mp_flipper_canvas_width();

    return mp_obj_new_int(width);
}
static MP_DEFINE_CONST_FUN_OBJ_0(flipperzero_canvas_width_obj, flipperzero_canvas_width);

static mp_obj_t flipperzero_canvas_height() {
    uint8_t height = mp_flipper_canvas_height();

    return mp_obj_new_int(height);
}
static MP_DEFINE_CONST_FUN_OBJ_0(flipperzero_canvas_height_obj, flipperzero_canvas_height);

static mp_obj_t flipperzero_canvas_text_width(mp_obj_t text_obj) {
    const char* text = mp_obj_str_get_str(text_obj);

    uint8_t width = mp_flipper_canvas_text_width(text);

    return mp_obj_new_int(width);
}
static MP_DEFINE_CONST_FUN_OBJ_1(flipperzero_canvas_text_width_obj, flipperzero_canvas_text_width);

static mp_obj_t flipperzero_canvas_text_height() {
    uint8_t height = mp_flipper_canvas_text_height();

    return mp_obj_new_int(height);
}
static MP_DEFINE_CONST_FUN_OBJ_0(flipperzero_canvas_text_height_obj, flipperzero_canvas_text_height);

static mp_obj_t flipperzero_canvas_draw_dot(mp_obj_t x_obj, mp_obj_t y_obj) {
    mp_int_t x = mp_obj_get_int(x_obj);
    mp_int_t y = mp_obj_get_int(y_obj);

    mp_flipper_canvas_draw_dot(x, y);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_2(flipperzero_canvas_draw_dot_obj, flipperzero_canvas_draw_dot);

static mp_obj_t flipperzero_canvas_draw_box(size_t n_args, const mp_obj_t* args) {
    if(n_args < 4) {
        return mp_const_none;
    }

    mp_int_t x = mp_obj_get_int(args[0]);
    mp_int_t y = mp_obj_get_int(args[1]);
    mp_int_t width = mp_obj_get_int(args[2]);
    mp_int_t height = mp_obj_get_int(args[3]);
    mp_int_t radius = n_args == 5 ? mp_obj_get_int(args[4]) : 0;

    mp_flipper_canvas_draw_box(x, y, width, height, radius);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(flipperzero_canvas_draw_box_obj, 4, 5, flipperzero_canvas_draw_box);

static mp_obj_t flipperzero_canvas_draw_frame(size_t n_args, const mp_obj_t* args) {
    if(n_args < 4) {
        return mp_const_none;
    }

    mp_int_t x = mp_obj_get_int(args[0]);
    mp_int_t y = mp_obj_get_int(args[1]);
    mp_int_t width = mp_obj_get_int(args[2]);
    mp_int_t height = mp_obj_get_int(args[3]);
    mp_int_t radius = n_args == 5 ? mp_obj_get_int(args[4]) : 0;

    mp_flipper_canvas_draw_frame(x, y, width, height, radius);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(flipperzero_canvas_draw_frame_obj, 4, 5, flipperzero_canvas_draw_frame);

static mp_obj_t flipperzero_canvas_draw_line(size_t n_args, const mp_obj_t* args) {
    if(n_args != 4) {
        return mp_const_none;
    }

    mp_int_t x0 = mp_obj_get_int(args[0]);
    mp_int_t y0 = mp_obj_get_int(args[1]);
    mp_int_t x1 = mp_obj_get_int(args[2]);
    mp_int_t y1 = mp_obj_get_int(args[3]);

    mp_flipper_canvas_draw_line(x0, y0, x1, y1);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(flipperzero_canvas_draw_line_obj, 4, 4, flipperzero_canvas_draw_line);

static mp_obj_t flipperzero_canvas_draw_circle(mp_obj_t x_obj, mp_obj_t y_obj, mp_obj_t r_obj) {
    mp_int_t x = mp_obj_get_int(x_obj);
    mp_int_t y = mp_obj_get_int(y_obj);
    mp_int_t r = mp_obj_get_int(r_obj);

    mp_flipper_canvas_draw_circle(x, y, r);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_3(flipperzero_canvas_draw_circle_obj, flipperzero_canvas_draw_circle);

static mp_obj_t flipperzero_canvas_draw_disc(mp_obj_t x_obj, mp_obj_t y_obj, mp_obj_t r_obj) {
    mp_int_t x = mp_obj_get_int(x_obj);
    mp_int_t y = mp_obj_get_int(y_obj);
    mp_int_t r = mp_obj_get_int(r_obj);

    mp_flipper_canvas_draw_disc(x, y, r);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_3(flipperzero_canvas_draw_disc_obj, flipperzero_canvas_draw_disc);

static mp_obj_t flipperzero_canvas_set_font(mp_obj_t font_obj) {
    mp_int_t font = mp_obj_get_int(font_obj);

    mp_flipper_canvas_set_font(font);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_1(flipperzero_canvas_set_font_obj, flipperzero_canvas_set_font);

static mp_obj_t flipperzero_canvas_set_color(mp_obj_t color_obj) {
    mp_int_t color = mp_obj_get_int(color_obj);

    mp_flipper_canvas_set_color(color);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_1(flipperzero_canvas_set_color_obj, flipperzero_canvas_set_color);

static mp_obj_t flipperzero_canvas_set_text(mp_obj_t x_obj, mp_obj_t y_obj, mp_obj_t str_obj) {
    mp_int_t x = mp_obj_get_int(x_obj);
    mp_int_t y = mp_obj_get_int(y_obj);

    const char* str = mp_obj_str_get_str(str_obj);

    mp_flipper_canvas_set_text(x, y, str);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_3(flipperzero_canvas_set_text_obj, flipperzero_canvas_set_text);

static mp_obj_t flipperzero_canvas_set_text_align(mp_obj_t x_obj, mp_obj_t y_obj) {
    mp_int_t x = mp_obj_get_int(x_obj);
    mp_int_t y = mp_obj_get_int(y_obj);

    mp_flipper_canvas_set_text_align(x, y);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_2(flipperzero_canvas_set_text_align_obj, flipperzero_canvas_set_text_align);

static mp_obj_t flipperzero_canvas_update() {
    mp_flipper_canvas_update();

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_0(flipperzero_canvas_update_obj, flipperzero_canvas_update);

static mp_obj_t flipperzero_canvas_clear() {
    mp_flipper_canvas_clear();

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_0(flipperzero_canvas_clear_obj, flipperzero_canvas_clear);

static mp_obj_t flipperzero_on_input(mp_obj_t callback_obj) {
    mp_flipper_on_input_callback = callback_obj;

    return callback_obj;
}
static MP_DEFINE_CONST_FUN_OBJ_1(flipperzero_on_input_obj, flipperzero_on_input);

static mp_obj_t flipperzero_input_trigger_handler(mp_obj_t flags_obj) {
    if(mp_flipper_on_input_callback != NULL) {
        mp_int_t flags = mp_obj_get_int(flags_obj);

        mp_obj_t button_obj = mp_obj_new_int(flags & MP_FLIPPER_INPUT_BUTTON);
        mp_obj_t type_obj = mp_obj_new_int(flags & MP_FLIPPER_INPUT_TYPE);

        mp_call_function_2_protected(mp_flipper_on_input_callback, button_obj, type_obj);
    }

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_1(flipperzero_input_trigger_handler_obj, flipperzero_input_trigger_handler);

void mp_flipper_on_input(uint16_t button, uint16_t type) {
    if(mp_flipper_on_input_callback != NULL) {
        uint16_t flags = button | type;
        mp_obj_t flags_obj = mp_obj_new_int_from_uint(flags);

        mp_sched_schedule(&flipperzero_input_trigger_handler_obj, flags_obj);
    }
}

static mp_obj_t flipperzero_dialog_message_set_text(size_t n_args, const mp_obj_t* args) {
    if(n_args < 3) {
        return mp_const_none;
    }

    const char* text = mp_obj_str_get_str(args[0]);

    mp_int_t x = mp_obj_get_int(args[1]);
    mp_int_t y = mp_obj_get_int(args[2]);
    mp_int_t h = n_args > 3 ? mp_obj_get_int(args[3]) : MP_FLIPPER_ALIGN_BEGIN;
    mp_int_t v = n_args > 4 ? mp_obj_get_int(args[4]) : MP_FLIPPER_ALIGN_BEGIN;

    mp_flipper_dialog_message_set_text(text, x, y, h, v);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(flipperzero_dialog_message_set_text_obj, 3, 5, flipperzero_dialog_message_set_text);

static mp_obj_t flipperzero_dialog_message_set_header(size_t n_args, const mp_obj_t* args) {
    if(n_args < 3) {
        return mp_const_none;
    }

    const char* text = mp_obj_str_get_str(args[0]);

    mp_int_t x = mp_obj_get_int(args[1]);
    mp_int_t y = mp_obj_get_int(args[2]);
    mp_int_t h = n_args > 3 ? mp_obj_get_int(args[3]) : MP_FLIPPER_ALIGN_BEGIN;
    mp_int_t v = n_args > 4 ? mp_obj_get_int(args[4]) : MP_FLIPPER_ALIGN_BEGIN;

    mp_flipper_dialog_message_set_header(text, x, y, h, v);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(flipperzero_dialog_message_set_header_obj, 3, 5, flipperzero_dialog_message_set_header);

static mp_obj_t flipperzero_dialog_message_set_button(mp_obj_t text_obj, mp_obj_t button_obj) {
    const char* text = mp_obj_str_get_str(text_obj);

    mp_int_t button = mp_obj_get_int(button_obj);

    mp_flipper_dialog_message_set_button(text, button);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_2(flipperzero_dialog_message_set_button_obj, flipperzero_dialog_message_set_button);

static mp_obj_t flipperzero_dialog_message_show() {
    mp_int_t button = mp_flipper_dialog_message_show();

    return mp_obj_new_int(button);
}
static MP_DEFINE_CONST_FUN_OBJ_0(flipperzero_dialog_message_show_obj, flipperzero_dialog_message_show);

static mp_obj_t flipperzero_dialog_message_clear() {
    mp_flipper_dialog_message_clear();

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_0(flipperzero_dialog_message_clear_obj, flipperzero_dialog_message_clear);

static const mp_rom_map_elem_t flipperzero_module_globals_table[] = {
    {MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_flipperzero)},
    {MP_ROM_QSTR(MP_QSTR_LIGHT_RED), MP_ROM_INT(MP_FLIPPER_LED_RED)},
    {MP_ROM_QSTR(MP_QSTR_LIGHT_GREEN), MP_ROM_INT(MP_FLIPPER_LED_GREEN)},
    {MP_ROM_QSTR(MP_QSTR_LIGHT_BLUE), MP_ROM_INT(MP_FLIPPER_LED_BLUE)},
    {MP_ROM_QSTR(MP_QSTR_LIGHT_BACKLIGHT), MP_ROM_INT(MP_FLIPPER_LED_BACKLIGHT)},
    {MP_ROM_QSTR(MP_QSTR_light_set), MP_ROM_PTR(&flipperzero_light_set_obj)},
    {MP_ROM_QSTR(MP_QSTR_light_blink_start), MP_ROM_PTR(&flipperzero_light_blink_start_obj)},
    {MP_ROM_QSTR(MP_QSTR_light_blink_set_color), MP_ROM_PTR(&flipperzero_light_blink_set_color_obj)},
    {MP_ROM_QSTR(MP_QSTR_light_blink_stop), MP_ROM_PTR(&flipperzero_light_blink_stop_obj)},
    {MP_ROM_QSTR(MP_QSTR_vibro_set), MP_ROM_PTR(&flipperzero_vibro_set_obj)},
    /*
Python script for notes generation

# coding: utf-8
# Python script for notes generation

from typing import List

note_names: List = ['C', 'CS', 'D', 'DS', 'E', 'F', 'FS', 'G', 'GS', 'A', 'AS', 'B']

for octave in range(9):
    for name in note_names:
        print("{MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_%s%s), MP_ROM_PTR(&flipperzero_speaker_note_%s%s)}," % (name,octave,name.lower(),octave))
*/
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_C0), MP_ROM_PTR(&flipperzero_speaker_note_c0)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_CS0), MP_ROM_PTR(&flipperzero_speaker_note_cs0)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_D0), MP_ROM_PTR(&flipperzero_speaker_note_d0)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_DS0), MP_ROM_PTR(&flipperzero_speaker_note_ds0)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_E0), MP_ROM_PTR(&flipperzero_speaker_note_e0)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_F0), MP_ROM_PTR(&flipperzero_speaker_note_f0)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_FS0), MP_ROM_PTR(&flipperzero_speaker_note_fs0)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_G0), MP_ROM_PTR(&flipperzero_speaker_note_g0)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_GS0), MP_ROM_PTR(&flipperzero_speaker_note_gs0)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_A0), MP_ROM_PTR(&flipperzero_speaker_note_a0)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_AS0), MP_ROM_PTR(&flipperzero_speaker_note_as0)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_B0), MP_ROM_PTR(&flipperzero_speaker_note_b0)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_C1), MP_ROM_PTR(&flipperzero_speaker_note_c1)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_CS1), MP_ROM_PTR(&flipperzero_speaker_note_cs1)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_D1), MP_ROM_PTR(&flipperzero_speaker_note_d1)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_DS1), MP_ROM_PTR(&flipperzero_speaker_note_ds1)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_E1), MP_ROM_PTR(&flipperzero_speaker_note_e1)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_F1), MP_ROM_PTR(&flipperzero_speaker_note_f1)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_FS1), MP_ROM_PTR(&flipperzero_speaker_note_fs1)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_G1), MP_ROM_PTR(&flipperzero_speaker_note_g1)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_GS1), MP_ROM_PTR(&flipperzero_speaker_note_gs1)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_A1), MP_ROM_PTR(&flipperzero_speaker_note_a1)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_AS1), MP_ROM_PTR(&flipperzero_speaker_note_as1)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_B1), MP_ROM_PTR(&flipperzero_speaker_note_b1)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_C2), MP_ROM_PTR(&flipperzero_speaker_note_c2)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_CS2), MP_ROM_PTR(&flipperzero_speaker_note_cs2)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_D2), MP_ROM_PTR(&flipperzero_speaker_note_d2)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_DS2), MP_ROM_PTR(&flipperzero_speaker_note_ds2)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_E2), MP_ROM_PTR(&flipperzero_speaker_note_e2)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_F2), MP_ROM_PTR(&flipperzero_speaker_note_f2)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_FS2), MP_ROM_PTR(&flipperzero_speaker_note_fs2)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_G2), MP_ROM_PTR(&flipperzero_speaker_note_g2)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_GS2), MP_ROM_PTR(&flipperzero_speaker_note_gs2)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_A2), MP_ROM_PTR(&flipperzero_speaker_note_a2)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_AS2), MP_ROM_PTR(&flipperzero_speaker_note_as2)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_B2), MP_ROM_PTR(&flipperzero_speaker_note_b2)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_C3), MP_ROM_PTR(&flipperzero_speaker_note_c3)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_CS3), MP_ROM_PTR(&flipperzero_speaker_note_cs3)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_D3), MP_ROM_PTR(&flipperzero_speaker_note_d3)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_DS3), MP_ROM_PTR(&flipperzero_speaker_note_ds3)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_E3), MP_ROM_PTR(&flipperzero_speaker_note_e3)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_F3), MP_ROM_PTR(&flipperzero_speaker_note_f3)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_FS3), MP_ROM_PTR(&flipperzero_speaker_note_fs3)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_G3), MP_ROM_PTR(&flipperzero_speaker_note_g3)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_GS3), MP_ROM_PTR(&flipperzero_speaker_note_gs3)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_A3), MP_ROM_PTR(&flipperzero_speaker_note_a3)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_AS3), MP_ROM_PTR(&flipperzero_speaker_note_as3)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_B3), MP_ROM_PTR(&flipperzero_speaker_note_b3)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_C4), MP_ROM_PTR(&flipperzero_speaker_note_c4)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_CS4), MP_ROM_PTR(&flipperzero_speaker_note_cs4)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_D4), MP_ROM_PTR(&flipperzero_speaker_note_d4)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_DS4), MP_ROM_PTR(&flipperzero_speaker_note_ds4)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_E4), MP_ROM_PTR(&flipperzero_speaker_note_e4)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_F4), MP_ROM_PTR(&flipperzero_speaker_note_f4)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_FS4), MP_ROM_PTR(&flipperzero_speaker_note_fs4)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_G4), MP_ROM_PTR(&flipperzero_speaker_note_g4)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_GS4), MP_ROM_PTR(&flipperzero_speaker_note_gs4)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_A4), MP_ROM_PTR(&flipperzero_speaker_note_a4)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_AS4), MP_ROM_PTR(&flipperzero_speaker_note_as4)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_B4), MP_ROM_PTR(&flipperzero_speaker_note_b4)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_C5), MP_ROM_PTR(&flipperzero_speaker_note_c5)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_CS5), MP_ROM_PTR(&flipperzero_speaker_note_cs5)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_D5), MP_ROM_PTR(&flipperzero_speaker_note_d5)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_DS5), MP_ROM_PTR(&flipperzero_speaker_note_ds5)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_E5), MP_ROM_PTR(&flipperzero_speaker_note_e5)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_F5), MP_ROM_PTR(&flipperzero_speaker_note_f5)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_FS5), MP_ROM_PTR(&flipperzero_speaker_note_fs5)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_G5), MP_ROM_PTR(&flipperzero_speaker_note_g5)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_GS5), MP_ROM_PTR(&flipperzero_speaker_note_gs5)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_A5), MP_ROM_PTR(&flipperzero_speaker_note_a5)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_AS5), MP_ROM_PTR(&flipperzero_speaker_note_as5)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_B5), MP_ROM_PTR(&flipperzero_speaker_note_b5)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_C6), MP_ROM_PTR(&flipperzero_speaker_note_c6)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_CS6), MP_ROM_PTR(&flipperzero_speaker_note_cs6)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_D6), MP_ROM_PTR(&flipperzero_speaker_note_d6)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_DS6), MP_ROM_PTR(&flipperzero_speaker_note_ds6)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_E6), MP_ROM_PTR(&flipperzero_speaker_note_e6)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_F6), MP_ROM_PTR(&flipperzero_speaker_note_f6)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_FS6), MP_ROM_PTR(&flipperzero_speaker_note_fs6)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_G6), MP_ROM_PTR(&flipperzero_speaker_note_g6)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_GS6), MP_ROM_PTR(&flipperzero_speaker_note_gs6)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_A6), MP_ROM_PTR(&flipperzero_speaker_note_a6)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_AS6), MP_ROM_PTR(&flipperzero_speaker_note_as6)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_B6), MP_ROM_PTR(&flipperzero_speaker_note_b6)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_C7), MP_ROM_PTR(&flipperzero_speaker_note_c7)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_CS7), MP_ROM_PTR(&flipperzero_speaker_note_cs7)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_D7), MP_ROM_PTR(&flipperzero_speaker_note_d7)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_DS7), MP_ROM_PTR(&flipperzero_speaker_note_ds7)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_E7), MP_ROM_PTR(&flipperzero_speaker_note_e7)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_F7), MP_ROM_PTR(&flipperzero_speaker_note_f7)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_FS7), MP_ROM_PTR(&flipperzero_speaker_note_fs7)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_G7), MP_ROM_PTR(&flipperzero_speaker_note_g7)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_GS7), MP_ROM_PTR(&flipperzero_speaker_note_gs7)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_A7), MP_ROM_PTR(&flipperzero_speaker_note_a7)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_AS7), MP_ROM_PTR(&flipperzero_speaker_note_as7)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_B7), MP_ROM_PTR(&flipperzero_speaker_note_b7)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_C8), MP_ROM_PTR(&flipperzero_speaker_note_c8)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_CS8), MP_ROM_PTR(&flipperzero_speaker_note_cs8)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_D8), MP_ROM_PTR(&flipperzero_speaker_note_d8)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_DS8), MP_ROM_PTR(&flipperzero_speaker_note_ds8)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_E8), MP_ROM_PTR(&flipperzero_speaker_note_e8)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_F8), MP_ROM_PTR(&flipperzero_speaker_note_f8)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_FS8), MP_ROM_PTR(&flipperzero_speaker_note_fs8)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_G8), MP_ROM_PTR(&flipperzero_speaker_note_g8)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_GS8), MP_ROM_PTR(&flipperzero_speaker_note_gs8)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_A8), MP_ROM_PTR(&flipperzero_speaker_note_a8)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_AS8), MP_ROM_PTR(&flipperzero_speaker_note_as8)},
    {MP_ROM_QSTR(MP_QSTR_SPEAKER_NOTE_B8), MP_ROM_PTR(&flipperzero_speaker_note_b8)},
    {MP_ROM_QSTR(MP_QSTR_speaker_start), MP_ROM_PTR(&flipperzero_speaker_start_obj)},
    {MP_ROM_QSTR(MP_QSTR_speaker_set_volume), MP_ROM_PTR(&flipperzero_speaker_set_volume_obj)},
    {MP_ROM_QSTR(MP_QSTR_speaker_stop), MP_ROM_PTR(&flipperzero_speaker_stop_obj)},
    {MP_ROM_QSTR(MP_QSTR_CANVAS_BLACK), MP_ROM_INT(MP_FLIPPER_COLOR_BLACK)},
    {MP_ROM_QSTR(MP_QSTR_CANVAS_WHITE), MP_ROM_INT(MP_FLIPPER_COLOR_WHITE)},
    {MP_ROM_QSTR(MP_QSTR_canvas_width), MP_ROM_PTR(&flipperzero_canvas_width_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_height), MP_ROM_PTR(&flipperzero_canvas_height_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_text_width), MP_ROM_PTR(&flipperzero_canvas_text_width_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_text_height), MP_ROM_PTR(&flipperzero_canvas_text_height_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_draw_dot), MP_ROM_PTR(&flipperzero_canvas_draw_dot_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_draw_box), MP_ROM_PTR(&flipperzero_canvas_draw_box_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_draw_frame), MP_ROM_PTR(&flipperzero_canvas_draw_frame_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_draw_line), MP_ROM_PTR(&flipperzero_canvas_draw_line_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_draw_circle), MP_ROM_PTR(&flipperzero_canvas_draw_circle_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_draw_disc), MP_ROM_PTR(&flipperzero_canvas_draw_disc_obj)},
    {MP_ROM_QSTR(MP_QSTR_FONT_PRIMARY), MP_ROM_INT(MP_FLIPPER_FONT_PRIMARY)},
    {MP_ROM_QSTR(MP_QSTR_FONT_SECONDARY), MP_ROM_INT(MP_FLIPPER_FONT_SECONDARY)},
    {MP_ROM_QSTR(MP_QSTR_canvas_set_font), MP_ROM_PTR(&flipperzero_canvas_set_font_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_set_color), MP_ROM_PTR(&flipperzero_canvas_set_color_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_set_text), MP_ROM_PTR(&flipperzero_canvas_set_text_obj)},
    {MP_ROM_QSTR(MP_QSTR_ALIGN_BEGIN), MP_ROM_INT(MP_FLIPPER_ALIGN_BEGIN)},
    {MP_ROM_QSTR(MP_QSTR_ALIGN_CENTER), MP_ROM_INT(MP_FLIPPER_ALIGN_CENTER)},
    {MP_ROM_QSTR(MP_QSTR_ALIGN_END), MP_ROM_INT(MP_FLIPPER_ALIGN_END)},
    {MP_ROM_QSTR(MP_QSTR_canvas_set_text_align), MP_ROM_PTR(&flipperzero_canvas_set_text_align_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_update), MP_ROM_PTR(&flipperzero_canvas_update_obj)},
    {MP_ROM_QSTR(MP_QSTR_canvas_clear), MP_ROM_PTR(&flipperzero_canvas_clear_obj)},
    {MP_ROM_QSTR(MP_QSTR_on_input), MP_ROM_PTR(&flipperzero_on_input_obj)},
    {MP_ROM_QSTR(MP_QSTR__input_trigger_handler), MP_ROM_PTR(&flipperzero_input_trigger_handler_obj)},
    {MP_ROM_QSTR(MP_QSTR_INPUT_BUTTON_BACK), MP_ROM_INT(MP_FLIPPER_INPUT_BUTTON_BACK)},
    {MP_ROM_QSTR(MP_QSTR_INPUT_BUTTON_OK), MP_ROM_INT(MP_FLIPPER_INPUT_BUTTON_OK)},
    {MP_ROM_QSTR(MP_QSTR_INPUT_BUTTON_LEFT), MP_ROM_INT(MP_FLIPPER_INPUT_BUTTON_LEFT)},
    {MP_ROM_QSTR(MP_QSTR_INPUT_BUTTON_RIGHT), MP_ROM_INT(MP_FLIPPER_INPUT_BUTTON_RIGHT)},
    {MP_ROM_QSTR(MP_QSTR_INPUT_BUTTON_UP), MP_ROM_INT(MP_FLIPPER_INPUT_BUTTON_UP)},
    {MP_ROM_QSTR(MP_QSTR_INPUT_BUTTON_DOWN), MP_ROM_INT(MP_FLIPPER_INPUT_BUTTON_DOWN)},
    {MP_ROM_QSTR(MP_QSTR_INPUT_TYPE_PRESS), MP_ROM_INT(MP_FLIPPER_INPUT_TYPE_PRESS)},
    {MP_ROM_QSTR(MP_QSTR_INPUT_TYPE_RELEASE), MP_ROM_INT(MP_FLIPPER_INPUT_TYPE_RELEASE)},
    {MP_ROM_QSTR(MP_QSTR_INPUT_TYPE_SHORT), MP_ROM_INT(MP_FLIPPER_INPUT_TYPE_SHORT)},
    {MP_ROM_QSTR(MP_QSTR_INPUT_TYPE_LONG), MP_ROM_INT(MP_FLIPPER_INPUT_TYPE_LONG)},
    {MP_ROM_QSTR(MP_QSTR_INPUT_TYPE_REPEAT), MP_ROM_INT(MP_FLIPPER_INPUT_TYPE_REPEAT)},
    {MP_ROM_QSTR(MP_QSTR_dialog_message_set_text), MP_ROM_PTR(&flipperzero_dialog_message_set_text_obj)},
    {MP_ROM_QSTR(MP_QSTR_dialog_message_set_header), MP_ROM_PTR(&flipperzero_dialog_message_set_header_obj)},
    {MP_ROM_QSTR(MP_QSTR_dialog_message_set_button), MP_ROM_PTR(&flipperzero_dialog_message_set_button_obj)},
    {MP_ROM_QSTR(MP_QSTR_dialog_message_show), MP_ROM_PTR(&flipperzero_dialog_message_show_obj)},
    {MP_ROM_QSTR(MP_QSTR_dialog_message_clear), MP_ROM_PTR(&flipperzero_dialog_message_clear_obj)},
};
static MP_DEFINE_CONST_DICT(flipperzero_module_globals, flipperzero_module_globals_table);

const mp_obj_module_t flipperzero_module = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t*)&flipperzero_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_flipperzero, flipperzero_module);
