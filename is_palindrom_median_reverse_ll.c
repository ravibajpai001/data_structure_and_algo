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
printf("%c ",root->val);
root=root->next;
}
printf("\n");
}

 is_mid_middle_reverse(node *head)
{
node *fir,*sec,*mid1,*mid2,*pp;
//printf("%d ",&(*head));
fir=head;
sec=head;
printf("hello\n");
while(sec!=NULL&&sec->next!=NULL)
{
pp=fir;
fir=fir->next;
sec=sec->next->next;
}
print(head);
if(sec!=NULL)
{
mid1=fir;
mid2=fir->next;
}
else{
mid1=pp;
mid2=fir;
}
//*if there are even node then reverse the lise form mid2 and add it's header to mid1;*/
print(head);
node *prev,*curr;
prev=NULL;
node *newr;
curr=mid2;
while(curr!=NULL)
{
print(head);
printf("\n");
newr=curr->next;
curr->next=prev;
prev=curr;
curr=newr;
}
mid1->next=prev;
printf("%d ",&(*head));
print(head);

}



int main()
{
node *head;
head=addnode('n');
head->next=addnode('a');
head->next->next=addnode('m');
head->next->next->next=addnode('a');
head->next->next->next->next=addnode('n');
printf("%d ",&(*head));
print(head);
is_mid_middle_reverse(head);
return 0;
}
