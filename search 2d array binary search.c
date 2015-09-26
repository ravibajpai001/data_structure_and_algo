/**
 * @input A : 2D integer array ' * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * @input B : Integer
 *
 * @Output Integer
 */
int searchMatrix(int** A, int n11, int n12, int B) {

    int low=1;
    int high=n11*n12;
    int mid ,i,j;
    while(low<=high)
    {
      mid=(low+high)/2;
      i=mid/n12;
      if(mid%n12==0)
      i--;
      j=mid%n12;
      if(j==0)
      j=n12-1;
      else
      j--;
      if(A[i][j]==B)
      {
          return 1;
      }
      else if(A[i][j]>B)
      {

          high=mid;
      }
      else if(A[i][j]<B)
      {

          low=mid+1;
      }


    }
    return 0;


}
int main()
{
int A[][]={11,21,32,44,45,
            56,67,88,90,95,
            100,102,105,110,130};
int p;
p=searchMatrix(&A, 5,5, 88);
if(p==1)
printf("found\n");
else
printf("not found\n");


}
