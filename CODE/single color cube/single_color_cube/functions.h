void setLED(uint8_t x, uint8_t y, uint8_t z,uint8_t p){

    int D = (x/3);
    int R = (x/4);
    if (x==2) R = 1;
    switch(z){

        case 1:
            bitWrite(LEDS[(0 + D)],((y-1)+4*(R)),p);
            break;

        case 2:
            bitWrite(LEDS[(2 + D)],((y-1)+4*(R)),p);
            break;

        case 3:
            bitWrite(LEDS[(4 + D)],((y-1)+4*(R)),p);
            break;

        case 4:
            bitWrite(LEDS[(6 + D)],((y-1)+4*(R)),p);
            break;
    }
}


void lim_setLED(uint8_t x, uint8_t y, uint8_t z,uint8_t p){

    if(x < 1) x++;
    if(y < 1) y++;
    if(z < 1) z++;
    if(x > 4) x=(x%4)+1;
    if(y > 4) y=(y%4)+1;
    if(z > 4) y=(z%4)+1;
    if(p > 1) p=1;
    setLED(x,y,z,p);

}