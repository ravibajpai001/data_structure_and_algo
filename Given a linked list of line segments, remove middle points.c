/*solution is incomplete it,s not giving right answer for linke dlist having diffrent size*/


#include<stdio.h>
#include<malloc.h>
struct node{
int xval;
int yval;
struct node *next;
};
typedef struct node node;

node *addnode(int value1,int value2)
{
node *xx;
xx=(node *)malloc(sizeof(node));
xx->xval=value1;
xx->yval=value2;
xx->next=NULL;
return xx;
}

print(node *head)
{
node *root;
root=head;
while(root!=NULL)
{
printf("x is %d y is %d and address is %ld\n",root->xval,root->yval,root);
root=root->next;
}
printf("\n");
}


/*This function is using here to find the size of linked list */
int getsize(node *head)
{
int p=0;
while(head!=NULL)
{
p++;
head=head->next;
}

return p;
}
/
node *remove_middle(node *head)
{
int flag=0;
node *p=head;
//(0,10)->(1,10)->(5,10)->(7,10)
  // int flag=0;                               //|
                               // (7,5)->(20,5)->(40,5)
while(p!=NULL&&p->next!=NULL&&p->next->next!=NULL)
{
if(p->xval==p->next->xval&&p->xval==p->next->next->xval)
{
node *z;
z=p->next;
p->next=p->next->next;
//flag=1;
}
else if(p->yval==p->next->yval&&p->yval==p->next->next->yval)
{
node *z;
z=p->next;
p->next=p->next->next;
}
else
{
p=p->next;
}

}



return head;
}








int main()
{
node *head1,*head2;
//node **intr;
node *intr;
head1=addnode(2,3);
head1->next=addnode(4,3);
head1->next->next=addnode(6,3);
head1->next->next->next=addnode(10,3);
head1->next->next->next->next=addnode(12,3);
//head1->next->next->next->next->next=addnode(20,5);
//head1->next->next->next->next->next->next=addnode(40,5);

//2,3)->(4,3)->(6,3)->(10,3)->(12,3)
print(head1);

intr=remove_middle(head1);
printf("main function se baahar aa gaya aur segmentation fault nahi ayi hahahahahhah!!!!!\n");
print(intr);
return 0;
}




