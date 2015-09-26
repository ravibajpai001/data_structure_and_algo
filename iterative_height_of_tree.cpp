/***
program to calculate height of a tree iterative  **/

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

 node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}



int  height_of_tree(node *root)
{
queue<struct node *> as;
as.push(root);
/**a lot's of question are solved by level order traversal or u can say bfs on rooted graph**/
int he=0;
int qsize=1;

while(!as.empty())
{
if(qsize==0)
return he;
while((qsize>0))
{
struct node *tmp;
tmp=as.front();
if(tmp->left!=NULL)
as.push(tmp->left);
if(tmp->right!=NULL)
as.push(tmp->right);
as.pop();
qsize--;
}
if(as.size()>0)
he++;
qsize=as.size();
}
return he;

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
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);

  root->left->left  = newNode(4);

  root->left->right = newNode(5);

printf("%d ",height_of_tree(root));
    return 0;
}





