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

struct node * extract_leaf_convert_to_dll(node *root,node **head)
{
if(root==NULL)
return NULL;

if(root->left==NULL&&root->right==NULL)
{
root->right=*head;
if(*head!=NULL)
(*head)->left=root;
*head=root;
return NULL;
}

root->right=extract_leaf_convert_to_dll(root->right,head);
root->left=extract_leaf_convert_to_dll(root->left,head);
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

/***    1
     /     \
    2       3
   / \       \
  4   5       6
 / \         / \
7   8       9   10
                      ***/
     struct node *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->right = newNode(6);
     root->left->left->left = newNode(7);
     root->left->left->right = newNode(8);
     root->right->right->left = newNode(9);
     root->right->right->right = newNode(10);


inorder(root);
printf("\n");
struct node *head=NULL;
   root=extract_leaf_convert_to_dll(root,&head);
inorder(root);
printf("\n");
printf("dll is \n");
while(head!=NULL)
{
printf("%d ",head->data);
head=head->right;
}
    return 0;
}







