#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "pico/stdlib.h"
#include "buzzer.h"

bool buzzer_init(Buzzer *buzzer, uint8_t pin) {
    if (!buzzer) return false;

    // Verifica se o pino é válido
    if (pin >= NUM_BANK0_GPIOS) return false;

    buzzer->pin = pin;
    buzzer->slice = pwm_gpio_to_slice_num(pin);

    gpio_set_function(pin, GPIO_FUNC_PWM);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f);
    pwm_init(buzzer->slice, &config, true);

    pwm_set_gpio_level(pin, 0);
    pwm_set_enabled(buzzer->slice, true);
    return true;
}

bool buzzer_play(Buzzer *buzzer, uint32_t frequency) {
    if (!buzzer || frequency == 0) return false;

    uint32_t clock_frequency = clock_get_hz(clk_sys);
    uint32_t top = clock_frequency / frequency - 1;

    // Verifica se o valor calculado para o top é válido
    if (top > 65535) return false;

    pwm_set_wrap(buzzer->slice, top);
    pwm_set_gpio_level(buzzer->pin, top / 2);
    return true;
}

void buzzer_stop(Buzzer *buzzer) {
    if (!buzzer) return;

    pwm_set_gpio_level(buzzer->pin, 0);
    pwm_set_enabled(buzzer->slice, false);
}

bool buzzer_play_note(Buzzer *buzzer, uint32_t frequency, uint32_t duration_ms) {
    if (!buzzer || !buzzer_play(buzzer, frequency)) return false;

    sleep_ms(duration_ms);
    buzzer_stop(buzzer);

    // Pequena pausa entre as notas
    sleep_ms(50);
    return true;
}
