void delay_msec(unsigned msec_count)
{

    unsigned i = 0;
    TMOD = 0x01;
    TF0_bit = 0;
    for (i = 0; i < msec_count; i++)
    {
        TL0 = 0xBE;
        TH0 = 0xfc;
        TR0_bit = 1;
        while (TF0_bit == 0)
            ;
        TR0_bit = 0;
        TF0_bit = 0;
    }

    return;
}
void delay_msec2(unsigned msec_count)
{

    unsigned i = 0;
    TMOD = 0x02;
    TF0_bit = 0;
    TH0 = 0x30;
    TR0_bit = 1;
    while (msec_count-- > 0)
    {
        for (i = 0; i < 4; i++)
        {
            while (TF0_bit == 0)
                ;
            TF0_bit = 0;
        }
    }
}
void main()
{
    CLKREG = 1;
    while (1)
    {
        delay_msec2(500);
        P3_6_bit = ~P3_6_bit;
    }
}