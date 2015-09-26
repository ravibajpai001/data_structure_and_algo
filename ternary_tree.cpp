#include<iostream>
#include<cstdio>
#include<malloc.h>

struct ternary_node{
char data;
bool flag;
struct ternary_node *left;
struct ternary_node *right;
struct ternary_node *eq;

};
typedef struct ternary_node node;
node *newNode(char data)
{
node *xx;
xx=(node *)malloc(sizeof(node));
xx->data=data;
xx->flag=false;
xx->left=NULL;
xx->right=NULL;
xx->eq=NULL;
return xx;
}
/**To insert  in ternary search tree*/
void insert_ternary(node **root,char *word)
{
if((*root)==NULL)
*root=newNode(*word);

if((*root)->data<(*word))
{
insert_ternary(&((*root)->right),word);
}
else if((*root)->data>(*word))
{
insert_ternary(&((*root)->left),word);
}
else{
if((*(word+1))!=NULL)
{
insert_ternary(&((*root)->eq),word+1);
}
else{
(*root)->flag=true;
}

}

}
/**To traverse ternary search tree**/
void traverse(node *root,char *buffer,int en)
{
if(root==NULL)
return;
traverse(root->left,buffer,en);
buffer[en]=root->data;
if(root->flag==true)
{
buffer[en+1]='\0';
printf("%s\n",buffer);

}

traverse(root->eq,buffer,en+1);
traverse(root->right,buffer,en);

}


/**To search in ternary search tree**/
bool search_ternary(node *root,char *word)
{
if(root==NULL)
return false;

if((root->data)>*word)
return search_ternary(root->left,word);
else if((root->data)<*word)
return search_ternary(root->right,word);
else {
if(*(word+1)=='\0')
return root->flag;
return search_ternary(root->eq,word+1);

}

}



int main()
{
    node *root = NULL;

    insert_ternary(&root, "cat");

    insert_ternary(&root, "up");
    insert_ternary(&root, "cats");
    insert_ternary(&root, "bug");
    insert_ternary(&root, "ravib");
     insert_ternary(&root, "cant");
   //char  char *as =new char;
   char *as=(char *)malloc(sizeof(char)*30);
    printf("Following is traversal of ternary search tree\n");
    traverse(root,as,0);

    printf("\nFollowing are search results for cats, bu and cat respectively\n");
     search_ternary(root, "ravib")?  printf("Found\n"): printf("Not Found\n");
    search_ternary(root, "cats")? printf("Found\n"): printf("Not Found\n");
     search_ternary(root, "cat")?  printf("Found\n"): printf("Not Found\n");
    search_ternary(root, "bu")?   printf("Found\n"): printf("Not Found\n");

    search_ternary(root, "ravib")?  printf("Found\n"): printf("Not Found\n");
    search_ternary(root, "cant")?  printf("Found\n"): printf("Not Found\n");
return 0;
}
