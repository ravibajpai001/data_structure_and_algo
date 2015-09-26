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



bool is_complete_b_tree(node *root)
{
queue<struct node *> as;
as.push(root);
bool flag=false;
while(!as.empty())
{
node *tmp;
tmp=as.front();
as.pop();
if(tmp->left!=NULL)
{
if(flag==true)
return false;
as.push(tmp->left);

}
else
{
flag=true;
}
if(tmp->right!=NULL)
{
if(flag==1)
return false;
as.push(tmp->right);

}
else{
flag=true;
}
}
return flag;
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
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
   root->right->left       = newNode(30);
    root->right->right      = newNode(31);
  root->left->left  = newNode(4);
  root->left->left->left  = newNode(14);
  root->left->left->right  = newNode(44);
  root->left->right = newNode(5);

if(is_complete_b_tree(root))
printf("yes\n");
else
printf("NO\n");
    return 0;
}




