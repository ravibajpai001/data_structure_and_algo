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
/******method 1 using counting length
node *nthnode(node *head,int k)
{
node *p=head;
int count =0;
while(p!=NULL)
{
count++;
p=p->next;
}
count=count-k;
while(count--)
{
head=head->next;
}
return head;
}***/

/***using two pointers*/
node *nthnode(node *head,int n)
{
node *fir,*sec;
fir=head;
sec=head;
while(n--)
{
fir=fir->next;
}
while(fir!=NULL)
{
fir=fir->next;
sec=sec->next;
}


return sec;



}


int main()
{
node *head;
head=addnode(5);
head->next=addnode(3);
head->next->next=addnode(13);
head->next->next->next=addnode(6);
head->next->next->next->next=addnode(8);
print(head);
int k=5;
printf("%d th node from end is %d\n",k,nthnode(head,5)->val);
return 0;
}




