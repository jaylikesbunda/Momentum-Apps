#include <furi_hal.h>
#include <furi_hal_infrared.h>

#include <mp_flipper_modflipperzero.h>
#include <mp_flipper_runtime.h>

#include "mp_flipper_context.h"

uint32_t* mp_flipper_infrared_receive(uint32_t timeout, size_t* length) {
    uint32_t* buffer = calloc(MP_FLIPPER_INFRARED_RX_BUFFER_SIZE, sizeof(uint32_t));

    *length = MP_FLIPPER_INFRARED_RX_BUFFER_SIZE;

    return buffer;
}
