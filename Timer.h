/*
 * Timer.h
 *
 * Created: 8/6/2022 8:18:48 PM
 *  Author: MSI
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include "STD_macros.h"

void Timer_CTC_mode_init();
void Timer_generate_signal_non_PWM();
void Timer_generate_signal_FAST_PWM();
void Timer_generate_signal_phase_correct_PWM();
void Fan_Speed(char DC);



#endif /* TIMER_H_ */