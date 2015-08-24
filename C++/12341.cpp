#include<iostream>
#include<string>
using namespace std;
#include<windows.h>
#define N 3
void f1()
{
	system("color 04");
    void f2(int);
	cout<<"超市食品管理系统"<<endl;
    cout<<"1，添加商品"<<endl;
    cout<<"2,销售商品"<<endl;
    cout<<"3，显示商品"<<endl;
    cout<<"4,退出系统"<<endl;
    cout<<"请输入你的选项"<<endl;
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
        cout<<"对不起该类商品种类数目已到上限，不能再添加了"<<endl;
	}
	else
	{
	    cout<<"请输入要添加的日常用品的种类个数"<<endl;
	    int a,i=0,j=0,ab=0;
	    cin>>a;
		string aa[N];
        cout<<"请输入该名字和数量"<<endl;
	    for(;i<a;i++)
		{
            cout<<"请输入第"<<i+1<<"个种类的名字"<<endl;
			cin>>aa[i];
			for(;j<count;j++)
			{
				if(name[j]==aa[i])
                {
					cout<<"已经存在该类商品"<<endl;
                    count--;
					cout<<"请输入又要添加个数"<<endl;
	                cin>>ab;
					num[j]+=ab;
					break;
				}
			}
            count++;
		    if(count==N)
			{
                cout<<"对不起该类商品种类数目已到上限，不能再继续往下添加了"<<endl;
				break;
			}
			if(ab==0)
			{
				name[i]=aa[i];
                cout<<"请输入添加个数"<<endl;
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
	cout<<"请输入你要销售的商品的名字"<<endl;
	cin>>aa;
	for(;j<count;j++)
	{
		if(aa==name[j])
		{
			cout<<"有该商品，请输入你要销售的数量"<<endl;
			cin>>k;
			if(k<0||k>num[j])
			{
				cout<<"抱歉，数量没有那么多，该商品还有"<<num[j]<<endl;
			}
			else
			{
				cout<<"数量足够,这就给你"<<endl;
				num[j]-=k;
			}
		}
		else
		{
            cout<<"抱歉，没有该商品"<<endl;break;
		}
	}
    system("pause");
    system("cls");
	f1();
}
void day::showg()
{
	cout<<"该类商品信息如下"<<endl;
    cout<<"该类商品目前种类数量为"<<endl;
    cout<<count<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<"名字"<<name[i]<<' '<<"数量"<<num[i]<<endl;
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
        cout<<"对不起该类商品种类数目已到上限，不能再添加了"<<endl;
	}
	else
	{
	    cout<<"请输入要添加的食品类的种类个数"<<endl;
	    int a,i=0,j=0,ab=0;
	    cin>>a;
		string aa[N];
        cout<<"请输入该名字和数量"<<endl;
	    for(;i<a;i++)
		{
            cout<<"请输入第"<<i+1<<"个种类的名字"<<endl;
			cin>>aa[i];
			for(;j<count;j++)
			{
				if(name[j]==aa[i])
                {
					cout<<"已经存在该类商品"<<endl;
                    count--;
					cout<<"请输入又要添加个数"<<endl;
	                cin>>ab;
					num[j]+=ab;
					break;
				}
			}
            count++;
		    if(count==N)
			{
                cout<<"对不起该类商品种类数目已到上限，不能再继续往下添加了"<<endl;
				break;
			}
			if(ab==0)
			{
				name[i]=aa[i];
                cout<<"请输入添加个数"<<endl;
	            cin>>num[i];
				cout<<"请输入保质期（多少月）"<<endl;
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
	cout<<"请输入你要销售的商品的名字"<<endl;
	cin>>aa;
	for(;j<count;j++)
	{
		if(aa==name[j])
		{
			cout<<"有该商品，请输入你要销售的数量"<<endl;
			cin>>k;
			if(k<0||k>num[j])
			{
				cout<<"抱歉，数量没有那么多，该商品还有"<<num[j]<<endl;
			}
			else
			{
				cout<<"数量足够,这就给你"<<endl;
				num[j]-=k;
			}
		}
		else
		{
            cout<<"抱歉，没有该商品"<<endl;break;
		}
	}
    system("pause");
    system("cls");
	f1();
}
void food::showg()
{
    cout<<"该类商品信息如下"<<endl;
    cout<<"该类商品目前种类数量为"<<endl;
    cout<<count<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<"名字"<<name[i]<<' '<<"数量"<<num[i]<<"保质期"<<time[i]<<endl;
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
        cout<<"对不起该类商品种类数目已到上限，不能再添加了"<<endl;
	}
	else
	{
	    cout<<"请输入要添加的器电类的种类个数"<<endl;
	    int a,i=0,j=0,ab=0;
	    cin>>a;
		string aa[N];
        cout<<"请输入该名字和数量"<<endl;
	    for(;i<a;i++)
		{
            cout<<"请输入第"<<i+1<<"个种类的名字"<<endl;
			cin>>aa[i];
			for(;j<count;j++)
			{
				if(name[j]==aa[i])
                {
					cout<<"已经存在该类商品"<<endl;
                    count--;
					cout<<"请输入又要添加个数"<<endl;
	                cin>>ab;
					num[j]+=ab;
					break;
				}
			}
            count++;
		    if(count==N)
			{
                cout<<"对不起该类商品种类数目已到上限，不能再继续往下添加了"<<endl;
				break;
			}
			if(ab==0)
			{
				name[i]=aa[i];
                cout<<"请输入添加个数"<<endl;
	            cin>>num[i];
                cout<<"请输入该种商品的颜色"<<endl;
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
	cout<<"请输入你要销售的商品的名字"<<endl;
	cin>>aa;
	for(;j<count;j++)
	{
		if(aa==name[j])
		{
			cout<<"有该商品，请输入你要销售的数量"<<endl;
			cin>>k;
			if(k<0||k>num[j])
			{
				cout<<"抱歉，数量没有那么多，该商品还有"<<num[j]<<endl;
			}
			else
			{
				cout<<"数量足够,这就给你"<<endl;
				num[j]-=k;
			}
		}
		else
		{
            cout<<"抱歉，没有该商品"<<endl;break;
		}
	}
    system("pause");
    system("cls");
	f1();
}
void elec::showg()
{
    cout<<"该类商品信息如下"<<endl;
    cout<<"该类商品目前种类数量为"<<endl;
    cout<<count<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<"名字"<<name[i]<<' '<<"数量"<<num[i]<<"颜色"<<color[i]<<endl;
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
    cout<<"1，添加日常用品类商品"<<endl;
    cout<<"2，添加食品商品"<<endl;
    cout<<"3，添加器电类商品"<<endl;
    cout<<"4，返回上级菜单"<<endl;
    cout<<"5，退出系统"<<endl;
    cout<<"请输入你的选项"<<endl;
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
    default :cout<<"对不起，没有这个选项，请重新输入"<<endl;system("cls");this->add();
	}	
}
void sup::sale()
{
    cout<<"1，销售日常用品类商品"<<endl;
    cout<<"2，销售食品商品"<<endl;
    cout<<"3，销售器电类商品"<<endl;
    cout<<"4，返回上级菜单"<<endl;
    cout<<"5，退出系统"<<endl;
    cout<<"请输入你的选项"<<endl;
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
    default :cout<<"对不起，没有这个选项，请重新输入"<<endl;system("cls");this->sale();
	}	
}
void sup::show()
{
    cout<<"1，显示日常用品类商品"<<endl;
    cout<<"2，显示食品商品"<<endl;
    cout<<"3，显示器电类商品"<<endl;
    cout<<"4，返回上级菜单"<<endl;
    cout<<"5，退出系统"<<endl;
    cout<<"请输入你的选项"<<endl;
	int a;
	cin>>a;
	f5(a); 
}
void sup::f5(int a)
{
    switch (a)
	{
	case 1:cout<<"这里来了1"<<endl;system("pause");this->d.showg();break;
	case 2:this->f.showg();break;
	case 3:this->e.showg();break;
	case 4: f1();break;
	case 5: exit(1);break;
    default :cout<<"对不起，没有这个选项，请重新输入"<<endl;system("cls");this->show();
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
    default :cout<<"对不起，没有这个选项，请重新输入"<<endl;system("cls");f1();
	}	
}
int main()
{
	f1();
	return 0;
}
