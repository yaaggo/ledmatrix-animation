#include "keypad.h"
#include "pico/stdlib.h"

void keypad_init(keypad *keypad, const uint8_t *columns, const uint8_t *rows) {
    for (int i = 0; i < 4; i++) {
        keypad->gpio_column[i] = columns[i];
        keypad->gpio_rows[i] = rows[i];

        gpio_init(columns[i]);
        gpio_set_dir(columns[i], GPIO_OUT);
        gpio_put(columns[i], 1);

        gpio_init(rows[i]);
        gpio_set_dir(rows[i], GPIO_IN);
        gpio_pull_up(rows[i]);
    }
    keypad->is_released = true;
}

void keypad_set_key_map(keypad *keypad, const char *key_map) {
    for (int i = 0; i < BUTTON_COUNT; i++) {
        keypad->buttons[i] = key_map[i];
    }
}

int keypad_get_index(keypad *keypad) {
    for (int col = 0; col < 4; col++) {
        gpio_put(keypad->gpio_column[col], 0);
        sleep_us(50);

        for (int row = 0; row < 4; row++) {
            if (!gpio_get(keypad->gpio_rows[row])) {
                gpio_put(keypad->gpio_column[col], 1);
                return row * 4 + col;
            }
        }
        gpio_put(keypad->gpio_column[col], 1);
    }
    return -1; // Nenhuma tecla pressionada
}

char keypad_get_key(keypad *keypad) {
    int index = keypad_get_index(keypad);
    if (index >= 0 && keypad->is_released) {
        keypad->is_released = false;
        return keypad->buttons[index];
    }
    if (index == -1) {
        keypad->is_released = true;
    }
    return '\0';
}
