#include<cstdio>
#include<iostream>
#include<vector>
#include<malloc.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
   int data;
   struct node* left;
   struct node* right;
};

/* Prototypes for funtions needed in printPaths() */

/*Given a binary tree, print out all of its root-to-leaf
 paths, one per line. Uses a recursive helper to do the work.*/


/* utility that allocates a new node with the
   given data and NULL left and right pointers. */
void  print_leaf_main(node *root ,vector<int> &as,int len)
 {
 if(root==NULL)
 return ;
 while(as.size()!=len)
 as.pop_back();
 as.push_back(root->data);
 len++;
 if(root->left==NULL&&root->right==NULL)
 {
  int i=0;
  for(i=0;i<as.size();i++)
  printf("%d ",as[i]);
  printf("\n");
 }
 else{
 print_leaf_main(root->left ,as,len);
 print_leaf_main(root->right ,as,len);

 }

 }

   void printPaths(node *root)
   {
         vector<int> as;
         int len=0;
         print_leaf_main(root ,as,len);


   }



struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

/* Driver program to test above functions*/
int main()
{

  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
    root->right->right    = newnode(22);
      root->right->right->left= newnode(120);
      root->right->right->right= newnode(45);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->left->right->left=newnode(16);
  root->left->right->right=newnode(13);
  root->right->left = newnode(2);

  printPaths(root);

  getchar();
  return 0;
}
