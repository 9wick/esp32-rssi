#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "ble.h"
#include "wifi.h"


#define SYSTEM_SWITCH_PIN_NO 39


bool system_switch_get_button() {
    gpio_pad_select_gpio(SYSTEM_SWITCH_PIN_NO);
    return gpio_get_level(SYSTEM_SWITCH_PIN_NO);
}

void system_switch_init_pin(int pinNo) {
    gpio_pad_select_gpio(pinNo);
    gpio_set_direction(pinNo, GPIO_MODE_INPUT);
}


void app_main(void)
{


    ESP_LOGI("main", "Hello world!");


    gpio_set_pull_mode(SYSTEM_SWITCH_PIN_NO, GPIO_PULLUP_ONLY);
    system_switch_init_pin(SYSTEM_SWITCH_PIN_NO);

    if(system_switch_get_button()){
        ble_main();
    }else{
        wifi_main();
    }


}
