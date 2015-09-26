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

void iterative_preorder(struct node *root)
{
stack<struct node *> as;
as.push(root);
struct node *tmp;
while(!as.empty())
{
tmp=as.top();
as.pop();
printf("%d ",tmp->data);
if((tmp->right)!=NULL)
as.push(tmp->right);
if((tmp->left)!=NULL)
as.push(tmp->left);
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
/**       8
          2      3
       1    1  2     1
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
**/
  /**  Constructed binary tree is
            1
          /   \
        2      3
      /  \      \
    4     5      8
     \          /
      6        11
     /          \
    7           26   **/
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->right->left      = newNode(300);
  root->right->right= newNode(8);
  root->right->right->left= newNode(11);
  root->right->right->left->right= newNode(26);
  root->left->left  = newNode(4);
  root->left->left->right  = newNode(6);
  root->left->left->right->left  = newNode(7);
  root->left->right = newNode(5);

   iterative_preorder(root);
    return 0;





}





