#include<iostream>
#include<map>
#include<malloc.h>
using namespace std;

struct node{
int data;
struct node *left;
struct node *right;
struct node *next;
};


typedef struct node node;

void inorder(node *root)
{
if(root==NULL)
return;
inorder(root->left);
if(root->next!=NULL)
printf("%d and inorder_suc is %d \n",root->data,root->next->data);
else
printf("%d and inorder_suc is null \n",root->data);
inorder(root->right);

}

void inorder_succ(node *root,node **nex)
{
if(root==NULL)
return;
inorder_succ(root->right,nex);
root->next=*nex;
*nex=root;
inorder_succ(root->left,nex);

}

node *newNode(int x)
{
node *p;
p=(node *)malloc(sizeof(node));
p->left=NULL;
p->right=NULL;
p->next=NULL;
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
node *nex;
root=newNode(1);
root->left=newNode(2);
root->left->left=newNode(4);
root->left->right=newNode(5);
root->right=newNode(3);
root->right->left=newNode(6);
root->right->right=newNode(7);

inorder_succ(root,&nex);
inorder(root);
return 0;
}
