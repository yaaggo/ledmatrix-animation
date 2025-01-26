#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/bootrom.h"

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

// int main() {
//     stdio_init_all();

    

//     // Inicializa o keypad
//     keypad kp;
//     Buzzer buzzer;

//     uint8_t rows[] = KEYPAD_PIN_ROWS;
//     uint8_t cols[] = KEYPAD_PIN_COLS;

//     for (int i = 0; i < 4; i++) {
//         kp.gpio_rows[i] = rows[i];
//         kp.gpio_column[i] = cols[i];
//     }

//     keypad_init(&kp, cols, rows);
//     keypad_set_key_map(&kp, keymap);
    

//     gpio_init(5);
//     gpio_set_dir(5, GPIO_IN);
//     gpio_pull_up(5);
    
//     // Inicializa a matriz de LEDs
//     matrix_init(MATRIX_LED_PIN, leds);
//     matrix_clear(leds);
//     matrix_update(leds);

//     matrix_update(leds);

//     while (1){

//         char key = keypad_get_key(&kp);

//         //char key = keypad_get_key(&kp);
//         if (key != '\0') {
//             printf("Tecla pressionada: %c\n", key);

//             switch(key) {
//                 case '1': {
//                     animation_play(BUBBLE_SORT_FRAME_COUNT, 6000, leds, bubble_sort_data);
//                     break;
//                 }
//                 case '2': {
//                     animation_play(FAN_FRAME_COUNT, 1000, leds, fan_data);
//                     break;
//                 }
//                 case '3': {
//                     animation_play(MARIO_FRAME_COUNT, 500, leds, mario_data);
//                     break;
//                 }
//                 case '4': {
//                     matrix_clear(leds);
//                     matrix_update(leds);
//                     reset_usb_boot(0, 0);
//                 }
//             }

//             matrix_update(leds);
//         }
//         sleep_ms(50);
//     }

//     return 0;
// }

// void generate_red_gradient(rgb_led *leds) {
//     for (int i = 0; i < LED_COUNT; i++) {
//         uint8_t red_intensity = (255 * i) / (LED_COUNT - 1);
//         leds[i] = (rgb_led){.r = red_intensity, .g = 0, .b = 0};
//     }
//     matrix_update(leds);
// }

// void matrix_fill(uint8_t r, uint8_t g, uint8_t b, rgb_led *leds) {
//     for(int i = 0; i < LED_COUNT; i++) {
//         matrix_set_led(i, COLOR_RGB(r, g, b), leds);
//     }
//     matrix_update(leds);
// }

// int main() {
//     stdio_init_all();

//     gpio_init(5);
//     gpio_set_dir(5, GPIO_IN);
//     gpio_pull_up(5);

//     matrix_init(MATRIX_LED_PIN, leds);
//     matrix_clear(leds);

//     int inc = 5;
//     int u = 0;

//     while (1) {
//         if(!gpio_get(5)) {
//             matrix_clear(leds);
//             matrix_update(leds);
//             reset_usb_boot(0, 0);
//         }
        
//         matrix_fill(u, u, u, leds);
//         u += inc;
//         if(u == 30 || u == 0) inc = -inc;

//         sleep_ms(30);

        
//     }

//     return 0;
// }