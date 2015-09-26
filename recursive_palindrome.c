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
printf("%c and address is  %d\n",root->val,root);
root=root->next;
}
printf("\n");
}
int k;
int recursive(node **head,node *left)
{

if(left==NULL)
{
return 1;
}



k=recursive(head,left->next)&&((*head)->val==left->val);
printf(" value is %c left is %d and head is %d \n",left->val,left,*head);
printf(" value of k is %d \n",k);
//if((*head)->next!=NULL)
*head=(*head)->next;
return k;


}

int xxy(node *xx)
{
return recursive(&xx,xx);
}
int main()
{
node *head;
int a;
head=addnode('v');
head->next=addnode('a');
head->next->next=addnode('j');
head->next->next->next=addnode('a');
head->next->next->next->next=addnode('n');
//printf("%d ",&(*head));
print(head);
a=xxy(head);
print("kaile hp\n");
if(a==1)
print("palindrome\n");
else
print("not palindrome\n");
return 0;
}
