/*
 * lcd.h
 *
 * Created: 4-3-2018 19:38:42
 *  Author: jeffr
 */ 

#ifndef LCD_H_
#define LCD_H_

void init();
void display_clear();
void display_text(char *str);
void set_cursor(int pos);
void set_display(int pos);

void lcd_command ( unsigned char dat );

#endif /* LCD_H_ */