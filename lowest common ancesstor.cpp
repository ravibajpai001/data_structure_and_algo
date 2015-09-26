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

struct node *lca(struct node *root,struct node *key1,struct node *key2)
{
if(root==NULL)
return NULL;
if(root==key1||root==key2)
return root;
struct node *le,*ri;
le=lca(root->left,key1,key2);
ri=lca(root->right,key1,key2);


if(le!=NULL &&ri!=NULL)
return root;
else if(le)
return le;
else
return ri;
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
       /  \    /  \
      4     5  6    7
     / \
    9   10
   / \
  11  12
  */
struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
      root->left->left->left = newNode(9);
      root->left->left->left->left = newNode(11);
      root->left->left->left->right = newNode(12);
        root->left->left->right = newNode(10);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
  struct node *ans;
ans=lca(root,root->left->left->right,root->left->left->left->left);
printf("lowest common ancesstor is %d",ans->data);
    return 0;
}







