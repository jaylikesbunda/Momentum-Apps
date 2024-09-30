#include <stdbool.h>
#include <stdint.h>

#include "mp_flipper_fileio.h"
#include "py/obj.h"
#include "py/stream.h"
#include "py/runtime.h"

extern const mp_obj_type_t mp_flipper_fileio_type;

typedef struct _mp_flipper_fileio_file_descriptor_t {
    mp_obj_base_t base;
    void* name;
    void* handle;
    size_t offset;
    mp_flipper_file_access_mode_t access_mode;
    mp_flipper_file_open_mode_t open_mode;
} mp_flipper_fileio_file_descriptor_t;

void* mp_flipper_file_new_file_descriptor(
    void* name,
    void* handle,
    size_t offset,
    mp_flipper_file_access_mode_t access_mode,
    mp_flipper_file_open_mode_t open_mode) {
    mp_flipper_fileio_file_descriptor_t* fd = mp_obj_malloc(mp_flipper_fileio_file_descriptor_t, &mp_flipper_fileio_type);

    fd->name = name;
    fd->handle = handle;
    fd->offset = offset;
    fd->access_mode = access_mode;
    fd->open_mode = open_mode;

    return fd;
}

static mp_uint_t mp_flipper_fileio_read(mp_obj_t self, void* buf, mp_uint_t size, int* errcode) {
    mp_flipper_fileio_file_descriptor_t* fd = (mp_flipper_fileio_file_descriptor_t*)self;

    return mp_flipper_file_read(fd->handle, buf, size, errcode);
}

static mp_uint_t mp_flipper_fileio_write(mp_obj_t self, const void* buf, mp_uint_t size, int* errcode) {
    mp_flipper_fileio_file_descriptor_t* fd = (mp_flipper_fileio_file_descriptor_t*)self;

    return mp_flipper_file_write(fd->handle, buf, size, errcode);
}

static mp_obj_t mp_flipper_fileio_close(mp_obj_t self) {
    mp_flipper_fileio_file_descriptor_t* fd = (mp_flipper_fileio_file_descriptor_t*)self;

    int errorno = mp_flipper_file_close(fd->handle, fd->name);

    if(errorno != 0) {
        mp_raise_OSError(errorno);
    }

    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_1(mp_flipper_fileio_close_obj, mp_flipper_fileio_close);

static mp_obj_t mp_flipper_fileio_name(mp_obj_t self) {
    mp_flipper_fileio_file_descriptor_t* fd = (mp_flipper_fileio_file_descriptor_t*)self;
    size_t size = 0;

    char* name = mp_flipper_file_name(fd->name, &size);

    return mp_obj_new_str(name, size);
}
static MP_DEFINE_CONST_FUN_OBJ_1(mp_flipper_fileio_name_obj, mp_flipper_fileio_name);

static mp_obj_t mp_flipper_fileio___exit___(size_t n_args, const mp_obj_t* args) {
    return mp_flipper_fileio_close(args[0]);
}
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(mp_flipper_fileio___exit___obj, 4, 4, mp_flipper_fileio___exit___);

static mp_obj_t mp_flipper_fileio_writable(mp_obj_t self) {
    return mp_flipper_file_writable((void*)self) ? mp_const_true : mp_const_false;
}
static MP_DEFINE_CONST_FUN_OBJ_1(mp_flipper_fileio_writable_obj, mp_flipper_fileio_writable);

static const mp_map_elem_t mp_flipper_file_locals_dict_table[] = {
    {MP_OBJ_NEW_QSTR(MP_QSTR_close), MP_ROM_PTR(&mp_flipper_fileio_close_obj)},
    {MP_OBJ_NEW_QSTR(MP_QSTR_name), MP_ROM_PTR(&mp_flipper_fileio_name_obj)},
    {MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&mp_identity_obj)},
    {MP_ROM_QSTR(MP_QSTR___exit__), MP_ROM_PTR(&mp_flipper_fileio___exit___obj)},
    {MP_OBJ_NEW_QSTR(MP_QSTR_writable), MP_ROM_PTR(&mp_flipper_fileio_writable_obj)},
    {MP_OBJ_NEW_QSTR(MP_QSTR_read), MP_ROM_PTR(&mp_stream_read_obj)},
    {MP_OBJ_NEW_QSTR(MP_QSTR_readinto), MP_ROM_PTR(&mp_stream_readinto_obj)},
    {MP_OBJ_NEW_QSTR(MP_QSTR_readline), MP_ROM_PTR(&mp_stream_unbuffered_readline_obj)},
    {MP_OBJ_NEW_QSTR(MP_QSTR_write), MP_ROM_PTR(&mp_stream_write_obj)},
};
static MP_DEFINE_CONST_DICT(mp_flipper_file_locals_dict, mp_flipper_file_locals_dict_table);

static const mp_stream_p_t mp_flipper_fileio_stream_p = {
    .read = mp_flipper_fileio_read,
    .write = mp_flipper_fileio_write,
};

MP_DEFINE_CONST_OBJ_TYPE(
    mp_flipper_fileio_type,
    MP_QSTR_FileIO,
    MP_TYPE_FLAG_NONE,
    protocol,
    &mp_flipper_fileio_stream_p,
    locals_dict,
    &mp_flipper_file_locals_dict);