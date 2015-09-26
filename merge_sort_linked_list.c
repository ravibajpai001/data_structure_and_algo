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
merge_sort(node **headref)
{
node *a,*b,*head;
head=*headref;

//1-if list is empty or unit length
if(head==NULL || head->next==NULL)
return ;

//2-split the list into two list
split(head,&a,&b);

//3-sort individual list
merge_sort(&a);
merge_sort(&b);

//4-merge sorted list
*headref=merge(&a,&b);
}
split(node *head,node **a,node **b)
{
node *p,*q,*be_p;
p=head;
q=head;
while(q!=NULL&&q->next!=NULL)
{
be_p=p;
p=p->next;
q=q->next->next;;
}
if(q==NULL)
{
*a=head;
be_p->next=NULL;
*b=p;
}
else if(q->next==NULL)
{
*a=head;
*b=p->next;
p->next=NULL;

}
}

merge(node **a, node **b)
{
node dummy;

node *tail;
tail=&dummy;
dummy.next=NULL;
//tail points to last node;
node *p,*q;
p=*a;
q=*b;
while(p!=NULL&&q!=NULL)
{
if(p->val>=q->val)
{
tail->next=q;
q=q->next;
}
else
{
tail->next=p;
p=p->next;
}
tail=tail->next;
}
if(p!=NULL)
{
while(p!=NULL)
{
tail->next=p;
p=p->next;
}
}
else if(q!=NULL)
{
while(q!=NULL)
{
tail->next=q;
q=q->next;
}
}

return dummy.next;
}

int main()
{
node *head2;
head2=addnode(16);
head2->next=addnode(8);
head2->next->next=addnode(103);
head2->next->next->next=addnode(15);
head2->next->next->next->next=addnode(7);
head2->next->next->next->next->next=addnode(20);

//(head2);
merge_sort(&head2);
print(head2);

}




