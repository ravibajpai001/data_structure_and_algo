#include <iostream>
#include<cstdio>
#include <stack>
#include<malloc.h>
#define MAX_Q_SIZE 500
using namespace std;

// Binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};
struct node** createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);

/* Given a binary tree, print its nodes in level order
   using array for implementing queue */
void printLevelOrder(struct node* root)
{
  int rear, front;
  struct node **queue = createQueue(&front, &rear);
  struct node *temp_node = root;

  while(temp_node)
  {
    printf("%d ", temp_node->data);

    /*Enqueue left child */
    if(temp_node->left)
      enQueue(queue, &rear, temp_node->left);

    /*Enqueue right child */
    if(temp_node->right)
      enQueue(queue, &rear, temp_node->right);

    /*Dequeue node and make it temp_node*/
    temp_node = deQueue(queue, &front);
  }
}

/*UTILITY FUNCTIONS*/
struct node** createQueue(int *front, int *rear)
{
  struct node **queue =
   (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);

  *front = *rear = 0;
  return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_node)
{
  queue[*rear] = new_node;
  (*rear)++;
}

struct node *deQueue(struct node **queue, int *front)
{
  (*front)++;
  return queue[*front - 1];
}
void make_children_sum(struct node *root)
{
if(root==NULL)
return;
if((root->left==NULL)&&(root->right==NULL))
return;
int l,r;
l=0;r=0;
if(root->left!=NULL)
l=root->left->data;
if(root->right!=NULL)
r=root->right->data;
make_children_sum(root->left);
make_children_sum(root->right);

if((l+r)>root->data)
root->data=l+r;
else if((l+r)<root->data)
{
if(root->left!=NULL)
{
root->left->data+=root->data-l-r;
make_children_sum(root->left);
}
else
{
root->right->data+=root->data-l-r;
make_children_sum(root->right);

}



}

}
// A utility functiont to create a new node
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main()
{
    struct node *root = newNode(8);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(1);
    root->left->right = newNode(1);
    root->right->left  = newNode(2);
    root->right->right = newNode(1);
    printLevelOrder(root);

   make_children_sum(root);
  printf("\n");
  printLevelOrder(root);
    return 0;
}


