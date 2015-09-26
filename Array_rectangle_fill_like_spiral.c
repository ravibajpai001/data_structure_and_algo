/**
 * @inresultut A : Integer
 *
 * @Outresultut 2D int array. You need to malloc memory. Fill in number_of_rows as row, number_of_columns as columns
 */
 #include<stdio.h>
 #include<malloc.h>
int ** generateMatrix(int A, int *number_of_rows, int *number_of_columns) {
	// SAMresultLE CODE
        /*

         * *number_of_columns = A;
         * int **result = (int **)malloc(A * sizeof(int *));
         * // DO STUFF HERE
         * return result;
         */
      //  resultrintf("i am here\n");
         int n=A,ii,jj;
           int num=1,i,j;
       int **result = (int **)malloc((2*n-1)* sizeof(int *));
       for (i=0; i<(2*n-1); i++)
       result[i] = (int *)malloc((2*n-1)* sizeof(int));

        //  resultrintf("i am here 33\n");
         *number_of_rows = A;
         *number_of_columns = A;
         for(i=0;i<=2*n-2;i++)
         {
             for(j=0;j<=2*n-2;j++)
             {
         //    resultrintf("i am here hi hi hi33\n");
                 result[i][j]=0;
             }
         }
        // resultrintf("i am here hi hi hi33777\n");
         i=0;
         j=0;

            /* for(jj=0;jj<n;jj++)
             {
        resultrintf("%d ",result[ii][jj]);
             }
             resultrintf("\n");
         }*/
         num=n;
         while(1)
         {
          if(num==0)
            break;
           //  resultrintf("i am here 444\n");
             while(j<=2*n-2&&result[i][j]==0)
             {
             result[i][j]=num;
           //  printf(" i is %d j is %d value is %d\n",i,j,num);
             j++;
             }
            // if(j==n-1)
             j--;
             i++;
          if(num==0)
            break;
            // printf(" i is %d j is %d value is %d\n",i,j,num);
            while(i<=2*n-2&&result[i][j]==0)
             {
             // resultrintf("i am here 444777\n");
                 result[i][j]=num;
                 // resultrintf("i is %d j is %d value is %d\n",i,j,num);
                 i++;
             }
             i--;
             j--;


             if(num==0)
            break;
            // resultrintf("i is %d j is %d value is %d",i,j,num);
             while(j>=0&&result[i][j]==0)
             {
                 result[i][j]=num;
                //  printf("i is %d j is %d value is %d\n",i,j,num);
                // num++;
                 j--;
             }


             j++;
             i--;
             if(num==0)
            break;
                while(i>=0&&result[i][j]==0)
             {
        // resultrintf("i am here 1243\n");
                 result[i][j]=num;
                //  printf("i is %d j is %d value is %d\n",i,j,num);
                // num++;
                 i--;
             }

             i++;
             j++;

             num--;

             if(num==0)
            break;

         }

         return result;
}

int main()
{
int n,i,j;
n=4;
i=5;
j=5;
int **A;
    A = (int **)malloc((2*n-1) * sizeof(int *));
         for (i=0; i<(2*n-1); i++)
         A[i]=(int *)malloc((2*n-1)* sizeof(int));
A=generateMatrix(n,&i,&j);
for(i=0;i<2*n-1;i++)
{
for(j=0;j<2*n-1;j++)
{
printf("%d ",A[i][j]);
}
printf("\n");

}
return 0;
}
