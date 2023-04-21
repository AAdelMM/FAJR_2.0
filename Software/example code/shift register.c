 // Define pins
 #define SR_CLK_PIN PD6
 #define SR_DATA_PIN PD5
 #define SR_LATCH_PIN PD7

 // Function to shift out a byte to the shift register
 void shiftOut(uint8_t data) {
	 // Shift out the data byte
	 for (uint8_t i = 0; i < 8; i++) {
		 if (data & (1 << i)) {
			 PORTD |= (1 << SR_DATA_PIN);
			 } else {
			 PORTD &= ~(1 << SR_DATA_PIN);
		 }
		 
		 PORTD |= (1 << SR_CLK_PIN);
		 PORTD &= ~(1 << SR_CLK_PIN);
	 }
	 
	 // Set latch pin high
	 PORTD |= (1 << SR_LATCH_PIN);
 }

 int main() {
	 // Initialize pins
	 DDRD |= (1 << SR_CLK_PIN) | (1 << SR_DATA_PIN) | (1 << SR_LATCH_PIN);
	 
	 // Write some data to the shift register
	 shiftOut(0b10101010);
	 
	 // Wait a bit
	 _delay_ms(1000);
	 
	 // Write some more data to the shift register
	 shiftOut(0b01010101);
	 
	 // Wait a bit
	 _delay_ms(1000);
	 
	 // Reset the output
	 PORTD &= ~(1 << SR_LATCH_PIN);
	 shiftOut(0x00);
	 PORTD |= (1 << SR_LATCH_PIN);
	 
	 while (1) {
		 // Main loop
		  // Write some data to the shift register
		  for(int j=0 ; j <=63; j++){
			shiftOut(j);
			_delay_ms(1000);
		  }
		  shiftOut(2);
		  
		  // Wait a bit
		  _delay_ms(1000);
		  
		  // Write some more data to the shift register
		  shiftOut(0b01010101);
		  
		  // Wait a bit
		  _delay_ms(1000);
	 }
	 
	 return 0;
 }


 