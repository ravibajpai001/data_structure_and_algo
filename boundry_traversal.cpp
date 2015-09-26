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
 node *left_t(node *root)
 {

 while((root->left)!=NULL||(root->right)!=NULL)
 {
 if(root->left!=NULL)
 {
 printf("%d ",root->data);
 root=root->left;
 }
 else if(root->right!=NULL)
 {
 printf("%d ",root->data);
 root=root->right;
 }
 }

 }
void leaf_t(struct node *root)
{
if(root==NULL)
return;
if(((root->left)==NULL)&&((root->right)==NULL))
{
printf("%d ",root->data);
return;
}
leaf_t(root->left);
leaf_t(root->right);

}
bool right_t_from_bottom(struct node *root)
{
if(root->left==NULL&&root->right==NULL)
return true;
if(root->right!=NULL)
{
    if(right_t_from_bottom(root->right))
    {
    printf("%d ",root->data);
    return true;
    }
}
else if(root->left!=NULL)
{
    if(right_t_from_bottom(root->left))
    {
    printf("%d ",root->data);
    return true;
    }

}

}


 void boundry_traversal(struct node *root)
 {
 /***Anti clock_wise direction ***/
 left_t(root);
 leaf_t(root);
 right_t_from_bottom(root->right);

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
          /   \
        2      3
      /  \      \
    4     5      8
     \          /
      6        11
     /          \
    7           26   **/
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->right->left      = newNode(300);
  root->right->right= newNode(8);
  root->right->right->left= newNode(11);
  root->right->right->left->right= newNode(26);
  root->left->left  = newNode(4);
  root->left->left->right  = newNode(6);
  root->left->left->right->left  = newNode(7);
  root->left->right = newNode(5);
  boundry_traversal(root);

    return 0;





}




