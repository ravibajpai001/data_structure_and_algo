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

/*BEGIN:- main solyution of the problem*/

in(node *head1,node *head2,node **inter)
{

//here we are using dummy node approch
//tail always point to last node
node e;
node *tail;
tail=&e;
tail->next=NULL;



node*p,*q,
p=head1;
q=head2;

while(p!=NULL&&q!=NULL)
{
if(p->val==q->val)
{
tail->next=addnode(p->val);
tail=tail->next;
 p=p->next;
 q=q->next;
}
else if(p->val<q->val)
{
p=p->next;

}
else{
q=q->next;
}

*inter=e.next;
}
}







/*END:- main solution of the problem*/
/*node *recursive_intersec(node *a,node *b )
{
if(a==NULL || b==NULL)
{
return NULL;
printf("heelllo returnig null\n");
}

printf("heelllo\n");
node *result;
if(a->val ==b->val)
{
result=a;
printf("new node in result is %lld\n",result);
if(a->next!=NULL&&b->next!=NULL)
result->next=recursive_intersec(a->next,b->next);
}
else if(a->val>b->val)
{
if(a!=NULL&&b->next!=NULL)
result->next=recursive_intersec(a,b->next);
}
else
{
if(a->next!=NULL&&b!=NULL)
result->next=recursive_intersec(a->next,b);
}
//result->next=NULL;
return result;
}
*/


int main()
{
node *head1,*head2;
node **intr;
//node *intr;
head1=addnode(5);
head1->next=addnode(6);
head1->next->next=addnode(9);
head1->next->next->next=addnode(13);
head1->next->next->next->next=addnode(17);
head1->next->next->next->next->next=addnode(20);



head2=addnode(6);
head2->next=addnode(8);
head2->next->next=addnode(13);
head2->next->next->next=addnode(15);
head2->next->next->next->next=addnode(17);
head2->next->next->next->next->next=addnode(20);
print(head1);
print(head2);
in(head1,head2,&intr);
//intr=recursive_intersec(head1,head2);
print(intr);
return 0;
}


