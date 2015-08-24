#include "SeqList.h"

void SepCombine_While()
{
	SeqList<int> La,Lb,Lc;
	int i,j,k;
	//********************��ʼ��La,Lb˳���
	for(i=1;i<=5;i++)
		La.Insert(i,2*i-1);
	for(j=1;j<=10;j++)
		Lb.Insert(j,2*j);

	La.PrintList();
	cout<<"\n********************************\n";
	Lb.PrintList();
	cout<<"\n********************************\n";
	//********************�ϲ�����
	i=j=k=1;
	while(i<=La.Length()&&j<=Lb.Length())
	{
		if(La.Get(i)<=Lb.Get(j))
		{
			Lc.Insert(k,La.Get(i));
			i++;
			k++;
		}
		else
		{
			Lc.Insert(k,Lb.Get(j));
			j++;
			k++;
		}
	}
	//***********************La��Lb�ĸ�����ʣ���Ԫ�أ�
	if(i>La.Length())
	{
		while(j<=Lb.Length())
		{
			Lc.Insert(k,Lb.Get(j));
			j++;k++;
		}
	}
	else
	{
		while(i<=La.Length())
		{
			Lc.Insert(k,La.Get(i));
			i++;k++;
		}
	}
	Lc.PrintList();
}