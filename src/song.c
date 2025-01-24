#include "song.h"

uint16_t melody[] = {
    NOTE_E7, NOTE_E7, 0, NOTE_E7,
    0, NOTE_C7, NOTE_E7, 0,
    NOTE_G7, 0, 0,  0,
    NOTE_G6, 0, 0, 0,

    NOTE_C7, 0, 0, NOTE_G6,
    0, 0, NOTE_E6, 0,
    0, NOTE_A6, 0, NOTE_B6,
    0, NOTE_AS6, NOTE_A6, 0,

    NOTE_G6, NOTE_E7, NOTE_G7,
    NOTE_A7, 0, NOTE_F7, NOTE_G7,
    0, NOTE_E7, 0, NOTE_C7,
    NOTE_D7, NOTE_B6, 0, 0,

    NOTE_C7, 0, 0, NOTE_G6,
    0, 0, NOTE_E6, 0,
    0, NOTE_A6, 0, NOTE_B6,
    0, NOTE_AS6, NOTE_A6, 0,

    NOTE_G6, NOTE_E7, NOTE_G7,
    NOTE_A7, 0, NOTE_F7, NOTE_G7,
    0, NOTE_E7, 0, NOTE_C7,
    NOTE_D7, NOTE_B6, 0, 0
};

uint16_t duration[] = {
    100, 100, 100, 100,
    100, 100, 100, 100,
    100, 100, 100, 100,
    100, 100, 100, 100,

    100, 100, 100, 100,
    100, 100, 100, 100,
    100, 100, 100, 100,
    100, 100, 100, 100,

    100, 100, 100, 100,
    100, 100, 100, 100,
    100, 100, 100, 100,
    100, 100, 100, 100,

    100, 100, 100, 100,
    100, 100, 100, 100,
    100, 100, 100, 100,
    100, 100, 100, 100
};

void play_melody(Buzzer *buzzer) {
    for (uint8_t i = 0; i < 78; i++) {
        buzzer_play_note(buzzer, melody[i], duration[i]);
        sleep_ms(50);
    }
}