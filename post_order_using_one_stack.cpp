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

void post_order(node *root)
{
stack<struct node *> as;

if(root->right!=NULL)
as.push(root->right);
as.push(root);
struct node *curr=root->left;
while(!as.empty())
{
while(curr!=NULL)
{
if(curr->right!=NULL)
as.push(curr->right);
as.push(curr);
curr=curr->left;
}
if(curr==NULL)
{
struct node *tmp,*qs;
tmp=as.top();
as.pop();
if((!as.empty())&&as.top()==tmp->right)
{
qs=as.top();
as.pop();
as.push(tmp);
curr=qs;
}
else
{
printf("%d ",tmp->data);
}


}




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

post_order(root);
    return 0;
}






