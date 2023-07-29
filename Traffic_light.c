/*
 * Traffic_light.c
 *
 * Created: 8/7/2022 6:21:38 PM
 *  Author: MSI
 */ 

#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "Timer.h"
#include "LED.h"
unsigned char red=10,yellow=5,green=7;
volatile unsigned char counter=0;


int main(void)
{
	LCD_init();
	Timer_CTC_mode_init();
	LED_init('D',0);
	LED_init('D',1);
	LED_init('D',2);
    while(1)
    {
		
		 red=10,yellow=5,green=7;
		 counter=0;
		 LED_TURN_OFF('D',2);
		 	LCD_clear();
			 LED_TURN_ON('D',0);
			 LCD_send_string("STOP!!");
		 	while (counter<100);
			 red--;
			 counter=0;
			 LCD_clear();
			 
			 
			
		 	
		  LCD_send_string("Time remaining=");
		  LCD_move_cursor(2,1);
		  LCD_send_char(red/10+'0');
		  LCD_send_char(red%10+'0');
		 while(red>0)
		 {
			
			 if(counter>=100){
			  red--;
			
			 LCD_move_cursor(2,1);
			 LCD_send_char(red/10+'0');
			 LCD_send_char(red%10+'0');
			 counter=0;
			 }			 
		 }
		 LED_TURN_OFF('D',0);
		 LCD_clear();
		 
		 LED_TURN_ON('D',1);
		   LCD_send_string("Time remaining=");
		   LCD_move_cursor(2,1);
		   LCD_send_char(yellow/10+'0');
		   LCD_send_char(yellow%10+'0');
		 	 while(yellow>1)
		 	 {
				  
			 	 
			 	 if(counter>=100){
				  yellow--;
			 	 
			 	 LCD_move_cursor(2,1);
			 	 LCD_send_char(yellow/10+'0');
			 	 LCD_send_char(yellow%10+'0');
			 	 counter=0;
				  }
				  				  
			 	 
		 	 }
			  LCD_clear();
			  LCD_send_string("Be READY!!");
			  while(counter<100);
			  counter=0;
			  LED_TURN_OFF('D',1);
			  LCD_clear();
			  LED_TURN_ON('D',2);
			  LCD_send_string("GO!!");
			  while(counter<100);
			  green--;
			  counter=0;
			  LCD_clear();
			  
			  
			    LCD_send_string("Time remaining=");
			    LCD_move_cursor(2,1);
			    LCD_send_char(green/10+'0');
			    LCD_send_char(green%10+'0');
			  
			  	 	 while(green>0)
			  	 	 {
							
				  	 	
				  	 	 if(counter>=100){
							 green--;
				  	 	
				  	 	 LCD_move_cursor(2,1);
				  	 	 LCD_send_char(green/10+'0');
				  	 	 LCD_send_char(green%10+'0');
				  	 	 counter=0;
							}				  	 	 
			  	 	 }
					

        
    }
}
ISR(TIMER0_COMP_vect)
{
	counter++;
}