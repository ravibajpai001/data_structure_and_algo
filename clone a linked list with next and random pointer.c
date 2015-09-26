
/*This code is working but my approch is wrong so wrong appproch is in commented part*/

#include<stdio.h>
struct node
{
int val;
struct node *next;
struct node *random;
};
typedef struct node node;

node *addnode(int value)
{
node *xx;
xx=(node *)malloc(sizeof(node));
xx->val=value;
xx->next=NULL;
xx->random=NULL;
return xx;
}

print(node *head)
{
node *root;
root=head;
while(root!=NULL)
{
printf("%d and address is %ld random address is %lld value at random %lld \n",root->val,root,root->random,root->random->val);
root=root->next;
}


}

/*node *clone(node *head )
{
node dummy;
node *tail=&dummy;
node *p=head;
while(p!=NULL)
{
tail->next=addnode(p->val);
tail->next->random=p;
p=p->next;
tail=tail->next;
}
node *q;
q=dummy.next;
while(q!=NULL)
{
q->random=q->random->random;
q=q->next;
}

return dummy.next;

}
*/
node * clone(node *head)
{
node *p=head;
while(p!=NULL)
{
node *new;
new=addnode(p->val);
new->next=p->next;
p->next=new;
p=p->next->next;
}
node *orig=head;
node *copy=head->next;
while(copy!=NULL)
{
copy->random=orig->random->next;
if(copy->next==NULL)
break;
copy=copy->next->next;
orig=orig->next->next;
}
printf("merge list is \n");
print(head);
printf("\n");
/*now splitting of copy list from original list*/
orig=head;
copy=head->next;
node *ans=copy;
while(copy!=NULL&&copy->next!=NULL)
{
orig->next=orig->next->next;
copy->next=copy->next->next;
orig=orig->next;
copy=copy->next;
}
return ans;

}
int main()
{

//12->15->10->11->5->6->2->3->NULL
node *head2;
head2=addnode(1);
head2->next=addnode(2);
head2->next->next=addnode(3);
head2->next->next->next=addnode(4);
head2->next->next->next->next=addnode(5);


head2->random=head2->next->next;
head2->next->random=head2;
head2->next->next->random=head2->next->next->next->next;
head2->next->next->next->random=head2->next->next;
head2->next->next->next->next->random=head2->next;
print(head2);
node *copy;
printf("copy list is\n");
copy=clone(head2);
print(copy);


}
