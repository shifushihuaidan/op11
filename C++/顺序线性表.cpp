#include<iostream>
#include<iomanip>
using namespace std;
class sqlist
{
public:
	int *data;
	int length;
	int maxsize;

	sqlist()
	{
		data=new int[100];
		length=0;
		maxsize=100;
	}
    void insert(int i,int a)
	{
	
	   int c=this->length;
		for(;c>=i;c--)
		data[c+1]=data[c];
		data[i]=a;
	    this->length++;
	}
	
	void sqlistdel(int i)
	{
	 int c=this->length;
		for(;i<c;i++)
		data[i]=data[i+1];
		data[c-1]=0;
	    this->length--;
	}
	find(int i);
	print();
	~sqlist()
	{
	delete []data;
	}
};
int main()
{
sqlist abc;
int a[5]={1,2,3,4,5};
for(int i=0;i<5;i++)
{
	abc.data[i]=a[i];
	abc.length++;
}
cout<<"�����ǰ���Ա������"<<endl;
for(int j=0;j<abc.length;j++)
cout<<abc.data[j]<<endl;
abc.insert(2,33);
cout<<"����������ݺ�ĵ�ǰ���Ա������"<<endl;
for(j=0;j<abc.length;j++)
cout<<abc.data[j]<<endl;
cout<<"ɾ���ڱ����±���3����"<<endl;
abc.sqlistdel(3);
cout<<"�����ǰ���Ա������"<<endl;
for(j=0;j<abc.length;j++)
cout<<abc.data[j]<<endl;
cout<<"��ǰ��Ĵ����Ч���ݵĳ�����"<<abc.length<<endl;
return 0;
}
