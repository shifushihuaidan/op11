#include<iostream.h>
#include<fstream>
using namespace std;
int main()
{
	int a[5];
	ofstream outfile("fl.dat",ios::out);
	for(int i=0;i<5;i++)
		a[i]=i+1;
    for(i=0;i<5;i++)
		outfile<<a[i]<<" ";
	outfile.close();
	return 0;


}