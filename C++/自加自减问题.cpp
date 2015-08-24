#include<iostream>
using namespace std;
int main()
{
float x=1;
float y;
y=(++x)/(++x)/(++x);
cout<<x<<endl;
cout<<y<<endl;
/*int j=5;
int i=j++*((++j+j++)*j--);     //j=j+1=6 i=j*((j+j)*j) =432   j=j+1 =7 j=j+1=8  j=j-1=7
cout<<i<<endl;
cout<<j<<endl;   */            
return 0;
}