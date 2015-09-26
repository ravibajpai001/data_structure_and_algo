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
int count(node *head,int k)
{
int count=0;
while(head!=NULL)
{
if(head->val==k)
count++;
head=head->next;
}
return count;


}

int main()
{
node *head;
head=addnode(5);
head->next=addnode(3);
head->next->next=addnode(3);
head->next->next->next=addnode(3);
head->next->next->next->next=addnode(8);
print(head);
printf("occurence is %d\n",count(head,3));
return 0;
}



