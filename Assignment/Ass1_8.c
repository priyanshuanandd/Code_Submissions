#include <stdio.h>
int i = 1;
void table(int n)
{

    int m = 1;

    m = n * i;
    printf("%d x %d = %d\n", n, i, m);
    i++;
    if (i != 11)
    {
        table(n);
    }
    else
    {
        i = 1;
    }
}
int main()
{
    int n;
    printf("Enter something: ");
    scanf("%d", &n);
    table(n);
    return 0;
}
