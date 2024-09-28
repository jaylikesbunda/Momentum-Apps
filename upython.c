#include <malloc.h>

#include <furi.h>
#include <gui/gui.h>
#include <dialogs/dialogs.h>
#include <storage/storage.h>
#include <cli/cli.h>
#include <cli/cli_vcp.h>

#include <mp_flipper_runtime.h>
#include <mp_flipper_compiler.h>

#include "upython.h"

Action action = ActionNone;
FuriString* file_path = NULL;

int32_t upython(void* args) {
    mp_flipper_cli_register(args);

    do {
        switch(action) {
        case ActionNone:
            action = mp_flipper_splash_screen();

            break;
        case ActionOpen:
            if(mp_flipper_select_python_file(file_path)) {
                action = ActionExec;
            } else {
                furi_string_set(file_path, APP_ASSETS_PATH("upython"));
            }

            break;
        case ActionRepl:
            break;
        case ActionExec:
            mp_flipper_file_execute(file_path);

            furi_string_set(file_path, APP_ASSETS_PATH("upython"));

            action = ActionNone;

            break;
        case ActionExit:
            break;
        }

        furi_delay_ms(1);
    } while(action != ActionExit);

    mp_flipper_cli_unregister(args);

    return 0;
}
