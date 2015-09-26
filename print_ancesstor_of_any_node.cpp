#include<iostream>
#include<map>
#include<malloc.h>
using namespace std;

struct node{
int data;
struct node *left;
struct node *right;
};


typedef struct node node;


bool print_ancesst(node *root,int data)
{
if(root==NULL)
return false;
if((root->data)==data)
return true;
if(print_ancesst(root->left,data)||print_ancesst(root->right,data))
printf("%d ",root->data);
}

node *newNode(int x)
{
node *p;
p=(node *)malloc(sizeof(node));
p->left=NULL;
p->right=NULL;
p->data=x;
return p;

}

int main()
{

 /**        1
          /    \
         /      \
        /        \
       /           \
      2             3
     /  \         /    \
    4     5     6      7
   / \   /  \  / \    /  \
  8  11  12 13 22 23  33  45


    **/

node *root;
root=newNode(1);
root->left=newNode(2);
root->left->left=newNode(4);
root->left->right=newNode(5);
root->right=newNode(3);
root->right->left=newNode(6);
root->right->left->left=newNode(22);
root->right->left->right=newNode(23);
root->right->right=newNode(7);

print_ancesst(root,23);

return 0;
}


