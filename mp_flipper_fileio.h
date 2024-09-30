#pragma once

#include <stdio.h>
#include <stdbool.h>

typedef enum {
    MP_FLIPPER_FILE_ACCESS_MODE_READ = (1 << 0),
    MP_FLIPPER_FILE_ACCESS_MODE_WRITE = (1 << 1),
} mp_flipper_file_access_mode_t;

typedef enum {
    MP_FLIPPER_FILE_OPEN_MODE_OPEN_EXIST = (1 << 0),
    MP_FLIPPER_FILE_OPEN_MODE_OPEN_ALWAYS = (1 << 1),
    MP_FLIPPER_FILE_OPEN_MODE_OPEN_APPEND = (1 << 2),
    MP_FLIPPER_FILE_OPEN_MODE_CREATE_NEW = (1 << 3),
    MP_FLIPPER_FILE_OPEN_MODE_CREATE_ALWAYS = (1 << 4),
} mp_flipper_file_open_mode_t;

void* mp_flipper_file_open(
    const char* name,
    mp_flipper_file_access_mode_t access_mode,
    mp_flipper_file_open_mode_t open_mode,
    size_t* offset);
void* mp_flipper_file_new_file_descriptor(
    void* name,
    void* handle,
    size_t offset,
    mp_flipper_file_access_mode_t access_mode,
    mp_flipper_file_open_mode_t open_mode);
int mp_flipper_file_close(void* handle, void* name);
char* mp_flipper_file_name(void* name, size_t* size);
bool mp_flipper_file_writable(void* handle);
size_t mp_flipper_file_read(void* handle, void* buffer, size_t size, int* errcode);
size_t mp_flipper_file_write(void* handle, const void* buffer, size_t size, int* errcode);
