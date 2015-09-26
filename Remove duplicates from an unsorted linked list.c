#include<iostream>
#include<map>
using namespace std;
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
node *remove_duplicate_unsorted(node *head)
{
map<int ,int > mp;






}



int main()
{
node *head;
head=addnode(8);
head->next=addnode(3);
head->next->next=addnode(13);
head->next->next->next=addnode(13);
head->next->next->next->next=addnode(16);
head->next->next->next->next->next=addnode(7);
head->next->next->next->next->next->next=addnode(7);
head->next->next->next->next->next->next->next=addnode(17);
head->next->next->next->next->next->next->next->next=addnode(8);
head->next->next->next->next->next->next->next->next->next=addnode(8);
head->next->next->next->next->next->next->next->next->next->next=addnode(20);

print(intr);
return 0;
}




