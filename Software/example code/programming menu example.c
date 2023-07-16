#include <avr/io.h>
#include <util/delay.h>

// Define the pin connections for the LCD
#define RS_PIN 0
#define EN_PIN 1
#define D4_PIN 2
#define D5_PIN 3
#define D6_PIN 4
#define D7_PIN 5

// Define the number of rows and columns of the LCD
#define ROWS 2
#define COLS 16

// Define the number of menu items and sub-menu items
#define NUM_MENU_ITEMS 3
#define NUM_SUB_ITEMS 3

// Define the command codes for the LCD
#define CLEAR_DISPLAY 0x01
#define RETURN_HOME 0x02
#define SET_CURSOR 0x80

// Define the menu structure
const char *menuItems[NUM_MENU_ITEMS] = {"Menu 1", "Menu 2", "Menu 3"};
const char *subItems[NUM_MENU_ITEMS][NUM_SUB_ITEMS] = {
  {"Sub-Item 1", "Sub-Item 2", "Sub-Item 3"},
  {"Sub-Item 4", "Sub-Item 5", "Sub-Item 6"},
  {"Sub-Item 7", "Sub-Item 8", "Sub-Item 9"}
};
int selectedItem = 0;
int selectedSubItem = 0;

void lcdCommand(unsigned char command) {
  // Send a command to the LCD
  PORTD &= ~(1 << RS_PIN);  // Set RS pin to LOW for commands
  PORTD |= (1 << EN_PIN);   // Set EN pin to HIGH
  PORTD = (PORTD & 0x3F) | ((command & 0xF0) >> 2);  // Send high nibble
  _delay_us(1);             // Wait for EN pin to settle
  PORTD &= ~(1 << EN_PIN);  // Set EN pin to LOW
  _delay_us(1);             // Wait for data to settle
  PORTD = (PORTD & 0x3F) | ((command & 0x0F) << 2);  // Send low nibble
  PORTD |= (1 << EN_PIN);   // Set EN pin to HIGH
  _delay_us(1);             // Wait for EN pin to settle
  PORTD &= ~(1 << EN_PIN);  // Set EN pin to LOW
  _delay_us(1);             // Wait for data to settle
}

void lcdData(unsigned char data) {
  // Send data to the LCD
  PORTD |= (1 << RS_PIN);   // Set RS pin to HIGH for data
  PORTD |= (1 << EN_PIN);   // Set EN pin to HIGH
  PORTD = (PORTD & 0x3F) | ((data & 0xF0) >> 2);  // Send high nibble
  _delay_us(1);             // Wait for EN pin to settle
  PORTD &= ~(1 << EN_PIN);  // Set EN pin to LOW
  _delay_us(1);             // Wait for data to settle
  PORTD = (PORTD & 0x3F) | ((data & 0x0F) << 2);  // Send low nibble
  PORTD |= (1 << EN_PIN);   // Set EN pin to HIGH
  _delay_us(1);             // Wait for EN pin to settle
  PORTD &= ~(1 << EN_PIN);  // Set EN pin to LOW
  _delay_us(1);             // Wait for data to settle
}

void lcdClear() {
  // Clear the display and return the cursor to the home position
  lcdCommand(CLEAR_DISPLAY);
  _delay_ms(2);
}

void lcdInit() {
  // Set the pin modes for the LCD
  DDRD |= (1 << RS_PIN) | (1 << EN_PIN) | (1 << D4_PIN) | (1 << D5_PIN) | (1 << D6_PIN) | (1 << D7_PIN);

  // Initialize the LCD and clear the display
  lcdCommand(0x28);  // Set data length, number of lines, and font
  lcdCommand(0x06);  // Set text direction and cursor increment
  lcdCommand(0x0C);  // Turn on display and cursor
  lcdClear();
}

void lcdPrint(const char *str) {
  // Print a null-terminated string to the LCD
  while (*str) {
    lcdData(*str++);
  }
}

void printMenuItem(int item) {
  // Print a menu item to the LCD
  lcdCommand(SET_CURSOR | 0);
  lcdPrint(menuItems[item]);
}

void printSubMenuItem(int item) {
  // Print a sub-menu item to the LCD
  lcdCommand(SET_CURSOR | (COLS + 1));
  lcdPrint(subItems[selectedItem][item]);
}

void updateMenu() {
  // Update the menu display on the LCD
  lcdClear();
  printMenuItem(selectedItem);
  printSubMenuItem(selectedSubItem);
}

void saveParameter() {
  // Save the selected sub-menu item parameter to memory
  // (Replace this with your own code to save the parameter)
  _delay_ms(10);
}

int main() {
  // Initialize the LCD and set up the menu
  lcdInit();
  updateMenu();

  // Main loop
  while (1) {
    // Check for button presses and update the selected menu item
    if (!(PINC & (1 << PC0))) {  // Button + pressed
      selectedSubItem = 0;
      selectedItem++;
      if (selectedItem >= NUM_MENU_ITEMS) {
        selectedItem = 0;
      }
      updateMenu();
    } else if (!(PINC & (1 << PC1))) {  // Button - pressed
      selectedSubItem = 0;
      selectedItem--;
      if (selectedItem < 0) {
        selectedItem = NUM_MENU_ITEMS - 1;
      }
      updateMenu();
    } else if (!(PINC & (1 << PC2))) {  // Button select pressed
      saveParameter();
      selectedSubItem++;
      if (selectedSubItem >= NUM_SUB_ITEMS) {
        selectedSubItem = 0;
      }
      printSubMenuItem(selectedSubItem);
    }
  }
  return 0;
}

/*

In this code snippet, the menu system is implemented using two arrays: menuItems for the main menu items, and subItems for the sub-menu items. The selectedItem and selectedSubItem variables keep track of which menu item and sub-menu item are currently selected.

The updateMenu function is called to update the LCD display with the current menu selection. The printMenuItem and printSubMenuItem functions are used to print the main menu item and sub-menu item to the LCD, respectively.

Button presses are checked in the main loop using the PINC register, which is connected to three push buttons (Button +, Button -, and Button Select). If Button + or Button - is pressed, the selectedItem variable is incremented or decremented, respectively, and the updateMenu function is called to update the LCD display. If Button Select is pressed, the saveParameter function is called to save the selected sub-menu item parameter to memory (replace this with your own code to save the parameter), and the selectedSubItem variable is incremented. If the selected sub-menu item is the last item in the list, it is wrapped around to the first item.

Note that this code assumes that the LCD is connected to the ATmega644 using a 4-bit mode interface, where the LCD data is sent using 4 data pins (D4-D7) instead of 8. If you are using an 8-bit mode interface, you will need to modify the lcdCommand and lcdData functions to send all 8 bits of the data.



*/