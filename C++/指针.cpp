#include<iostream>
using namespace std;
int main()
{

	int a[5]={1,2,3,4,5};
	int *pa,*pb;
	pa=&a[0];
	pb=&a[4];
	cout<<"*pa--"<<*pa<<endl;
	cout<<"*pb--"<<*pb<<endl;
	pa=pa+2;
	cout<<"pa+2--"<<*pa<<endl;
	pa++;
	cout<<"pa++--"<<*pa<<endl;
	int c=pb-pa;
	cout<<"c="<<c<<endl;
	return 0;
}