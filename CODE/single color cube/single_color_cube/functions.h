void setLED(uint8_t x, uint8_t y, uint8_t z,uint8_t p){

    int D = (x/3);
    int R = (x/4);
    if (x==2) R = 1;
    switch(z){

        case 1:
            bitWrite(LEDS0[(0 + D)],((y-1)+4*(R)),(p & 0x01) >> 0);
            bitWrite(LEDS1[(0 + D)],((y-1)+4*(R)),(p & 0x02) >> 1);
            bitWrite(LEDS2[(0 + D)],((y-1)+4*(R)),(p & 0x04) >> 2);
            bitWrite(LEDS3[(0 + D)],((y-1)+4*(R)),(p & 0x08) >> 3);
            break;

        case 2:
            bitWrite(LEDS0[(2 + D)],((y-1)+4*(R)),(p & 0x01) >> 0);
            bitWrite(LEDS1[(2 + D)],((y-1)+4*(R)),(p & 0x02) >> 1);
            bitWrite(LEDS2[(2 + D)],((y-1)+4*(R)),(p & 0x04) >> 2);
            bitWrite(LEDS3[(2 + D)],((y-1)+4*(R)),(p & 0x08) >> 3);
            break;

        case 3:
            bitWrite(LEDS0[(4 + D)],((y-1)+4*(R)),(p & 0x01) >> 0);
            bitWrite(LEDS1[(4 + D)],((y-1)+4*(R)),(p & 0x02) >> 1);
            bitWrite(LEDS2[(4 + D)],((y-1)+4*(R)),(p & 0x04) >> 2);
            bitWrite(LEDS3[(4 + D)],((y-1)+4*(R)),(p & 0x08) >> 3);
            break;

        case 4:
            bitWrite(LEDS0[(6 + D)],((y-1)+4*(R)),(p & 0x01) >> 0);
            bitWrite(LEDS1[(6 + D)],((y-1)+4*(R)),(p & 0x02) >> 1);
            bitWrite(LEDS2[(6 + D)],((y-1)+4*(R)),(p & 0x04) >> 2);
            bitWrite(LEDS3[(6 + D)],((y-1)+4*(R)),(p & 0x08) >> 3);
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
    if(p > 15) p=15;
    if(p > 200) p=0;
    setLED(x,y,z,p);

}

void Cube_Clear(){
    for(int i = 0; i < BYTES_P_PLANE * LEDS_SINGLE_AXIS; i++){
        LEDS0[i] = 0;
        LEDS1[i] = 0;
        LEDS2[i] = 0;
        LEDS3[i] = 0;
    }
}