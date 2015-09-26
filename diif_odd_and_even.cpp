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

void dif_odd_even(struct node *root,int lev,int *sum)
{
if(root)
{
   if(lev%2==0)
   {
   *sum=*sum+root->data;
   }
   else
   {
   *sum=*sum-root->data;

    }

    dif_odd_even(root->left,lev+1,sum);
    dif_odd_even(root->right,lev+1,sum);


}



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
        2      3
      /  \
    4     8
  */
  struct node *root = newNode(1);
  root->left        = newNode(6);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(8);
int sum=0;
dif_odd_even(root,0,&sum);
printf("%d ",sum);
    return 0;
}



