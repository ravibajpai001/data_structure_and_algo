/***
program to calculate height of a tree iterative  **/

#include <iostream>
#include<cstdio>
#include <map>
#include<queue>
#include<malloc.h>

using namespace std;

// Binary Tree node
struct node
{
    int data;
    int hd;
    struct node *left, *right;
};

 node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->hd=0;
    node->left = NULL;
    node->right = NULL;

    return(node);
}


void bot_view(struct node *root,int dis,map<int,int > &x)
{
queue<struct node *> as;
as.push(root);
while(!as.empty())
{
struct node *xx;
xx=as.front();
as.pop();
if(x[xx->hd]==0)
x[xx->hd]=xx->data;
if(xx->left)
as.push(xx->left);
if(xx->right)
as.push(xx->right);

}


}



void inorder( struct node *root,int tx)
{

if(root)
{
inorder(root->left,tx-1);
root->hd=tx;
inorder(root->right,tx+1);
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
         \
          4
           \
            5
             \
              6
  */
  struct node *pp;

  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->right  = newNode(4);
  root->left->right->right = newNode(5);
  root->left->right->right->right = newNode(6);
  map<int,int> as;
  inorder(root,0);
  bot_view(root,0,as);
  map<int,int>::iterator it=as.begin();
  while(it!=as.end())
  {
  printf("%d ",it->second);
  it++;
  }
    return 0;
}









