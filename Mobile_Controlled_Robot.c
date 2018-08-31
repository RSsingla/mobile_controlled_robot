// Project name 	: DTMF_CONTROLLED_ROBOT
// Designed By 		: Entrench Electronics
// Designed for		: Entrench Electronics
//                	  http://entrench.in

/* Program for "DTMF_CONTROLLED_ROBOT/Gets input from HT9170B DTMF decoder module connect on PB0, PD7, PD6, PD5" 
________________________________________________________________________________________________________________

Connection Settings of the Kit

LEDs---@------------->PB1
LEDs---@------------->PB2
LEDs---@------------->PB3
LEDs---@------------->PB4
Left Sensor---------->PC3
Right Sensor--------->PC0
DTMF D0-------------->PB0
DTMF D1-------------->PD7
DTMF D2-------------->PD6
DTMF D3-------------->PB5
RIGHT MOTOR(+)------->PB1
RIGHT MOTOR(-)------->PB2
LEFT MOTOR(-)-------->PB3
LEFT MOTOR(+)-------->PB4
BOOTLoader Condition Check----->PC5(If 0 bootloader section else program execution
							    section of Flash memory)
RESET-------------------------->PC6
Crystal Oscillator------------->PB6 and PB7
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/

#define F_CPU 12000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "Entrench.c"
int main(void)
{
int d=0;
int b=0;      
DDRB=0b00011110;  //PB1, PB2, PB3, PB4 as output bits connected to motors and PB0 as input bit connected to DTMF decoder IC
DDRD=0b00000000;  //PD7, PD6, PD5 connected to DTMF decoder IC hence input bits

while(1)          // infinite loop
{
b=PINB&0b00000001;
d=PIND&0b11100000; 


if(d==0b10000000 && b==0b00000000)          //if Key 2 of cell phone pressed
{
PORTB=0b00010010;    // move straight
}


if(d==0b01000000 && b==0b00000001)          // if Key 5 of cell phone pressed
{
PORTB=0b00000000;    //stop
}
}   //while closed
}   //main closed
