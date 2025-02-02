# Semáforo com Temporizador Periódico

Este projeto implementa um semáforo utilizando a Raspberry Pi Pico W, três LEDs (vermelho, amarelo e verde) e temporização de 3 segundos entre as transições de sinal. O código faz uso da função `add_repeating_timer_ms()` da ferramenta Pico SDK para alternar os estados dos LEDs de acordo com um ciclo pré-definido.

## Requisitos

1. **Hardware**:
   - Microcontrolador Raspberry Pi Pico W
   - 3 LEDs (vermelho, amarelo e verde)
   - 3 Resistores de 330 Ω
   
2. **Funcionamento**:
   - O semáforo inicia no LED vermelho e alterna para amarelo e verde sequencialmente.
   - Cada estado dura 3 segundos.
   - As mudanças de estado dos LEDs ocorrem dentro da função de callback do temporizador.
   - A cada segundo, a rotina principal imprime mensagens na porta serial.

## Constantes Utilizadas

- **LED_PIN_R**: Define o pino do LED vermelho (13).
- **LED_PIN_G**: Define o pino do LED verde (11).
- **LED_PIN_Y**: Define o pino do LED amarelo (12).

## Funções Implementadas

### `repeating_timer_callback(struct repeating_timer *t)`

Essa função é chamada pelo temporizador a cada 3 segundos para alternar os estados dos LEDs:

- Liga e desliga os LEDs de acordo com o estado atual.
- Alterna o estado do semáforo conforme o ciclo definido.

### `led_init()`

Inicializa os pinos GPIO dos LEDs e configura-os como saída.

## Execução do Programa

1. Inicializa a comunicação serial.
2. Configura os LEDs chamando `led_init()`.
3. Cria um temporizador periódico de 3 segundos com `add_repeating_timer_ms()`.
4. Mantém o programa em um loop infinito, imprimindo mensagens a cada segundo.