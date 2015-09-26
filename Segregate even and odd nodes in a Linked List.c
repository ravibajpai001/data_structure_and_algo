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
/**method 1 insert odd node at end of the list**/
node *seggregrate_even_or_odd(node *head)
{
node *p=head;
node dummy1;
node dummy2;
node *tail1=&dummy1;
node *tail2=&dummy2;
node *start=head;
while(p!=NULL)
{
if(p->val%2==0)
{
tail1->next=p;
tail1=tail1->next;
}
else
{
tail2->next=p;
tail2=tail2->next;
}
p=p->next;

}
tail2->next=NULL;
tail1->next=dummy2.next;
return dummy1.next;

}


int main()
{
node *head,*res;
head=addnode(5);
head->next=addnode(3);
head->next->next=addnode(13);
head->next->next->next=addnode(6);
head->next->next->next->next=addnode(16);
head->next->next->next->next->next=addnode(7);
head->next->next->next->next->next->next=addnode(15);
head->next->next->next->next->next->next->next=addnode(17);
head->next->next->next->next->next->next->next->next=addnode(8);
head->next->next->next->next->next->next->next->next->next=addnode(10);
head->next->next->next->next->next->next->next->next->next->next=addnode(20);
print(head);
res=seggregrate_even_or_odd(head);print(head);
print(res);
return 0;
}





