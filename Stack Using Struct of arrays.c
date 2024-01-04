#include <stdio.h>
#define maxsize 100
struct lifo
{
    int arr[maxsize];
    int top;
};
typedef struct lifo stack;
stack s;
void createstack(stack *s)
{
    s->top = -1;
}
void push(stack *s, int element) 1
{
    if (s->top == maxsize - 1)
    {
        printf("full\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = element;
    }
}
int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Underflow");
    }
    else
    {
        return (s->arr[s->top--]);
    }
}

int main()
{
    stack a, b;
    create(&a);
    create(&b);

    return 0;
}