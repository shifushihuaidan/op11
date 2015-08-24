#include<iostream>
using namespace std;
int main()
{
    int i,j,t;
	int a[7]={22,12,44,532,-33,1,7};
	for(i=0;i<6;i++)
	{
		for(j=i+1;j<7;j++)
		{
			if(a[i]>a[j])
			{
				t=a[j];
			    a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(i=0;i<7;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;		
}