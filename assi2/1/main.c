#include"bst.h"
#include<stdlib.h>

int main()
{
    nodeptr root = NULL;
    root = newNode(8);
    root->left=newNode(3);
    root->left->left=newNode(1);
    root->left->right=newNode(6);
    root->left->right->left=newNode(4);
    root->left->right->right=newNode(7);
    root->right=newNode(10);
    root->right->right=newNode(14);
    root->right->right->left=newNode(13);
    bstsort(root);
}