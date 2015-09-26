 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 bool mycomp(int n1,int n2)
 {
    long long int n1n2,n2n1;
    string a,b,c,d;
    a=to_string(n1);
    b=to_string(n2);
    c=a.append(b);
    d=b.append(a);
   // n1n2=atoi(c);
    //n2n1=atoi(d);
    if(c.compare(d)>0)
    return true;
    else
    return false;
 }

 string largestNumber(const vector<int> &A) {
 int i;
 sort(A.begin(),A.end(),mycomp);
 string pp;
 for(i=0;i<A.size();i++)
 {
     pp=pp.append(to_string(A[i]));
 }
 return pp;
}
int main()
{
vector<int >  a;
string p;
p=largestNumber(a);
printf("%s ",p);
return 0;
}
