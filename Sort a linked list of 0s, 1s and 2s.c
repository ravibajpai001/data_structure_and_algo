#include<stdio.h>
struct node{
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
while(head!=NULL)
{
printf("value is %d and address is %lld\n",head->val,head);
head=head->next;
}
printf("\n");
}
sort(node *head)
{
int n1,n2,n3;
n1=0;
n2=0;
n3=0;
node *p=head,*q=head;
while(head!=NULL)
{
if(head->val==0)
n1++;
else if(head->val==1)
n2++;
else if(head->val==2)
n3++;
head=head->next;
}
while(n1--)
{
q->val=0;
q=q->next;
}
while(n2--)
{
q->val=1;
q=q->next;
}
while(n3--)
{
q->val=2;
q=q->next;
}
return p;
}

int main()
{
node *head;
int k=2;
head=addnode(2);
head->next=addnode(0);
head->next->next=addnode(1);
head->next->next->next=addnode(2);
head->next->next->next->next=addnode(0);
head->next->next->next->next->next=addnode(1);
print(head);
sort(head);
print(head);
return 0;
}

