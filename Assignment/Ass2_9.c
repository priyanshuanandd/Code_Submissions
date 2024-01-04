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
void insertat3()
{
    node *newnode = getnode();
    int i = 1;
    node *temp2;
    if (start == NULL)
    {
        printf("List Empty\n");
    }
    else
    {
        node *temp = start;
        while (i != 2)
        {
            temp = temp->next;
            i++;
        }
        temp2 = temp->next;
        temp->next = newnode;
        newnode->next = temp2;
    }
}
int main()
{
    int n;
    printf("Enter Length of Linked List");
    scanf("%d", &n);
    createlist(n);
    insertat3();// function required
    printlist();
}