#include <flip_store.h>

// Function to free the resources used by FlipStoreApp
void flip_store_app_free(FlipStoreApp* app) {
    if(!app) {
        FURI_LOG_E(TAG, "FlipStoreApp is NULL");
        return;
    }

    // Free View(s)
    if(app->view_main) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewMain);
        view_free(app->view_main);
    }
    if(app->view_app_info) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppInfo);
        view_free(app->view_app_info);
    }
    if(app->view_firmware_download) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewFirmwareDownload);
        view_free(app->view_firmware_download);
    }

    // Free Submenu(s)
    if(app->submenu_main) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewSubmenu);
        submenu_free(app->submenu_main);
    }
    if(app->submenu_options) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewSubmenuOptions);
        submenu_free(app->submenu_options);
    }
    if(app->submenu_app_list) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppList);
        submenu_free(app->submenu_app_list);
    }
    if(app->submenu_firmwares) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewFirmwares);
        submenu_free(app->submenu_firmwares);
    }
    if(app->submenu_app_list_bluetooth) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppListBluetooth);
        submenu_free(app->submenu_app_list_bluetooth);
    }
    if(app->submenu_app_list_games) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppListGames);
        submenu_free(app->submenu_app_list_games);
    }
    if(app->submenu_app_list_gpio) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppListGPIO);
        submenu_free(app->submenu_app_list_gpio);
    }
    if(app->submenu_app_list_infrared) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppListInfrared);
        submenu_free(app->submenu_app_list_infrared);
    }
    if(app->submenu_app_list_ibutton) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppListiButton);
        submenu_free(app->submenu_app_list_ibutton);
    }
    if(app->submenu_app_list_media) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppListMedia);
        submenu_free(app->submenu_app_list_media);
    }
    if(app->submenu_app_list_nfc) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppListNFC);
        submenu_free(app->submenu_app_list_nfc);
    }
    if(app->submenu_app_list_rfid) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppListRFID);
        submenu_free(app->submenu_app_list_rfid);
    }
    if(app->submenu_app_list_subghz) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppListSubGHz);
        submenu_free(app->submenu_app_list_subghz);
    }
    if(app->submenu_app_list_tools) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppListTools);
        submenu_free(app->submenu_app_list_tools);
    }
    if(app->submenu_app_list_usb) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppListUSB);
        submenu_free(app->submenu_app_list_usb);
    }

    // Free Widget(s)
    if(app->widget) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAbout);
        widget_free(app->widget);
    }

    // Free Variable Item List(s)
    if(app->variable_item_list) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewSettings);
        variable_item_list_free(app->variable_item_list);
    }

    // Free Text Input(s)
    if(app->uart_text_input_ssid) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewTextInputSSID);
        text_input_free(app->uart_text_input_ssid);
    }
    if(app->uart_text_input_pass) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewTextInputPass);
        text_input_free(app->uart_text_input_pass);
    }

    // Free popup
    if(app->popup) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewPopup);
        popup_free(app->popup);
    }

    // Free dialog
    if(app->dialog_delete) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewAppDelete);
        dialog_ex_free(app->dialog_delete);
    }
    if(app->dialog_firmware) {
        view_dispatcher_remove_view(app->view_dispatcher, FlipStoreViewFirmwareDialog);
        dialog_ex_free(app->dialog_firmware);
    }

    // deinitalize flipper http
    flipper_http_deinit();

    // free the view dispatcher
    view_dispatcher_free(app->view_dispatcher);

    // close the gui
    furi_record_close(RECORD_GUI);

    // free the app
    free(app);
}

void flip_store_request_error(Canvas* canvas) {
    if(fhttp.last_response != NULL) {
        if(strstr(fhttp.last_response, "[ERROR] Not connected to Wifi. Failed to reconnect.") !=
           NULL) {
            canvas_clear(canvas);
            canvas_draw_str(canvas, 0, 10, "[ERROR] Not connected to Wifi.");
            canvas_draw_str(canvas, 0, 50, "Update your WiFi settings.");
            canvas_draw_str(canvas, 0, 60, "Press BACK to return.");
        } else if(strstr(fhttp.last_response, "[ERROR] Failed to connect to Wifi.") != NULL) {
            canvas_clear(canvas);
            canvas_draw_str(canvas, 0, 10, "[ERROR] Not connected to Wifi.");
            canvas_draw_str(canvas, 0, 50, "Update your WiFi settings.");
            canvas_draw_str(canvas, 0, 60, "Press BACK to return.");
        } else {
            FURI_LOG_E(TAG, "Received an error: %s", fhttp.last_response);
            canvas_draw_str(canvas, 0, 42, "Unusual error...");
            canvas_draw_str(canvas, 0, 50, "Update your WiFi settings.");
            canvas_draw_str(canvas, 0, 60, "Press BACK to return.");
        }
    } else {
        canvas_clear(canvas);
        canvas_draw_str(canvas, 0, 10, "[ERROR] Unknown error.");
        canvas_draw_str(canvas, 0, 50, "Update your WiFi settings.");
        canvas_draw_str(canvas, 0, 60, "Press BACK to return.");
    }
}
