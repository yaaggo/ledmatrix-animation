#include "pico/stdlib.h"
#include "include/keypad.h"
#include "include/matrix.h"
#include "include/buzzer.h"
#include "song.h"

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

void play_melody(Buzzer *buzzer) {
    for (size_t i = 0; i < 78; i++) {
        buzzer_play_note(buzzer, melody[i], duration[i]);
        sleep_ms(50); // Pausa entre notas
    }
}

int main() {
    stdio_init_all();

    // Inicializa o keypad
    keypad kp;
    Buzzer buzzer;

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

    buzzer_init(&buzzer, BUZZER_PIN_A);

    printf("Sistema inicializado!\n");

    while (1) {
        char key = keypad_get_key(&kp);
        if (key != '\0') {
            printf("Tecla pressionada: %c\n", key);
            play_melody(&buzzer);
        }
        sleep_ms(50); // Aguarda para evitar leitura duplicada
    }

    return 0;
}
