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

int32_t upython(void* args) {
    if(args == NULL) {
        mp_flipper_repl_register();
    } else {
        action = ActionOpen;
    }

    do {
        if(args == NULL && mp_flipper_splash_screen() == ActionExit) {
            break;
        }

        if(action == ActionOpen) {
            FuriString* file_path = NULL;

            if(args != NULL) {
                file_path = furi_string_alloc_set_str(args);
            } else {
                file_path = furi_string_alloc_set_str(APP_ASSETS_PATH("upython"));
            }

            if(args != NULL || mp_flipper_select_python_file(file_path)) {
                mp_flipper_file_execute(file_path);
            }

            furi_string_free(file_path);
        }

        if(args != NULL) {
            break;
        }
    } while(true);

    if(args == NULL) {
        mp_flipper_repl_unregister();
    }

    return 0;
}
