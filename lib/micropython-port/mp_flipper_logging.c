#include <furi.h>

#include <mp_flipper_logging.h>
#include <mp_flipper_runtime.h>

#include "mp_flipper_context.h"

static inline FuriLogLevel decode_log_level(uint8_t level) {
    switch(level) {
    case MP_FLIPPER_LOG_LEVEL_TRACE:
        return FuriLogLevelTrace;
        break;
    case MP_FLIPPER_LOG_LEVEL_DEBUG:
        return FuriLogLevelDebug;
        break;
    case MP_FLIPPER_LOG_LEVEL_INFO:
        return FuriLogLevelInfo;
        break;
    case MP_FLIPPER_LOG_LEVEL_WARN:
        return FuriLogLevelWarn;
        break;
    case MP_FLIPPER_LOG_LEVEL_ERROR:
        return FuriLogLevelError;
        break;
    default:
        return FuriLogLevelDefault;
        break;
    }
}

uint8_t mp_flipper_log_get_level() {
    mp_flipper_context_t* ctx = mp_flipper_context;

    return ctx->log_level;
}

void mp_flipper_log_set_level(uint8_t level) {
    mp_flipper_context_t* ctx = mp_flipper_context;

    ctx->log_level = level;
}

void mp_flipper_log(uint8_t raw_level, const char* message) {
    FuriLogLevel level = decode_log_level(raw_level);

    furi_log_print_format(level, "uPython", message);
}
