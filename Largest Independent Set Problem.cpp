#include <iostream>
#include<cstdio>
#include <stack>
#include<queue>
#include<malloc.h>
#define MAX_Q_SIZE 500
using namespace std;

/**It is a DP problem which is not easy to solve  **/
struct node
{
    int data;
    int ans;
    struct node *left, *right;
};

 node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->ans=0;
    node->left = NULL;
    node->right = NULL;

    return(node);
}


int largest_independent_set(node *root)
{
if(root==NULL)
return 0;
if((root->left==NULL)&&(root->right==NULL))
return 1;
if(root->ans!=0)
return root->ans;
int n1,n2,l,r;
n1=0;n2=1;
n1=largest_independent_set(root->left)+largest_independent_set(root->right);
if(root->left!=NULL)
n2+=largest_independent_set(root->left->left)+largest_independent_set(root->left->right);
if(root->right!=NULL)
n2+=largest_independent_set(root->right->left)+largest_independent_set(root->right->right);

root->ans=(n1>n2)?n1:n2;
return root->ans;
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

  struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

cout<<largest_independent_set(root);
    return 0;
}




