#include "SeqStack.h"



int main()
{
	SeqStack<int> stack(10);
	int init[10]={1,2,6,9,0,3,8,7,5,4};
	for(int i=0;i<10;i++)
	{
		stack.Push(init[i]);
	}
	stack.Print();
	cout<<"************************\n";

	stack.Push(88);
	cout<<stack.Pop()<<endl;
	stack.Print();
	cout<<"************************\n";
	
	stack.MakeEmpty();
	stack.Print();
	cout<<"************************\n";
    int N,r;
	cout<<"������һ��ʮ���ƣ�";
	cin>>N;
	cout<<"��Ҫת���ɼ����ƣ�";
	cin>>r;
	conversion(N,r);
 
	

	int a;
	cin>>a;
	getchar();
	return 0;
}
