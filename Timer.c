/*
 * Timer.c
 *
 * Created: 8/6/2022 8:19:02 PM
 *  Author: MSI
 */ 
#include "Timer.h"
void Timer_CTC_mode_init()
{
	//set timer clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	//enable ctc mode
	SET_BIT(TCCR0,WGM01);
	// enable interrupt of ctc mode
	SET_BIT(TIMSK,OCIE0);
	sei();
	//enable interrupt every 10 ms
	OCR0=80;
	
}
void Timer_generate_signal_non_PWM()
{
	SET_BIT(DDRB,3);
	//set timer clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	//enable ctc mode
	SET_BIT(TCCR0,WGM01);
	// identify the frequancy of signal generated
	OCR0=64;
	// generate tog signal on pb3 every compare match
	SET_BIT(TCCR0,COM00);
}
void Timer_generate_signal_FAST_PWM()
{
	SET_BIT(DDRB,3);
	//set timer clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	// enable fast PWM mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	// identify the frequancy of signal generated
	OCR0=64;
	//generate set on compare match and clear on bottom(inverting mode)
	//SET_BIT(TCCR0,COM00);
	//SET_BIT(TCCR0,COM01);
	//generate clear on compare match and set on bottom(non-inverting mode)
	SET_BIT(TCCR0,COM01);
	
	
}
void Timer_generate_signal_phase_correct_PWM()
{
		SET_BIT(DDRB,3);
		//set timer clock
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS02);
		// enable phase correct mode PWM mode
		SET_BIT(TCCR0,WGM00);
		// identify the frequancy of signal generated
		OCR0=64;
		//generate set on compare match when counting up and clear on  compare match when down counting 
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		//generate clear on compare match when counting up and set on compare match when down counting
		
		//SET_BIT(TCCR0,COM01);
	
}
void Fan_Speed(char DC)
{
		SET_BIT(DDRB,3);
		//set timer clock
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS02);
		// enable fast PWM mode
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		// identify the frequancy of signal generated
		OCR0=(DC/100)*256;
		//generate set on compare match and clear on bottom(inverting mode)
		//SET_BIT(TCCR0,COM00);
		//SET_BIT(TCCR0,COM01);
		//generate clear on compare match and set on bottom(non-inverting mode)
		SET_BIT(TCCR0,COM01);
		
}