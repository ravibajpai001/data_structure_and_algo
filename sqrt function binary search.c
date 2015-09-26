#include<stdio.h>
int sqrt(int A) {
double low=0;
double high=A;
double mid=0;
double old =-1;
while((old -mid) >0.000001||(mid-old)>0.000001)
{
printf("low is %lf high is %lf mid is %lf and old is %lf\n",low,high,mid ,old);
old=mid;
mid=(low+high)/2;
double z;
z=mid*mid;
if(z==A)
return mid;
if(z  > A)
high=mid;
else if(z<A)
low=mid;
}
printf("last time low is %.10lf high is %.10lf mid is %.10lf and old is %.10lf\n",low,high,mid ,old);
//printf("mid is %lf it's floor is %ld\n",mid,floor(mid));
//old=mid;
//int zzz=mid;
return floor(high);

}
int main()
{

int n=sqrt(4);
printf("%d ",n);


return 0;
}
