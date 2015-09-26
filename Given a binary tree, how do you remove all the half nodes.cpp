/***
program to calculate height of a tree iterative  **/

#include <iostream>
#include<cstdio>
#include <stack>
#include<queue>
#include<malloc.h>
#define MAX_Q_SIZE 500
using namespace std;

// Binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};

 node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
void remove_half(struct node *root)
{
if(root==NULL)
return ;
if(root->left&&root->left->left&&(root->left->right==NULL))
{
root->left=root->left->left;
}
else if(root->left&&root->left->right&&(root->left->left==NULL))
{
root->left=root->left->right;
}
if(root->right&&root->right->right&&(root->right->left==NULL))
{
root->right=root->right->right;
}
else if(root->right&&root->right->left&&(root->right->right==NULL))
{
root->right=root->right->left;
}

remove_half(root->left);

remove_half(root->right);


}
void inorder(struct node *root)
{

if(root)
{
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
}

int main()
{
/***         8
          2      3
       1    1  2     1
    struct node *root = newNode(8);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(1);
    root->left->right = newNode(1);
    root->right->left  = newNode(2);
    root->right->right = newNode(1);
   inoder_moriss(root);***/
 struct node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);


inorder(root);
printf("\n");
remove_half(root);
inorder(root);
    return 0;
}








