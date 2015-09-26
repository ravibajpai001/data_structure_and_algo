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
    string val;
    struct node *left, *right;
};

node *construct_tree(node *root,int a[],int r,int data)
{

int n,k;
n=a[r]
k=a[r]*10+a[r+1];
root->left=newNode();
root->right=newNode(k);

return root;
}


struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = "";
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
          /    \
        2       3
      /  \    /    \
    4     5   300   8
     \          /
      6        11
     /          \
    7           26   **/
  struct node *root = newNode();
   int[] a = {1, 2, 2, 1};
  construct_tree(root,a,0,3);

   level_order(root);
    return 0;





}






