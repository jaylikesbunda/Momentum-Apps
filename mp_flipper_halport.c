#include "py/mperrno.h"
#include "py/obj.h"
#include "py/runtime.h"
#include <stdio.h>

#include "py/mphal.h"
#include "py/builtin.h"

#include "mp_flipper_halport.h"
#include "mp_flipper_fileio.h"

mp_obj_t mp_builtin_open(size_t n_args, const mp_obj_t* args, mp_map_t* kwargs) {
    const char* file_name = mp_obj_str_get_str(args[0]);

    uint8_t access_mode = MP_FLIPPER_FILE_ACCESS_MODE_READ;
    uint8_t open_mode = MP_FLIPPER_FILE_OPEN_MODE_OPEN_EXIST;
    bool is_text = true;

    if(n_args > 1) {
        size_t len;

        const char* mode = mp_obj_str_get_data(args[1], &len);

        for(size_t i = 0; i < len; i++) {
            if(i == 0 && mode[i] == 'r') {
                access_mode = MP_FLIPPER_FILE_ACCESS_MODE_READ;
                open_mode = MP_FLIPPER_FILE_OPEN_MODE_OPEN_EXIST;

                continue;
            }

            if(i == 0 && mode[i] == 'w') {
                access_mode = MP_FLIPPER_FILE_ACCESS_MODE_WRITE;
                open_mode = MP_FLIPPER_FILE_OPEN_MODE_CREATE_ALWAYS;

                continue;
            }

            if(i == 1 && mode[i] == 'b') {
                is_text = false;

                continue;
            }

            if(i == 1 && mode[i] == 't') {
                is_text = true;

                continue;
            }

            if(i >= 1 && mode[i] == '+') {
                access_mode = MP_FLIPPER_FILE_ACCESS_MODE_READ | MP_FLIPPER_FILE_ACCESS_MODE_WRITE;
                open_mode = MP_FLIPPER_FILE_OPEN_MODE_OPEN_APPEND;

                continue;
            }

            mp_raise_OSError(MP_EINVAL);
        }
    }

    void* handle = mp_flipper_file_open(file_name, access_mode, open_mode);
    void* fd = mp_flipper_file_new_file_descriptor(handle, file_name, access_mode, open_mode, is_text);

    return MP_OBJ_FROM_PTR(fd);
}

MP_DEFINE_CONST_FUN_OBJ_KW(mp_builtin_open_obj, 1, mp_builtin_open);

void mp_hal_stdout_tx_str(const char* str) {
    mp_flipper_stdout_tx_str(str);
}

void mp_hal_stdout_tx_strn_cooked(const char* str, size_t len) {
    mp_flipper_stdout_tx_strn_cooked(str, len);
}

mp_import_stat_t mp_import_stat(const char* path) {
    mp_flipper_import_stat_t stat = mp_flipper_import_stat(path);

    if(stat == MP_FLIPPER_IMPORT_STAT_FILE) {
        return MP_IMPORT_STAT_FILE;
    }

    if(stat == MP_FLIPPER_IMPORT_STAT_DIR) {
        return MP_IMPORT_STAT_DIR;
    }

    return MP_IMPORT_STAT_NO_EXIST;
}

size_t gc_get_max_new_split(void) {
    return mp_flipper_gc_get_max_new_split();
}