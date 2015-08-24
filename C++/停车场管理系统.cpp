#include<iostream>
#include<fstream>
#include<string>                            //预处理指令
#include<iomanip>
using namespace std;
#include<windows.h>
#define maxnumber 50 //栈的空间最大值
#define maxsize 10 //通道，队列的空间最大值
#define Price 3//停车价格
void color(int a)//定义设置颜色函数，带参数，参数控制颜色
	{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);//头文件也可以是ConsoleColor.h
	}
class sqstack //车场的车位类定义，栈
{
public:
	int elem[maxnumber];
	int top;
	sqstack()
	{
		top=-1;
	}
	void push(int x)//进栈
	{
		top++;
		elem[top]=x;
	}
	void pop()//出栈
	{
		int x;
		x=elem[top];
		//return x;
	}
	int gettop()//获取栈顶元素，值
	{
		return elem[top];
	}
	int regard()//判断是否栈满，满了返回值为0，未满返回值为1
	{
		if(top==maxnumber-1)
			return 0;
		else return 1;
	}
	void print()
	{
		cout<<elem[top];
	}

};
class sequeue  //车场等候通道类，队列，定义
{
public:
	int *base;
	int front;
	int rear;
	sequeue()
	{
		base=new int [maxsize];
		front=rear=0;
	}
	void enqueue(int e)//进队
	{
		base[rear]=e;
		rear=(rear+1)%maxsize;
	}
	int dequeue(int *e)//出队
	{
		*e=base[front];
		front=(front+1)%maxsize;
		return 1;
	}
	void print()//输出函数
	{
		for(int i=front;i<rear;i++)
			cout<<base[i];
	}
	int dependfull()//判断队列是否已满，满了返回值为0，未满返回值为1
	{
		if((rear+1)%maxsize==front)
			return 0;
		else
			return 1;
	
	}
	int dependnul()//判断队列是否为空，满了返回值为0，未满返回值为1
	{
		if(rear==front)
			return 0;
		else
			return 1;
	}


};
class carstop: public sequeue,public sqstack//停车场管理类,多重继承类
{
public:
    int ac;
	int ad;
	int time[maxnumber];//停车时间
	int number[maxnumber];//车位号
	int carnumber;//车牌号
	int ae;
	int i;
	int af;
	int ag;
	int ah;
	int ai;
    
