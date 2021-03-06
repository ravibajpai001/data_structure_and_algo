#include <iostream>
#include<cstdio>
#include <stack>
#include<malloc.h>
using namespace std;

// Binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};



struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

void deepest_left_leaf(struct node *root,int *max_level,int level,bool is_left,struct node **ans)
{
if(root==NULL)
return;
if((root->left==NULL)&&(root->right==NULL)&&is_left&&level>*max_level)
{
*ans=root;
*max_level=level;
return;
}
deepest_left_leaf(root->left,max_level,level+1,true,ans);
deepest_left_leaf(root->right,max_level,level+1,false,ans);

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
         /
        16
        / \
        11 12
            \13
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->right->left = newNode(16);
  root->left->right->left->left = newNode(11);
  root->left->right->left->right = newNode(12);
   root->left->right->left->right->right = newNode(12);
  struct node *ans;
int max_level=0;
deepest_left_leaf(root,&max_level,0,false,&ans);
if(ans)
printf("%d ",ans->data);

    return 0;
}




