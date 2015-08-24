#include<iostream>
using namespace std;
void main()
{
	int a,b,c;
	a=b=c=0;
	bool d=++a||++b;
    cout<<"结果为a"<<a<<endl;
    cout<<"结果为b"<<b<<endl;
    cout<<"结果为c"<<c<<endl;
    bool e=d&&++c;
	cout<<"结果为a"<<a<<endl;
    cout<<"结果为b"<<b<<endl;
    cout<<"结果为c"<<c<<endl;
}