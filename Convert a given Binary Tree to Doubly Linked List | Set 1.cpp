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






void inorder( struct node *root)
{

if(root)
{
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}


}















void make_left(struct node *root)
{
static struct node *prev=NULL;
if(root)
{
make_left(root->left);
root->left=prev;
prev=root;
make_left(root->right);
}


}
node *tree_to_double_linked_list(node *root)
{
if(root==NULL)
return NULL;

 node *tmp1,*tmp2;
 tmp1=NULL;
 tmp2=NULL;
  tmp1=root->left;
  tmp2=root->right;

if(tmp1)
{
tmp1=tree_to_double_linked_list(root->left);
 while(tmp1->right!=NULL)
 tmp1=tmp1->right;
 tmp1->right=root;
 root->left=tmp1;
}


if(tmp2)
{
tmp2=tree_to_double_linked_list(root->right);
while(tmp2->left!=NULL)
 tmp2=tmp2->left;
 root->right=tmp2;
 tmp2->left=root;
}
return root;
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

   /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *pp;
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);

  root->left->left  = newNode(4);

  root->left->right = newNode(5);
inorder(root);
pp=tree_to_double_linked_list(root);
printf("\n");
while(pp->left!=NULL)
pp=pp->left;
while(pp!=NULL)
{
printf("%d ",pp->data);
pp=pp->right;
}

    return 0;
}








