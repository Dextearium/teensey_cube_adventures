#include <SPI.h>
#include "config.h"
//SPI settings
SPISettings SETTINGS(CLKSPD,MSBFIRST,SPI_MODE0);


//array
volatile uint8_t LEDS0[8];
volatile uint8_t LEDS1[8];
volatile uint8_t LEDS2[8];
volatile uint8_t LEDS3[8];
//every 2 index's is a single layer thus indexs 0 & 1 are layer one and etc


// setting up the MUX interrupt
IntervalTimer MUX;



void mux(){
    static uint8_t Layer = 0;
    static uint8_t i = 1;

    digitalWrite(OE,HIGH);//turn off output
    SPI.transfer(0x08 >> Layer);

    if(i>7){
        switch(Layer){
            case 0:
                SPI.transfer(LEDS3[1]);
                SPI.transfer(LEDS3[0]);
                break;
            case 1:
                SPI.transfer(LEDS3[3]);
                SPI.transfer(LEDS3[2]);
                break;
            case 2:
                SPI.transfer(LEDS3[5]);
                SPI.transfer(LEDS3[4]);
                break;
            case 3:
                SPI.transfer(LEDS3[7]);
                SPI.transfer(LEDS3[6]);
                break;
        }
    }
    else if(i>3){
        switch(Layer){
            case 0:
                SPI.transfer(LEDS2[1]);
                SPI.transfer(LEDS2[0]);
                break;            
            case 1:
                SPI.transfer(LEDS2[3]);
                SPI.transfer(LEDS2[2]);
                break;
            case 2:
                SPI.transfer(LEDS2[5]);
                SPI.transfer(LEDS2[4]);
                break;
            case 3:
                SPI.transfer(LEDS2[7]);
                SPI.transfer(LEDS2[6]);
                break;
        }
    }
    else if(i>1){
        switch(Layer){
            case 0:
                SPI.transfer(LEDS1[1]);
                SPI.transfer(LEDS1[0]);
                break;
            
            case 1:
                SPI.transfer(LEDS1[3]);
                SPI.transfer(LEDS1[2]);
                break;
            
            case 2:
                SPI.transfer(LEDS1[5]);
                SPI.transfer(LEDS1[4]);
                break;

            case 3:
                SPI.transfer(LEDS1[7]);
                SPI.transfer(LEDS1[6]);
                break;
        }
    }
    else{
        switch(Layer){
            case 0:
                SPI.transfer(LEDS0[1]);
                SPI.transfer(LEDS0[0]);
                break; 
            case 1:
                SPI.transfer(LEDS0[3]);
                SPI.transfer(LEDS0[2]);
                break;
            case 2:
                SPI.transfer(LEDS0[5]);
                SPI.transfer(LEDS0[4]);
                break;
            case 3:
                SPI.transfer(LEDS0[7]);
                SPI.transfer(LEDS0[6]);
                break;
        }
    }


    digitalWrite(RCLK,HIGH);
    digitalWrite(RCLK,LOW);
    digitalWrite(OE,LOW);

    Layer++;
    i++;

    if(i == 16){
        i = 1;
    }

    if(Layer == LEDS_SINGLE_AXIS){
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
        LEDS0[i] = 0;
        LEDS1[i] = 0;
        LEDS2[i] = 0;
        LEDS3[i] = 0;
    }

    MUX.begin(mux,300);

    SPI.begin(); //start up the SPI library
    SPI.setBitOrder(MSBFIRST); //Most Significant Bit First
    SPI.setDataMode(SPI_MODE0); // Mode 0 Rising edge of data, keep clock low
    digitalWrite(RCLK,LOW);
    //SPI.usingInterrupt(mux);
    interrupts();
}




