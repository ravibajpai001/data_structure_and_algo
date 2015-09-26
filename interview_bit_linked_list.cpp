
#include<stdio.h>
#include<malloc.h>
struct ListNode{
int val;
struct ListNode *next;
};
typedef struct ListNode ListNode;
/*push(ListNode **head,int value)
{
ListNode *xx,*t;
xx=(ListNode *)malloc(sizeof(ListNode));
xx->val=value;
xx->next=*head;
*head=xx;
}*/

ListNode *addListNode(int value)
{
ListNode *xx;
xx=(ListNode *)malloc(sizeof(ListNode));
xx->val=value;
xx->next=NULL;
return xx;
}

void print(ListNode *head)
{
ListNode *root;
root=head;
while(root!=NULL)
{
printf("%d and address is %ld\n",root->val,root);
root=root->next;
}
printf("\n");
}


/*if m>o then question is straightforward but if m==0 then what???????*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* removeNthFromEnd(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode dummy;

    ListNode *tail=&dummy;
    ListNode *first,*second;
    printf("main vappas aa gaya aaaaa\n");
    first=A;
    second=A;
    int n=B;
    n--;
    while(second!=NULL&&n--)
    {
    printf("hello hi how are you\n");
        second=second->next;
    }
    printf("333main vappas aa gaya\n");
    if(second==NULL)
    {
       A=A->next;
        if(A==NULL)
        {
         return NULL;
        }
       while(A!=NULL)
       {
        printf("hello hi how are you 25323\n");
           tail->next=A;
           A=A->next;
           tail=tail->next;
       }
       return dummy.next;
    }
    printf("444main vappas aa gaya\n");
    while(second->next!=NULL&&second->next->next!=NULL)
    {
     printf("hello hi how are you eef f25323\n");
        second=second->next;
        first=first->next;
    }
    if(first==A)
    {
     printf("555hello hi how are you dgdfg\n");
       if(A->next!=NULL)
       {
        A=A->next;
       printf("hello hi how are you dgdfg\n");
       while(A!=NULL)
       {
           tail->next=A;
           A=A->next;
           tail=tail->next;
       }
       return dummy.next;
       }
       else{
   printf("666hello hi how are you dgdfg\n");
       return NULL;
       }
    }
    else
    {
    printf("hi how are you\n");
      first->next=first->next->next;
      return A;

    }
}



int main()
{
ListNode *head2;
head2=addListNode(6);
/*head2->next=addListNode(8);
head2->next->next=addListNode(13);
head2->next->next->next=addListNode(15);
head2->next->next->next->next=addListNode(17);
head2->next->next->next->next->next=addListNode(20);
head2->next->next->next->next->next->next=addListNode(34);
head2->next->next->next->next->next->next->next=addListNode(44);
head2->next->next->next->next->next->next->next->next=addListNode(47);*/
int k=2;
print(head2);
ListNode *p;
printf("main vappas aa g frfaya\n");
p=removeNthFromEnd(head2,1);
printf("main vappas aa gaya\n");
print(p);
}





