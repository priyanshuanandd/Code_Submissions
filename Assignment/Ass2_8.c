#include <stdio.h>
#include <stdlib.h>
typedef struct list node;
struct list
{
    int data;
    struct list *next;
};
node *start = NULL;
node *getnode()
{

    node *newnode = (node *)malloc(sizeof(node));
    printf("Enter the data for the node : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
}
node *createlist(int n)
{

    while (n--)
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
}
void printlist()
{

    if (start == NULL)
    {
        printf("x");
    }
    else
    {
        node *ptr = start;
        while (ptr != NULL)
        {
            printf("%d ->", ptr->data);
            ptr = ptr->next;
        }
        printf("x\n");
    }
}
void delatbeg()
{
    if (start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        node *temp = start;
        start = start->next;
        free(temp);
    }
}

void delatmid(int n)
{
    if (n % 2 != 0)
    {
        n = n / 2 + 1;
    }
    else
    {
        n = n/2;
    }
    int i = 1;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *temp = start;
        node *prev;
        while (i != n)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        free(temp);
    }
}
int main()
{
    int n;
    printf("Enter Length of Linked List");
    scanf("%d", &n);
    createlist(n);
    // deleting first and middle node
    printlist();
    // delatbeg();
    delatmid(n);
    printlist();
}