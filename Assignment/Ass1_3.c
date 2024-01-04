#include <stdio.h>
int sum(int n)
{
    int i;
    int s = n, m = n;
    for (i = 1; i < n; i++)
    {
        m = m * n * n;
        s = s + m;
    }
    return s;
}
int main()
{
    int n;
    scanf("%d", &n);
    int k = sum(n);
    printf("%d", k);
    return 0;
}