#include <stdio.h>
#include <stdlib.h>
typedef struct list node;
struct list
{
    int data;
    struct list *next;
};
node *start = NULL;
void last_node_address()
{
    node *temp = start;
    if (start = NULL)
    {
        printf("%x", &start);
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("%x", &temp);
    }
}

int main()
{
    last_node_address();
}