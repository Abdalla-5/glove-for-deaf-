/*
 * DIO_program.c
 *
 * Created: 9/3/2022 4:38:18 PM
 *  Author: DELL
 */ 
#include "STD_TYPES (1).h"
#include "BIT_MATH (1).h"

#include "ATMEGA32 _memory_map.h"
#include "DIO_interface (1).h" 


void DIO_setPinDirection (u8 PortId ,u8 PinId ,u8 PinDirection)
{
 if ((PortId<=3)&&(PinId<=7)&&((DIO_PIN_output==PinDirection)||(DIO_PIN_input==PinDirection)))
 {
  switch(PortId)
  {
	  case DIO_PORTA:   //2         //mmkn switch gowa switch bas 3shan mantla8batsh
	     if (DIO_PIN_output==PinDirection)
		 {
			 SET_BIT(DDRA,PinId);
		 }
		 else  
		 {
			CLEAR_BIT(DDRA,PinId) ;
		 }
	  break;
	  
	  case DIO_PORTB://2
	   if (DIO_PIN_output==PinDirection)
	   {
		   SET_BIT(DDRB,PinId);
	   }
	   else
	   {
		   CLEAR_BIT(DDRB,PinId) ;
	   }
	  break;
	  
	  case DIO_PORTC:
	   if (DIO_PIN_output==PinDirection)
	   {
		   SET_BIT(DDRC,PinId);
	   }
	   else
	   {
		   CLEAR_BIT(DDRC,PinId) ;
	   }
	  break;
	  
	  case DIO_PORTD:
	   if (DIO_PIN_output==PinDirection)
	   {
		   SET_BIT(DDRD,PinId);
	   }
	   else
	   {
		   CLEAR_BIT(DDRD,PinId) ;
	   }
	  break;
	  
  }
 }
}

void DIO_setPinValue (u8 PortId ,u8 PinId ,u8 PinValue)
{
if ((PortId<=3)&&(PinId<=7)&&((DIO_PIN_HIGH==PinValue)||(DIO_PIN_LOW==PinValue)))
{
	switch(PortId)
	{
		case DIO_PORTA://0
		if (DIO_PIN_HIGH==PinValue)
		{
			SET_BIT(PORTA,PinId);
		}
		else
		{
			CLEAR_BIT(PORTA,PinId);
		}
		break;
case DIO_PORTB:
if (DIO_PIN_HIGH==PinValue)
{
	SET_BIT(PORTB,PinId);
}
else
{
	CLEAR_BIT(PORTB,PinId);
}

break;
case DIO_PORTC:
if (DIO_PIN_HIGH==PinValue)
{
	SET_BIT(PORTC,PinId);
}
else
{
	CLEAR_BIT(PORTC,PinId);
}
	break;
	case DIO_PORTD:
	if (DIO_PIN_HIGH==PinValue)
	{
		SET_BIT(PORTD,PinId);
	}
	else
	{
		CLEAR_BIT(PORTD,PinId);
	}
	break;
	
	
	
	
	
	
	}
  }	
}
void DIO_getPinValue (u8 PortId ,u8 PinId ,u8* PinValue ) //mmkn return u8 bas void a7san
{
	if ((PortId<=3)&&(PinId<=7)&&(PinValue!=NULL))
	{
		switch (PortId)
		{
			case DIO_PORTA:
			
			*PinValue =READ_BIT(PINA,PinId);
			
			break;
			
			
			
			case DIO_PORTB:
			
			*PinValue =READ_BIT(PINB,PinId);
			
			break;
			
			case DIO_PORTC:
			
			*PinValue =READ_BIT(PINC,PinId);
			
			break;
			
			
			case DIO_PORTD:
			
			*PinValue =READ_BIT(PIND,PinId);
			
			break;
		}
	}
}
void DIO_togglePinValue (u8 PortId ,u8 PinId)
{
 if ((PortId<=3)&&(PinId<=7))
 {
	 switch (PortId)
	 {
		 case  DIO_PORTA:
		 TOGGLE_BIT(PORTA,PinId);
		 break;
		 
		 
		 case  DIO_PORTB:
		 TOGGLE_BIT(PORTB,PinId);
		 break;
		 
		 
		 case  DIO_PORTC:
		 TOGGLE_BIT(PORTC,PinId);
		 break;
		 
		 
		 case  DIO_PORTD:
		 TOGGLE_BIT(PORTD,PinId);
		 break;
	 }

 }
}









//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

void DIO_setPortDirection (u8 PortId ,u8 PortDirection)
{
	if ((PortId<=3)&&((DIO_PORT_output==PortDirection)||(DIO_PORT_input==PortDirection)))
	{
		switch(PortId)
		{
			
			case DIO_PORTA:
			if (DIO_PORT_output==PortDirection)
			{
				DDRA=0b11111111;
			}
			else
			{
				DDRA=0b00000000;
			}
			break;
			
			
			case DIO_PORTB :
			if (DIO_PORT_output==PortDirection)
			{
				DDRB=0b11111111;
			}
			else
			{
				DDRB=0b00000000;
			}
			break;
			
			
			
			
			case DIO_PORTC:
			if (DIO_PORT_output==PortDirection)
			{
				DDRC=0b11111111;
			}
			else
			{
				DDRC=0b00000000;
			}
			break;
			
			
			
			case DIO_PORTD:
			if (DIO_PORT_output==PortDirection)
			{
				DDRD=0b11111111;
			}
			else
			{
				DDRD=0b00000000;
			}
			break;
		}
	}
}


void DIO_setPortValue (u8 PortId ,u8 PortValue)
{
	if ( PortId<=3)
	{
		switch( PortId)
		{
			case DIO_PORTA:
			PORTA=PortValue;
			
			break;
			
			
			case DIO_PORTB:
			PORTB=PortValue;
			
			break;
			
			case DIO_PORTC:
			PORTC=PortValue;
			
			break;
			
			case DIO_PORTD:
			PORTD=PortValue;
			
			break;
		}
	}
		
}



void DIO_getPortValue (u8 PortId ,u8* PortValue )
{
	
	
	if ((PortId<=3)&&(PortValue!=NULL))
	{
		switch (PortId)
		{
			case DIO_PORTA:
			
			*PortValue =PINA;
			
			break;
			
			case DIO_PORTB:
			
			*PortValue =PINB;
			
			break;
			
			
			case DIO_PORTC:
			
			*PortValue =PINC;
			
			break;
			
			case DIO_PORTD:
			
			*PortValue =PIND;
			
			break;
			
	}
	
	}
	
}

void DIO_togglePortValue (u8 PortId )
{
	
	
	if (PortId<=3)
	{
		switch (PortId)
		{
			case DIO_PORTA:
			
			PORTA = ~PORTA;
			
			break;
			
			case DIO_PORTB:
			
			PORTB = ~PORTB;
			
			break;
			
			
			case DIO_PORTC:
			
			PORTC = ~PORTC;
			
			break;
			
			case DIO_PORTD:
		PORTD = ~PORTD;
			
			break;
			
		}
		
	  }
		
	}