#include<iostream>
using namespace std;
class seqlist
{
public:
	int *elem;
	int maxsize;
	seqlist()
	{
        elem=new int [100];
		maxsize=100;
	}
	void inist()
	{
		for(int i=0;i<10;i++)
		{
			elem[i]=i+1;
		}
	}
	void print()
	{
		for(int i=0;i<10;i++)
			cout<<elem[i]<<" ";
	}
	void insert(int i,int x)
	{
		int j;
		for(j=9;j>=i-1;j--)
			elem[j+1]=elem[j];
		elem[i-1]=x;

	}
	void del(int i)
	{
		for(int j=i-1;j<9;j++)
			elem[j]=elem[j+1];
	}
};
int main()
{
	seqlist l;
	l.inist();
	l.print();
	cout<<endl;
	l.insert(2,22);
    l.print();
	cout<<endl;
	l.del(2);
	l.print();
	return 0;
}
	