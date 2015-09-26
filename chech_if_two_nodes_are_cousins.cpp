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
void is_on_same_level(struct node *root,struct node *key1 ,struct node *key2,int *lev1,int *lev2,int lev)
{
if(root==NULL)
return;
if(root==key1)
{
*lev1=lev;
}
if(root==key2)
{
*lev2=lev;
}
if(((*lev1)!=-1)&&((*lev2)!=-1))
return;
is_on_same_level(root->left,key1 ,key2,lev1,lev2,lev+1);
is_on_same_level(root->right,key1 ,key2,lev1,lev2,lev+1);

}

bool find(struct node *root,struct node *key1,struct node *key2)
{
if(root==NULL)
return false;
return (root->left==key1&&root->right==key2)||(root->left==key2&&root->right==key1)||find(root->left,key1,key2)||find(root->right,key1,key2);

}

bool is_cousins(struct node *root,struct node *key1 ,struct node *key2 )
{
int lev1,lev2;
lev1=-1;
lev2=-1;
is_on_same_level(root,key1,key2,&lev1,&lev2,0);


return (lev1==lev2)&&(!find(root,key1,key2));






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
      /  \    / \
    4     5  6   7
   / \   / \
  11 12 13 14
     */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->right->left       = newNode(6);
  root->right->right       = newNode(7);
  root->left->left  = newNode(4);
  root->left->left->left  = newNode(11);
  root->left->left->right  = newNode(12);
  root->left->right = newNode(5);
  root->left->right->left = newNode(13);
  root->left->right->right = newNode(14);


if(is_cousins(root,root->left->left, root->right->left))
printf("yes");
else
printf("no\n");
    return 0;
}






