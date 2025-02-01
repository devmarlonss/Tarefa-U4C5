#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definições dos pinos dos leds e do botão
#define LED_PIN_R 13
#define LED_PIN_G 11
#define LED_PIN_B 12
#define BUTTON_PIN 5

// Função de inicialização e configuração das portas gpio dos leds
void led_init() {
    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);
    printf("%d led pin on\n", LED_PIN_R);
    gpio_init(LED_PIN_G);
    gpio_set_dir(LED_PIN_G, GPIO_OUT);
    printf("%d led pin on\n", LED_PIN_G);
    gpio_init(LED_PIN_B);
    gpio_set_dir(LED_PIN_B, GPIO_OUT);
    printf("%d led pin on\n", LED_PIN_B);
}

int main() {
    stdio_init_all();

    led_init(); // Inicia os leds

    // Inicia o botão
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN); // Determina como resistor pull-up

    while (true) {

    }
}
