unsigned count = 0;
void external0ISR(void) org 0x0003
{
    unsigned char i = 0;
    count++;
    P2 = ~count;
    for (i = 0; i < 64; i++);
    return;
}

void external0ISR(void) org 0x0003
{
    unsigned char i = 0;
    count--;
    P2 = ~count;
    for (i = 0; i < 64; i++);
    return;
}
void main(void)
{
    EA_bit = 1;
    IT0_bit = 1;
    IT1_bit = 1;
    EX0_bit = 1;
    EX1_bit = 1;
    while (1)
        ;
}