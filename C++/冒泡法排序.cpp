#include<iostream>
using namespace std;
int main()
{
    int i,j,t;
	int a[7]={22,12,44,532,-33,1,7};
	for(j=0;j<6;j++)
	{
		for(i=0;i<7-j;i++)
		{
			if(a[i]>a[i+1])
			{
				t=a[i+1];
			    a[i+1]=a[i];
				a[i]=t;
			}
		}
	}
	for(i=0;i<7;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;		
}