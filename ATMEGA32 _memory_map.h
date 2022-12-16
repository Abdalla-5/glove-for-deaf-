/*
 * ATMEGA32__memory_map.h
 *
 * Created: 9/3/2022 5:10:03 PM
 *  Author: DELL
 */ 


#ifndef ATMEGA32_MEMORY_MAP_H_
#define ATMEGA32_MEMORY_MAP_H_

#define DDRA   *(volatile u8*)0x3A
#define DDRB   *(volatile u8*)0x37
#define DDRC   *(volatile u8*)0x34
#define DDRD   *(volatile u8*)0x31
//########################
#define PORTA  *(volatile u8*)0x3B
#define PORTB  *(volatile u8*)0x38
#define PORTC  *(volatile u8*)0x35
#define PORTD  *(volatile u8*)0x32
//##################
#define PINA   *(volatile u8*)0x39
#define PINB   *(volatile u8*)0x36
#define PINC   *(volatile u8*)0x33
#define PIND   *(volatile u8*)0x30

//INTERRUPTS
//MCUCR
#define MCUCR  *(volatile u8*)0x55

//MCUCSR
#define MCUCSR *(volatile u8*)0x54

//GICR
#define GICR   *(volatile u8*)0x5B

//GIFR
#define GIFR   *(volatile u8*)0x5A

//SREG
#define SREG   *(volatile u8*)0x5F


//   ADC REGISTERS
#define ADMUX    (*(volatile u8* )0x27)//ADC MULTIPLEXER REGISTER

#define ADCSRA   (*(volatile u8* )0x26)//ADC CONTROL AND STATUS REGISTER
//ADC DATA REGISTER
#define ADCL     (*(volatile u8* )0x24)
#define ADCH     (*(volatile u8* )0x25)
#define ADC_u16  (*(volatile u16*)0x24)
//./////
#define SFIOR    (*(volatile u8* )0x50)//SPECIAL FUNC REGISTER



/* TIMER0*/

// Timer/Counter Control Register
#define TCCR0           (*(volatile u8*)0x53)

// Timer/Counter Register
#define TCNT0           (*(volatile u8*)0x52)

// Output Compare Register
#define OCR0            (*(volatile u8*)0x5C)

// Timer/Counter Interrupt Mask Register
#define TIMSK           (*(volatile u8*)0x59)

// Timer/Counter Interrupt Flag Register
#define TIFR            (*(volatile u8*)0x58)




//TIMER 1 REGISTER

// Timer/Counter Control Register A
#define TCCR1A               (*(volatile u8*)0x4F)

// Timer/Counter Control Register B
#define TCCR1B               (*(volatile u8*)0x4E)



// Timer/Counter 1 Register
#define TCNT1_u16            (*(volatile u16*)0x4C)

// Output Compare Register A
#define OCR1A_u16            (*(volatile u16*)0x4A)
// Output Compare Register B
#define OCR1B_u16            (*(volatile u16*)0x48)


#define ICR1_u16             (*(volatile u16*)0x46)

////watch dog TIMER CONTROL REGISTER

#define   WDTCR             (*(volatile u8*)0x41)

                               /* UART REGISTERS*/
							   
// USART I/O Data Register
#define UDR               (*(volatile u8*)0x2C)	

// USART Control and Status Register A
#define UCSRA             (*(volatile u8*)0x2B)

// USART Control and Status Register B
#define UCSRB             (*(volatile u8*)0x2A)	

// USART Control and Status Register C
#define UCSRC             (*(volatile u8*)0x40)	

// USART Baud Rate Registers
#define UBRRL             (*(volatile u8*)0x29)			  
#define UBRRH             (*(volatile u8*)0x40)
							

                             /* SPI REGISTERS*/

// SPI Control Register
#define SPCR              (*(volatile u8*)0x2D)
							 
// SPI Status Register
#define SPSR              (*(volatile u8*)0x2E)

// SPI Data Register
#define SPDR              (*(volatile u8*)0x2F)





//TWI REGISTERS:
//BIT RATE REGISTER

#define  TWBR           (*(volatile u8*)0x20)

//TWI CONTROL REGISTER

#define     TWCR         (*(volatile u8*)0x56)

//TWI STATUS REGISTER

#define       TWSR       (*(volatile u8*)0x21)

//TWI DATA REGISTER

#define      TWDR        (*(volatile u8*)0x23)

//TWI(SLAVE) ADRESS REGISTER

#define      TWAR       (*(volatile u8*)0x22)

#endif /* ATMEGA32_MEMORY_MAP_H_ */