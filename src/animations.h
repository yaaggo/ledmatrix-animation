#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <stdint.h>
#include "include/matrix.h"
#include <stdio.h>
#include "pico/stdlib.h"

#define BUBBLE_SORT_FRAME_COUNT 23
#define FAN_FRAME_COUNT 4
#define MARIO_FRAME_COUNT 2

rgb_led hex_to_rgb_conversor(uint32_t hex_color);
void animation_play(uint8_t frames,
                    uint32_t duration, 
                    rgb_led *leds,
                    const uint32_t animation[][25]);

extern const uint32_t bubble_sort_data[23][25];
extern const uint32_t fan_data[4][25];
extern const uint32_t mario_data[2][25];

#endif