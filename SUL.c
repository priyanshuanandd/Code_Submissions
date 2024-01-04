#include <stdio.h>
#include <stdlib.h>
typedef struct stuck stack;
struct stuck
{
    int data;
    stack *next;
};

stack *top;

void create(stack **top)
{
    *top = NULL;
}
