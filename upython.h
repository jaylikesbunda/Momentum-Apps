#pragma once

#include <cli/cli.h>
#include <furi.h>

#define TAG "uPython"

typedef enum {
    ActionNone,
    ActionOpen,
    ActionRepl,
    ActionExec,
    ActionExit
} Action;

extern Action action;

Action mp_flipper_splash_screen();
bool mp_flipper_select_python_file(FuriString* file_path);

void mp_flipper_repl_register();
void mp_flipper_repl_unregister();

void mp_flipper_repl_execute(Cli* cli, FuriString* args, void* ctx);

void mp_flipper_file_execute(FuriString* file);
