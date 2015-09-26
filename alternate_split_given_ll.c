#include<stdio.h>
#include<malloc.h>
struct node
{
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
node *root;
root=head;
while(root!=NULL)
{
printf("%d and address is %lld\n",root->val,root);
root=root->next;
}
printf("\n");
}
/*Begin :I am trying to implement using reference variable*/
node *split_list(node *p)
{
node* result = NULL;
 // struct node** lastPtrRef = &result;
 printf("%lld \n",result);
node **jj=&result;;
printf("i am here %lld\n",&result);
node *head=p;
while(head->next!=NULL)
{
//printf("i am here\n");
*jj=head->next;
printf("printf jj is %lld *jj is %lld value is %lld head is %lld\n",jj,*jj,(*jj)->val,head);
head->next=head->next->next;
head=head->next;
//if((*jj)->next!=NULL)
jj=&((*jj)->next);
//else
if(head==NULL)
break;
printf("address is %lld\n",*jj);
}
printf("result is %lld result value is %lld \n",result,result->val);
return result;
/*end:*/
}
int main()
{
node j;
node *head;
node *second;
head=addnode(13);
head->next=addnode(13);
head->next->next=addnode(20);
head->next->next->next=addnode(28);
head->next->next->next->next=addnode(58);
head->next->next->next->next->next=addnode(88);
print(head);
second=split_list(head);

print("hi \n");
print(head);
print(second);
return 0;
}
