#include <iostream>
#include<cstdio>
#include <stack>
#include<queue>
#include<malloc.h>
using namespace std;

// Binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};

void  sum_of_all_root_to_leaf_number(node *root,int num,int *sum)
{
if(root==NULL)
return ;
num=num*10+root->data;
if(root->left==NULL&&root->right==NULL)
{
printf("       %d\n",num);
*sum=*sum+num;
}
sum_of_all_root_to_leaf_number(root->left,num,sum);
sum_of_all_root_to_leaf_number(root->right,num,sum);

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
      /  \       \
    4     8       1
     \             /
      4          1
                  /
                2
  */
  struct node *root = newNode(1);
  root->left        = newNode(6);
  root->right       = newNode(3);
  root->right->right       = newNode(1);
  root->right->right->left       = newNode(1);
  root->right->right->left->left       = newNode(2);
  root->left->left  = newNode(4);
  root->left->left->right  = newNode(4);
  root->left->right = newNode(8);
  int num=0;
  int sum=0;
  sum_of_all_root_to_leaf_number(root,num,&sum);
  printf("sum is %d",sum);
    return 0;
}







