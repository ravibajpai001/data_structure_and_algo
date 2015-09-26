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

void vertical_sum(node *root,int x,map<int,int> &mp)
{
if(root==NULL)
return;
mp[x]+=root->data;
vertical_sum(root->left,x-1,mp);
vertical_sum(root->right,x+1,mp);


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
map<int,int> mp;
vertical_sum(root,0,mp);

map<int,int>::iterator it=mp.begin();
while(it!=mp.end())
{

printf("%d ",it->second);
it++;
}


return 0;
}

