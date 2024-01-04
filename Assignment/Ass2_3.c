#include <stdio.h>

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n, m;
    printf("Enter Positions in ascending order :\n ");

    scanf("%d %d", &n, &m);

    int a, b;
    printf("Enter Numbers : \n");
    scanf("%d %d", &a, &b);

    int arr2[11];

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cnt++;
        arr2[i] = arr[i];
    }
    arr2[n - 1] = a;

    for (int i = n; i < m - 1; i++)
    {
        cnt++;
        arr2[i] = arr[i - 1];
    }

    arr2[m - 1] = b;

    for (int i = cnt; i < (sizeof(arr) / 4); i++)
    {
        arr2[i + 2] = arr[i];
    }

    for (int i = 0; i < 11; i++)
    {
        printf("%d ", arr2[i]);
    }
}