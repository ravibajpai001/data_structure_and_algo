/**
 * @input A : Integer
 *
 * @Output 2D int array. You need to malloc memory. Fill in number_of_rows as row.
 * For each row i, A[i][0] should indicate the number of columns in row i.
 * Then A[i][1] to A[i][col] should have the values in those columns.
 */
 generate(int A, int *number_of_rows) {
	// SAMPLE CODE
	/*
	 * *number_of_rows = A;
	 * int **result = (int **)malloc(A * sizeof(int *));
	 * // DO STUFF HERE
	 * return result;
	 */
	 int m=1,i,j;
int **result=(int **)malloc(A*sizeof(int *));
  for(i=0;i<A;i++)
  {

      result[i]=(int *)malloc(m*sizeof(int));
      m++;
  }
 j=0;
 i=0;
  result[i][j]=1;
 // printf("haha %d",result[0][0]);
  for(i=1;i<A;i++)
  {
  for(j=0;j<=i;j++)
      {
         if(j==i||j==0)
         result[i][j]=1;
         else
         result[i][j]=result[i-1][j-1]+result[i-1][j];

     }
  }

m=1;
  for(i=0;i<A;i++)
  {
  for(j=0;j<m;j++)
      {
          printf("  %d ",result[i][j]);
     }
     printf("\n");
      m++;
  }
  //*number_of_rows=A;
//return result;

}
int main()
{

int n;
generate(7,&n);

}
