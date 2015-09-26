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
node *split_list(node *head)
{
node dummy;
node *tail=&dummy;
tail->next=NULL;
while(head!=NULL&&head->next!=NULL)
{ /*IF WE WRITE (head->next!=NULL&&haed!=NULL) it may give segmentation fault*/
tail->next=head->next;
head->next=head->next->next;
head=head->next;
if(head==NULL)
break;
printf("i am inside loop tail->next is %lld and head is %lld\n",tail->next,head);
tail=tail->next;
}
return dummy.next;
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

print("main lop se wapis aa gaya hi \n");
//print(head);
print(second);
return 0;
}
