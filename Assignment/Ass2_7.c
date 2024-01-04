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
void insertatbeg()
{
    node *newnode = getnode();
    node *temp = sta
    rt;
    start = newnode;
    newnode->next = temp;
}

void insertatend()
{
    node *newnode = getnode();
    node *temp;
    temp = start;

    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
int main()
{
    insertatbeg();
    insertatend();
}