#include <furi.h>
#include <storage/storage.h>

#include <mp_flipper_fileio.h>
#include <mp_flipper_runtime.h>

#include "mp_flipper_context.h"
#include "mp_flipper_file_helper.h"

inline void* mp_flipper_file_open(
    const char* name,
    mp_flipper_file_access_mode_t access_mode,
    mp_flipper_file_open_mode_t open_mode,
    size_t* offset) {
    mp_flipper_context_t* ctx = mp_flipper_context;

    File* file = storage_file_alloc(ctx->storage);
    FuriString* path = furi_string_alloc_set_str(name);

    do {
        if(mp_flipper_try_resolve_filesystem_path(path) == MP_FLIPPER_IMPORT_STAT_NO_EXIST) {
            mp_flipper_raise_os_error_with_filename(MP_ENOENT, name);

            break;
        }

        if(!storage_file_open(file, furi_string_get_cstr(path), access_mode, open_mode)) {
            mp_flipper_raise_os_error_with_filename(MP_ENOENT, name);

            break;
        }
    } while(false);

    // TODO close open files upon application exit

    return file;
}

inline int mp_flipper_file_close(void* handle) {
    mp_flipper_context_t* ctx = mp_flipper_context;

    File* file = handle;

    if(storage_file_is_open(file) && storage_file_close(file)) {
        // NOP
    } else {
        // TODO handle error
    }

    storage_file_free(file);

    return 0;
}

inline bool mp_flipper_file_writable(void* handle) {
    File* file = handle;

    // TODO

    return true;
}

inline size_t mp_flipper_file_read(void* handle, void* buffer, size_t size, int* errcode) {
    File* file = handle;

    *errcode = 0; // TODO handle error

    return storage_file_read(file, buffer, size);
}

inline size_t mp_flipper_file_write(void* handle, const void* buffer, size_t size, int* errcode) {
    File* file = handle;

    *errcode = 0; // TODO handle error

    return storage_file_write(file, buffer, size);
}
