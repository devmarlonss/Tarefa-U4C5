#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definições dos pinos dos leds e do botão
#define LED_PIN_R 13
#define LED_PIN_G 11
#define LED_PIN_B 12
#define BUTTON_PIN 5

// Indica se todos os leds estão ativos
bool all_leds_active = false;

// Função de callback para desligar os leds após o tempo programado
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if (gpio_get(LED_PIN_G)) {
        gpio_put(LED_PIN_G, 0); // Desativa o led verde
        printf("Green led off\n");
    } else if (gpio_get(LED_PIN_B)) {
        gpio_put(LED_PIN_B, 0); // Desativa o led azul
        printf("Blue led off\n");
    } else if (gpio_get(LED_PIN_R)) {
        gpio_put(LED_PIN_R, 0); // Desativa o led vermelho
        printf("Red led off\n");
        all_leds_active = false; // Indica que todos os leds estão apagados
        printf("All leds off\n");
        return 0; // retorna 0 para que o alarme não se repita
    }

    return 3000000; // retorna 300000 microssegundos (3 segundos) para que o alarme se repita nesse tempo
}

// Função para ligar todos os leds
void all_leds_on() {
    gpio_put(LED_PIN_R, 1); // Ativa o led vermelho
    printf("Red led on\n");
    gpio_put(LED_PIN_G, 1); // Ativa o led verde
    printf("Green led on\n");
    gpio_put(LED_PIN_B, 1);// Ativa o led 
    printf("Blue led on\n");
}

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
    printf("%d button pin on\n", BUTTON_PIN);

    while (true) {
        // Verifica se o botão foi pressionado e se todos os leds estão desativados
        if (!gpio_get(BUTTON_PIN) && !all_leds_active) {
            sleep_ms(50); // Leve Debouncing

            if (!gpio_get(BUTTON_PIN)) {
                all_leds_on(); // Liga todos os leds
                all_leds_active = true; // Indica que o led está ativo

                add_alarm_in_ms(3000, turn_off_callback, NULL, false); // Adiciona o alarme
            }
        }

        sleep_ms(10); // Atraso para desempenho
    }
}
