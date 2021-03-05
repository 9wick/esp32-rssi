#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "ble.h"
#include "wifi.h"



void app_main(void)
{

    ESP_LOGI("main", "Hello world!");
//    ble_main();
    wifi_main();
}
