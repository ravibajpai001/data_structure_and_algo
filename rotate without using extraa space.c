#include<stdio.h>
int main()
{

int A[2][2]={1,2,
             3,4};

int i,j,tmp;
int n=2;

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf(" %d ",A[i][j]);
}
printf("\n");
}

for(i=0;i<n;i++)
{
for(j=0;j<=i;j++)
{
tmp=A[i][j];
A[i][j]=A[j][i];
A[j][i]=tmp;
//printf(" %d ",A[i][j]);
}
//printf("\n");
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf(" %d ",A[i][j]);
}
printf("\n");
}

for(i=0;i<n;i++)
{
for(j=0;j<n/2;j++)
{
tmp=A[i][j];
A[i][j]=A[i][n-1-j];
A[i][n-1-j]=tmp;
}
}


printf("\n");

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf(" %d ",A[i][j]);
}
printf("\n");
}

return 0;
}

