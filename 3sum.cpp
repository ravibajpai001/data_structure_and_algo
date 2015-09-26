/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 *
 * @Output Integer
 */
int threeSumClosest(int* A, int n1, int B) {
    for(i=0;i<n1;i++)
    {
        for(j=i+1;j<=n1;j++)
        {
            sum=A[i]+A[j];
            int p=B-sum,tt;
            low=j+1;
            high=n1;
            while(low<high)
            {
                int mid=(low+high)/2;
                if(A[mid]==p)
                {
                    min_diff=0;
                    break;
                }
                else if(A[mid]<B&&A[mid+1]<B)
                {
                low=mid+1;
                }
                else(A[mid]>B&&A[mid-1]>B)
                {
                high=mid-1;
                }
                else if(){


                }
            }

        }
    }
}

