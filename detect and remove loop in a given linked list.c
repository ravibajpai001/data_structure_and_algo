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
removeloop(node *head ,node *p)
{
node *pt=head;
while(1)
{
node *q=p;
while(q->next!=p&&q->next!=pt)
{
q=q->next;
}
if((q->next)==pt)
{
q->next=NULL;
return ;
}
else
{
pt=pt->next;
}

}



}
loop_detect(node *head)
{
node *p,*q;
p=head;
q=head;
while(q!=NULL&&p!=q||p==head&&q==head)
{
//printf("p address is %lld and q address is %lld\n",p,q);
p=p->next;
q=q->next->next;
}
if(q!=NULL)
{
printf("yaa there is a loop\n");
removeloop(head,p);
printf("new list is\n");
print(head);
}
else
printf("no loop\n");

}


int main()
{
node *head2;
head2=addnode(6);
head2->next=addnode(8);
head2->next->next=addnode(13);
head2->next->next->next=addnode(15);
head2->next->next->next->next=addnode(17);
head2->next->next->next->next->next=addnode(20);
head2->next->next->next->next->next->next=head2->next->next;

//(head2);
loop_detect(head2);

}



