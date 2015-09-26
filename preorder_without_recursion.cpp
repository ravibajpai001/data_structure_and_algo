
// C program for iterative postorder traversal using one stack
#include <iostream>
#include<stack>
#include<cstdio>
#include<malloc.h>
using namespace std;

// A tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Stack type
struct Stack
{
    int size;
    int top;
    struct Node* *array;
};

// A utility function to create a new tree node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


void postOrderIterative(struct Node* root)
{
    // Check for empty tree
    struct Node* tmp;
   stack<struct Node * > as;
   stack<int> ans;
   as.push(root);
   while(!as.empty())
   {
   tmp=as.top();
   ans.push(tmp->data);
   as.pop();
   if((tmp->left)!=NULL)
    as.push(tmp->left);
     if((tmp->right)!=NULL)
    as.push(tmp->right);


   }
   while(!ans.empty())
   {

   printf("%d ",ans.top());
   ans.pop();
   }
}

// Driver program to test above functions
int main()
{
    // Let us construct the tree shown in above figure
    struct Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    postOrderIterative(root);

    return 0;
}
