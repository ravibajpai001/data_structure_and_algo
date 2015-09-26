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
printf("%d ",root->val);
root=root->next;
}
printf("\n");
}

 duplicate_remove(node *head)
 {
 int num;
  num=head->val;
 node *p,*q;
 q=head;
 p=head->next;
 while(p!=NULL)
 {
 if(p->val==num)
 {
 q->next=p->next;
 free(p);
 p=q->next;
 num=q->val;
 }
 else{

   p=p->next;
   q=q->next;
   num=p->val;

 }

 }


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
duplicate_remove(head);
print(head);
return 0;
}

