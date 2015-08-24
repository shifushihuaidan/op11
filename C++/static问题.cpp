#include<iostream>
using namespace std;
int fun(int a)
{
int b=4;
static int c;
b++;
c++;
return(a+b+c);
}
int main()
{
int a=2,c=3;
cout<<fun(c)<<' '<<fun(a)<<' '<<fun(fun(c))<<endl;
return 0;
}