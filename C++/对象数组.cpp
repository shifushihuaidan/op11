#include<iostream>
using namespace std;
class student
{
public:
	int data;
	student(int a)
	{
	data=a;
	}

};
int main()
{    int i,j;
    student t(0);
	student stu[7]={22,33,11,44,21,3,1};
for(j=0;j<=6;j++)
	{
		for(i=0;i<=7-j;i++)
		{
			if(stu[i].data>stu[i+1].data)
			{
				t.data=stu[i+1].data;
			    stu[i+1].data=stu[i].data;
					
				stu[i].data=t.data;
			}
		}
	}
	for(i=0;i<7;i++)
		cout<<stu[i].data<<" ";
	cout<<endl;
	return 0;

}