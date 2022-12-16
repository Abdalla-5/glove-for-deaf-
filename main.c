/*
 * GccApplication8.c
 *
 * Created: 12/16/2022 5:28:04 PM
 * Author : ADMIN
 */ 

#define F_CPU 16000000
#include <util/delay.h>
#include "STD_TYPES (1).h"
#include "BIT_MATH (1).h"

#include "ATMEGA32 _memory_map.h"
#include "DIO_interface (1).h"
#include "LCD_interface.h"



#define A0 y1==0
#define A1 y1==1
#define B0 y2==0
#define B1 y2==1
#define C0 y3==0
#define C1 y3==1
#define D0 y4==0
#define D1 y4==1
#define E0 y5==0
#define E1 y5==1




int main(void)
{
	u8 y1;
	u8 y2;
	u8 y3;
	u8 y4;
	u8 y5;
	

	u8 *first_string= "welcome" ;
	u8 *second_string=("RECOGNITION");
	u8 *string1=("happy life");
	u8 *string2=("you");
	u8 *string3=("good work");
	u8 *string4=("I watch you");
	u8 *string5=("really love you");
	u8 *string6=("I love you");
	u8 *string7=("wonderfull");
	
	//lcd pins output
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_output);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_output);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_output);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_output);
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_output);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_output);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_output);
	//sensors pins input
	DIO_setPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_input);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_input);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN4,DIO_PIN_input);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_input);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN6,DIO_PIN_input);
	
	// UART_init();
	LCD_init();
	
	LCD_writeString(first_string);
	//ADC_init();
	_delay_ms(1000);
	LCD_clear();
	LCD_writeString(second_string);
	_delay_ms(1000);
	
	while (1)
	{
		
		LCD_clear();
		
		DIO_getPinValue(DIO_PORTD,DIO_PIN2,&y1);
		
		DIO_getPinValue(DIO_PORTD,DIO_PIN3,&y2);
		
		DIO_getPinValue(DIO_PORTD,DIO_PIN4,&y3);
		
		DIO_getPinValue(DIO_PORTD,DIO_PIN5,&y4);
		
		DIO_getPinValue(DIO_PORTD,DIO_PIN6,&y5);
		
		_delay_ms(500);
		if   (A1 && B1 && C1 && D1 && E1)
		{
			
		}
		//////////////////////////////////////////////////////
		else if  (A0 && B0 && C0 && D0 && E0)
		{
			LCD_clear();
		
			LCD_writeString(string1);
			
			
			_delay_ms(1000);
			
		}
		/////////////////////////////////////////////////////
		else if  (A1 && B0 && C1 && D1 && E1)
		{
			LCD_clear();
			
			LCD_writeString(string2);
			
			
			_delay_ms(1000);
			
		}
		////////////////////////////////////////////////////////////////
		else if  (A0 && B1 && C1 && D1 && E1)
		{
			LCD_clear();
			
			LCD_writeString(string3);
			
			
			_delay_ms(1000);
			
		}
		//////////////////////////////////////////////////////////////////
		else if  (A1 && B0 && C0 && D1 && E1)
		{
			LCD_clear();
			
			LCD_writeString(string4);
			
			_delay_ms(1000);
			
		}
		///////////////////////////////////////////////////////////////////
		else if  (A0 && B0 && C0 && D1 && E0)
		{
			LCD_clear();
			
			LCD_writeString(string5);
			
		
			_delay_ms(1000);
			
		}
		/////////////////////////////////////////////////////////////
		else if  (A0 && B0 && C1 && D1 && E0)
		{
			LCD_clear();
			
			LCD_writeString(string6);
			
			
			_delay_ms(1000);
		
		}
		//////////////////////////////////////////////////////////////////
		else if  (A1 && B0 && C1 && D1 && E0)
		{
			LCD_clear();
			
			LCD_writeString(string7);
		
			_delay_ms(1000);
			
		}
	}
	
}


