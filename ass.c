/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
 #include<stdio.h>
 #include<stdlib.h>
int* plusOne(int* A, int n1, int *length_of_array) {
	// SAMPLE CODE
        /*
         * *length_of_array = n1 + 1; // length of result array
         * int *result = (int *) malloc(*length_of_array * sizeof(int));
         * // DO STUFF HERE. NOTE : length_of_array can be n1 OR n1 + 1.
         * return result;
         */
         int carry=1,n,j;
         n=n1;
         for(j=n-1;j>=0;j--)
         {


                 A[j]=A[j]+carry;
                 carry = A[j]/10;
                 A[j] %= 10;


         }
         if(carry)
         {
            // printf("value of ni s %d\n",n);
             A=(int *)realloc(A,sizeof(int)*(n+1));
                 for(j=n-1;j>=0;j--)
         {


               //printf("hello1\n");

                 A[j+1]=A[j];
                 // printf("hello2\n");




         }
    // printf("length of array %d\n",*length_of_array);
         *length_of_array=n+1;
        // int i;
       //  printf("length of array %d\n",*length_of_array);
        // for(i=0;i<=*length_of_array;i++)
        // {

          //   printf("%d ",A[i]);
        // }
            A[0]=carry;
         }
         return A;
}
int main()
{
int A[]={0};
int p;
int *q;
q=plusOne(A, 1,&p);

printf("%d",*q);
}

