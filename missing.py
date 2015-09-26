lass Solution:
    # @param A : tuple of integers
    # @return a list of integers
    def repeatedNumber(self, A):

        #x-> m-d
        #y-> m+d

        sum=0
        s_sum=0
        for i in A:
            sum+=i
            s_sum+=i*i
        n1=len(A)
        x=n1
        x*=n1+1
        x/=2
        x-=sum

        y=n1
        y*=n1+1
        y*=2*n1+1
        y/=6
        y-=s_sum
        y=y/x

        m=(x+y)/2
        d=(y-x)/2;

        res = [d,m]
        #res[0]=d;
        #res[1]=m;

        return res;
