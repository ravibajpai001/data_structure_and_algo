#include<stdio.h>
#include<malloc.h>
struct node{
char val;
struct node*next;
};
typedef struct node node;

/*Stack implementation begin*/
push(char a[],int val,int *size)
{
if(*size>=100)
printf("stack overflow jabardasti");
a[*size]=val;
(*size)++;
}
char pop(char a[],int *size)
{
if((*size)==0)
{
printf("stack is empty\n");
return ;
}
char p;
p=a[*size -1];
(*size)--;
return p;

}

/*Stack implementation end*/
node *addnode(char value)
{
node *xx;
xx=(node *)malloc(sizeof(node));
xx->val=value;
xx->next=NULL;
return xx;
}

/*solution 1 using stack*/
int is_string(node *head)
{
char stack_arr[100];
int size=0;
char x;
node *xyz;
xyz=head;
while(xyz!=NULL)
{
push(stack_arr,xyz->val,&size);
xyz=xyz->next;
}

while(head!=NULL)
{
x=pop(stack_arr,&size);
//printf("stack item is %c \n",x);
if(head->val!=x)
return 0;
head=head->next;

}
return 1;
}
int main()
{
node *head;
head=addnode('n');
head->next=addnode('a');
head->next->next=addnode('m');
head->next->next->next=addnode('a');
head->next->next->next->next=addnode('n');
int a;
a=is_string(head);
if(a==1)
printf("yes\n");
else
printf("no\n");
return 0;
}

