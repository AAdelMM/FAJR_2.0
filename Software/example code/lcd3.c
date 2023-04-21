//Here's an example of how to control a second shift register CD4094 
//in daisy chain with ATmega644 without SPI in C programming language 
//to control an 8-bit LCD:

#include <avr/io.h>
#include <util/delay.h>

// Define the shift register pins
#define SRCLK_PIN   PB0     // Shift Register Clock
#define RCLK_PIN    PB1     // Register Clock
#define SER_PIN     PB2     // Serial Data

// Define the CD4094 pins
#define OE_PIN      PC0     // Output Enable
#define MR_PIN      PC1     // Master Reset

// Define the LCD pins
#define LCD_RS      PC2     // Register Select
#define LCD_RW      PC3     // Read/Write
#define LCD_EN      PC4     // Enable
#define LCD_D0      PB3     // Data Bit 0
#define LCD_D1      PB4     // Data Bit 1
#define LCD_D2      PB5     // Data Bit 2
#define LCD_D3      PB6     // Data Bit 3
#define LCD_D4      PB7     // Data Bit 4
#define LCD_D5      PD0     // Data Bit 5
#define LCD_D6      PD1     // Data Bit 6
#define LCD_D7      PD2     // Data Bit 7

// Initialize the shift register pins
void init_shift_register() {
    DDRB |= (1 << SRCLK_PIN) | (1 << RCLK_PIN) | (1 << SER_PIN);
    PORTB &= ~((1 << SRCLK_PIN) | (1 << RCLK_PIN) | (1 << SER_PIN));
}

// Initialize the CD4094 pins
void init_cd4094() {
    DDRC |= (1 << OE_PIN) | (1 << MR_PIN);
    PORTC &= ~((1 << OE_PIN) | (1 << MR_PIN));
}

// Shift out 8 bits of data to the shift registers in daisy chain
void shift_out_daisy_chain(uint8_t data1, uint8_t data2) {
    // Shift out the first 8 bits of data to the first shift register
    for (int i = 7; i >= 0; i--) {
        // Set the SER pin to the current bit of the data
        if ((data1 >> i) & 1) {
            PORTB |= (1 << SER_PIN);
        } else {
            PORTB &= ~(1 << SER_PIN);
        }
        // Pulse the SRCLK pin to shift the data bit into the shift register
        PORTB |= (1 << SRCLK_PIN);
        PORTB &= ~(1 << SRCLK_PIN);
    }
    // Shift out the second 8 bits of data to the second shift register
    for (int i = 7; i >= 0; i--) {
        // Set the SER pin to the current bit of the data
        if ((data2 >> i) & 1) {
            PORTB |= (1 << SER_PIN);
        } else {
            PORTB &= ~(1 << SER_PIN);
        }
        // Pulse the SRCLK pin to shift the data bit into the shift register
        PORTB |= (1 << SRCLK_PIN);
        PORTB &= ~(1 << SRCLK_PIN);
    }
    // Pulse the RCLK pin to latch the data in the registers
    PORTB |= (1 << RCLK_PIN);
    PORTB &= ~(1 << RCLK_PIN);
}

// Send a command to the LCD
void lcd_command(uint8_t cmd) {
    PORTC &= ~(1 << LCD_RS);        // RS = 0 for command
    PORTC &= ~(1 << LCD_RW);        // RW = 0 for write
    shift_out_daisy_chain(0x00, cmd);
    PORTC |= (1 << LCD_EN);         // EN = 1 to latch data
    _delay_us(1);
    PORTC &= ~(1 << LCD_EN);        // EN = 0
    _delay_us(100);
}

// Send data to the LCD
void lcd_data(uint8_t data) {
    PORTC |= (1 << LCD_RS);         // RS = 1 for data
    PORTC &= ~(1 << LCD_RW);        // RW = 0 for write
    shift_out_daisy_chain(0x00, data);
    PORTC |= (1 << LCD_EN);         // EN = 1 to latch data
    _delay_us(1);
    PORTC &= ~(1 << LCD_EN);        // EN = 0
    _delay_us(100);
}

// Initialize the LCD
void lcd_init() {
    // Initialize the shift register pins
    init_shift_register();
    // Initialize the CD4094 pins
    init_cd4094();
    // Wait for the LCD to power up
    _delay_ms(50);
    // Function Set: