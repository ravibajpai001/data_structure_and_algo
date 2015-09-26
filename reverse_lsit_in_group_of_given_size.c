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


/*this a recursive solution after every k node function is called again with new head*/
node *reverselist(node *head,int k)
{
node *prev,*curr,*x,*t;
prev=NULL;
t=head;
curr=head;
int j=k;
while(curr!=NULL&&j--)
{
x=curr->next;
curr->next=prev;
prev=curr;
curr=x;
}

if(curr!=NULL)
{
t->next=reverselist(x,k);;
}


return prev;

}


int main()
{
node *head2;
head2=addnode(6);
head2->next=addnode(8);
head2->next->next=addnode(13);
head2->next->next->next=addnode(15);
head2->next->next->next->next=addnode(17);
head2->next->next->next->next->next=addnode(20);
head2->next->next->next->next->next->next=addnode(34);
head2->next->next->next->next->next->next->next=addnode(44);
head2->next->next->next->next->next->next->next->next=addnode(47);
int k=3;
print(head2);
head2=reverselist(head2,k);
print(head2);

}




