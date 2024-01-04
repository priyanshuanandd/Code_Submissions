#include <stdio.h>
#include <stdlib.h>
typedef struct ll node;
struct ll
{
    int data;
    struct ll *next;
};
node *start = NULL;

void reverse_list()
{
    int i = 1;
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
node *getnode()
{
    node *newnode = (node *)malloc(sizeof(node));
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}
void createlist(int n)
{
    int i = 0;
    node *temp;
    for (i = 0; i < n; i++)
    {
        node *newnode = getnode();

        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
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

void addatfront(node *s, node *t)
{
    node *sback;
    node *tfront;
    node *temp = start;
    while (temp->next != s)
    {

        temp = temp->next;
    }
    sback = temp;

    node *prev;

    prev = temp;
    while (prev != t)
    {
        prev = temp;
        temp = temp->next;
    }

    tfront = temp;
    temp = start;
    sback->next = tfront;
    start = s;
    t->next = temp;
}

void addatback(node *s, node *t)
{
    node *sback;
    node *tfront;
    node *temp = start;
    while (temp->next != s)
    {

        temp = temp->next;
    }
    sback = temp;

    node *prev;

    prev = temp;
    while (prev != t)
    {
        prev = temp;
        temp = temp->next;
    }
    tfront = temp;

    sback->next = tfront;
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = s;

    t->next = NULL;
}

node *search(int n)
{
    node *temp = start;
    while (temp->data != n)
    {
        temp = temp->next;
    }
    return temp;
}
int main()
{
    createlist(10);
    // print_ll();f

    reverse_list();
    print_ll();

    backofnode(search(2), search(5));
    print_ll();
}