	carstop()
	{
		ai=ag=af=i=ac=ae=ad=0;
		time[i]=number[i]=0;
	}
	void goin()
	{
		char secret[50];
		char ab[]="0794444944";
		color(11);
        cout<<setw(30)<<" ";
		cout<<"你好，请输入密码"<<endl;
		cout<<setw(30)<<" ";
        cin>>secret;
		if(strcmp(secret,ab)==0)
		{
			cout<<setw(30)<<" ";
            color(14);
		    cout<<"欢迎光临，你是合法用户"<<endl;
			system("cls");
			present();
		}
		else
		{
	        cout<<setw(30)<<" ";
            color(16);
		    cout<<"对不起，你还不是合法用户"<<endl;
		    goin();
		}
	}
	void present()
	{
		cout<<setw(30)<<" ";
        system("color 33");
		cout<<"停车场管理系统"<<endl;
		cout<<setw(15)<<" ";
		cout<<"****************************************"<<endl;
        cout<<setw(15)<<" ";
		cout<<"****************************************"<<endl;
        cout<<setw(15)<<" ";
		cout<<"1，车辆进出管理"<<setw(10)<<" "<<"2，车辆查询管理"<<endl;
		cout<<setw(15)<<" ";
		cout<<"3，基本参数设置"<<setw(10)<<" "<<"4，退出系统"<<endl;
        cout<<setw(15)<<" ";
		cout<<"5，返回上级菜单"<<endl;
        cout<<setw(15)<<" ";
		cout<<"****************************************"<<endl;
        cout<<setw(15)<<" ";
		cout<<"****************************************"<<endl;
        cout<<setw(30)<<" ";
		cout<<"请输入选项号"<<setw(3)<<" ";
		cin>>ac;
		switch(ac)
		{
            case 1: carinout();break;
            /*case 2: carsearch();break;
	        case 3: set();break;*/
		    case 4: leave();break;
		    case 5: retu();break;
		    default :cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");present();
		}
	}
	void carsearch()
	{
        cout<<setw(15)<<" ";
		cout<<"1,全部显示即可显示所有车辆和车位信息";
        cout<<setw(10)<<" ";
		cout<<"2,车辆信息查询可依据车牌号对其相关信息查询"<<endl;
        cout<<setw(15)<<" ";
		cout<<"3,车位信息查询可依据车位号对其相关信息查询";
        cout<<setw(10)<<" ";
		cout<<"4,便道信息查询可依据车位号对其相关信息查询"<<endl;
        cout<<setw(15)<<" ";
		cout<<"5，返回上级菜单"<<endl;
        cout<<setw(10)<<" ";
		cout<<"6,退出系统"<<endl;
        cout<<setw(30)<<" ";
	    cout<<"请输入选项号"<<endl;
		cout<<setw(3)<<" ";
		cin>>ag;
		switch(ag)
		{
		    case 1 : 
		    case 5 : system("cls");cout<<setw(15)<<" ";
		
		    case 1 : 
		    case 5 : system("cls");goin();break;
		    case 6 : leave();break;
			default : cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");carinop();
		};break;
		    case 6 : leave();break;
			default : cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");carinop();
		}


	}
    void carinout()
	{
        cout<<setw(30)<<" ";
	    cout<<"车辆进出管理"<<endl;
		cout<<setw(15)<<" ";
		cout<<"1,车辆进入管理"<<setw(10)<<" "<<"2,车辆出场管理"<<endl;
        cout<<setw(15)<<" ";
		cout<<"3,返回上级菜单"<<endl;
        cout<<setw(30)<<" ";
		cout<<"请输入选项号"<<setw(3)<<" ";
		cin>>ad;
	    switch(ad)
		{
		    case 1: carin();break;
			case 2: carout();break;
			case 3:system("cls"); present();break;
			default : cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");present();
		}
		

	}
    void carout()
	{
        system("cls");
        cout<<setw(30)<<" ";
	    cout<<"请输入要离去的车牌号";
		cout<<setw(3)<<" ";
		cin>>ah;
		int k=0;
		for(int j=0;j<=top;j++)
		{
			if(elem[j]==ah||number[j]==ah)
			{
				k++;
                cout<<setw(30)<<" ";
				cout<<"找到了"<<endl;
                cout<<setw(30)<<" ";
				cout<<"车牌号为"<<setw(3)<<" "<<elem[j]<<endl;
				cout<<setw(30)<<" "<<"车位号为"<<setw(3)<<" "<<number[j]<<endl;
				cout<<setw(30)<<" "<<"应缴费"<<setw(3)<<" "<<time[j]*Price<<endl;break;

			}
		}
		if(k==0)
		{
	        cout<<setw(30)<<" ";
            cout<<"抱歉，没有这车"<<endl;
		}
		else
		{
			int *p=0;
            p=&elem[j];
			for(j--;j<=top;j++)
			{
				pop();
			}
			for(k--;k<top;k++)
			{
				push(*p);
				p++;
			}
			int l=0;
			l=dependnul();
			if(l==1)
			{
				push(base[front]);
                front=(front+1)%maxsize;
			}	
		}
		caroutop();
	}
	void caroutop()
	{
        system("cls");
        cout<<setw(30)<<" ";
		cout<<"1，返回上级菜单"<<endl;
        cout<<setw(30)<<" ";
		cout<<"2,退出系统"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 1 : system("cls");carinout();break;
		    case 2 : leave();break;
			default : cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");carinop();
		}

	}
    void carin()
	{
		ae=regard();
		ad=dependfull();
		if(ae==0)
		{
			cout<<setw(15)<<" ";
			cout<<"对不起,车场满了,请到通道等候"<<endl;
			if(ad==0)
			{
                cout<<setw(15)<<" ";
			    cout<<"太抱歉了,通道也满了，欢迎下次再来"<<endl;
			}
			else
			{
				system("cls");
                cout<<setw(30)<<" ";
				cout<<"请输入进通道的车牌号";
                cout<<setw(3)<<" ";
				cin>>carnumber;
				enqueue(carnumber);
			}

		}
		else
		{
                cout<<setw(30)<<" ";
				cout<<"请输入进场车牌号";
                cout<<setw(3)<<" ";
				cin>>carnumber;
				number[i]++;
				cout<<setw(30)<<" ";
				cout<<"请输入停车时间";
                cout<<setw(3)<<" ";
				cin>>time[i];
			    push(carnumber);
                i++;
		}
        carinop();
	}
	void carinop()
	{
		system("cls");
        cout<<setw(30)<<" ";
		cout<<"1，返回上级菜单"<<endl;
        cout<<setw(30)<<" ";
		cout<<"2,退出系统"<<endl;
        cout<<setw(30)<<" ";
	    cin>>af;
		switch(af)
		{
		    case 1 : system("cls");carinout();break;
		    case 2 : leave();break;
			default : cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");carinop();
		}
	}
    void retu()
	{
		goin();
	}
    void leave()
	{
		exit(1);
	}

};
int main()
{
    carstop car;
	car.goin();
	return 0;

}