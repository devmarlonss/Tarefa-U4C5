#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definições dos pinos dos leds
#define LED_PIN_R 13
#define LED_PIN_G 11
#define LED_PIN_B 12

// Função de inicialização e configuração das portas gpio dos leds
void led_init() {
    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);
    gpio_init(LED_PIN_G);
    gpio_set_dir(LED_PIN_G, GPIO_OUT);
    gpio_init(LED_PIN_B);
    gpio_set_dir(LED_PIN_B, GPIO_OUT);
}

int main() {
    stdio_init_all();

    led_init();

    while (true) {
    }
}
