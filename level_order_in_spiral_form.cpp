#include <iostream>
#include<cstdio>
#include <stack>
using namespace std;

// Binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};

void  printSpiral(struct node *root){
 stack<struct node *> as1;
  stack<struct node *> as2;
  as1.push(root);
  while(!as1.empty()||!as2.empty())
  {
  while(!as1.empty())
  {
  struct node*tmp;
  tmp=as1.top();
  printf("%d ",tmp->data);
  if(tmp->right!=NULL)
  as2.push(tmp->right);
  if(tmp->left!=NULL)
  as2.push(tmp->left);
   as1.pop();
  }
  printf("\n");
  while(!as2.empty())
  {
  struct node*tmp;
  tmp=as2.top();
  printf("%d ",tmp->data);
  if(tmp->left!=NULL)
  as1.push(tmp->left);
  if(tmp->right!=NULL)
  as1.push(tmp->right);
   as2.pop();
  }
   printf("\n");
  }

 }
// A utility functiont to create a new node
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
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
    cout << "Spiral Order traversal of binary tree is \n";
    printSpiral(root);

    return 0;
}
