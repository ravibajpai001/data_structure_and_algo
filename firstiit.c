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
x=(int *)malloc(sizeof(int));
x->next=NULL;
x->val=value;
return x;
}
node *del_alter_node(node *head)
{
node *x;
while(node->next!=NULL)
{
x=node->next;
node->next=x->next;
node=node->next;
free(x);
}
}
print(node *head)
{
node *root;
root=head;
while(head->next!=NULL)
{
printf("%d ",root->val);
root=root->val;
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

del_alter_node(head);
print(head);

}
