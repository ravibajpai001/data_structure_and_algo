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
reverse(node **p)
{
node *prev,*curr,*x;
prev=NULL;
curr=*p;
while(curr!=NULL)
{
x=curr->next;
curr->next=prev;
prev=curr;
curr=x;
}
*p=prev;


}
solution(node **head)
{
reverse(head);

node *x,*p,*last;
x=*head;
int max=x->val;
p=x->next;
last=x;
while(p!=NULL)
{

if(p->val<max)
{
node *tmp;
tmp=p;
last->next=p->next;
p=p->next;
free(tmp);
}
else if(p->val > max)
{
max=p->val;
last=p;
p=p->next;
}


}
*head=x;
reverse(head);


}






int main()
{
//12->15->10->11->5->6->2->3->NULL
node *head2;
head2=addnode(12);
head2->next=addnode(15);
head2->next->next=addnode(10);
head2->next->next->next=addnode(11);
head2->next->next->next->next=addnode(5);
head2->next->next->next->next->next=addnode(6);
head2->next->next->next->next->next->next=addnode(2);
head2->next->next->next->next->next->next->next=addnode(3);
printf("original list\n");
print(head2);
solution(&head2);

printf("answer list\n");
print(head2);

}




