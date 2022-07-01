#include <SPI.h>
#include "config.h"
//SPI settings
SPISettings SETTINGS(CLKSPD,MSBFIRST,SPI_MODE0);


//array
volatile uint8_t LEDS[8];
//every 2 index's is a single layer thus indexs 0 & 1 are layer one and etc


// setting up the MUX interrupt
IntervalTimer MUX;



void mux(){
    static uint8_t Layer = 0;
    //static uint8_t N = 1;


    digitalWrite(OE,HIGH);//turn off output
    SPI.transfer(0x08 >> Layer);
    //SPI.transfer(0x01 << Layer);

        switch(Layer){
            case 0:
                SPI.transfer(LEDS[1]);
                SPI.transfer(LEDS[0]);
                break;
            
            case 1:
                SPI.transfer(LEDS[3]);
                SPI.transfer(LEDS[2]);
                break;
            
            case 2:
                SPI.transfer(LEDS[5]);
                SPI.transfer(LEDS[4]);
                break;

            case 3:
                SPI.transfer(LEDS[7]);
                SPI.transfer(LEDS[6]);
                break;


        }

    digitalWrite(RCLK,HIGH);
    digitalWrite(RCLK,LOW);
    digitalWrite(OE,LOW);

    Layer++;

    if(Layer >= LEDS_SINGLE_AXIS){
        Layer = 0;
    }

}




void cube_init(){



    pinMode(OE,OUTPUT);
    pinMode(RCLK,OUTPUT);
    pinMode(SRCLR,OUTPUT);
    pinMode(BUTTON,INPUT);
    digitalWrite(OE,LOW);
    digitalWrite(SRCLR,HIGH);



    for(int i = 0; i < BYTES_P_PLANE * LEDS_SINGLE_AXIS; i++){
        LEDS[i] = 0;
    }

    MUX.begin(mux,4000);

    SPI.begin(); //start up the SPI library
    SPI.setBitOrder(MSBFIRST); //Most Significant Bit First
    SPI.setDataMode(SPI_MODE0); // Mode 0 Rising edge of data, keep clock low
    SPI.setClockDivider(SPI_CLOCK_DIV2); //Run the data in at 16MHz/2 - 8MHz
    digitalWrite(RCLK,LOW);
    //SPI.usingInterrupt(mux);
    interrupts();
}




