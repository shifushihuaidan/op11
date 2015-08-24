#include<iostream>
using namespace std;
void main()
{
	int c,i,n=10;
    int a[10]={1,4,34,7,5,8,34,6,9,110};
    cout<<"请输入你要插入的是第几个位置"<<endl;      //1，找到要插入的位置第   I  个元素
    cin>>i;
	i--;
    cout<<"请输入你插入的数值"<<endl;               //2,从数组最后一个元素开始依次向后移一位
    cin>>c;
    for(int j=9;j>=i;j--)
    a[j+1]=a[j];                                    //  3，第I个元素的值就空出来了，你再给他输入你想输入的值即可
    a[i]=c;
    for(i=0;i<11;i++)
    cout<<a[i]<<' ';                                // 然后数组的长度增加了 1
}
