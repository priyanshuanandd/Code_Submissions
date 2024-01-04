#include <stdio.h>

int main()
{
    int n;
    printf("Enter length of number : ");
    scanf("%d", &n);
    char s[100];
    scanf("%s", &s);

    for (int i = 0; i < n / 2; i++)
    {

        if (s[i] != s[n - 1 - i])
        {

             printf("Isn't a palindrome\n");
            return 0;
        }
    }
    printf("Is a palindrome");
    return 0;
}