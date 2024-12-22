#define COUNT 5000
unsigned msec_count = 0;
unsigned usect0_count = 4;

void timer0ISR(void) org 0x000B
{
    usect0_count--;
    if (usect == 0)
    {
        msec_count--;
        usect0_count = 4;
    }
    TL0 = 0xBE;
    TH0 = 0xFC;
    if (msec_count == 0)
    {

        msec_count = COUNT;
        P3_6_bit = ~P3_6_bit;
    }
    return;
}

void main(void)
{
    CLKREG = 0 ;
    TR0_bit = 0;
    TMOD = 0x01;
    TL0 =0xBE;

    TH0 = 0xFC;
    msec_count = COUNT;

    EA_bit = 1;
    ET0_bit = 1;
    TR0_bit = 1;
    while(1);
}