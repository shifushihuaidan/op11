#include "SeqList.h"

void SepCombine_For()
{
	SeqList<int> La,Lb,Lc;
	int i,j,k;
	//********************��ʼ��La,Lb˳���
	for(i=1;i<=5;i++)
		La.Insert(i,2*i-1);
	for(j=1;j<=5;j++)
		Lb.Insert(j,2*j);

	La.PrintList();
	cout<<"\n********************************\n";
	Lb.PrintList();
	cout<<"\n********************************\n";
	//********************�ϲ�����
	k=1;
	int m=1;
	for(i=1;i<=La.Length();i++)
	{
		for(j=m;j<=Lb.Length();j++)
		{
			if(La.Get(i)<=Lb.Get(j))
			{
				Lc.Insert(k,La.Get(i));
				k++;
				break;
			}
			else
			{
				Lc.Insert(k,Lb.Get(j));
				m++;
			}
			k++;

		}
	}
	//********************Lb���ܻ�û��
	for(j=m;j<=Lb.Length();j++)
	{
		Lc.Insert(k,Lb.Get(j));
	}
	Lc.PrintList();
}