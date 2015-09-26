#include<stdio.h>
int mAin()
{

int A[5][5]={1,2,3,4,5,
             6,7,8,9,10,
             11,12,13,14,15,
             16,17,18,19,20,
             21,22,23,24,25};

int i,j;
int n=5;
             for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf(" %d ",A[i][j]);
}
printf("\n");
}

int b[4][5];
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
b[j][n-1-i]=A[i][j];

}
}


for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf(" %d ",b[i][j]);
}
printf("\n");
}

return 0;
}
