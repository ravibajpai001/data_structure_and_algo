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


void inorder(node *root)
{
if(root==NULL)
return;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}

void preorder(node *root)
{
if(root==NULL)
return;
printf("%d ",root->data);
preorder(root->left);
preorder(root->right);
}




int searchi(int in[],int start,int en,int data)
{
int i;
for(i=start;i<=en;i++)
{
if(in[i]==data)
return i;
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
node *inorder_preorder_build(int in[],int pre [],int start,int en)
{
node *root;
static int pre_index=0;
if(start>en)
return NULL;
root=newNode(pre[pre_index]);
if(start==en)

{
pre_index++;
return root;
}


int ind;
ind=searchi(in,start,en,pre[pre_index++]);
root->left=inorder_preorder_build(in,pre,start,ind-1);

root->right=inorder_preorder_build(in,pre,ind+1,en);



return root;
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



    **/
int in[]={4,2,5,1,6,3,7};
int pre[]={1,2,4,5,3,6,7};
node *root;
root=inorder_preorder_build(in,pre,0,6);

inorder(root);
printf("\n");
preorder(root);

return 0;
}


