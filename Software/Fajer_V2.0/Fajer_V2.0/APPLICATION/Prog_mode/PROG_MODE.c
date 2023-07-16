/*
 * PROG_MODE.c
 *
 * Created: 4/22/2023 8:42:08 AM
 *  Author: Ahmed Adel
 */ 
 #include "./PROG_MODE.h"

 void doorMode(void){
     //display name of function in line 1 and parameter value in line 2
	 //this function has 3 option for now (normal door, automatic door, semi automatic door)
	 //after selecting value save it in eeprom
	 lcd_command(0x80);
	 lcd_string("Door Mode");
	 while(1){
		if(!(PINA & (1 << plus)))
		{
			lcd_command(0xc0);
			
			lcd_string("Auto");
			if(!(PINA & (1 << Enter)))
			{
				break;
			}
			
		};
	 }
 }
 void displayType(void){
	//display name of function in line 1 and parameter value in line 2 
	//this function has 2 option for now (7 segment, binary)
 }
 void lightTimer(void){
	//display name of function in line 1 and parameter value in line 2
	//this function set value to light timer from 0 to 60 sec
 }
 void doorNumber(void){
	//display name of function in line 1 and parameter value in line 2
	//this function set number of door in use
 }
 void callCollective(void){
	//display name of function in line 1 and parameter value in line 2
	//this function set number of door in use
 }
 void inspSpeed(void){
	 //display name of function in line 1 and parameter value in line 2
	 //this function set elevator speed in inspection speed
 }
 //missing programming function here // p6
 void dopTimer(void){
	//display name of function in line 1 and parameter value in line 2
	//this function set opening door time valid in automatic door only
 }
 void dclTimer(void){
	 //display name of function in line 1 and parameter value in line 2
	 //this function set closing door time valid in automatic door only
 }
 void waitTimer(void){
	 //display name of function in line 1 and parameter value in line 2
	 //this function set time between stop time and another call response
 }
 void slowTimer(void){
	 //display name of function in line 1 and parameter value in line 2
	 //this function set time to run in slow speed without level sensor is active
 }
 void fastTimer(void){
	 //display name of function in line 1 and parameter value in line 2
	 //this function set time to run in fast speed without counting signal is active 
 }
 void lockError(void){
	 //display name of function in line 1 and parameter value in line 2
	 //this function set lock checking error enable or disable
 }
 void camTimer(void){
	 //display name of function in line 1 and parameter value in line 2
	 //this function set time to active cam to get lock signal active 
 }
 void camTrials(void){
	 //display name of function in line 1 and parameter value in line 2
	 //this function set number of trials without getting error
 }
 void timeOut(void){
	 //display name of function in line 1 and parameter value in line 2
	 //this function set timer to turn elevator out of service
 }
 void setPassword(void){
	 //display name of function in line 1 and parameter value in line 2
	 //this function set password to board to access the programming
 }
 void correction(void){
	 //display name of function in line 1 and parameter value in line 2
	 //this function set auto correction after power on
 }
//function to select which parameter to change value
void parameterSelect(uint8_t pSelect){
	switch(pSelect)
	{
		case 0:
		doorMode();
		break;
		case 1:
		displayType();
		break;
		case 2:
		lightTimer();
		break;
		case 3:
		doorNumber();
		break;
		case 4:
		callCollective();
		break;
		case 5:
		inspSpeed();
		break;
		case 6:
		break;
		case 7:
		dopTimer();
		break;
		case 8:
		dclTimer();
		break;
		case 9:
		waitTimer();
		break;
		case 10:
		slowTimer();
		break;
		case 11:
		fastTimer();
		break;
		case 12:
		lockError();
		break;
		case 13:
		camTimer();
		break;
		case 14:
		camTrials();
		break;
		case 15:
		timeOut();
		break;
		case 16:
		setPassword();
		break;
		case 17:
		correction();
		break;
	}
}
 
 void program(void){

	char Program_list[20][16] = { "Door Mode", //0
	                              "Display Type", //1
								  "Light Time", //2
								  "Door Number",  //3
								  "Call Collective", //4
								  "Insp Speed", //5
								  "Reserved",     //6
								  "Dop Timer",    //7
								  "Dcl Timer",    //8
								   "Wait Timer",    //9
								   "Slow Timer",    //10
								   "Fast Timer",    //11
								   "Lock Error",    //12
								   "Cam Timer",    //13
								   "Cam Trials",     //14
								   "Time Out",     //15
								   "Set Password",   //16
								   "Correction",};   //17



	// display "programming"
	lcd_command(0x80); // Set cursor at the beginning of the first line
	lcd_string("  >Programming<"); // Display a string on the LCD
	//check if have password then display password entry 
	lcd_command(0xc0);
	lcd_string("press (+)");
	
	
	while(1)
	{
		//check if plus is pressed change menu forward
		if(!(PINA & (1 << plus)))
		{
			lcd_command(0xc0);  //set cursor to second line
			lcd_string("                ");//to clear one row
			_delay_ms(500);
			p++;
			
			if (p > 17)
			{
				p = 0;
			}
		//check if mins is pressed change menu backward
		}else if(!(PINA & (1 << mins)))
		{
			lcd_command(0xc0);  //set cursor to second line
			lcd_string("                ");  //to clear one row
			_delay_ms(500);
			p--;
			if (p < 0 || p > 17)
			{
				p = 17;
			}
		
		}
		if(!(PINA & (1 << Enter)))
		{
			lcd_command(0x80);
			lcd_string("                ");
			lcd_command(0xc0);
			lcd_string("                ");
			parameterSelect(p);
		}
		lcd_command(0x80); // Set cursor at the beginning of the first line
		lcd_string("  >Programming<"); // Display a string on the LCD
		lcd_command(0xc0);//set cursor to second line
		lcd_string(Program_list[p]);

	}
	
	//show next parameter and if + goto next if enter display internal value
	//first idea is make function for each parameter
	
	
 }