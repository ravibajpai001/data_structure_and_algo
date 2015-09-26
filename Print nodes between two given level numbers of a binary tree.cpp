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

void  print_bet_level(struct node *root,int l1,int l2)
{
int lev=0;
queue<struct node *> as;
struct node *curr=root;
as.push(root);
int qsize;
while(!as.empty()||curr!=NULL)
{
qsize=as.size();
while(qsize--)
{
struct node *t;
t=as.front();
if(lev>=l1&&lev<=l2)
printf("%d ",t->data);
as.pop();
if(t->left)
as.push(t->left);
if(t->right)
as.push(t->right);
}
printf(" \n");
lev++;
if(lev>l2)
break;

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
  int l1,l2;
  l1=1;l2=3;
 print_bet_level(root,l1,l2);
    return 0;
}










