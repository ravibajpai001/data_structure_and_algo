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

 end_first(node **head)
 {
 node *p,*q;
 q=NULL;
 p=*head;
 while(p->next!=NULL)
 {
 q=p;
 p=p->next;
 }
 q->next=NULL;
 p->next=*head;
 *head=p;
 print(*head);

 }


int main()
{
node *head;
head=addnode(5);
head->next=addnode(3);
head->next->next=addnode(3);
head->next->next->next=addnode(8);
head->next->next->next->next=addnode(8);
print(head);
end_first(&head);
print(head);
return 0;
}


