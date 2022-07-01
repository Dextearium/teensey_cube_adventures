//Sets up all of the varables for the pinouts
int OE = 14;//Output Enable LOW = ON
int RCLK = 17;// stores registers when rising (acts as chip select)
int SRCLR = 16;//clears shift register when low
int BUTTON = 18;//button pin

//Constants
int CLKSPD = 20000000; // the clock speed of the SPI transfer
int LEDS_SINGLE_AXIS = 4;
int LEDS_P_LAYER = (LEDS_SINGLE_AXIS * LEDS_SINGLE_AXIS);
int LEDS_TOTAL = (LEDS_SINGLE_AXIS * LEDS_SINGLE_AXIS * LEDS_SINGLE_AXIS);
int BYTES_P_PLANE = (LEDS_P_LAYER / 8);

/*
Output information

LEDS order in output 
1 is the LSB 
Bottom left is (0,0)
   X X X X    4 8 12 16
   X X X X    3 7 11 15
   X X X X    2 6 10 14
   X X X X    1 5 9  13


The Planes start after the LEDs
The Top plane is bit 17
The Third is 18
The Second is 19
And the First is 20

The first 4 bits are Unused

Thus the output looks like 
 XXXX      0000      0000 0000 0000 0000
 Useless   Planes            LEDS
*/









