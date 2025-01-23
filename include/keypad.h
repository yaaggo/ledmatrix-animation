#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>
#include <stdbool.h>

#define BUTTON_COUNT 16

typedef struct {
    uint8_t buttons[BUTTON_COUNT];
    uint8_t gpio_column[4];
    uint8_t gpio_rows[4];
    bool is_released;
} keypad;

void keypad_init(keypad *keypad, const uint8_t *columns, const uint8_t *rows);
void keypad_set_key_map(keypad *keypad, const char *key_map);
int keypad_get_index(keypad *keypad);
char keypad_get_key(keypad *keypad);

#endif