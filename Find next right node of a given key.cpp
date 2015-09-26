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

struct node *next_right_node(struct node *root,struct node *ses)
{
queue <struct node *> as;
as.push(root);
int flag=0;
int qsize;
while(!as.empty())
{
qsize=as.size();
while(qsize--)
{

struct node *tmp;
tmp=as.front();
as.pop();
if(qsize>0&&tmp==ses)
{
return as.front();
}
else if((qsize==0)&&(tmp==ses))
{
return NULL;


}
else{
if(tmp->left!=NULL)
as.push(tmp->left);
if(tmp->right!=NULL)
as.push(tmp->right);
}


}



}



return NULL;
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
    4     8       11
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
struct node *ass=next_right_node(root,root);

if(ass)
printf("%d ",ass->data);
else
printf("NULL\n");
    return 0;
}






