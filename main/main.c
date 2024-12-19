#include "soc/gpio_reg.h"
#include "driver/gpio.h"
#include "hal/gpio_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_err.h"


#define GREEN_LED 17
#define YELLOW_LED 16
void app_main(void) {
    gpio_reset_pin(GREEN_LED);
    gpio_reset_pin(YELLOW_LED);

    gpio_config_t io_conf = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << GREEN_LED) | (1ULL << YELLOW_LED)
    };

    gpio_config(&io_conf);

    while (1) {
        gpio_set_level(GREEN_LED, 1);
        ESP_LOGI("app_main", "GREEN LED ON");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(GREEN_LED, 0);
        ESP_LOGI("app_main", "LED OFF");

        vTaskDelay(1000 / portTICK_PERIOD_MS);

        gpio_set_level(YELLOW_LED, 1);
        ESP_LOGI("app_main", "YELLOW LED ON");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(YELLOW_LED, 0);
        ESP_LOGI("app_main", "YELLOW LED OFF");

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
