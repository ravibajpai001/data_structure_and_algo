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


void level_order(struct node *root)
{
queue<struct node *> as;
as.push(root);
while(!as.empty())
{
struct node *tmp;
tmp=as.front();
as.pop();
printf("%d ",tmp->data);
if(tmp->left!=NULL)
{
as.push(tmp->left);
}
if(tmp->right!=NULL)
{
as.push(tmp->right);
}
}
}

void insert_complete_tree_linked_list(struct node **root,struct node *x)
{

if((*root)==NULL)
  *root=x;
  queue<struct node *> as;
  as.push(*root);
  while(!as.empty())
  {
  struct node *tmp;
  tmp=as.front();
  as.pop();
  if(tmp->left==NULL)
  {
  tmp->left=x;
  return;
  }
  else   if(tmp->left!=NULL)
  {
  as.push(tmp->left);
  }
   else   if(tmp->right==NULL)
  {
  tmp->right=x;
  return;
  }
    else   if(tmp->right!=NULL)
  {
  as.push(tmp->right);
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
  root->left->left  = newNode(4);
  root->left->left->left  = newNode(39);
  root->left->right = newNode(5);

   level_order(root);

   struct node *x;
   x=newNode(321);
   insert_complete_tree_linked_list(&root,x);
   printf("\n");
   level_order(root);
   return 0;





}





