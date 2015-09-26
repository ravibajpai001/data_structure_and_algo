#include<iostream>
#include<fstream>
using namespace std;

int main()
{
/**i want to write some data on file * */

fstream as;
as.open("as.txt",ios::ate);
as<<"hello\n";
as<<"hello world\n";


as.close();




return 0;
}
