#include <stdio.h>
#include <stdlib.h>
typedef struct unit_of_tree node;
struct unit_of_tree
{
    int data;
    node *left;
    node *right;
};
void preordertraversal(node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    printf("\t%d", ptr->data);

    preordertraversal(ptr->left);

    preordertraversal(ptr->right);
}

void inordertraversal(node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    inordertraversal(node->left);
    printf("\t%d", ptr->data);
    inordertraversal(node->right);
}

void postordertraversal(node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    inordertraversal(ptr->left);
    inordertraversal(ptr->right);
    printf("\t%d", ptr->data);
}

