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

struct node * remove_node_which_dont_lie_path_sum_grat_k(struct node *root,int sum,int k)
{

if(root==NULL)
return NULL;
sum=sum+root->data;

root->left=remove_node_which_dont_lie_path_sum_grat_k(root->left,sum,k);
root->right=remove_node_which_dont_lie_path_sum_grat_k(root->right,sum,k);
if((root->left==NULL)&&(root->right==NULL))
{
if(sum<k)
{
/**What to do in this case**/
delete root;
root=NULL;

}

}

return root;
}
void inorder(struct node *root)
{
if(root)
{
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);

}
}
int main()
{
/***
              8
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
     int k = 45;
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(12);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->left->left->right->left = newNode(13);
    root->left->left->right->right = newNode(14);
    root->left->left->right->right->left = newNode(15);
    node *ans;
    inorder(root);

ans=remove_node_which_dont_lie_path_sum_grat_k(root,0,45);
printf("\n");
inorder(ans);
    return 0;
}






