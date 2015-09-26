#include<stdio.h>
struct node{
int val;
struct node*next;
};
typedef struct node node;
print_recursive(node *head)
{
if(head==NULL)
return;
print_recursive(head->next);
printf("%d ",head->val);
}
node *addnode(int value)
{
node *xx;
xx=(node *)malloc(sizeof(node));
xx->val=value;
xx->next=NULL;
return xx;
}

int main()
{
node *head;
head=addnode(5);
head->next=addnode(3);
head->next->next=addnode(4);
head->next->next->next=addnode(6);
head->next->next->next->next=addnode(14);

print_recursive(head);


return 0;
}
