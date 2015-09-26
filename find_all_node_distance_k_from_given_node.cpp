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
void print_down(struct node *root,int k,int lev)
{
if(root==NULL)
return;
if(lev==k)
{
printf("%d ",root->data);
return;
}
print_down(root->left,k,lev+1);
print_down(root->right,k,lev+1);

}





int nodes_at_k_distance(struct node *root,struct node *key,int k)
{

if(root==key)
{
print_down(root,k,0);
return 0;
}
int le,ri;
if(root->left)
le=nodes_at_k_distance(root->left,key,k);
if(le>=0)
{
if(le+1==k)
printf("%d ",root->data);
else if(k-le-2>=0)
print_down(root->right,k-le-2,0);
return le+1;
}
if(root->right)
ri=nodes_at_k_distance(root->right,key,k);
if(ri>=0)
{
if(ri+1==k)
printf("%d ",root->data);
else if(k-ri-2>=0)
print_down(root->left,k-ri-2,0);



return ri+1;
}



return -1;





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
       /  \    /  \
      4     5  6    7
     / \
    9   10
   / \
  11  12
  */
struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
      root->left->left->left = newNode(9);
      root->left->left->left->left = newNode(11);
      root->left->left->left->right = newNode(12);
        root->left->left->right = newNode(10);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
  struct node *ans;
  nodes_at_k_distance(root,root->left->right ,3);
    return 0;
}










