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
void printlist(node *ptr)
{
    if (ptr == NULL)
    {
        printf("x");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ->", ptr->data);
            ptr = ptr->next;
        }
        printf("x");
    }
}
int main()
{
    int n;
    printf("Enter Length of Linked List");
    scanf("%d", &n);
    createlist(n);
    printlist(start);
}