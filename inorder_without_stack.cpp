#include<stack>
#include<iostream>
#include<malloc.h>
#include<cstdio>
using namespace std;
struct tNode
{
   int data;
   struct tNode* left;
   struct tNode* right;
};

/* Structure of a stack node. Linked List implementation is used for
   stack. A stack node contains a pointer to tree node and a pointer to
   next stack node */



/* Iterative function for inorder tree traversal */
void inOrder(struct tNode *root)
{
stack<struct tNode *> as;
struct tNode *curr=root,*tmp;
while(curr!=NULL||(!as.empty()))
{
while(curr!=NULL)
{
as.push(curr);
curr=curr->left;
}
tmp=as.top();
printf("%d ",tmp->data);
as.pop();
curr=tmp->right;


}

 }

/* UTILITY FUNCTIONS */
/* Function to push an item to sNode*/
/*void push(struct sNode** top_ref, struct tNode *t)
{
  /* allocate tNode
  struct sNode* new_tNode =
            (struct sNode*) malloc(sizeof(struct sNode));

  if(new_tNode == NULL)
  {
     printf("Stack Overflow \n");
     getchar();
     exit(0);
  }

  /* put in the data
  new_tNode->t  = t;

  /* link the old list off the new tNode
  new_tNode->next = (*top_ref);

  /* move the head to point to the new tNode
  (*top_ref)    = new_tNode;
}

/* The function returns true if stack is empty, otherwise false
bool isEmpty(struct sNode *top)
{
   return (top == NULL)? 1 : 0;
}

/* Function to pop an item from stack
struct tNode *pop(struct sNode** top_ref)
{
  struct tNode *res;
  struct sNode *top;


  if(isEmpty(*top_ref))
  {
     printf("Stack Underflow \n");
     getchar();
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->t;
     *top_ref = top->next;
     free(top);
     return res;
  }
}
 */
/* Helper function that allocates a new tNode with the
   given data and NULL left and right pointers. */
struct tNode* newtNode(int data)
{
  struct tNode* tNode = (struct tNode*)
                       malloc(sizeof(struct tNode));
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;

  return(tNode);
}

/* Driver program to test above functions*/
int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct tNode *root = newtNode(1);
  root->left        = newtNode(2);
  root->right       = newtNode(3);
  root->left->left  = newtNode(4);
  root->left->right = newtNode(5);

  inOrder(root);

  getchar();
  return 0;
}
