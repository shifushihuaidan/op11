#include<iostream>
using namespace std;
void main()
{
	int a,b,c;
	a=b=c=0;
	bool d=++a||++b;
    cout<<"���Ϊa"<<a<<endl;
    cout<<"���Ϊb"<<b<<endl;
    cout<<"���Ϊc"<<c<<endl;
    bool e=d&&++c;
	cout<<"���Ϊa"<<a<<endl;
    cout<<"���Ϊb"<<b<<endl;
    cout<<"���Ϊc"<<c<<endl;
}