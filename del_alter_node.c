#include<stdio.h>
#include<malloc.h>
struct node{
int val;
struct node *next;
};
typedef struct node node;

node *addnode(int value)
{
node *x;
x=(node *)malloc(sizeof(node));
x->next=NULL;
x->val=value;
return x;
}

/*node *del_alter_node(node *head)
{
node *x,*y;
y=head;
while(y->next!=NULL&&y!=NULL)
{
x=y->next;
y->next=x->next;
y=y->next;
free(x);
}
}*/

/*this is recursive function for same*/
 *del_alter_node_recursive(node *head)
{
if(head==NULL)
return ;

node* root=head,*root1;
if(root->next!=NULL&&root!=NULL)
{
root1=root->next;
root->next=root1->next;
root=root->next;
free(root1);
del_alter_node_recursive(root);
}
else
return;

}
/*end of recursive function*/

print(node *head)
{
node *root;
root=head;
while(root!=NULL)
{
printf("%d ",root->val);
root=root->next;
}
}
int main()
{
node *head;
head=addnode(1);
head->next=addnode(2);
head->next->next=addnode(3);
head->next->next->next=addnode(4);
head->next->next->next->next=addnode(5);
head->next->next->next->next->next=addnode(10);
head->next->next->next->next->next->next=addnode(13);

//del_alter_node(head);
del_alter_node_recursive(head);
print(head);
return 0;
}
