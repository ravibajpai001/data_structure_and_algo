#include<stdio.h>
#include<limits.h>

/* A tree node structure */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};


// This function Sets the target_leaf_ref to refer the leaf node of the maximum

/* Utility function to create a new Binary Tree node */
struct node* newNode (int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}




void get_max_leaf(struct node *root,int sum,int *max_s,struct node **max_leaf)
{

if(root==NULL)
return;
if((root->left==NULL)&&(root->right==NULL))
{
sum+=root->data;
if(sum>(*max_s))
{
*max_s=sum;
*max_leaf=root;
}
}
else{
sum+=root->data;
get_max_leaf(root->left,sum,max_s,max_leaf);
get_max_leaf(root->right,sum,max_s,max_leaf);
}

}






bool print_path(struct node *root,struct node *max_leaf)
{
if(root==NULL)
return false;
if((root==max_leaf)||print_path(root->left,max_leaf)||print_path(root->right,max_leaf))
{
printf("%d ",root->data);
return true;
}
return false;

}


int maxSumPath(struct node *root)
{
int max_s=INT_MIN;
int sum=0;
struct node **max_leaf;
get_max_leaf(root,sum,&max_s,max_leaf);
print_path(root,*max_leaf);

return max_s;
}
/* Driver function to test above functions */
int main()
{
    struct node *root = NULL;

    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);

    printf ("Following are the nodes on the maximum sum path \n");
    int sum = maxSumPath(root);
    printf ("\nSum of the nodes is %d ", sum);

    return 0;
}
