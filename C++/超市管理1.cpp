#include<iostream>//预处理指令，包括头文件
#include<string>//string类的声明和定义在这里面
#include<fstream>//文件流对象头文件
#include<iomanip>//setw()格式控制函数头文件
#include <ctime>//时间类SYSTEMTIME以及时间提取函数locate()头文件
using namespace std;//使用名字命名空间，在不同代码块这样可以重复命名
#include<windows.h>//system("cls")和syetem("pause")在类中生命了，所以要导入此类
#include<stdlib.h>//system("color xy")头文件，x和y 是十六进制数，x表示字体颜色，y表示背景颜色
#define N 3//宏定义，商品种类最大上限数
#define M 100//宏定义，一个M
void color(int a)//定义设置颜色函数，带参数，参数控制颜色，用了句柄
	{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);//头文件也可以是ConsoleColor.h
	}
int opr(SYSTEMTIME x)//定义一个一般函数，提取时间类对象的时间，返回秒数
{
	return(x.wHour*3600+x.wMinute*60+x.wSecond);
}
void f1()//一般函数，定义
{
	system("color 0b");//调用系统函数，改变背景颜色和字体颜色
    void f2(int);//f2函数的声明
    cout<<setw(15)<<" ";//调用setw()函数来控制格式
    cout<<"****************************************"<<endl;//原样输出
    cout<<endl;
    cout<<setw(25)<<" ";
	cout<<"超市食品管理系统"<<endl;
    cout<<endl;
    cout<<setw(15)<<" ";
    cout<<"****************************************"<<endl;
    cout<<setw(27)<<" ";
    cout<<"1,添加商品"<<endl;
    cout<<setw(27)<<" ";
    cout<<"2,销售商品"<<endl;
    cout<<setw(27)<<" ";
    cout<<"3,显示商品"<<endl;
    cout<<setw(27)<<" ";
    cout<<"4,退出系统"<<endl;
    cout<<setw(27)<<" ";
    cout<<"请输入你的选项";
    cout<<setw(3)<<" ";
	int a;//定义一个局部变量
	cin>>a;//键盘输入值
	f2(a);//调用函数f2
}
class good//商品类
{
protected://访问属性声明，protected，可以被子类（派生类）访问，但外界不能访问
    string name[N];//定义string数组用来接收商品的名称
	int num[N];//整型数组，用来存储数量
    SYSTEMTIME sysTime[N];//时间类对象数组，用来存放给商品进入超市时间
	int count;//当前商品的种类数量
public:
	virtual void addg()=0;//纯虚函数定义，在子类再定义，在此处只是声明
	virtual void saleg()=0;//但是系统会给一个所谓的虚函数表来存放这些函数首地址
	virtual void showg()=0;//也可以在=0前面加上const
	good()//默认构造函数，无参数，
	{
		count=0;//初始化count为0
	}
};
class day:public good//日常商品类，属于good的子类，公有继承
{
public:
	void addg();//虚函数定义
	void saleg();
	void showg();
	day():good()//无参数构造函数，其实也可以不要，
	{}
};
void day::addg()//增加日常商品类的商品，类外定义，注意类外定义要记得加上类名限制
{
    cout<<endl;
    cout<<setw(27)<<" ";
	cout<<"1秒后清屏"<<endl;
    Sleep(1000);//调用sleep函数让程序暂停3秒，注意次函数参数单位是毫秒
    system("cls");//清屏，把屏幕上的东西全部清空
	cout<<setw(27)<<" ";
	cout<<"请输入要添加的日常用品的种类个数"<<endl;
	int a,i=0,j=0,ab;//定义几个局部变量，注意定义局部变量最好初始化了，不然有时会出现空间分配错误
    cout<<setw(27)<<" ";
	cin>>a;//键盘输入值
    string aa[M];//定义字符串数组
    cout<<setw(27)<<" ";
    cout<<"请输入该名字和数量"<<endl;;
	for(;i<a;i++)//for循环语句，来遍历元素看是否已存在该商品，存在则只是加数量，不存在则另当别论
	{
        cout<<setw(27)<<" ";
        cout<<"请输入第"<<i+1<<"个种类的名字"<<endl;
        cout<<setw(27)<<" ";
	    cin>>aa[i];
	    ab=-1;
	    for(j=0;j<count;j++)
		{
		    if(name[j]==aa[i])
			{
                cout<<setw(27)<<" ";
		        cout<<"已经存在该类商品"<<endl;
                cout<<setw(27)<<" ";
                cout<<"最近进入超市时间为";	
		        cout<<sysTime[j].wHour << "时" <<sysTime[j].wMinute;		        
		        cout<<"分"<<sysTime[j].wSecond <<"秒"<<endl;
                cout<<setw(27)<<" ";
		        cout<<"请输入又要添加个数"<<endl;
                cout<<setw(27)<<" ";
	            cin>>ab;
			    num[j]+=ab;
                GetLocalTime(&sysTime[j]);//获取当前电脑时间，
			    break;
			}
		}
		if(count==N)//判断是否达到了上限
		{
            cout<<setw(27)<<" ";
            cout<<"对不起该类商品种类数目已到上限，不能再继续往下添加了"<<endl;
		    break;
		}
		if(ab==-1)//若不存在该商品，则其他内容也要更新
		{
			name[count]=aa[i];
            cout<<setw(27)<<" ";
            cout<<"请输入添加个数"<<endl;
            cout<<setw(27)<<" ";
	        cin>>num[count];
            GetLocalTime(&sysTime[count]);
		    cout<<setw(27)<<" ";
			cout<<"进入超市时间为";	
		    cout<<sysTime[count].wHour << "时" <<sysTime[count].wMinute;
		    cout<<"分" << sysTime[count].wSecond <<"秒"<<endl;
            count++;
		}
	}
    ofstream outfile("day.txt",ios::app);  //文件输出流定义，ios::app意思是在文件末尾加入新数据
    for(i=0;i<count;i++)
	{
        outfile<<name[i]<<" ";//一个一个写入文件
        outfile<<num[i]<<" ";
	}
    cout<<setw(27)<<" ";
	cout<<"1秒后换颜色"<<endl;
    Sleep(1000);
    system("color 04");
    void turn2();//turn2函数声明
	turn2();//调用turn2函数
}
void day::saleg()//销售日常类商品的商品
{
    cout<<endl;
    cout<<setw(27)<<" ";
	cout<<"1秒后清屏"<<endl;
    Sleep(1000);
    system("cls");
	string aa;
    int j=0,k=0,ee=0;
    cout<<setw(27)<<" ";
	cout<<"请输入你要销售的商品的名字"<<endl;//输入要销售的商品名称，然后遍历查找看有无此商品，
    cout<<setw(27)<<" ";                      //若有，则输出当前数量，判断是否符合销售数目，
	cin>>aa;                                  //若不足，或者是没有则直接输出，商品不足
	for(;j<count;j++)
	{
		if(aa==name[j])
		{
            ee=1;
            cout<<setw(27)<<" ";
            cout<<"有该商品,该类商品目前现有"<<num[j]<<endl;
            cout<<setw(27)<<" ";
            cout<<"请输入你要销售的数量"<<endl;
            cout<<setw(27)<<" ";
			cin>>k;
			if(k<0||k>num[j])
			{
                cout<<setw(27)<<" ";
				cout<<"抱歉，数量没有那么多，该商品还有"<<num[j]<<endl;break;
			}
			else
			{
                cout<<setw(27)<<" ";
				cout<<"数量足够,这就给你"<<endl;
				num[j]-=k;
                cout<<setw(27)<<" ";
				cout<<"该类商品目前还有"<<num[j]<<endl;
				if(num[j]==0)
				{
					count--;
				}
				break;
			}
		}
	}
	if(ee==0)
	{
        cout<<setw(27)<<" ";
        cout<<"抱歉，没有该商品"<<endl;
	}
    cout<<setw(27)<<" ";
	cout<<"1秒后换颜色"<<endl;
    Sleep(1000);
    system("color 37");
    void turn3();//函数turn3声明
	turn3();//调用turn3函数
}
void day::showg()//输出日常类商品的商品信息
{
    cout<<endl;
    cout<<setw(27)<<" ";
	cout<<"1秒后清屏"<<endl;
    Sleep(1000);//屏幕暂停3秒
    system("cls");//清屏
    cout<<setw(27)<<" ";
	cout<<"该类商品信息如下"<<endl;
    cout<<setw(27)<<" ";
    cout<<"该类商品目前种类数量为";
    cout<<setw(3)<<" ";
    cout<<count<<endl;
	for(int i=0;i<count;i++)//输出商品相关信息，名称，数目，入库时间
	{
        cout<<setw(27)<<" ";
		cout<<"名字"<<name[i]<<' '<<"数量"<<num[i]<<endl;
        cout<<setw(27)<<" ";
        cout<<"最近进入超市时间为";	
	    cout<<sysTime[i].wHour << "时" <<sysTime[i].wMinute;
	    cout<<"分" << sysTime[i].wSecond <<"秒"<<endl;
	}
    cout<<setw(27)<<" ";
	cout<<"1秒后换颜色"<<endl;
    Sleep(1000);
    system("color 28");
	void turn4();//turn4函数声明
	turn4();//调用turn4函数
}
class food:public good//食物类商品类，good的派生类，公有继承
{
	int time[N];//新增数据
public:
    void addg();//虚函数定义
	void saleg();
	void showg();
};
void food::addg()//增加食物类商品
{
	cout<<endl;
    cout<<setw(27)<<" ";
    cout<<"1秒后清屏"<<endl;
    Sleep(1000);
    system("cls");
	cout<<setw(27)<<" ";
    cout<<"请输入要添加的食品类商品的种类个数"<<endl;
	    int a,i=0,j=0,ab;
        cout<<setw(27)<<" ";
	    cin>>a;
		string aa[M];
        cout<<setw(27)<<" ";
        cout<<"请输入该名字和数量"<<endl;        //for循环语句，来遍历元素看是否已存在该商品，存在则只是加数量，不存在则另当别论 
	    for(;i<a;i++)
		{
            cout<<setw(27)<<" ";
            cout<<"请输入第"<<i+1<<"个种类的名字"<<endl;
            cout<<setw(27)<<" ";
			cin>>aa[i];
			ab=-1;
			for(j=0;j<count;j++)
			{
				if(name[j]==aa[i])
                {
                    cout<<setw(27)<<" ";
					cout<<"已经存在该类商品"<<endl;
                    cout<<setw(27)<<" ";
                    cout<<"最近进入超市时间为";	
				    cout<<sysTime[j].wHour << "时" <<sysTime[j].wMinute;		        
		            cout<<"分"<<sysTime[j].wSecond <<"秒"<<endl;      
                    cout<<setw(27)<<" ";
					cout<<"请输入又要添加个数"<<endl;                  
                    cout<<setw(27)<<" ";
	                cin>>ab;
					num[j]+=ab;
                    GetLocalTime(&sysTime[j]); 
					break;
				}
			}
		    if(count==N)
			{
                cout<<setw(27)<<" ";
                cout<<"对不起该类商品种类数目已到上限，不能再继续往下添加了"<<endl;
				break;
			}
			if(ab==-1)
			{
				name[count]=aa[i];
                cout<<setw(27)<<" ";
                cout<<"请输入添加个数"<<endl;
                cout<<setw(27)<<" ";
	            cin>>num[count];
                GetLocalTime(&sysTime[count]);
				cout<<setw(27)<<" ";
			    cout<<"进入超市时间为";	
				cout<<sysTime[count].wHour << "时" <<sysTime[count].wMinute;
				cout<<"分" << sysTime[count].wSecond <<"秒"<<endl;
                cout<<setw(27)<<" ";
                cout<<"请输入保质期（多少月）"<<endl;
                cout<<setw(27)<<" ";
				cin>>time[count];
                count++;
			}
		}
    ofstream outfile("food.txt",ios::app);   //文件输出流定义，ios::app意思是在文件末尾加入新数据
    for(i=0;i<count;i++)
	{
        outfile<<name[i]<<" ";//一个一个写入文件
        outfile<<num[i]<<" ";
	}
    cout<<setw(27)<<" ";
	cout<<"1秒后换颜色"<<endl;
    Sleep(1000);
    system("color 14");
    void turn2();//函数turn2声明
	turn2();//调用turn2函数
}
void food::saleg()//销售食物类商品
{
    cout<<endl;
    cout<<setw(27)<<" ";
	cout<<"1秒后清屏"<<endl;
    Sleep(1000);
    system("cls");//清屏
	string aa;//定义一个字符串，下面用来判断是狗已存在该商品
    int j=0,k=0,ee=0;
    cout<<setw(27)<<" ";
	cout<<"请输入你要销售的商品的名字"<<endl;
    cout<<setw(27)<<" ";
	cin>>aa;
	for(;j<count;j++)//输入要销售的商品名称，然后遍历查找看有无此商品
	{
		if(aa==name[j])
		{
            ee=1;
            cout<<setw(27)<<" ";
            cout<<"有该商品,该类商品目前现有"<<num[j]<<endl;
            cout<<setw(27)<<" ";
            cout<<"请输入你要销售的数量"<<endl;
            cout<<setw(27)<<" ";
			cin>>k;
			if(k<0||k>num[j])//若有，则输出当前数量，判断是否符合销售数目
			{
                cout<<setw(27)<<" ";
				cout<<"抱歉，数量没有那么多，该商品还有"<<num[j]<<endl;break; //若不足，或者是没有则直接输出，商品不足
			}
			else
			{
                cout<<setw(27)<<" ";
				cout<<"数量足够,这就给你"<<endl;
				num[j]-=k;
                cout<<setw(27)<<" ";
				cout<<"该类商品目前还有"<<num[j]<<endl;
				if(num[j]==0)
				{
					count--;
				}
				break;
			}
		}
	}
	if(ee==0)
	{
        cout<<setw(27)<<" ";
        cout<<"抱歉，没有该商品"<<endl;
	}
    cout<<setw(27)<<" ";
	cout<<"1秒后换颜色"<<endl;
    Sleep(1000);
    system("color 07");
    void turn3(); //函数turn3声明
	turn3();//调用函数turn3
}
void food::showg()//输出食物类商品的商品信息
{
    cout<<endl;
    cout<<setw(27)<<" ";
	cout<<"1秒后清屏"<<endl;
    Sleep(1000);//程序暂停3秒
    system("cls");//清屏
    cout<<setw(27)<<" ";
    cout<<"该类商品信息如下"<<endl;
    cout<<setw(27)<<" ";
    cout<<"该类商品目前种类数量为";
    cout<<setw(3)<<" ";
    cout<<count<<endl;
	for(int i=0;i<count;i++)//for语句循环输出商品相关信息，这里的食物类，当然还有很正要的保质期
	{
        cout<<setw(27)<<" ";
		cout<<"名字"<<name[i]<<' '<<"数量"<<num[i]<<"保质期"<<time[i]<<endl;
        SYSTEMTIME outtime;
        GetLocalTime(&outtime);
        cout<<setw(27)<<" ";
		cout<<"当前时间为";
        cout<<outtime.wHour << "时" <<outtime.wMinute;
        cout<<"分" << outtime.wSecond <<"秒"<<endl;
        int cd=opr(outtime);
	    int ce=opr(sysTime[i]);
		int ae=cd-ce;
        cout<<setw(27)<<" ";
        cout<<"已存放"<<ae<<"秒";
		if(ae<time[i]*120)
		{
            cout<<setw(3)<<" ";
			cout<<"还在保质期内"<<endl;
		}
		else
		{
            cout<<setw(27)<<" ";
			cout<<"抱歉，已过期，请回收掉"<<endl;
		}
	}
    cout<<setw(27)<<" ";
	cout<<"1秒后换颜色"<<endl;
    Sleep(1000);
    system("color 31");
    void turn4();//函数turn4声明
	turn4();//调用函数turn4
}
class elec:public good//电器类商品类,good类的派生类，公有继承
{
	string color[N];//新增数剧成员
public:
    void addg();//虚函数定义，类外定义，注意类名限制
	void saleg();
	void showg();
};
void elec::addg()//增加电器类商品
{
	cout<<endl;
    cout<<setw(27)<<" ";
    cout<<"1秒后清屏"<<endl;
    Sleep(1000);//屏幕暂停3秒
    system("cls");
	cout<<setw(27)<<" ";
    cout<<"请输入要添加的电器类商品的种类个数"<<endl;
	    int a,i=0,j=0,ab;
        cout<<setw(27)<<" ";
	    cin>>a;
		string aa[M];
        cout<<setw(27)<<" ";
        cout<<"请输入该名字和数量"<<endl;
	    for(;i<a;i++)                      //for循环语句，来遍历元素看是否已存在该商品，存在则只是加数量，不存在则另当别论 
		{
            cout<<setw(27)<<" ";
            cout<<"请输入第"<<i+1<<"个种类的名字"<<endl;
            cout<<setw(27)<<" ";
			cin>>aa[i];
			ab=-1;
			for(j=0;j<count;j++)
			{
				if(name[j]==aa[i])
                {
                    cout<<setw(27)<<" ";
					cout<<"已经存在该类商品"<<endl;
                    cout<<setw(27)<<" ";
                    cout<<"最近进入超市时间为";
				    cout<<sysTime[j].wHour << "时" <<sysTime[j].wMinute;
				    cout<<"分" << sysTime[j].wSecond <<"秒"<<endl;
                    cout<<setw(27)<<" ";
					cout<<"请输入又要添加个数"<<endl;
                    cout<<setw(27)<<" ";
	                cin>>ab;
					num[j]+=ab;
                    GetLocalTime(&sysTime[j]); 
					break;
				}
			}
		    if(count==N)
			{
                cout<<setw(27)<<" ";
                cout<<"对不起该类商品种类数目已到上限，不能再继续往下添加了"<<endl;
				break;
			}
			if(ab==-1)
			{
				name[count]=aa[i];
                cout<<setw(27)<<" ";
                cout<<"请输入添加个数"<<endl;
                cout<<setw(27)<<" ";
	            cin>>num[count];
                GetLocalTime(&sysTime[count]);
				cout<<setw(27)<<" ";
			    cout<<"进入超市时间为";	
				cout<<sysTime[count].wHour << "时" <<sysTime[count].wMinute;
				cout<<"分" << sysTime[count].wSecond <<"秒"<<endl;
                cout<<setw(27)<<" ";
                cout<<"请输入该种商品的颜色"<<endl;
                cout<<setw(27)<<" ";
				cin>>color[count];
                count++;
			}
		}
    ofstream outfile("elec.txt",ios::app); //文件输出流定义，ios::app意思是在文件末尾加入新数据 
    for(i=0;i<count;i++)
	{
        outfile<<name[i]<<" ";//一个一个写入文件
        outfile<<num[i]<<" ";
	}
    cout<<setw(27)<<" ";
	cout<<"1秒后换颜色"<<endl;
    Sleep(1000);
    system("color 23");
    void turn2();//函数turn2声明
	turn2();//调用函数turn2
}
void elec::saleg()//销售电器类商品
{
    cout<<endl;
    cout<<setw(27)<<" ";
	cout<<"1秒后清屏"<<endl;
    Sleep(1000);
    system("cls");
	string aa;
    int j=0,k=0,ee=0;
    cout<<setw(27)<<" ";
	cout<<"请输入你要销售的商品的名字"<<endl;
    cout<<setw(27)<<" ";
	cin>>aa;                             //输入要销售的商品名称，然后遍历查找看有无此商品   
	for(;j<count;j++)
	{
		if(aa==name[j])
		{
            ee=1;
            cout<<setw(27)<<" ";
            cout<<"有该商品,该类商品目前现有"<<num[j]<<endl;
            cout<<setw(27)<<" ";
            cout<<"请输入你要销售的数量"<<endl;//若有，则输出当前数量，判断是否符合销售数目
			cout<<setw(27)<<" ";
			cin>>k;
			if(k<0||k>num[j])
			{
                cout<<setw(27)<<" ";
				cout<<"抱歉，数量没有那么多，该商品还有"<<num[j]<<endl;break; //若不足，或者是没有则直接输出，商品不足
			}
			else
			{
                cout<<setw(27)<<" ";
				cout<<"数量足够,这就给你"<<endl;
				num[j]-=k;
                cout<<setw(27)<<" ";
				cout<<"该类商品目前还有"<<num[j]<<endl;
				if(num[j]==0)
				{
					count--;
				}
				break;
			}
		}
	}
	if(ee==0)
	{
        cout<<setw(27)<<" ";
        cout<<"抱歉，没有该商品"<<endl;
	}
    cout<<setw(27)<<" ";
	cout<<"1秒后换颜色"<<endl;
    Sleep(1000);
    system("color 17");
    void turn3(); //函数turn3声明
	turn3();//调用函数turn3
}
void elec::showg()//输出电器类商品的商品信息
{
    cout<<endl;
    cout<<setw(27)<<" ";
    cout<<"1秒后清屏"<<endl;
    Sleep(1000);
    system("cls");
    cout<<setw(27)<<" ";
    cout<<"该类商品信息如下"<<endl;
    cout<<setw(27)<<" ";
    cout<<"该类商品目前种类数量为";
    cout<<setw(3)<<" ";
    cout<<count<<endl;
	for(int i=0;i<count;i++)//for语句循环输出商品相关信息，名称，数目，颜色
	{
        cout<<setw(27)<<" ";
		cout<<"名字"<<name[i]<<' '<<"数量"<<num[i]<<"颜色"<<color[i]<<endl;
        cout<<setw(27)<<" ";
        cout<<"最近进入超市时间为";	
	    cout<<sysTime[i].wHour << "时" <<sysTime[i].wMinute;
	    cout<<"分" << sysTime[i].wSecond <<"秒"<<endl;
	}
    cout<<setw(27)<<" ";
	cout<<"1秒后换颜色"<<endl;
    Sleep(1000);
    system("color 45");
    void turn4();//函数turn4声明
	turn4();//调用函数turn4
}
class sup//超市类
{
	day d;//数据成员day类对象
	food f;//数据成员food类对象
	elec e;//数据成员elec类对象
public:
	void add();//成员函数声明
    void f3(int);
	void sale();
	void f4(int);
	void show();
	void f5(int);
};
sup s1;
void sup::add()//添加商品函数
{
	cout<<endl;
	cout<<setw(27)<<" ";
    cout<<"1，添加日常用品类商品"<<endl;
    cout<<setw(27)<<" ";
    cout<<"2，添加食品商品"<<endl;
    cout<<setw(27)<<" ";
    cout<<"3，添加器电类商品"<<endl;
    cout<<setw(27)<<" ";
    cout<<"4，返回上级菜单"<<endl;
    cout<<setw(27)<<" ";
    cout<<"5，退出系统"<<endl;
    cout<<setw(27)<<" ";
    cout<<"请输入你的选项";
    cout<<setw(3)<<" ";
	int a;
	cin>>a;
	f3(a);
}
void sup::f3(int a)
{
    switch (a)//switch语句来接收键盘输入的值，选择进入其他菜单
	{
	case 1:this->d.addg();break;
	case 2:this->f.addg();break;
	case 3:this->e.addg();break;
	case 4: f1();break;
	case 5: exit(1);break;
    default :cout<<setw(27)<<" ";cout<<"对不起，没有这个选项，请重新输入"<<endl;system("cls");this->add();
	}	
}
void sup::sale()//销售商品函数
{
	cout<<endl;
    cout<<setw(27)<<" ";
    cout<<"1，销售日常用品类商品"<<endl;
    cout<<setw(27)<<" ";
    cout<<"2，销售食品商品"<<endl;
    cout<<setw(27)<<" ";
    cout<<"3，销售器电类商品"<<endl;
    cout<<setw(27)<<" ";
    cout<<"4，返回上级菜单"<<endl;
    cout<<setw(27)<<" ";
    cout<<"5，退出系统"<<endl;
    cout<<setw(27)<<" ";
    cout<<"请输入你的选项"<<endl;
	int a;
    cout<<setw(27)<<" ";
	cin>>a;
	f4(a);
}
void sup::f4(int a)//sup类成员函数类外定义
{
    switch (a)
	{
	case 1:this->d.saleg();break;
	case 2:this->f.saleg();break;
	case 3:this->e.saleg();break;
	case 4: f1();break;
	case 5: exit(1);break;
    default :cout<<setw(27)<<" ";cout<<"对不起，没有这个选项，请重新输入"<<endl;system("cls");this->sale();
	}	
}
void sup::show()//显示商品函数
{
	cout<<endl;
    cout<<setw(27)<<" ";
    cout<<"1,显示日常用品类商品"<<endl;
    cout<<setw(27)<<" ";
    cout<<"2,显示食品商品"<<endl;
    cout<<setw(27)<<" ";
    cout<<"3,显示器电类商品"<<endl;
    cout<<setw(27)<<" ";
    cout<<"4,返回上级菜单"<<endl;
    cout<<setw(27)<<" ";
    cout<<"5,退出系统"<<endl;
    cout<<setw(27)<<" ";
    cout<<"请输入你的选项";
    cout<<setw(3)<<" ";
	int a;
	cin>>a;
	f5(a); 
}
void sup::f5(int a)//sup类成员函数类外定义
{
    switch (a)
	{
	case 1:this->d.showg();break;
	case 2:this->f.showg();break;
	case 3:this->e.showg();break;
	case 4: f1();break;
	case 5: exit(1);break;
    default :cout<<setw(27)<<" ";cout<<"对不起，没有这个选项，请重新输入"<<endl;system("cls");this->show();
	}	
}
void f2(int a)//一般函数定义
{
	switch (a)
	{
	case 1: s1.add();break;
	case 2: s1.sale();break;
	case 3: s1.show();break;
	case 4: exit(1);break;
    default :cout<<setw(27)<<" ";cout<<"对不起，没有这个选项，请重新输入"<<endl;system("cls");f1();
	}	
}
void turn2()//一般函数定义，调用s1.add函数
{
	s1.add();
}
void turn3()//一般函数定义，调用s1.sale函数
{
	s1.sale();
}
void turn4()//一般函数定义，调用s1.show函数
{
	s1.show();
}
int abc=0;
void goin()//登录界面函数，设置登录密码，和设置输入密码的机会
	{
		char secret[50];
		char ab[]="0794444944";
		system("color 5D");
        cout<<setw(30)<<" ";
		cout<<"你好，请输入密码,3次机会"<<endl;
		cout<<setw(30)<<" ";
        cin>>secret;
		abc++;
		if(strcmp(secret,ab)==0)
		{
			cout<<setw(30)<<" ";
		    cout<<"欢迎光临，你是合法用户"<<endl;
            cout<<setw(30)<<" ";
			system("pause");
			system("cls");
			f1();
		}
		else
		{
	        cout<<setw(30)<<" ";
		    cout<<"对不起，你还不是合法用户"<<endl;
			if(abc<=2)
		        goin();
			else
			{
                cout<<setw(30)<<" ";
				cout<<"对不起，次数已满";
				exit(1);
			}
		}
	}
int main()
{
	goin();//调用函数goin
	return 0;//返回给计算机的，我们看不到
}
