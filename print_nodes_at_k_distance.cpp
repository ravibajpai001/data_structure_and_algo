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
node *newNode(int x)
{
node *p;
p=(node *)malloc(sizeof(node));
p->left=NULL;
p->right=NULL;
p->data=x;
return p;

}

void node_k_distant(node *root,int k,int l)
{
if(root==NULL||l>k)
return;
else if(l <k)
{
node_k_distant(root->left,k,l+1);
node_k_distant(root->right,k,l+1);

}
else if(l==k){
printf("%d ",root->data);

}



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
node_k_distant(root,1,0);


return 0;
}

