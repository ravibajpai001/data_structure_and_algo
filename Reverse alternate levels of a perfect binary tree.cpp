#include<iostream>
#include<cstdio>
using namespace std;

// A Binary Tree node
struct Node
{
    char data;
    struct Node *left, *right;
};

// A utility function to create a new Binary Tree Node
struct Node *newNode(char item)
{
    struct Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 void store_odd_node(struct Node *root,int a[],int *size,int lev,int flag)
 {
 if(root==NULL)
 return ;
 store_odd_node(root->left,a,size,lev+1,flag);

 if(((lev%2)==1)&&flag==1)
 {
 a[*size]=root->data;
 *size=(*size)+1;

 }
 else if(((lev%2)==1)&&flag==0)
 {

 root->data=a[*size];
 *size=(*size)+1;


 }

 store_odd_node(root->right,a,size,lev+1,flag);




 }
void reverseAlternate(struct Node *root)
{

int a[200];
int size=0;
store_odd_node(root,a,&size,0,1);
int i=0;
int j=size-1;
while(i<j)
{
int tt;
tt=a[j];
a[j]=a[i];
a[i]=tt;
i++;
j--;
}
size=0;
store_odd_node(root,a,&size,0,0);


}

// A utility function to print indorder traversal of a
// binary tree
void printInorder(struct Node *root)
{
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Driver Program to test above functions
int main()
{
    struct Node *root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->right = newNode('g');
    root->left->left->left = newNode('h');
    root->left->left->right = newNode('i');
    root->left->right->left = newNode('j');
    root->left->right->right = newNode('k');
    root->right->left->left = newNode('l');
    root->right->left->right = newNode('m');
    root->right->right->left = newNode('n');
    root->right->right->right = newNode('o');

    cout << "Inorder Traversal of given tree\n";
    printInorder(root);

    reverseAlternate(root);

    cout << "\n\nInorder Traversal of modified tree\n";
    printInorder(root);

    return 0;
}
