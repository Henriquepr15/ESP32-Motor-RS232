#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "driver/gpio.h"
#include "driver/uart.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define INPUT_SIGNAL    GPIO_NUM_4
#define MOTOR_OUTPUT    GPIO_NUM_5
#define UART_PORT       UART_NUM_1

void init_gpio(void);
void init_uart(void);
void send_uart_message(const char *msg);

void app_main(void) {
    init_gpio();
    init_uart();

    while (1) {
        int signal = gpio_get_level(INPUT_SIGNAL);

        if (signal == 0) {
            gpio_set_level(MOTOR_OUTPUT, 1);
            send_uart_message("Motor ON\r\n");
            vTaskDelay(pdMS_TO_TICKS(10000));
            gpio_set_level(MOTOR_OUTPUT, 0);
            send_uart_message("Motor OFF\r\n");
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void init_gpio(void) {
    gpio_config_t io_conf = {0};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = (1ULL << INPUT_SIGNAL);
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);

    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << MOTOR_OUTPUT);
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);
}

void init_uart(void) {
    uart_config_t uart_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_driver_install(UART_PORT, 1024, 0, 0, NULL, 0);
    uart_param_config(UART_PORT, &uart_config);
    uart_set_pin(UART_PORT, GPIO_NUM_17, GPIO_NUM_16, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}

void send_uart_message(const char *msg) {
    uart_write_bytes(UART_PORT, msg, strlen(msg));
}
