#include <stdio.h>
#include <stdlib.h>
typedef struct list node;
struct list
{
    int data;
    node *next;
};

node *start = NULL;
node *getnode()
{
    node *newnode = (node *)malloc(sizeof(node));
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

void createlist(int n)
{
    node *newnode = getnode();
    node *temp = start;
    while (n--)
    {
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            while (temp->next == NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void reverse_list()
{
    int i = 0;
    node *one = start;
    node *two = one->next;
    node *three = two->next;

    while (three != NULL)
    {
        if (i == 1)
        {
            one->next = NULL;
        }
        else
        {
            two->next = one;
            one = two;
            two = three;
            three = three->next;
        }
        i++;
    }
    two->next = one;
    start = two;
}
void print_ll()
{
    node *temp;
    temp = start;
    if (start == NULL)
    {
        printf("The List is Empty");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
    }
    printf("x \n");
}
int main()
{
    createlist(5);
    print_ll();
    reverse_list();
    print_ll();
}
