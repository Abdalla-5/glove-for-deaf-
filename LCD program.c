/*
 * LCD_program.c
 *
 * Created: 9/10/2022 3:19:54 PM
 *  Author: DELL
 */ 
#include "STD_TYPES (1).h"
#include "BIT_MATH (1).h"

#include "DIO_interface (1).h"
#include "LCD_interface.h"
#include "config.h"
#define F_CPU 16000000
#include <util/delay.h>

void LCD_send_command(u8 command)
{
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);  //SET RS PIN=0(WRITE COMMAND)
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);  //BEN5ALEEHA WRITE
	LCD_write_half_port(command>>4);//write the most bits of command on pins
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);//enable start
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);//enable end (kont badeeha pulse high we b3d kda low we benhom delay)
	
	LCD_write_half_port(command);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);//enable start
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);//enable end (kont badeeha pulse high we b3d kda low we benhom delay)
	// EB3AT ELMOST THEN DELAY THEN EB3AT EL LEAST (DA TAFSEER ELSOTOOR ELY FO2)
}

void LCD_init(void)
{
	_delay_ms(35);
	
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);  //SET RS PIN=0(WRITE COMMAND)
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);  //BEN5ALEEHA WRITE
	LCD_write_half_port(0b0010);
	
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);//enable start
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);//enable end (kont badeeha pulse high we b3d kda low we benhom delay)
	LCD_send_command(0b00101000);   //(e5tarna elN be 1 wel f be 0)3shan n=line display wel f be 0 3shan sha8aleen 5x7
	_delay_us(45);
	LCD_send_command(0b00001111);//   (display on/off control)          d=0 (display off) welba2y ay haga dayman eld=1 lazemmm
	_delay_us(45);
	LCD_send_command(0b00000001);//clear display 
	_delay_ms(2);
	LCD_send_command(0b00000110);//i/d increment mode =1 lazm(auto increment),,,s=0 3shan elshift
	
	// end of initialization
	// e5tyarat el s wel dwelkalam da mn eldata sheet
	
	
	
	
	
	
	
	
	
}

void LCD_send_char(u8 data)
{
	
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);  //SET RS PIN=1(WRITE data)
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);  //BEN5ALEEHA WRITE
	LCD_write_half_port(data>>4);//write the most bits of command on pins
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);//enable start
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);//enable end (kont badeeha pulse high we b3d kda low we benhom delay)
	
	LCD_write_half_port(data);//least bits
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);//enable start
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);//enable end (kont badeeha pulse high we b3d kda low we benhom delay)
	// EB3AT ELMOST THEN DELAY THEN EB3AT EL LEAST (DA TAFSEER ELSOTOOR ELY FO2)
	
	
	
}

void LCD_write_half_port(u8 value)
{
	if (1==READ_BIT(value,0))
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
		
	}
	else
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
	}
	
	
	
	if (1==READ_BIT(value,1))
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
		
	}
	else
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
	}
	
	
	
	
	if (1==READ_BIT(value,2))
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
		
	}
	else
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
	}
	
	

if (1==READ_BIT(value,3))
{
	DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
	
}
else
{
	DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
}


}
void LCD_writeString(u8 *String)
{
	u8 Local_stringLengh = 0;
	while (String[Local_stringLengh] != '\0')
	{
		LCD_send_char(String[Local_stringLengh]);
		++ Local_stringLengh;
	}
}
void LCD_clear(void)
{
	// Clear Display
	LCD_send_command(0b00000001);
	_delay_ms(2);
}


void LCD_writeNumber(u32 number)
{
	u32 Local_reversed = 1;
	if (number == 0)
	{
		LCD_send_char('0');
	}
	else
	{
		// Reverse Number
		while (number != 0)
		{
			Local_reversed = Local_reversed*10 + (number%10);
			number /= 10;
		}
		
		do
		{
			LCD_send_char((Local_reversed%10)+'0');
			Local_reversed /= 10;
		}while (Local_reversed != 1);
	}
}
