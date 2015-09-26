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

bool check_if_all_leaves_are_same_level(node *root ,int *leaf_level,int lev)
{
if(root==NULL)
return true;
if((*leaf_level==-1)&&(root->left==NULL)&&(root->right==NULL))
{
*leaf_level=lev;
return true;
}
else if((root->left==NULL)&&(root->right==NULL)&&(lev==*leaf_level))
{
return true;

}
else if((root->left==NULL)&&(root->right==NULL)&&(lev!=*leaf_level))
{

return false;

}
else{

return check_if_all_leaves_are_same_level(root->left ,leaf_level,lev+1)&&check_if_all_leaves_are_same_level(root->right ,leaf_level,lev+1);

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
        6      3
      /  \
    4     8
  */
  struct node *root = newNode(1);
  root->left        = newNode(6);
  root->right       = newNode(3);
   root->right->right       = newNode(11);
  root->left->left  = newNode(4);
 // root->left->right = newNode(8);
int sum=-1;
if(check_if_all_leaves_are_same_level(root ,&sum,0))
printf("yes\n");
else
printf("no\n");
    return 0;
}




