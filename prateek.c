#include <stdio.h>
unsigned char lookup_7seg[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
unsigned char display_code[] = {0x99, 0xb0, 0xa4, 0xf9};
unsigned int display_value = 1122;
void transfer_display_code()
{
    unsigned char i, j;
    for (i = 0; i < 4; i++)
    {
        j = display_value % 10;
        display_code[i] = lookup_7seg[j];

        display_value /= 10;
    }
    return;
}
void display_data(void)
{
    unsigned char i, j;
    while (1)
    {
        j = 1;
        for (i = 0; i < 4; i++)
        {
            P0 = display_code[i];
            P1 = j;
            delay_ms(10);
            j = j << 1;
        }
    }
    return;
}
int test_key()
{
    //tests the key P2.0 return 1 if P2.0 is pressed else returns 0;
    P2_0_bit = 1;

    if(P2_0_bit == 0 ) return 1;
    else return 0;
}
void main()
{
    display_value = 1234;
    transfer_display_code();
    display_data();
}