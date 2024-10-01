#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "py/obj.h"
#include "py/stream.h"
#include "py/runtime.h"
#include "py/mperrno.h"

#include "mp_flipper_fileio.h"

extern const mp_obj_type_t mp_flipper_fileio_type;
extern const mp_obj_type_t mp_flipper_textio_type;

typedef struct _mp_flipper_fileio_file_descriptor_t {
    mp_obj_base_t base;
    void* handle;
    mp_obj_t name;
    uint8_t access_mode;
    uint8_t open_mode;
} mp_flipper_fileio_file_descriptor_t;

void* mp_flipper_file_new_file_descriptor(void* handle, const char* name, uint8_t access_mode, uint8_t open_mode, bool is_text) {
    mp_flipper_fileio_file_descriptor_t* fd = mp_obj_malloc_with_finaliser(
        mp_flipper_fileio_file_descriptor_t, is_text ? &mp_flipper_textio_type : &mp_flipper_fileio_type);

    fd->handle = handle;
    fd->name = mp_obj_new_str(name, strlen(name));
    fd->access_mode = access_mode;
    fd->open_mode = open_mode;

    return fd;
}

static mp_uint_t mp_flipper_fileio_read(mp_obj_t self, void* buf, mp_uint_t size, int* errcode) {
    mp_flipper_fileio_file_descriptor_t* fd = MP_OBJ_TO_PTR(self);

    return mp_flipper_file_read(fd->handle, buf, size, errcode);
}

static mp_uint_t mp_flipper_fileio_write(mp_obj_t self, const void* buf, mp_uint_t size, int* errcode) {
    mp_flipper_fileio_file_descriptor_t* fd = MP_OBJ_TO_PTR(self);

    return mp_flipper_file_write(fd->handle, buf, size, errcode);
}

static mp_uint_t mp_flipper_fileio_ioctl(mp_obj_t self, mp_uint_t request, uintptr_t arg, int* errcode) {
    mp_flipper_fileio_file_descriptor_t* fd = MP_OBJ_TO_PTR(self);

    if(request == MP_STREAM_SEEK) {
        struct mp_stream_seek_t* seek = (struct mp_stream_seek_t*)(uintptr_t)arg;
        size_t position;
        bool success;

        switch(seek->whence) {
        case MP_SEEK_SET:
            mp_flipper_file_seek(fd->handle, seek->offset);

            break;

        case MP_SEEK_CUR:
            position = mp_flipper_file_tell(fd->handle);

            mp_flipper_file_seek(fd->handle, position + seek->offset);

            break;

        case MP_SEEK_END:
            position = mp_flipper_file_size(fd->handle);

            mp_flipper_file_seek(fd->handle, position + seek->offset);

            break;
        }

        seek->offset = mp_flipper_file_tell(fd->handle);

        return 0;
    }

    if(request == MP_STREAM_FLUSH) {
        if(!mp_flipper_file_sync(fd->handle)) {
            *errcode = MP_EIO;

            return MP_STREAM_ERROR;
        }

        return 0;
    }

    if(request == MP_STREAM_CLOSE) {
        if(fd->handle != NULL) {
            if(!mp_flipper_file_close(fd->handle)) {
                *errcode = MP_EIO;

                return MP_STREAM_ERROR;
            }
        }

        return 0;
    }

    *errcode = MP_EINVAL;

    return MP_STREAM_ERROR;
}

static mp_obj_t mp_flipper_fileio_name(mp_obj_t self) {
    mp_flipper_fileio_file_descriptor_t* fd = MP_OBJ_TO_PTR(self);

    return fd->name;
}
static MP_DEFINE_CONST_FUN_OBJ_1(mp_flipper_fileio_name_obj, mp_flipper_fileio_name);

static mp_obj_t mp_flipper_fileio_writable(mp_obj_t self) {
    mp_flipper_fileio_file_descriptor_t* fd = MP_OBJ_TO_PTR(self);

    return (fd->access_mode & MP_FLIPPER_FILE_ACCESS_MODE_WRITE) ? mp_const_true : mp_const_false;
}
static MP_DEFINE_CONST_FUN_OBJ_1(mp_flipper_fileio_writable_obj, mp_flipper_fileio_writable);

static const mp_map_elem_t mp_flipper_file_locals_dict_table[] = {
    {MP_OBJ_NEW_QSTR(MP_QSTR_name), MP_ROM_PTR(&mp_flipper_fileio_name_obj)},
    {MP_ROM_QSTR(MP_QSTR_read), MP_ROM_PTR(&mp_stream_read_obj)},
    {MP_ROM_QSTR(MP_QSTR_readinto), MP_ROM_PTR(&mp_stream_readinto_obj)},
    {MP_ROM_QSTR(MP_QSTR_readline), MP_ROM_PTR(&mp_stream_unbuffered_readline_obj)},
    {MP_ROM_QSTR(MP_QSTR_readlines), MP_ROM_PTR(&mp_stream_unbuffered_readlines_obj)},
    {MP_OBJ_NEW_QSTR(MP_QSTR_writable), MP_ROM_PTR(&mp_flipper_fileio_writable_obj)},
    {MP_ROM_QSTR(MP_QSTR_write), MP_ROM_PTR(&mp_stream_write_obj)},
    {MP_ROM_QSTR(MP_QSTR_flush), MP_ROM_PTR(&mp_stream_flush_obj)},
    {MP_ROM_QSTR(MP_QSTR_close), MP_ROM_PTR(&mp_stream_close_obj)},
    {MP_ROM_QSTR(MP_QSTR_seek), MP_ROM_PTR(&mp_stream_seek_obj)},
    {MP_ROM_QSTR(MP_QSTR_tell), MP_ROM_PTR(&mp_stream_tell_obj)},
    {MP_ROM_QSTR(MP_QSTR___del__), MP_ROM_PTR(&mp_stream_close_obj)},
    {MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&mp_identity_obj)},
    {MP_ROM_QSTR(MP_QSTR___exit__), MP_ROM_PTR(&mp_stream___exit___obj)},
};
static MP_DEFINE_CONST_DICT(mp_flipper_file_locals_dict, mp_flipper_file_locals_dict_table);

static const mp_stream_p_t mp_flipper_fileio_stream_p = {
    .read = mp_flipper_fileio_read,
    .write = mp_flipper_fileio_write,
    .ioctl = mp_flipper_fileio_ioctl,
    .is_text = false,
};

MP_DEFINE_CONST_OBJ_TYPE(
    mp_flipper_fileio_type,
    MP_QSTR_FileIO,
    MP_TYPE_FLAG_NONE,
    protocol,
    &mp_flipper_fileio_stream_p,
    locals_dict,
    &mp_flipper_file_locals_dict);

static const mp_stream_p_t mp_flipper_textio_stream_p = {
    .read = mp_flipper_fileio_read,
    .write = mp_flipper_fileio_write,
    .ioctl = mp_flipper_fileio_ioctl,
    .is_text = true,
};

MP_DEFINE_CONST_OBJ_TYPE(
    mp_flipper_textio_type,
    MP_QSTR_TextIO,
    MP_TYPE_FLAG_NONE,
    protocol,
    &mp_flipper_textio_stream_p,
    locals_dict,
    &mp_flipper_file_locals_dict);