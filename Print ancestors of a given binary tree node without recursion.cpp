
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

void print_ancess_without_recurr(struct node *root,struct node *key)
{

stack<struct node *> as;
struct node*curr=root;
while(!as.empty()||curr!=NULL)
    {
     while(curr!=NULL)
     {
     if(curr->right)
     as.push(curr->right);
     as.push(curr);
     curr=curr->left;
    }
    if(curr==NULL)
    {
     struct node*tmp;
    tmp=as.top();
    as.pop();
    if((!as.empty())&&(as.top()==tmp->right))
    {
    struct node *zx;
    zx=as.top();
    as.pop();
    as.push(tmp);
    curr=zx;
    if(curr==key)
    {
       while(!as.empty())
       {
       printf("%d ",as.top());
       as.pop();
       }
       return;
    }

    }
    else{
       if(curr==key)
       {
       while(!as.empty())
       {
       printf("%d ",as.top());
       as.pop();
       }
       return;
      }
       }




    }


}







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

print_ancess_without_recurr(root,root->right->right->left);

    return 0;
}







