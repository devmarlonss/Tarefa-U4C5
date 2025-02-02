
# README - Temporizador de Disparo (One Shot) com Raspberry Pi Pico W

**Descrição**  
Este projeto implementa um sistema de temporização para o acionamento de LEDs, controlado pelo clique de um botão (pushbutton). O sistema usa o Raspberry Pi Pico W e LEDs de cores azul, vermelho e verde. A temporização é controlada utilizando a função `add_alarm_in_ms()` do Pico SDK, e os LEDs são acionados e desligados em sequência, com intervalos de 3 segundos.

**Requisitos**  
- O botão (pushbutton) controla o acionamento dos LEDs, sendo necessário clicar no botão para iniciar o ciclo de LEDs acesos.
- Quando o botão for pressionado, todos os LEDs (vermelho, verde e azul) serão ligados.
- Após 3 segundos, o sistema desliga um LED, e, após mais 3 segundos, o próximo LED será desligado, até que todos os LEDs estejam apagados.
- A mudança de estado dos LEDs é gerenciada por temporizadores com função de callback.
- O botão só pode iniciar a sequência de LEDs quando todos os LEDs estiverem apagados, prevenindo múltiplos disparos.
- O código utiliza uma leve rotina de *debouncing* para evitar múltiplos registros de pressionamento do botão.

**Componentes Utilizados**  
- **Microcontrolador:** Raspberry Pi Pico W
- **LEDs:** 3 (azul, vermelho e verde)
- **Resistores:** 3 de 330Ω
- **Botão (Pushbutton):** 1

**Definições de Constantes**  
- **LED_PIN_R (13):** Pino do LED vermelho  
- **LED_PIN_G (11):** Pino do LED verde  
- **LED_PIN_B (12):** Pino do LED azul  
- **BUTTON_PIN (5):** Pino do botão (pushbutton)  

**Estrutura do Código**  

- **Variáveis de Estado:**  
  - `all_leds_active`: Indica se todos os LEDs estão ativos.

- **Função de Callback - Temporizador:**  
  - A função `turn_off_callback()` é chamada a cada 3 segundos para desligar os LEDs sequencialmente, com o último LED sendo apagado após o ciclo completo.

- **Função para Ligar Todos os LEDs:**  
  - A função `all_leds_on()` liga os 3 LEDs quando o botão é pressionado.

- **Função de Inicialização:**  
  - A função `led_init()` configura os pinos dos LEDs e do botão para garantir o funcionamento correto do sistema.

- **Função Principal (main):**  
  - Inicializa a comunicação serial e os pinos dos LEDs e do botão.
  - Monitora o estado do botão, e, ao pressioná-lo, liga todos os LEDs e inicia o temporizador para desligá-los em sequência.
