#include <iostream>
#include "A.h"
using namespace std;

void f1()
{
	int x=100;
	int* p;
	p=&x;
	cout<<(*p)<<"\n";

}
void f2()
{
	int a[]={1,2,3,4,5,6};
	int* p;
	p=a;
	while(p)
	{
		cout<<(*p)<<"\n";
		p++;
		if((*p)==6)
			break;
	}
}
void f3()
{
	char a[]="jlkajjflkajdkjfjjjjj";
	char* p=a;
	while(p)
	{
		cout<<(*p)<<"\n";
		p++;
		if((*p)=='\0')
			break;
	}
}
int main()
{
	f1();
	cout<<"*************************************\n";
	f2();
	cout<<"*************************************\n";
	f3();
	cout<<"*************************************\n";
	A* a=new A();
	a->x=19;
	cout<<a->x;
	getchar();	
	return 0;

}