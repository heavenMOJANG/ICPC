#include<reg51.h>
#include<absacc.h>
#define IN0 XBYTE[0x7ff8]
#define uchar unsigned char
uchar xdata *addz;
uchar pdata adcdata[8];
uchar i;
void main(void){
    IT1 = 1;
    EA = 1;
    EX1 = 1;
    i = 0;
    addz = &IN0;
    *addz = i;
    while(1);
}
void init1(void) interrupt 2{
    adcdata[i] = *addz;
    i ++;
    addz ++;
    if (i < 8) { *addz = i; }
    else { EA = 0; EX1 = 0; }
}