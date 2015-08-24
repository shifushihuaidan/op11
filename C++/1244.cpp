#include<iostream>
#include<fstream>
#include<string>                            //预处理指令
#include<iomanip>
using namespace std;
#include<windows.h>
#include<stdlib.h>
#define maxnumber 2 //栈的空间最大值
#define maxsize 2 //通道，队列的空间最大值
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
	int pop()//出栈
	{
		int x;
		x=elem[top];
		return x;
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
	int ik;
	int af;
	int ag;
	int ah;
	int ai;
	int aj;
    int abc;
    
	carstop()
	{
		abc=aj=ai=ag=af=ik=ac=ae=ad=0;
		for(int j=0;j<maxnumber;j++)
			number[j]=j+1;
	}
	void goin()
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
            color(14);
		    cout<<"欢迎光临，你是合法用户"<<endl;
            cout<<setw(30)<<" ";
			system("pause");
			system("cls");
			present();
		}
		else
		{
	        cout<<setw(30)<<" ";
            color(16);
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
            case 2: carsearch();break;
	        case 3: set();break;
		    case 4: leave();break;
		    case 5: retu();break;
		    default :cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");present();
		}
	}
    void set()
	{
        cout<<setw(15)<<" ";
		cout<<"1,修改停车空间大小"<<endl;
        cout<<setw(15)<<" ";
		cout<<"2,修改通道最大停车量"<<endl;
        cout<<setw(15)<<" ";
		cout<<"3,查看停车空间大小，通道最大停车量，停车价格"<<endl;
        cout<<setw(15)<<" ";
		cout<<"4,修改停车价格"<<endl;
        cout<<setw(15)<<" ";
        cout<<"5，返回上级菜单"<<endl;
        cout<<setw(15)<<" ";
		cout<<"6,退出系统"<<endl;
        cout<<setw(30)<<" ";
	    cout<<"请输入选项号";
		cout<<setw(3)<<" ";
		cin>>ag;
		switch(ag)
		{
		    case 1 : 
            case 4 : 
			case 2 : cout<<setw(30)<<" ";cout<<"你暂时无权限，请到代码中第一行修改"<<endl;break;
			case 3 : watch();break;
		    case 5 : system("cls");present();break;
		    case 6 : leave();break;
			default : cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");set();
		}
         watchop();
	}
    void watch()
	{
		cout<<setw(15)<<" ";
		cout<<"车场最大停位数"<<setw(3)<<" "<<maxnumber;
        cout<<setw(3)<<" ";
		cout<<"通道最大停车数"<<setw(3)<<" "<<maxsize-1;
        cout<<setw(3)<<" ";
		cout<<"停车价格"<<setw(3)<<" "<<Price<<endl;
        watchop();
	}
	void watchop()
	{
        cout<<setw(30)<<" ";
		cout<<"7，返回上级菜单"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,退出系统"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 7 : system("cls");set();break;
		    case 8 : leave();break;
			default : cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");carinop();
		}

	
	}

	void carsearch()
	{
        cout<<setw(15)<<" ";
		cout<<"1,全部显示即可显示所有车辆和车位信息"<<endl;
        cout<<setw(15)<<" ";
		cout<<"2,车辆信息查询可依据车牌号对其相关信息查询"<<endl;
        cout<<setw(15)<<" ";
		cout<<"3,车位信息查询可依据车位号对其相关信息查询"<<endl;
        cout<<setw(15)<<" ";
		cout<<"4,便道信息查询可依据车号对其相关信息查询"<<endl;
        cout<<setw(15)<<" ";
		cout<<"5，返回上级菜单"<<endl;
        cout<<setw(15)<<" ";
		cout<<"6,退出系统"<<endl;
        cout<<setw(30)<<" ";
	    cout<<"请输入选项号";
		cout<<setw(3)<<" ";
		cin>>ag;
		switch(ag)
		{
		    case 1 : allpresent();break;
			case 2 : oncarnumber();break;
			case 3 : onnumber();break;
			case 4 : wait();break;
		    case 5 : system("cls");present();break;
		    case 6 : leave();break;
			default : cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");carsearch();
		}
	}
	void wait()
	{
        system("cls");
		cout<<setw(30)<<" "<<"请输入你要找的车的车牌号";
        cout<<setw(3)<<" ";
		cin>>aj;
		int jj=0;
        for(int j=0;j<maxsize;j++)
		{
			if(base[j]==aj)
			{
				jj++;
                cout<<setw(30)<<" "<<"找到了"<<endl;
				cout<<setw(10)<<" "<<"通道中，车牌号是"<<aj<<endl;
			}
		}
		if(jj==0)
			cout<<setw(30)<<" "<<"抱歉，通道中没有"<<endl;
       waitop();
	}
	void waitop()
	{
        cout<<setw(30)<<" ";
		cout<<"7，返回上级菜单"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,退出系统"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 7 : system("cls");carsearch();break;
		    case 8 : leave();break;
			default : cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");carinop();
		}

	}
	void onnumber()
	{
        system("cls");
		cout<<setw(30)<<" "<<"请输入你要找的车的车位号";
        cout<<setw(3)<<" ";
		cin>>aj;
		int kk=0;
        for(int j=0;j<=top;j++)
		{
			if(number[j]==aj)
			{
				kk++;
				cout<<setw(30)<<" "<<"找到了"<<endl;
				cout<<setw(25)<<" "<<"在车场中,车牌号是"<<elem[j]<<setw(3)<<" "<<"时间"<<time[j];
				cout<<setw(3)<<" "<<"应缴费"<<time[j]*Price<<endl;break;
			}
		}
		if(kk==0)
			cout<<setw(30)<<" "<<"抱歉，车场中没有"<<endl;
        onnumberop();
	}
	void onnumberop()
	{
        cout<<setw(30)<<" ";
		cout<<"7，返回上级菜单"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,退出系统"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 7 : system("cls");carsearch();break;
		    case 8 : leave();break;
			default : cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");carinop();
		}

	}
	void oncarnumber()
	{
        system("cls");
		cout<<setw(30)<<" "<<"请输入你要找的车的车牌号";
        cout<<setw(3)<<" ";
        int jj=0;
		int gk=0;
        int kj=0;
		cin>>aj;
		for(;jj<=top;jj++)
		{
			if(elem[jj]==aj)
			{
				kj++;
				break;
			}
		}
	    if(kj!=0)
		{
            cout<<setw(30)<<" "<<"找到了"<<endl;
		    cout<<setw(25)<<" "<<"在车场中,车位号是"<<number[jj];
            cout<<setw(3)<<" "<<"时间"<<time[jj];
			cout<<setw(3)<<" "<<"应缴费"<<time[jj]*Price<<endl;
		}
	    else
		{
            if(kj==0)
			{
                cout<<setw(30)<<" "<<"抱歉，车场中没有"<<endl;
			}
		for(int j=0;j<maxsize;j++)
		{
	        if(base[j]==aj)
			{
				gk++;
                cout<<setw(30)<<" "<<"找到了"<<endl;
			    cout<<setw(10)<<" "<<"在通道中，车牌号是"<<aj<<endl;break;
			}
		}
		if(gk==0)
		{
            cout<<setw(30)<<" "<<"抱歉，通道中也没有"<<endl;
		}
		}
        oncarnumberop();

	}
	void oncarnumberop()
	{
        cout<<setw(30)<<" ";
		cout<<"7，返回上级菜单"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,退出系统"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 7 : system("cls");carsearch();break;
		    case 8 : leave();break;
			default : cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");carinop();
		}


	}
    void allpresent()
	{
		cout<<setw(30)<<" "<<"车场中的车信息如下"<<endl;
		for(int j=0;j<=top;j++)
		{
		    cout<<setw(25)<<" "<<"车位号"<<number[j];
            cout<<setw(3)<<" "<<"时间"<<time[j];
			cout<<setw(3)<<" "<<"费用"<<time[j]*Price<<endl;
		}
        allpresentop();

	}
	void allpresentop()
	{
        cout<<setw(30)<<" ";
		cout<<"7，返回上级菜单"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,退出系统"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 7 : system("cls");carsearch();break;
		    case 8 : leave();break;
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
	    cout<<"请输入要离去的车牌号,或车位号";
		cout<<setw(3)<<" ";
		cin>>ah;
		int k=0;
		int j=0;
        int a[maxnumber];
		int m=0;
		for(;j<=top;j++)
		{
	        if(elem[j]==ah||number[j]==ah)
			{
			    k++;
                cout<<setw(30)<<" ";
				cout<<"找到了"<<endl;
                cout<<setw(30)<<" ";
				cout<<"车牌号为"<<setw(3)<<" "<<elem[j]<<endl;
				cout<<setw(30)<<" "<<"车位号为"<<setw(3)<<" "<<number[j]<<endl;
				cout<<setw(30)<<" "<<"应缴费"<<setw(3)<<" "<<time[j]*Price<<endl;
                for(j;j<top;j++)
		            time[j]=time[j+1];
				break;
			}
		}
        int t=0;
		if(k==0)
		{
	        cout<<setw(30)<<" ";
            cout<<"抱歉，车场中没有这车"<<endl;
		}
		else
		{
		    for(;j<top;j++)
		        elem[j]=elem[j+1];
			int m=0;
			m=dependnul();
			if(m==1)
			{
			    elem[top]=base[front];
                cout<<setw(30)<<" ";
				cout<<"通道车补进，车牌号为"<<setw(3)<<" "<<base[front]<<endl;
                front=(front+1)%maxsize;
                cout<<setw(30)<<" ";
                cout<<"该车，停放时间";
                cout<<setw(3)<<" ";
                cin>>time[top];
			}
			else
				top--;
		}
	    caroutop();
	}
	void caroutop()
	{
        cout<<setw(30)<<" ";
		cout<<"7，返回上级菜单"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,退出系统"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 7 : system("cls");carinout();break;
		    case 8 : leave();break;
			default : cout<<setw(15)<<" "<<"对不起，没有这个选项"<<endl;system("pause");system("cls");carinop();
		}

	}
    void carin()
	{
		ae=regard();
		ad=dependfull();
		if(ae==0)
		{
			cout<<setw(25)<<" ";
			cout<<"对不起,车场满了,请到通道等候"<<endl;
			if(ad==0)
			{
                cout<<setw(25)<<" ";
			    cout<<"太抱歉了,通道也满了，欢迎下次再来"<<endl;
			}
			else
			{
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
				cout<<setw(30)<<" ";
				cout<<"请输入停车时间";
                cout<<setw(5)<<" ";
				cin>>time[ik];
			    push(carnumber);
                ik++;
		}
        carinop();
	}
	void carinop()
	{
        cout<<setw(30)<<" ";
		cout<<"7，返回上级菜单"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,退出系统"<<endl;
        cout<<setw(30)<<" ";
	    cin>>af;
		switch(af)
		{
		    case 7 : system("cls");carinout();break;
		    case 8 : leave();break;
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