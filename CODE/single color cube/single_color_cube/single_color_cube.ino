#include "mux.h"
#include "functions.h"


void setup() {
  cube_init();
}

void loop() {

  for(int x=1;x<5;x++){
    for(int y=1;y<5;y++){
      for(int z=1;z<5;z++){
        setLED(x,y,z,1);
        delay(250);
      }
    }
  }

for(int x=1;x<5;x++){
    for(int y=1;y<5;y++){
      for(int z=1;z<5;z++){
        setLED(x,y,z,0);
        delay(250);
      }
    }
  }
}
