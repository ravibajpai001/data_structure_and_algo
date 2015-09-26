/** the problem is an extension of reverse list in group of size k***/

#include<stdio.h>
#include<malloc.h>
struct node{
char val;
struct node *next;
};
typedef struct node node;

node *addnode(char value)
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
printf("value is %d and address is %lld\n",root->val,root);
root=root->next;
}
printf("\n");
}

 node *reverse_alternet_k_node(node *head,int k,int flag)
 {
 node *prev,*curr,*next;
 prev=NULL;
 curr=head;
  int n=k;
 if(flag==1)
 {
 while(curr!=NULL&&k--)
 {
 next=curr->next;
 curr->next=prev;
 prev=curr;
 curr=next;
 }
 if(next!=NULL)
 head->next=reverse_alternet_k_node(next,n,1-flag);
/*feeling happy*/
 return prev;
 }
 else if(flag==0)
 {
 node *p=head,*prev;
 while(p!=NULL&&k--)
 {
 prev=p;
 p=p->next;
 }
 if(p!=NULL)
 prev->next=reverse_alternet_k_node(p,n,1-flag);
 return head;
 }

 }
int main()
{
node *head,*ans;
head=addnode(5);
head->next=addnode(4);
head->next->next=addnode(6);
head->next->next->next=addnode(12);
head->next->next->next->next=addnode(13);
head->next->next->next->next->next=addnode(113);
head->next->next->next->next->next->next=addnode(45);
head->next->next->next->next->next->next->next=addnode(63);
head->next->next->next->next->next->next->next->next=addnode(78);
head->next->next->next->next->next->next->next->next->next=addnode(99);
print(head);
int k=2;
ans=reverse_alternet_k_node(head,k,1);
print(ans);
return 0;
}

