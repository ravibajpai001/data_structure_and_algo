#include<fstream>
#include<iostream>
using namespace std;
struct as
{
string name;
int age;


};
/*void save(fstream &as,struct as  k)
{
//as.write(&(k.name)),sizeof(string);
as.write((k.age),sizeof(int));


}**/
int main()
{

fstream rj;
rj.open("asa.dat",ios::out|ios::binary);

struct as *p;
p->name="ravi";
p->age=11;

rj.write(p,sizeof(p));
//save(rj,p);



rj.close();

return 0;
}
