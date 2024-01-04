#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        printf("Divisible by 2\n");
    }
    else
    {
        printf("Not Divisible by 2\n");
    }
    if (n % 3 == 0)
    {
        printf("Divisible by 3\n");
    }
    else
    {
        printf("Not Divisible by 3\n");
    }
    if (n % 5 == 0)
    {
        printf("Divisible by 5\n");
    }
    else
    {
        printf("Not Divisible by 5\n");
    }
}