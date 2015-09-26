/**
 * @input A : Integer
 *
 * @Output 2D int array. You need to malloc memory. Fill in number_of_rows as row, number_of_columns as columns
 */
 #include<stdio.h>
int ** generateMatrix(int A, int *number_of_rows, int *number_of_columns) {
	// SAMPLE CODE
        /*

         * *number_of_columns = A;
         * int **result = (int **)malloc(A * sizeof(int *));
         * // DO STUFF HERE
         * return result;
         */
        printf("i am here\n");
         int n=A,ii,jj;
           int num=1,i,j;
       int **p = (int **)malloc(A * sizeof(int *));
       for (i=0; i<n; i++)
       p[i] = (int *)malloc(A * sizeof(int));

          printf("i am here 33\n");
         *number_of_rows = A;
         *number_of_columns = A;
         for(i=0;i<n;i++)
         {
             for(j=0;j<n;j++)
             {
                 p[i][j]=0;
             }
         }
         i=0;
         j=0;
                      for(ii=0;ii<n;ii++)
         {
             for(jj=0;jj<n;jj++)
             {
        printf("%d ",p[ii][jj]);
             }
             printf("\n");
         }
         while(1)
         {
            if(num==(n*n+1))
             break;

           //  printf("i am here 444\n");
             while(j<=n-1&&p[i][j]==0)
             {
           //  printf("i am here 44445 ");
             p[i][j]=num;
             printf(" i is %d j is %d value is %d\n",i,j,num);
             num++;
             j++;
             }
             j--;
             i++;
          if(num==(n*n+1))
             break;
             printf(" i is %d j is %d value is %d\n",i,j,num);
            while(i<=n-1&&p[i][j]==0)
             {
              printf("i am here 444777\n");
                 p[i][j]=num;
                  printf("i is %d j is %d value is %d\n",i,j,num);
                 num++;
                 i++;
             }
                              for(ii=0;ii<n;ii++)
         {
             for(jj=0;jj<n;jj++)
             {
        printf("%d ",p[ii][jj]);
             }
             printf("\n");
         }

             i--;
             j--;
               if(num==(n*n+1))
             break;
             printf("i is %d j is %d value is %d",i,j,num);
             while(j>=0&&p[i][j]==0)
             {

                 p[i][j]=num;
                  printf("i is %d j is %d value is %d",i,j,num);
                 num++;
                 j--;
             }
                              for(ii=0;ii<n;ii++)
         {
             for(jj=0;jj<n;jj++)
             {
        printf("%d ",p[ii][jj]);
             }
             printf("\n");
         }
             j++;
             i--;
               if(num==(n*n+1))
             break;
                while(i>=0&&p[i][j]==0)
             {
         printf("i am here 1243\n");
                 p[i][j]=num;
                  printf("i is %d j is %d value is %d",i,j,num);
                 num++;
                 i--;
             }
                              for(ii=0;ii<n;ii++)
         {
             for(jj=0;jj<n;jj++)
             {
        printf("%d ",p[ii][jj]);
             }
             printf("\n");
         }
             i++;
             j++;
              printf("i am here 55\n");
             if(num==(n*n+1))
             break;


         }

         return p;
}

int main()
{

int n,i,j;
n=5;
i=5;
j=5;
int **A;
    A = (int **)malloc(n * sizeof(int *));
         for (i=0; i<n; i++)
         A[i] = (int *)malloc(n * sizeof(int));
A=generateMatrix(n,&i,&j);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d ",A[i][j]);
}
printf("\n");

}



}
