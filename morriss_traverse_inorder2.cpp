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


void moris_inorder(struct node *root)
{
struct node *curr=root;
while(curr!=NULL)
{
struct node*temp;

if((curr->left)!=NULL)
{
temp=curr->left;
while(temp->right!=NULL&&temp->right!=curr)
temp=temp->right;
      if((temp->right)==NULL)
      {
      temp->right=curr;
      curr=curr->left;
     }
     else if((temp->right)==curr)
     {
     temp->right=NULL;
     printf("%d ",curr->data);
     curr=curr->right;
     }

}
else{
printf("%d ",curr->data);
curr=curr->right;
}


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
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

moris_inorder(root);
    return 0;
}



