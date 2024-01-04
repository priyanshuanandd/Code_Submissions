#include <stdio.h>

#define len 6
int stack[len];

int top = 0;
void display()
{
    printf("\n");
    int i;
    if (top == 0)
    {
        printf("Empty\n");
    }
    else
    {
        for ( i = 0; i < top; i++)
        {
            printf("\t%d", stack[i]);
        }
    }
}
void pop()
{
    if (top == 0)
    {
        printf("Stack Underflow Condition\n");
    }
    else
    {
        printf("The Element popped is : %d", stack[--top]);
    }
}
void push()
{
    if (top == len)
    {
        printf("\nStack Overflow Condition\n");
    }
    else
    {
        int n;
        printf("Enter the data \n");
        scanf("%d", &n);
        stack[top] = n;
        top++;
        printf("%d has been pushed \n at position %d", n, top - 1);
    }
}

int main()
{
    push();
    push();
    display();
}