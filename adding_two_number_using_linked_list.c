/*solution is incomplete it,s not giving right answer for linke dlist having diffrent size*/


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
/*This function is using here to find the sum of linked having equal size */
node *recursive_sum(node *a,node *b,int *p)
{
node dummy;
node *tail,*t;
tail=&dummy;
int zz;
if(a->next==NULL&&b->next==NULL)
{
node *pp;
int z;
z=a->val+b->val+*p;
printf("value of z is %d \n",z);
tail->next=addnode(z%10);
*p=z/10;

return dummy.next;
}
tail->next=recursive_sum(a->next,b->next,p);

zz=a->val+b->val+*p;
printf("value of z is %d \n",zz);
t=addnode(zz%10);
t->next=tail->next;
tail->next=t;
*p=zz/10;
return dummy.next;
}

/*This function is using here to add excess part of bigger list to final list */
remaining_list_add(node *fir,node *as,node **result,int *p)
{
//node dummy;
//node *tail;
//tail=&dummy;
node *t;
int zz;
if(as->next==fir)
{
node *pp;
int z;
z=as->val+*p;
pp=addnode(z%10);
*p=z/10;
pp->next=*result;
*result=pp;
printf("value of zz is %d\n",z);
//print(*result);
}
else{
remaining_list_add(fir,as->next,result,p);

zz=as->val+*p;
printf("value of zz is %d\n",zz);
t=addnode(zz%10);
t->next=*result;
*result=t;
*p=zz/10;
}

}

/*This function is using here to swap two list*/
swap_pointer(node **a,node **b)
{
node *t;
t=*a;
*a=*b;
*b=t;
}

node *sumList(node *a,node *b)
{
node *result;
int carry=0,diff;
int fir_s,sec_s;
node *fir,*sec;
fir=a;
sec=b;
fir_s=getsize(a);
sec_s=getsize(b);
if(fir_s==sec_s)
{
result=recursive_sum(fir,sec,&carry);
}
else{
diff=fir_s-sec_s;
if(fir_s<sec_s)
{
swap_pointer(&fir,&sec);
diff=sec_s-fir_s;
}
node *as;
as=fir;
while(diff--)
{
fir=fir->next;
}
result=recursive_sum(fir,sec,&carry);
printf("main hu don\n");
remaining_list_add(fir,as,&result,&carry);
//node *ttt;
//for(ttt=fir)
}
if(carry>0)
{
node *p;
p=addnode(carry);
p->next=result;
result=p;

}
}

int main()
{
node *head1,*head2;
//node **intr;
node *intr;
head1=addnode(5);
head1->next=addnode(6);
head1->next->next=addnode(9);




head2=addnode(6);
head2->next=addnode(8);
head2->next->next=addnode(1);
head2->next->next->next=addnode(5);
print(head1);
print(head2);

intr=sumList(head1,head2);
printf("main function se baahar aa gaya aur segmentation fault nahi ayi hahahahahhah!!!!!\n");
print(intr);
return 0;
}



