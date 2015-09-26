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
rotate(node **head,int k)
{
node *star,*kth,*kp1th,*last;
star=*head;
node *p;
p=*head;
while(k--)
{
last=p;
p=p->next;
}
kth=last;
kp1th=p;
while(p->next!=NULL)
{
p=p->next;
}
last=p;
last->next=*head;
kth->next=NULL;
*head=kp1th;
}

int main()
{
node *head;
int k=2;
head=addnode(13);
head->next=addnode(13);
head->next->next=addnode(20);
head->next->next->next=addnode(28);
head->next->next->next->next=addnode(58);
head->next->next->next->next->next=addnode(88);
print(head);
rotate(&head,4);
print(head);
return 0;
}
