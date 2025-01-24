#ifndef BUZZER_H
#define BUZZER_H

#include <stdint.h>
#include <stdbool.h>

#define BUZZER_PIN_A 21
#define BUZZER_PIN_B 10

/**
 * Estrutura para representar um buzzer.
 */
typedef struct {
    uint8_t pin;    ///< Pino GPIO do buzzer
    uint32_t slice;     ///< Slice do PWM associado ao buzzer
} Buzzer;

/**
 * Inicializa o buzzer no pino especificado.
 *
 * @param buzzer Ponteiro para a estrutura Buzzer a ser inicializada.
 * @param pin Pino GPIO ao qual o buzzer está conectado.
 * @return true se a inicialização for bem-sucedida, false caso contrário.
 */
void buzzer_init(Buzzer *buzzer, uint8_t pin);

/**
 * Configura e inicia o PWM para reproduzir um som com a frequência especificada.
 *
 * @param buzzer Ponteiro para a estrutura Buzzer.
 * @param frequency Frequência do som em Hz.
 * @return true se a operação for bem-sucedida, false caso contrário.
 */
void buzzer_play(Buzzer *buzzer, uint32_t frequency);

/**
 * Para o som emitido pelo buzzer e desativa o slice PWM associado.
 *
 * @param buzzer Ponteiro para a estrutura Buzzer.
 */
void buzzer_stop(Buzzer *buzzer);

/**
 * Reproduz uma nota com duração definida.
 *
 * @param buzzer Ponteiro para a estrutura Buzzer.
 * @param frequency Frequência da nota em Hz.
 * @param duration_ms Duração da nota em milissegundos.
 * @return true se a operação for bem-sucedida, false caso contrário.
 */
void buzzer_play_note(Buzzer *buzzer, uint32_t frequency, uint32_t duration_ms);

#endif // BUZZER_H
