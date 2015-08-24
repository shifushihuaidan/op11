#include<Iostream.h>
void swap(int a[])
{ int t;
  t=a[0];
  a[0]=a[1];
  a[1]=t;
}
void main()
{  int data[2]={5,8};
  swap(data);int x=data[0];int y=data[1];
   cout<<x<<y;
}
