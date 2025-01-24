#include <stdio.h>

#include "pico/stdlib.h"
#include "include/keypad.h"
#include "include/matrix.h"
#include "include/buzzer.h"

#include "song.h"
#include "animations.h"


#define KEYPAD_PIN_ROWS {1, 2, 3, 4}  // Pinos das linhas do keypad
#define KEYPAD_PIN_COLS {8, 9, 10, 11} // Pinos das colunas do keypad

rgb_led leds[LED_COUNT];

const char keymap[] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'
};

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
    matrix_init(MATRIX_LED_PIN, leds);
    matrix_clear(leds);

    matrix_set_led(54, COLOR(255, 0 ,0), leds);
    matrix_update(leds);

    while (1) {
        char key = keypad_get_key(&kp);
        if (key != '\0') {
            printf("Tecla pressionada: %c\n", key);

            switch(key) {
                case '1': {
                    animation_play(BUBBLE_SORT_FRAME_COUNT, 6000, leds, bubble_sort_data);
                    break;
                }
                case '2': {
                    while(animation_play(FAN_FRAME_COUNT, 1000, leds, fan_data), 1);
                    break;
                }
                case '3': {
                    while(animation_play(MARIO_FRAME_COUNT, 500, leds, mario_data), 1);
                    break;
                }
            }

            matrix_update(leds);
        }
        sleep_ms(50);
    }

    return 0;
}
