#include<iostream>
#include<malloc.h>
using namespace std;
struct node {
int data;
struct node*left;
struct node *right;
};
typedef struct node node;
node *newNode(int val)
{
node *newe;
newe=(node *)malloc(sizeof(node));
newe->left=NULL;
newe->right=NULL;
newe->data=val;
return newe;
}
int is_path_equal_to_sum(node *root ,int val)
{
if(root==NULL)
return 0;
if(((root->left)==NULL)&&((root->right)==NULL)&&(val==root->data))
{
return 1;
}
else {

return (is_path_equal_to_sum(root->left,val-root->data))|(is_path_equal_to_sum(root->right,val-root->data));
}
}

int main()
{
/**
                           1

              12                   2

        9         5           11            8
                           10
                               6  ***/
node *root=newNode(1);
root->left=newNode(12);
root->right=newNode(2);
root->right->left=newNode(11);
root->right->right=newNode(8);
root->left->right=newNode(5);
root->left->left=newNode(9);
root->right->left->left=newNode(10);
root->right->left->left->right=newNode(6);
if(is_path_equal_to_sum(root,22))
printf("yes\n");
else
printf("no\n");

}
