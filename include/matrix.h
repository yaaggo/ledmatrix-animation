#ifndef MATRIX_H
#define MATRIX_H

#define LED_COUNT 25
#define LED_LINE 5
#define MATRIX_LED_PIN 7

#define COLOR(r, g, b) (rgb_led) {g, r, b}

typedef struct pixel_t {
    uint8_t r, g, b;
    uint8_t activate;
} rgb_led ;

void matrix_init(uint pin, rgb_led *leds);
void matrix_set_led(uint8_t index, rgb_led color, rgb_led *leds);
void matrix_set_led_xy(uint8_t x, uint8_t y, rgb_led color, rgb_led *leds);
void matrix_clear(rgb_led *leds);
void matrix_update(rgb_led *leds);
void matrix_letter(char letter, rgb_led color, rgb_led *leds);
void matrix_string(char *buffer, rgb_led color, rgb_led *leds);
void matrix_rainbow_wave(rgb_led *leds);
rgb_led hue_to_rgb(int hue);

#endif