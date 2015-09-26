#include<stdio.h>
#include<malloc.h>
struct node{
int val;
struct node *next;
};
typedef struct node node;
/*push(node **head,int value)
{
node *xx,*t;
xx=(node *)malloc(sizeof(node));
xx->val=value;
xx->next=*head;
*head=xx;
}*/

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


/*if m>o then question is straightforward but if m==0 then what???????*/
node *delete_N_node_after_m_node(node *head,int m,int n)
{
node dummy;
node *tail=&dummy;
while(m--)
{

tail->next=head;
printf("inside first loop ,address of tail->next is %lld\n",tail->next);
head=head->next;
tail=tail->next;
}
n=n+1;
while(n--&&head!=NULL)
{
printf("inside second loop address of deleted node is %lld\n",head);
node *tmp;
tmp=head;
head=head->next;
free(tmp);
}
tail->next=head;
return dummy.next;
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
int k=2;
print(head2);
head2=delete_N_node_after_m_node(head2,0,7);
printf("main vappas aa gaya\n");
print(head2);
}





