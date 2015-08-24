#include <iostream>   
using namespace std;  

void main()
{   
	int a[2]={1,2},*p;
	p=&a[1];
	cout<<*p<<endl;
}