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
					 cout<<"�ڶ���x��ֵΪ"<<x<<endl;
              } 
              x++; 
				cout<<"��һ��x��ֵΪ"<<x<<endl;
	   }
	   cout<<"���x��ֵΪ"<<x<<endl;

}