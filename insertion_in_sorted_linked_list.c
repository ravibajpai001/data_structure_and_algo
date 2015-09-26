#include<stdio.h>
#include<malloc.h>
struct node{
int val;
struct node *next;
};
typedef struct node node;

prin(node *head)
{
node *root;
root=head;
while(root!=NULL)
{
printf("%d and address is %d \n ",root->val,root);
root=root->next;
}
printf("\n");

}
 node *addnode(int value)
{
node *p;
p=(node *)malloc(sizeof(node));
p->val=value;
p->next=NULL;
return p;
}
void insert_sort_way(node **head,int value)
{

/*First way to do this*/
/*node *prev,*curr,*newr;
curr=*head;
printf("address of head is %d\n",*head);
if((*head)->val>value)
{
newr=addnode(value);
newr->next=*head;
*head=newr;
printf("address of head is %d\n",*head);
return;
}

while((curr->val)<value)
{
printf("xvd\n");
prev=curr;
curr=curr->next;
}
newr=addnode(value);
prev->next=newr;
newr->next=curr;
printf("address of head is %d\n",*head);*/

/*Second way to do this*/

node **curr,*newr;
curr=head;
printf("address of curr is %lld and cuur itself %lld\n",&curr,curr);
while(*curr!=NULL&&(*curr)->val<value)
{
curr=&((*curr)->next);

}
newr=addnode(value);
newr->next=*curr;
*curr=newr;
}
int main()
{
node *head,**s;
head=addnode(5);
head->next=addnode(15);
head->next->next=addnode(20);
head->next->next->next=addnode(38);
head->next->next->next->next=addnode(67);
s=&head;
printf("address of s is %lld and s it's self %lld\n",&s,s);
prin(head);
printf("double pointer address is %lld \n",&head);
insert_sort_way(&head,26);
printf("double pointer address is %lld \n",&head);
prin(head);
insert_sort_way(&head,2);
printf("double pointer address is %lld \n",&head);
prin(head);

return 0;

}
