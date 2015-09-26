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


void spcl_level_order_trvsl(struct node *root)
{
queue<struct node *> as;
as.push(root);

while(!as.empty())
{
struct node *fi,*sec;
fi=as.front();
printf("%d ",fi->data);
if(fi==root)
{
as.pop();
as.push(fi->left);
as.push(fi->right);

}
else
{
as.pop();
sec=as.front();
as.pop();
printf("%d ",sec->data);
if(fi->left)
as.push(fi->left);
if(sec->right)
as.push(sec->right);
if(fi->right)
as.push(fi->right);
if(sec->left)
as.push(sec->left);

}
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

  struct  node *root = newNode(1);

    root->left        = newNode(2);
    root->right       = newNode(3);

    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);

    root->left->left->left->left  = newNode(16);
    root->left->left->left->right  = newNode(17);
    root->left->left->right->left  = newNode(18);
    root->left->left->right->right  = newNode(19);
    root->left->right->left->left  = newNode(20);
    root->left->right->left->right  = newNode(21);
    root->left->right->right->left  = newNode(22);
    root->left->right->right->right  = newNode(23);
    root->right->left->left->left  = newNode(24);
    root->right->left->left->right  = newNode(25);
    root->right->left->right->left  = newNode(26);
    root->right->left->right->right  = newNode(27);
    root->right->right->left->left  = newNode(28);
    root->right->right->left->right  = newNode(29);
    root->right->right->right->left  = newNode(30);
    root->right->right->right->right  = newNode(31);

spcl_level_order_trvsl(root);
    return 0;
}









