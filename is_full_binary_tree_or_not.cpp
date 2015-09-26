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
bool is_full(struct node *root)
{
if(root==NULL)
return false;
if(root->left==NULL&&root->right==NULL)
return true;
return (root->left&&root->right)&&is_full(root->left)&&is_full(root->right);

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
      /  \    / \
    4     5  6   7
   / \   / \
  11 12 13 14
     */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->right->left       = newNode(6);
  root->right->right       = newNode(7);
  root->left->left  = newNode(4);
  //root->left->left->left  = newNode(11);
  root->left->left->right  = newNode(12);
  root->left->right = newNode(5);
  root->left->right->left = newNode(13);
  root->left->right->right = newNode(14);


if(is_full(root))
printf("yes");
else
printf("no\n");
    return 0;
}







