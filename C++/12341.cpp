#include<iostream>
#include<string>
using namespace std;
#include<windows.h>
#define N 3
void f1()
{
	system("color 04");
    void f2(int);
	cout<<"����ʳƷ����ϵͳ"<<endl;
    cout<<"1�������Ʒ"<<endl;
    cout<<"2,������Ʒ"<<endl;
    cout<<"3����ʾ��Ʒ"<<endl;
    cout<<"4,�˳�ϵͳ"<<endl;
    cout<<"���������ѡ��"<<endl;
	int a;
	cin>>a;
	f2(a);
}
class good
{
protected:
    string name[N];
	int num[N];
	int count;
public:
	virtual void addg()=0;
	virtual void saleg()=0;
	virtual void showg()=0;
	good()
	{
		count=0;
	}
};
class day:public good
{
public:
	void addg();
	void saleg();
	void showg();
	day():good()
	{}
};
void day::addg()
{
    if(count==N)
	{
        cout<<"�Բ��������Ʒ������Ŀ�ѵ����ޣ������������"<<endl;
	}
	else
	{
	    cout<<"������Ҫ��ӵ��ճ���Ʒ���������"<<endl;
	    int a,i=0,j=0,ab=0;
	    cin>>a;
		string aa[N];
        cout<<"����������ֺ�����"<<endl;
	    for(;i<a;i++)
		{
            cout<<"�������"<<i+1<<"�����������"<<endl;
			cin>>aa[i];
			for(;j<count;j++)
			{
				if(name[j]==aa[i])
                {
					cout<<"�Ѿ����ڸ�����Ʒ"<<endl;
                    count--;
					cout<<"��������Ҫ��Ӹ���"<<endl;
	                cin>>ab;
					num[j]+=ab;
					break;
				}
			}
            count++;
		    if(count==N)
			{
                cout<<"�Բ��������Ʒ������Ŀ�ѵ����ޣ������ټ������������"<<endl;
				break;
			}
			if(ab==0)
			{
				name[i]=aa[i];
                cout<<"��������Ӹ���"<<endl;
	            cin>>num[i];
			}
		}
	}
	system("pause");
	system("cls");
	f1();
}
void day::saleg()
{
	char aa[100],j=0,k=0;
	cout<<"��������Ҫ���۵���Ʒ������"<<endl;
	cin>>aa;
	for(;j<count;j++)
	{
		if(aa==name[j])
		{
			cout<<"�и���Ʒ����������Ҫ���۵�����"<<endl;
			cin>>k;
			if(k<0||k>num[j])
			{
				cout<<"��Ǹ������û����ô�࣬����Ʒ����"<<num[j]<<endl;
			}
			else
			{
				cout<<"�����㹻,��͸���"<<endl;
				num[j]-=k;
			}
		}
		else
		{
            cout<<"��Ǹ��û�и���Ʒ"<<endl;break;
		}
	}
    system("pause");
    system("cls");
	f1();
}
void day::showg()
{
	cout<<"������Ʒ��Ϣ����"<<endl;
    cout<<"������ƷĿǰ��������Ϊ"<<endl;
    cout<<count<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<"����"<<name[i]<<' '<<"����"<<num[i]<<endl;
	}
    system("pause");
    system("cls");
	f1();
}
class food:public good
{
	int time[N];
public:
    void addg();
	void saleg();
	void showg();
};
void food::addg()
{
    if(count==N)
	{
        cout<<"�Բ��������Ʒ������Ŀ�ѵ����ޣ������������"<<endl;
	}
	else
	{
	    cout<<"������Ҫ��ӵ�ʳƷ����������"<<endl;
	    int a,i=0,j=0,ab=0;
	    cin>>a;
		string aa[N];
        cout<<"����������ֺ�����"<<endl;
	    for(;i<a;i++)
		{
            cout<<"�������"<<i+1<<"�����������"<<endl;
			cin>>aa[i];
			for(;j<count;j++)
			{
				if(name[j]==aa[i])
                {
					cout<<"�Ѿ����ڸ�����Ʒ"<<endl;
                    count--;
					cout<<"��������Ҫ��Ӹ���"<<endl;
	                cin>>ab;
					num[j]+=ab;
					break;
				}
			}
            count++;
		    if(count==N)
			{
                cout<<"�Բ��������Ʒ������Ŀ�ѵ����ޣ������ټ������������"<<endl;
				break;
			}
			if(ab==0)
			{
				name[i]=aa[i];
                cout<<"��������Ӹ���"<<endl;
	            cin>>num[i];
				cout<<"�����뱣���ڣ������£�"<<endl;
				cin>>time[i];
			}
		}
	}
    system("pause");
    system("cls");
	f1();

}
void food::saleg()
{
    char aa[100],j=0,k=0;
	cout<<"��������Ҫ���۵���Ʒ������"<<endl;
	cin>>aa;
	for(;j<count;j++)
	{
		if(aa==name[j])
		{
			cout<<"�и���Ʒ����������Ҫ���۵�����"<<endl;
			cin>>k;
			if(k<0||k>num[j])
			{
				cout<<"��Ǹ������û����ô�࣬����Ʒ����"<<num[j]<<endl;
			}
			else
			{
				cout<<"�����㹻,��͸���"<<endl;
				num[j]-=k;
			}
		}
		else
		{
            cout<<"��Ǹ��û�и���Ʒ"<<endl;break;
		}
	}
    system("pause");
    system("cls");
	f1();
}
void food::showg()
{
    cout<<"������Ʒ��Ϣ����"<<endl;
    cout<<"������ƷĿǰ��������Ϊ"<<endl;
    cout<<count<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<"����"<<name[i]<<' '<<"����"<<num[i]<<"������"<<time[i]<<endl;
	}
    system("pause");
    system("cls");
	f1();
}
class elec:public good
{
	string color[N];
public:
    void addg();
	void saleg();
	void showg();
};
void elec::addg()
{
    if(count==N)
	{
        cout<<"�Բ��������Ʒ������Ŀ�ѵ����ޣ������������"<<endl;
	}
	else
	{
	    cout<<"������Ҫ��ӵ���������������"<<endl;
	    int a,i=0,j=0,ab=0;
	    cin>>a;
		string aa[N];
        cout<<"����������ֺ�����"<<endl;
	    for(;i<a;i++)
		{
            cout<<"�������"<<i+1<<"�����������"<<endl;
			cin>>aa[i];
			for(;j<count;j++)
			{
				if(name[j]==aa[i])
                {
					cout<<"�Ѿ����ڸ�����Ʒ"<<endl;
                    count--;
					cout<<"��������Ҫ��Ӹ���"<<endl;
	                cin>>ab;
					num[j]+=ab;
					break;
				}
			}
            count++;
		    if(count==N)
			{
                cout<<"�Բ��������Ʒ������Ŀ�ѵ����ޣ������ټ������������"<<endl;
				break;
			}
			if(ab==0)
			{
				name[i]=aa[i];
                cout<<"��������Ӹ���"<<endl;
	            cin>>num[i];
                cout<<"�����������Ʒ����ɫ"<<endl;
				cin>>color[i];
			}
		}
	}
    system("pause");
    system("cls");
	f1();

}
void elec::saleg()
{
    char aa[100],j=0,k=0;
	cout<<"��������Ҫ���۵���Ʒ������"<<endl;
	cin>>aa;
	for(;j<count;j++)
	{
		if(aa==name[j])
		{
			cout<<"�и���Ʒ����������Ҫ���۵�����"<<endl;
			cin>>k;
			if(k<0||k>num[j])
			{
				cout<<"��Ǹ������û����ô�࣬����Ʒ����"<<num[j]<<endl;
			}
			else
			{
				cout<<"�����㹻,��͸���"<<endl;
				num[j]-=k;
			}
		}
		else
		{
            cout<<"��Ǹ��û�и���Ʒ"<<endl;break;
		}
	}
    system("pause");
    system("cls");
	f1();
}
void elec::showg()
{
    cout<<"������Ʒ��Ϣ����"<<endl;
    cout<<"������ƷĿǰ��������Ϊ"<<endl;
    cout<<count<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<"����"<<name[i]<<' '<<"����"<<num[i]<<"��ɫ"<<color[i]<<endl;
	}
    system("pause");
    system("cls");
	f1();
}
class sup
{
	day d;
	food f;
	elec e;
public:
	void add();
    void f3(int);
	void sale();
	void f4(int);
	void show();
	void f5(int);
};
sup s1;
void sup::add()
{
    cout<<"1������ճ���Ʒ����Ʒ"<<endl;
    cout<<"2�����ʳƷ��Ʒ"<<endl;
    cout<<"3�������������Ʒ"<<endl;
    cout<<"4�������ϼ��˵�"<<endl;
    cout<<"5���˳�ϵͳ"<<endl;
    cout<<"���������ѡ��"<<endl;
	int a;
	cin>>a;
	f3(a);
}
void sup::f3(int a)
{
    switch (a)
	{
	case 1:this->d.addg();break;
	case 2:this->f.addg();break;
	case 3:this->e.addg();break;
	case 4: f1();break;
	case 5: exit(1);break;
    default :cout<<"�Բ���û�����ѡ�����������"<<endl;system("cls");this->add();
	}	
}
void sup::sale()
{
    cout<<"1�������ճ���Ʒ����Ʒ"<<endl;
    cout<<"2������ʳƷ��Ʒ"<<endl;
    cout<<"3��������������Ʒ"<<endl;
    cout<<"4�������ϼ��˵�"<<endl;
    cout<<"5���˳�ϵͳ"<<endl;
    cout<<"���������ѡ��"<<endl;
	int a;
	cin>>a;
	f4(a);
}
void sup::f4(int a)
{
    switch (a)
	{
	case 1:this->d.saleg();break;
	case 2:this->f.saleg();break;
	case 3:this->e.saleg;break;
	case 4: f1();break;
	case 5: exit(1);break;
    default :cout<<"�Բ���û�����ѡ�����������"<<endl;system("cls");this->sale();
	}	
}
void sup::show()
{
    cout<<"1����ʾ�ճ���Ʒ����Ʒ"<<endl;
    cout<<"2����ʾʳƷ��Ʒ"<<endl;
    cout<<"3����ʾ��������Ʒ"<<endl;
    cout<<"4�������ϼ��˵�"<<endl;
    cout<<"5���˳�ϵͳ"<<endl;
    cout<<"���������ѡ��"<<endl;
	int a;
	cin>>a;
	f5(a); 
}
void sup::f5(int a)
{
    switch (a)
	{
	case 1:cout<<"��������1"<<endl;system("pause");this->d.showg();break;
	case 2:this->f.showg();break;
	case 3:this->e.showg();break;
	case 4: f1();break;
	case 5: exit(1);break;
    default :cout<<"�Բ���û�����ѡ�����������"<<endl;system("cls");this->show();
	}	
}
void f2(int a)
{
	switch (a)
	{
	case 1: s1.add();break;
	case 2: s1.sale();break;
	case 3: s1.show();break;
	case 4: exit(1);break;
    default :cout<<"�Բ���û�����ѡ�����������"<<endl;system("cls");f1();
	}	
}
int main()
{
	f1();
	return 0;
}
