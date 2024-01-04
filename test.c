#include <stdio.h>
struct test
{
    int data;
    struct test *next;
    /* data */
};
struct test *start = NULL;

int main()
{
    int x =5;
    int * y = &x;
    printf("%x",&y);
}