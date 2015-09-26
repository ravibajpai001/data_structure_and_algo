#include<stdio.h>
#include<malloc.h>
struct node
{
int val;
struct node *next;
};

typedef struct node node;

node *addnode(int value)
{
node *p;
p=(node *)malloc(sizeof(node));
p->val=value;
p->next=NULL;
return p;
}
print(node *head)
{
node *root;
root=head;
while(root!=NULL)
{
printf("%d and address is %lld\n",root->val,root);
root=root->next;
}
printf("\n");
}
/*Begin :I am trying to implement using reference variable*/

node *swap(node *head)
{
if(head==NULL)
return NULL;
if(head->next==NULL)
return head;
node *t;
t=head->next;
head->next=head->next->next;;
t->next=head;
t->next->next=swap(t->next->next);
return t;
}
int main()
{
node j;
node *second;
node *head;;
head=addnode(13);
head->next=addnode(13);
head->next->next=addnode(20);
head->next->next->next=addnode(28);
head->next->next->next->next=addnode(58);
//head->next->next->next->next->next=addnode(88);
print(head);
//print(head);
second=swap(head);
print(second);
return 0;
}

