#include "mux.h"



void setup() {
  cube_init();
}

void loop() {

bitWrite(LEDS[0],0,1);
bitWrite(LEDS[2],5,1);
bitWrite(LEDS[5],2,1);
bitWrite(LEDS[7],7,1);
delay(1000);

bitWrite(LEDS[0],0,0);
bitWrite(LEDS[2],5,0);
bitWrite(LEDS[5],2,0);
bitWrite(LEDS[7],7,0);

bitWrite(LEDS[1],0,1);
bitWrite(LEDS[3],5,1);
bitWrite(LEDS[4],2,1);
bitWrite(LEDS[6],7,1);

delay(1000);
}
