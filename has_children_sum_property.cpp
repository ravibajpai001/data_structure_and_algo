#include <iostream>
#include<cstdio>
#include <stack>
using namespace std;

// Binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};

bool has_children_sum(struct node *root)
{
int x,y;
if(root==NULL)
return true;
if(root->left==NULL&&root->right==NULL)
return true;
x=0;y=0;
if(root->left!=NULL)
x=root->left->data;
if(root->right!=NULL)
y=root->right->data;
return (root->data==x+y)&&(has_children_sum(root->left))&&(has_children_sum(root->right));

}
// A utility functiont to create a new node
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main()
{
    struct node *root = newNode(8);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(1);
    root->left->right = newNode(1);
    root->right->left  = newNode(2);
    root->right->right = newNode(1);
    if(has_children_sum(root))
    printf("yes\n");
    else
    printf("no\n");

    return 0;
}

