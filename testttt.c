#include <stdio.h>

int func(int * n)
{
    *n = 5;
    printf("\n%d\n", *n);
}

int main()
{
    int n = 2;
    printf("%d", n);
    func(&n);
    printf("%d", n);
    int * k = &n;
    int ** l= &k
}
