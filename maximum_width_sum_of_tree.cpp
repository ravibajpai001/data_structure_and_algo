#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};


void max_rec(struct node *root,int as[],int lev)
{
if(root)
{

max_rec(root->left,as,lev+1);
as[lev]++;
max_rec(root->right,as,lev+1);

}

}
int maxWidth(struct node * root)
{

int arr[20]={0};
max_rec(root,arr,0);
int max=0,i;
  for(i=0;i<20;i++)
  {
  if(arr[i]>max)
  max=arr[i];
  }
return max;

}
/* functioni to create a new node of tree and returns pointer */
struct node* newNode(int data);

/* Function to convert a tree to double tree */


/* UTILITY FUNCTIONS TO TEST doubleTree() FUNCTION */
 /* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
  if (node == NULL)
    return;
  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
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
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->right->left  = newNode(13);
 //  root->right->right= newNode(23);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
   int x=0;
   x=maxWidth(root);
   printf("%d ",x);

  getchar();
  return 0;
}


