#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		a=10;
	}
public:
	int a;
};
class B:public A
{
public:
	B()
	{}
};
int main()
{
	B a1;
	cout<<"²âÊÔ"<<a1.a<<endl;
	return 0;
}