#include <furi_hal.h>
#include <furi_hal_infrared.h>

#include <mp_flipper_modflipperzero.h>
#include <mp_flipper_runtime.h>

#include "mp_flipper_context.h"

typedef struct {
    uint32_t* buffer;
    uint16_t pointer;
    bool running;
} mp_flipper_infrared_rx_session_t;

static void infrared_receive_callback(void* ctx, bool level, uint32_t duration) {
    mp_flipper_infrared_rx_session_t* session = ctx;

    if(session->pointer < MP_FLIPPER_INFRARED_RX_BUFFER_SIZE) {
        session->buffer[session->pointer] = duration;

        session->pointer++;
    } else {
        session->running = false;
    }
}

static void infrared_timeout_callback(void* ctx) {
    mp_flipper_infrared_rx_session_t* session = ctx;

    session->running = false;

    furi_hal_infrared_async_rx_stop();
}

inline uint32_t* mp_flipper_infrared_receive(uint32_t timeout, size_t* length) {
    mp_flipper_infrared_rx_session_t* session = malloc(sizeof(mp_flipper_infrared_rx_session_t));

    session->buffer = calloc(MP_FLIPPER_INFRARED_RX_BUFFER_SIZE, sizeof(uint32_t));
    session->pointer = 0;
    session->running = true;

    furi_hal_infrared_async_rx_set_capture_isr_callback(infrared_receive_callback, session);
    furi_hal_infrared_async_rx_set_timeout_isr_callback(infrared_timeout_callback, session);

    furi_hal_infrared_async_rx_start();

    furi_hal_infrared_async_rx_set_timeout(timeout);

    while(session->running) {
        furi_delay_us(10);
    }

    *length = session->pointer;

    void* pointer = session->buffer;

    free(session);

    return pointer;
}
