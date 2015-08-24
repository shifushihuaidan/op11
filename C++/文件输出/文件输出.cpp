#include<iostream.h>
#include<fstream>
using namespace std;
int main()
{
	int a[5],i;
	ofstream outfile("fl.txt",ios::out);
	for(i=0;i<5;i++)
		a[i]=i+1;
    for(i=0;i<5;i++)
		outfile<<a[i]<<" ";
	outfile.close();
	ifstream infile("fl.txt",ios::in);
    for(i=0;i<5;i++)
		infile>>a[i];
    for(i=0;i<5;i++)
		cout<<a[i]<<endl;
	infile.close();
	return 0;


}