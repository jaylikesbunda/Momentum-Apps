#pragma once

#include <stdint.h>

#define MP_FLIPPER_LOG_LEVEL_TRACE (0)
#define MP_FLIPPER_LOG_LEVEL_DEBUG (1)
#define MP_FLIPPER_LOG_LEVEL_INFO (2)
#define MP_FLIPPER_LOG_LEVEL_WARN (3)
#define MP_FLIPPER_LOG_LEVEL_ERROR (4)
#define MP_FLIPPER_LOG_LEVEL_NONE (5)

uint8_t mp_flipper_log_get_level();
void mp_flipper_log_set_level(uint8_t level);
void mp_flipper_log(uint8_t raw_level, const char* message);
