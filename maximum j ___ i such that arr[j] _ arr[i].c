#include<stdio.h>
int maxjminusi(int *A,int n) {
int *lmin=(int *)malloc(sizeof(int));
int *rmax=(int *)malloc(sizeof(int));
int i,j,diff;
lmin[0]=A[0];
rmax[n-1]=A[n-1];
for(i=1;i<n;i++)
{
if(A[i]<lmin[i-1])
lmin[i]=A[i];
else
lmin[i]=lmin[i-1];
}
for(i=n-1;i>=0;i--)
{
if(A[i]>rmax[i+1])
rmax[i]=A[i];
else
rmax[i]=rmax[i+1];
}
i=0;
j=0;
int max=-1;
while(i<n&&j<n)
{
if(lmin[i]<rmax[j])
{
diff=j-i;
if(diff>max)
max=diff;
j++;
}
else{
i++;
}
}
return diff;
}
int main()
{
int i,n;
n=10;
int b[]={9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
int *A=(int *)malloc(n*sizeof(int));
for(i=0;i<n;i++)
{
A[i]=b[i];
}

printf("ans is %d\n",maxjminusi(A,n));
return 0;
}

