#include<stdio.h>
#include<malloc.h>
struct node{
int val;
struct node *next;
};
typedef struct node node;

node *addnode(int value)
{
node *xx;
xx=(node *)malloc(sizeof(node));
xx->val=value;
xx->next=NULL;
return xx;
}

print(node *head)
{
node *root;
root=head;
while(root!=NULL)
{
printf("%d and address is %ld\n",root->val,root);
root=root->next;
}
printf("\n");
}
node *merge_alternate(node *first,node **second)
{
node *p=first;
node *q;
q=*second;
while(p!=NULL)
{
node *pnex,*qnex;
pnex=p->next;
qnex=q->next;

p->next=q;
q->next=pnex;

p=pnex;
q=qnex;
}
*second=q;
return first;
}


int main()
{
node *head1;
head1=addnode(6);
head1->next=addnode(8);
head1->next->next=addnode(13);
head1->next->next->next=addnode(15);
head1->next->next->next->next=addnode(17);
head1->next->next->next->next->next=addnode(20);
node *head2,*finallist;
head2=addnode(4);
head2->next=addnode(7);
head2->next->next=addnode(14);
head2->next->next->next=addnode(18);
head2->next->next->next->next=addnode(19);
head2->next->next->next->next->next=addnode(22);
head2->next->next->next->next->next->next=addnode(212);
head2->next->next->next->next->next->next->next=addnode(33);
head2->next->next->next->next->next->next->next->next=addnode(55);
print(head1);
printf("second list before\n");
print(head2);
//(head2);
//finallist=merge(&head1,&head2);
finallist=merge_alternate(head1,&head2);
print(finallist);


printf("second list after\n");
print(head2);
}





