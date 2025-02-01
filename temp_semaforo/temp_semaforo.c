#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definições dos pinos dos leds
#define LED_PIN_R 13
#define LED_PIN_G 11
#define LED_PIN_Y 12

// Variáveis de estado do led
bool led_r = true;
bool led_g = false;
bool led_y = false;

// Função de callback para acender os leds
bool repeating_timer_callback(struct repeating_timer *t) {
    printf("3 segundos\n");

    // Liga os leds de acordo com os valores das variáveis de estado
    gpio_put(LED_PIN_R, led_r);
    printf("led_r - %d\n", led_r);
    gpio_put(LED_PIN_G, led_g);
    printf("led_g - %d\n", led_g);
    gpio_put(LED_PIN_Y, led_y);
    printf("led_y - %d\n", led_y);

    // Verifica o estado atual do led e alterna para o próximo estado
    if (led_r) {
        led_r = !led_r;
        led_y = !led_y;
    } else if (led_y) {
        led_y = !led_y;
        led_g = !led_g;
    } else if (led_g) {
        led_g = !led_g;
        led_r = !led_r;
    }
    return true;
}

// Função de inicialização e configuração das portas gpio dos leds
void led_init() {
    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);
    printf("%d led pin on\n", LED_PIN_R);
    gpio_init(LED_PIN_G);
    gpio_set_dir(LED_PIN_G, GPIO_OUT);
    printf("%d led pin on\n", LED_PIN_G);
    gpio_init(LED_PIN_Y);
    gpio_set_dir(LED_PIN_Y, GPIO_OUT);
    printf("%d led pin on\n", LED_PIN_Y);
}

int main() {
    stdio_init_all();

    led_init(); // Iniciar leds

    struct repeating_timer timer; // Estrutura do temporizador
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); // temporizador chama a função de callback a cada 3 segundos

    while (true) {
        printf("1 segundo\n");
        sleep_ms(1000);
    }
}
