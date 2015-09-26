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
/****
intersection point of two linked list
count the length of both list let's say it is d
now move the longer list to d distance and then move in both list
*/
int getsl(node *head)
{
int count=0;
while(head!=NULL)
{
head=head->next;
count++;
}
return count;
}
node *intersection_point(node *head1,node *head2)
{
int d;
int n1=getsl(head1);
int n2=getsl(head2);
d=n1-n2;
if(d>0)
{
while(d--)
{
head1=head1->next;
}
}
else{
while(d--)
{
head2=head2->next;
}
}
while(head1!=head2)
{
head1=head1->next;
head2=head2->next;
}
return head1;
}



int main()
{
node *head;
head=addnode(5);
head->next=addnode(3);
head->next->next=addnode(13);
head->next->next->next=addnode(6);
head->next->next->next->next=addnode(8);
head->next->next->next->next->next=addnode(18);
head->next->next->next->next->next->next=addnode(34);
head->next->next->next->next->next->next->next=addnode(46);
node *head2;
head2=addnode(51);
head2->next=addnode(34);
head2->next->next=addnode(113);
head2->next->next->next=addnode(64);
head2->next->next->next->next=head->next->next->next->next;


print(head);
printf("\n");
print(head2);
printf("intersection point node is %lld and value is %d\n",intersection_point(head,head2),intersection_point(head,head2)->val);
return 0;
}





