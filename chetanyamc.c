#include <stdio.h>
#include <stdlib.h>

struct lifo
{
    int value;
    struct lifo *next;
};
typedef struct lifo stack;

stack *top;

void create(stack **top)
{

    *top = NULL;
}

void push(stack *top, int n)
{
    if (top == NULL)
    {
        printf("\nstack overflow");
    }
    else
    {
        stack *new;
        new = (stack *)malloc(sizeof(stack));
        new->value = n;
        new->next = top;
        top = new;
    }
}

int pop(stack *top)
{
    int t;
    stack *ptr;

    if (top == NULL)
    {
        printf("\n the stack is empty");
        return -1;
    }
    else
    {
        t = top->value;
        ptr = top;
        ptr = ptr->next;
        return t;
        free(ptr);
    }
}

int isempty(stack *top)
{
    if (top == NULL)
    {
        return (1);
    }

    else
    {
        return (0);
    }
}

void peek(stack *top)
{
    if (top == NULL)
    {
        printf("\n the stack is empty");
    }
    else
    {
        int a;
        a = top->value;
        printf("the element at the top is:%d", a);
    }
}

void display(stack *top)
{
    if (top == NULL)
    {
        printf("\n the stack is empty");
    }
    else
    {
        stack *temp;
        temp = top;
        while (temp != NULL)
        {
            printf(" %d", temp->value);
            temp = temp->next;
        }
    }
}

int main()
{
    stack a;
    create(&a);
    push(&a, 1);
    push(&a, 2);
    display(&a);
}