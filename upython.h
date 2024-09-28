#pragma once

#include <cli/cli.h>
#include <furi.h>

#define TAG "uPython"
#define CLI "py"

typedef enum {
    ActionNone,
    ActionOpen,
    ActionRepl,
    ActionExec,
    ActionExit
} Action;

extern Action action;
extern FuriString* file_path;

Action mp_flipper_splash_screen();
bool mp_flipper_select_python_file(FuriString* file_path);

void mp_flipper_cli_register(void* args);
void mp_flipper_cli_unregister(void* args);

void mp_flipper_cli(Cli* cli, FuriString* args, void* ctx);

void mp_flipper_repl_execute(Cli* cli);

void mp_flipper_file_execute(FuriString* file);
