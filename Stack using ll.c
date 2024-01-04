#include <stdio.h>
#include <stdlib.h>
struct stacki
{
    int data;
    struct list *next;
};

typedef struct stacki stack;
stack *top = NULL;
void create(stack **top)
{
    *top = NULL;
}
int pop(stack *top)
{
    int t;
    stack *ptr;
    if (top == NULL)
    {
        printf("\n Stack is empty");
        exit(-1);
    }
    else
    {
        t = (top)->data;
        ptr = top;
        top = top->next;
        free(ptr);
        return t;
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
        return 0;
    }
}
void push(stack *top, int element)
{
    stack *new;
    new = (stack *)malloc(sizeof(stack));
    if (new == NULL)
    {
        printf("\n Stack is full");
        exit(—1);
    }
    new->data = element;
    new->next = top;
    top = new;
}
int main()
{
    stack *A, *B;
    create(&A);
    create(&B);
    push(&A, 10);
    printf("%d", pop(&A));
}