#include <stdio.h>

int bubble_sort(int a[], int n)
{
    for (int times = 1; times <= n - 1; times++)
    {
        for (int j = 0; j <= n - times - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }
}
void Print_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return;
}

int main()
{
    int arr[8] = {1, 2, 3, 6, 7, 8, 9, 0};
    int brr[9] = {4, 5, 6, 5, 4, 6, 7, 5, 3};
    int crr[(sizeof(arr) + sizeof(brr)) / 4];
    bubble_sort(arr, sizeof(arr) / 4);
    bubble_sort(brr, sizeof(brr) / 4);
    for (int i = 0; i < (sizeof(arr) + sizeof(brr)) / 4; i++)
    {
        if (i <= (sizeof(arr) / 4) - 1)
        {
            crr[i] = arr[i];
        }
        if (i > (sizeof(arr) / 4) - 1)
        {
            crr[i] = brr[i - sizeof(arr) / 4];
        }
    }
    Print_array(crr, (sizeof(arr) + sizeof(brr)) / 4);
}