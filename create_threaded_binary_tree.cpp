/***
program to calculate height of a tree iterative  **/

#include <iostream>
#include<cstdio>
#include <map>
#include<queue>
#include<malloc.h>

using namespace std;

// Binary Tree node
struct node
{
    int data;
    int hd;
    struct node *left, *right;
};

 node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->hd=0;
    node->left = NULL;
    node->right = NULL;

    return(node);
}


void convert_to_thread(node *root)
{

struct node*curr=root;
while(curr!=NULL)
{
if(curr->left!=NULL)
{
struct node *tmp=curr->left;
while(tmp->right!=NULL&&tmp->right!=curr)
{
tmp=tmp->right;

}
if(tmp->right==NULL)
{
tmp->right=curr;
curr=curr->left;

}
else if(tmp->right==curr)
{
curr=curr->right;
}

}
else{

curr=curr->right;




}




}






}


void inorder( struct node *root)
{

if(root)
{
inorder(root->left);
printf("%d ",root->data);
if(root->right)
printf("%d ",root->right->data);
else
printf("NULL");
printf("\n");
inorder(root->right);
}


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

   /*       1
            / \
           2   3
          / \ / \
         4  5 6  7   */
     struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
  map<int,int> as;
  inorder(root);
  convert_to_thread(root);
  while(root->left!=NULL)
  root=root->left;

  printf("after it");
  while(root->right!=NULL)
  {
  printf("%d %d\n",root->data,root->right->data);
  root=root->right;

  }
 // inorder(root);
    return 0;
}










