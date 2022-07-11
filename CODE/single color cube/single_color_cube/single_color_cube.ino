#include "mux.h"
#include "functions.h"


void setup() {
  cube_init();
}

void loop() {

  for(int x=1;x<5;x++){
    for(int y=1;y<5;y++){
      for(int z=1;z<5;z++){
        lim_setLED(x,y,z,8);
        delay(100);
      }
    }
  }

  for(int z=1;z<5;z++){
    for(int y=1;y<5;y++){
      for(int x=1;x<5;x++){
        lim_setLED(x,y,z,16);
        delay(100);
      }
    }
  }


for(int i=0;i<5;i++){
  
  
  for(int z=4;z>0;z--){
    for(int y=1;y<5;y++){
      for(int x=1;x<5;x++){
        lim_setLED(x,y,z,2);
      }
    }
    delay(100);
  }

  for(int z=1;z<5;z++){
    for(int y=1;y<5;y++){
      for(int x=1;x<5;x++){
        lim_setLED(x,y,z,1);
        
      }
    }
    delay(100);
  }
}


  Cube_Clear();
  delay(500);
}
