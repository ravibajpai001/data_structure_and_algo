#include <iostream>
#include<cstdio>
#include <stack>
#include<malloc.h>
#define MAX_Q_SIZE 500
using namespace std;

// Binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};

void print_left_view(node *root,int lev)
{
/*we can do it by level order traverrsal and print first node at each level*/
if(root==NULL)
return;
static int max_so_far=-1;
if(lev>max_so_far)
{
printf("%d \n",root->data);
max_so_far=lev;
}
print_left_view(root->left,lev+1);
print_left_view(root->right,lev+1);



}

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
        6      3
      /  \       \
    4     8       11
  */
  struct node *root = newNode(1);
  root->left        = newNode(6);
  root->right       = newNode(3);
   root->right->right       = newNode(11);
    root->right->right->left       = newNode(110);
     root->right->right->left->left       = newNode(112);
  root->left->left  = newNode(4);
  root->left->left->right  = newNode(40);
   root->left->right = newNode(8);
print_left_view(root,0);
    return 0;
}





