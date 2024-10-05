#pragma once

#include <stdint.h>
#include <stdbool.h>

extern uint8_t MP_FLIPPER_LOG_LEVEL_TRACE;
extern uint8_t MP_FLIPPER_LOG_LEVEL_DEBUG;
extern uint8_t MP_FLIPPER_LOG_LEVEL_INFO;
extern uint8_t MP_FLIPPER_LOG_LEVEL_WARN;
extern uint8_t MP_FLIPPER_LOG_LEVEL_ERROR;
extern uint8_t MP_FLIPPER_LOG_LEVEL_NONE;

uint8_t mp_flipper_log_get_effective_level();
bool mp_flipper_log_level_is_valid(uint8_t level);
void mp_flipper_log(uint8_t raw_level, const char* message);
