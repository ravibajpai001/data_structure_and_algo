//there are three approches one is using dummy node ,another is using local reference and the last one is using recursion
//i will try using dummay node and recursion
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


/*node *merge(node **a, node **b)
{
1-using dummy node

//create a dummmy node
//tail is always pointing to last node
node dummy;
node *tail;
tail=&dummy;
node *p,*q;
p=*a;
q=*b;
while(p!=NULL&&q!=NULL)
{

if((p->val)>=(q->val))
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
tail=tail->next;
}
}
if(q!=NULL)
{
while(q!=NULL)
{
tail->next=q;
q=q->next;
tail=tail->next;
}
}
return dummy.next;




}
*/
node *recursive_merge(node * a,node *b)
{
if(a==NULL)
return b;
else if(b==NULL)
return a;
node *result;
if(a->val<=b->val)
{
result=a;
result->next=recursive_merge(a->next,b);
}
else{
result=b;
result->next=recursive_merge(a,b->next);
}
return result;
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

//(head2);
//finallist=merge(&head1,&head2);
finallist=recursive_merge(head1,head2);
print(finallist);
}




