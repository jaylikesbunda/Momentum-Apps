#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "py/obj.h"

extern const mp_obj_type_t mp_flipper_logger_type;

typedef struct _mp_flipper_logger_t {
    mp_obj_base_t base;
    mp_obj_t name;
} mp_flipper_logger_t;

static mp_obj_t mp_flipper_logger_debug(size_t n_args, const mp_obj_t* args) {
    if(n_args < 2) {
        return mp_const_none;
    }

    mp_flipper_logger_t* logger = MP_OBJ_TO_PTR(args[0]);

    const char* message = mp_obj_str_get_str(args[1]);

    mp_flipper_log_debug(logger->name, message, &args[2], n_args - 2);

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(mp_flipper_logger_debug_obj, 2, 4, mp_flipper_logger_debug);

static mp_obj_t mp_flipper_logger_name(mp_obj_t self) {
    mp_flipper_logger_t* logger = MP_OBJ_TO_PTR(self);

    return logger->name;
}
static MP_DEFINE_CONST_FUN_OBJ_1(mp_flipper_logger_name_obj, mp_flipper_logger_name);

static const mp_map_elem_t mp_flipper_logger_locals_dict_table[] = {
    {MP_OBJ_NEW_QSTR(MP_QSTR_name), MP_ROM_PTR(&mp_flipper_logger_name_obj)},
    {MP_ROM_QSTR(MP_QSTR_debug), MP_ROM_PTR(&mp_flipper_logger_debug_obj)},
};
static MP_DEFINE_CONST_DICT(mp_flipper_logger_locals_dict, mp_flipper_logger_locals_dict_table);

MP_DEFINE_CONST_OBJ_TYPE(mp_flipper_logger_type, MP_QSTR_Logger, MP_TYPE_FLAG_NONE, locals_dict, &mp_flipper_logger_locals_dict);

static mp_obj_t mp_flipper_logging_get_logger(mp_obj_t name) {
    mp_flipper_logger_t* logger = mp_obj_malloc(mp_flipper_logger_t, &mp_flipper_logger_type);

    logger->name = name;

    return MP_OBJ_FROM_PTR(logger);
}
static MP_DEFINE_CONST_FUN_OBJ_1(mp_flipper_logging_get_logger_obj, mp_flipper_logging_get_logger);

static const mp_rom_map_elem_t mp_module_logging_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_logging)},
    {MP_ROM_QSTR(MP_QSTR_getLogger), MP_ROM_PTR(&mp_flipper_logging_get_logger_obj)},
};

static MP_DEFINE_CONST_DICT(mp_module_logging_globals, mp_module_logging_globals_table);

const mp_obj_module_t mp_module_logging = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t*)&mp_module_logging_globals,
};

MP_REGISTER_EXTENSIBLE_MODULE(MP_QSTR_logging, mp_module_logging);