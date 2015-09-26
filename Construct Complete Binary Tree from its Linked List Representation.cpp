#include <iostream>
#include<cstdio>
#include <stack>
#include<queue>
#include<malloc.h>
#define MAX_Q_SIZE 500
using namespace std;

// Binary Tree node
struct Treenode
{
    int data;
    struct Treenode *left, *right;
};




struct List
{
    int val;
    struct List *next;
};

typedef struct List List;
typedef struct Treenode Tree;

 Tree* newNode(int data)
{
    Tree * node = new Tree;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

List* newListNode(int data)
{
    List* ne = new List;
    ne->val = data;
    ne->next=NULL;

    return ne;
}

Tree *List_to_complete_tree(List *x)
{

queue<Tree *> as;
Tree *root;
root=newNode(x->val);
as.push(root);
x=x->next;
while(  x!=NULL&&!as.empty()  )
{
Tree *tmp;
tmp=as.front();
if(tmp->left==NULL)
{
tmp->left=newNode(x->val);
x=x->next;
as.push(tmp->left);
}
else if(tmp->right==NULL)
{
tmp->right=newNode(x->val);
x=x->next;
as.push(tmp->right);
as.pop();
}


}

return root;
}




void level_order(Tree *root)
{
queue<Tree  *> as;
as.push(root);
while(!as.empty())
{
Tree  *tmp;
tmp=as.front();
as.pop();
printf("%d ",tmp->data);
if(tmp->left!=NULL)
{
as.push(tmp->left);
}
if(tmp->right!=NULL)
{
as.push(tmp->right);
}

}

}



int main()
{
/*1 2 3 4 5 6 7 8 9 10 12*/
 List *x=newListNode(1);
 x->next=newListNode(2);
 x->next->next=newListNode(3);
 x->next->next->next=newListNode(4);
 x->next->next->next->next=newListNode(5);
 x->next->next->next->next->next=newListNode(6);
 x->next->next->next->next->next->next=newListNode(7);
 x->next->next->next->next->next->next->next=newListNode(8);
 x->next->next->next->next->next->next->next->next=newListNode(9);
 x->next->next->next->next->next->next->next->next->next=newListNode(10);
 x->next->next->next->next->next->next->next->next->next->next=newListNode(11);

 Tree *root;
root=List_to_complete_tree(x);
level_order(root);
    return 0;
}





