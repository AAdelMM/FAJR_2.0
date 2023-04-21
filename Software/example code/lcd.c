//Here is an example code in C programming language to control a 16x2 LCD using an ATmega644 microcontroller:

/* 
In this code, the lcd_init() function initializes the LCD with the required settings, 
such as 8-bit mode, 2-line display, and 5x8 font. The lcd_command() function sends a command to the LCD, 
such as clearing the display or setting the cursor position. The lcd_data() function sends a data byte to the LCD, 
such as a character or string. Finally, the lcd_string() function takes a string argument 
and sends each character of the string to the LCD using the lcd_data() function.
To use this code, you need to connect the LCD to the ATmega644 microcontroller as follows:

RS pin of the LCD to PD0 pin of the microcontroller
EN pin of the LCD to PD1 pin of the microcontroller
D0-D7 pins of the LCD to PD2-PD7 pins of the microcontroller
Note that the F_CPU macro should be set to the CPU frequency in Hz and the _delay_ms() 
and _delay_us() functions should be adjusted accordingly for the desired delay times.     
*/
/*************************************************************************************/

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL // CPU frequency in Hz
#define LCD_PORT PORTD // LCD data port
#define LCD_RS PD0 // LCD RS pin
#define LCD_EN PD1 // LCD EN pin

void lcd_init(void);
void lcd_command(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_string(char *str);

int main(void)
{
    lcd_init(); // Initialize the LCD

    while (1)
    {
        lcd_command(0x80); // Set cursor at the beginning of the first line
        lcd_string("Hello, World!"); // Display a string on the LCD
        _delay_ms(1000); // Wait for 1 second

        lcd_command(0xC0); // Set cursor at the beginning of the second line
        lcd_string("ATmega644"); // Display another string on the LCD
        _delay_ms(1000); // Wait for 1 second
    }

    return 0;
}

void lcd_init(void)
{
    // Set LCD data port as output
    LCD_PORT = 0x00;
    DDRD = 0xFF;

    // Wait for LCD to power up
    _delay_ms(100);

    // Send initialization commands to the LCD
    lcd_command(0x38); // 8-bit mode, 2-line display, 5x8 font
    lcd_command(0x0C); // Display on, cursor off, blink off
    lcd_command(0x01); // Clear display
    lcd_command(0x06); // Increment cursor, no shift
}

void lcd_command(unsigned char cmd)
{
    LCD_PORT = cmd;
    PORTD &= ~(1 << LCD_RS); // Set RS pin low for command mode
    PORTD |= (1 << LCD_EN); // Set EN pin high to enable LCD
    _delay_us(1);
    PORTD &= ~(1 << LCD_EN); // Set EN pin low to disable LCD
    _delay_us(50);
}

void lcd_data(unsigned char data)
{
    LCD_PORT = data;
    PORTD |= (1 << LCD_RS); // Set RS pin high for data mode
    PORTD |= (1 << LCD_EN); // Set EN pin high to enable LCD
    _delay_us(1);
    PORTD &= ~(1 << LCD_EN); // Set EN pin low to disable LCD
    _delay_us(50);
}

void lcd_string(char *str)
{
    while (*str)
    {
        lcd_data(*str++);
    }
}