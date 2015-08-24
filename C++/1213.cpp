#include<iostream>
using namespace std;
void main()
{
   int i,j,x=0; 
       for(i=0;i<2;i++) 
       {
              x++;
              for(j=0;j<=3;j++) 
              { 
                     if(j%2) continue; 
                     x++; 
					 cout<<"第二层x的值为"<<x<<endl;
              } 
              x++; 
				cout<<"第一层x的值为"<<x<<endl;
	   }
	   cout<<"最后x的值为"<<x<<endl;

}