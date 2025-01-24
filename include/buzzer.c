#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "pico/stdlib.h"
#include "buzzer.h"

void buzzer_init(Buzzer *buzzer, uint8_t pin) {
    buzzer->pin = pin;
    buzzer->slice = pwm_gpio_to_slice_num(pin); 
    gpio_set_function(pin, GPIO_FUNC_PWM); 
    pwm_set_gpio_level(buzzer->pin, 0);
    pwm_set_enabled(buzzer->slice, false);
}

void buzzer_play(Buzzer *buzzer, uint32_t freq) {
    uint32_t sys_clock = clock_get_hz(clk_sys); 
    uint32_t clock_div = 4;
    uint32_t wrap = sys_clock / (clock_div * freq) - 1; 

    pwm_set_clkdiv(buzzer->slice, clock_div); 
    pwm_set_wrap(buzzer->slice, wrap); 
    pwm_set_gpio_level(buzzer->pin, wrap / 2);
    pwm_set_enabled(buzzer->slice, true);
}

void buzzer_stop(Buzzer *buzzer) {
    pwm_set_enabled(buzzer->slice, false);
}

void buzzer_play_note(Buzzer *buzzer, uint32_t freq, uint32_t duration_ms) {
    buzzer_play(buzzer, freq);
    sleep_ms(duration_ms);
    pwm_set_gpio_level(buzzer->pin, 0);
    //buzzer_stop(buzzer);
}