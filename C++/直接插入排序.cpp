#include<iostream>
using namespace std;                           
int main()
{
	int a[5]={10,8,78,98,34},t,i,j;
    for(i=1;i<5;i++)
    {
      if(a[i-1]>a[i])
      {
         t=a[i];
         for(j=i-1;a[j]>a[i];j--)
             a[j+1]=a[j];
          a[j+1]=t;
     }
     }
    for(i=0;i<5;i++)
		cout<<a[i]<<' ';
	return 0;
}
                                               