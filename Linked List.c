#include <stdio.h>
#include <stdlib.h>
typedef struct ll node;
struct ll
{
    int data;
    struct ll *next;
};
node *start = NULL;
// makes a newnode

void reverse_list()
{

    int i = 1;
    node *a = start;
    node *b = a->next;
    node *c = b->next;
    while (c != NULL)
    {
        if (i == 1)
        {
            a->next = NULL;
        }
        else
        {
            b->next = a;
            a = b;
            b = c;
            c = c->next;
        }
        i++;
    }
    b->next = a;
    start = b;
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
int countnode(node *loc)
{
    int cnt = 0;

    while (loc != NULL)
    {
        cnt++;
        loc = loc->next;
    }
    return cnt;
}

void insertatbeg()
{
    node *temp;
    temp = start;
    node *newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        start = newnode;
        newnode->next = temp;
    }
}
void insertatend()
{
    node *newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
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
void insertatpos()
{

    node *temp = start;
    node *prev;
    printf("\n Enter the Location : ");

    int n;
    scanf("%d", &n);
    node *newnode = getnode();
    int i;
    for (i = 0; i < n - 1; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = newnode;
    newnode->next = temp;
}
void delatbeg()
{
    if (start == NULL)
    {
        printf("THE LIST IS EMPTY \n");
    }
    else
    {
        node *temp = start;
        start = start->next;
        free(temp);
    }
}
void delatend()
{

    if (start == NULL)
    {
        printf("THE LIST IS EMPTY \n");
    }
    else
    {
        node *temp = start;
        node *prev = start;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}
void delatpos()
{
    node *temp = start;
    node *prev;
    int pos;
    int i;
    printf("Enter Position : ");
    scanf("%d", &pos);
    for (i = 0; i < pos - 1; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}
void revprint_ll(node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        revprint_ll(ptr->next);
        printf("%d ->", ptr->data);
    }
}
void sumofll()
{
    int x = 0;
    node *temp = start;
    while (temp != NULL)
    {
        printf("%d", x);
        int x = x + temp->data;
    }
    printf("%d", x);
}
int main()
{
    createlist(4);
    //  insertatpos();
    // insertatbeg();
    // insertatend();
    //  delatbeg();
    // delatend();
    // delatpos();
    print_ll(start);
    reverse_list();
    print_ll(start);
    sumofll();
    // last_node_address();
    // printf("\n count is : %d", countnode(start));

    return 0;
}