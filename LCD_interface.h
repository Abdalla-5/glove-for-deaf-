/*
 * LCD_interface.h
 *
 * Created: 9/10/2022 3:21:12 PM
 *  Author: DELL
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_




void LCD_init(void);
void LCD_send_char(u8 data);
void LCD_send_command(u8 command);
void LCD_write_half_port(u8 value);
void LCD_writeString(u8*String);
void LCD_clear(void);
void LCD_writeNumber(u32 number);
#endif /* LCD_INTERFACE_H_ */