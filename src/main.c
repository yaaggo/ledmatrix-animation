#include "pico/stdlib.h"
#include "include/keypad.h"
#include "include/matrix.h"

#include <stdio.h>

#define KEYPAD_PIN_ROWS {1, 2, 3, 4}  // Pinos das linhas do keypad
#define KEYPAD_PIN_COLS {8, 9, 10, 11} // Pinos das colunas do keypad
#define MATRIX_PIN 7 // Pino para controlar os LEDs

rgb_led leds[LED_COUNT];
const char keymap[] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'
};

void keypad_to_matrix_color(char key, rgb_led *leds) {
    // Mapa de cores para as teclas do keypad
    rgb_led colors[] = {
        COLOR(255, 0, 0),    // 1: Vermelho
        COLOR(0, 255, 0),    // 2: Verde
        COLOR(0, 0, 255),    // 3: Azul
        COLOR(255, 255, 0),  // A: Amarelo
        COLOR(255, 0, 255),  // 4: Magenta
        COLOR(0, 255, 255),  // 5: Ciano
        COLOR(128, 128, 128),// 6: Cinza
        COLOR(255, 128, 0),  // B: Laranja
        COLOR(128, 0, 255),  // 7: Roxo
        COLOR(0, 128, 255),  // 8: Azul claro
        COLOR(128, 255, 0),  // 9: Verde claro
        COLOR(255, 255, 255),// C: Branco
        COLOR(64, 0, 0),     // *: Vermelho escuro
        COLOR(0, 64, 0),     // 0: Verde escuro
        COLOR(0, 0, 64),     // #: Azul escuro
        COLOR(128, 64, 0)    // D: Marrom
    };

    // Obtem posição (x, y) a partir da tecla pressionada
    int index = 0;
    if (key >= '1' && key <= '9') {
        index = key - '1';
    } else if (key == '0') {
        index = 13;
    } else if (key == '*') {
        index = 12;
    } else if (key == '#') {
        index = 14;
    } else if (key >= 'A' && key <= 'D') {
        index = 11 + (key - 'A');
    } else {
        return; // Tecla inválida
    }

    // Determina coordenadas X e Y na matriz de LED
    int x = index % 4;
    int y = index / 4;

    // Define a cor no LED correspondente
    matrix_set_led_xy(x, y, colors[index], leds);
    matrix_update(leds);
}

int main() {
    stdio_init_all();

    // Inicializa o keypad
    keypad kp;
    uint8_t rows[] = KEYPAD_PIN_ROWS;
    uint8_t cols[] = KEYPAD_PIN_COLS;
    for (int i = 0; i < 4; i++) {
        kp.gpio_rows[i] = rows[i];
        kp.gpio_column[i] = cols[i];
    }
    keypad_init(&kp, cols, rows);
    keypad_set_key_map(&kp, keymap);
    // Inicializa a matriz de LEDs
    matrix_init(MATRIX_PIN, leds);
    matrix_clear(leds);
    matrix_update(leds);

    printf("Sistema inicializado!\n");

    while (1) {
        char key = keypad_get_key(&kp);
        if (key != '\0') {
            printf("Tecla pressionada: %c\n", key);
            keypad_to_matrix_color(key, leds);
        }
        sleep_ms(50); // Aguarda para evitar leitura duplicada
    }

    return 0;
}
