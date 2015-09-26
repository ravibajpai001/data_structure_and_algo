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


int level_node(node *root,int data,int l)
{
int p;
if(root==NULL)
return -1;
if((root->data)==data)
{
return l;
}
else
{
p=level_node(root->left,data,l+1);
if(p==-1)
return  level_node(root->right,data,l+1);
else
return p;

}
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

 /**     1
       /   \
      2      3
     / \    / \
    4   5  6   7  **/

node *root;
root=newNode(1);
root->left=newNode(2);
root->left->left=newNode(4);
root->left->right=newNode(5);
root->right=newNode(3);
root->right->left=newNode(6);
root->right->right=newNode(7);

printf("%d ",level_node(root,3,0));

return 0;
}

