#include<iostream>//下面的几行是预处理指令，输入输出流对象头文件
#include<fstream>//文件流对象头文件
#include<string> //字符串头文件                           
#include<iomanip>//setw()格式控制函数头文件
#include <ctime>//时间类SYSTEMTIME以及时间提取函数locate()头文件
using namespace std;//使用名字命名空间
#include<windows.h>//system()指令，color()函数头文件
#include<stdlib.h>//system("color xy")头文件，x和y 是十六进制数，x表示字体颜色，y表示背景颜色
#define maxnumber 2 //栈的空间最大值，车场最大停车数，宏定义
#define maxsize 2 //通道最大停车数，队列的空间最大值，宏定义
#define Price 3//停车价格，宏定义
SYSTEMTIME sysTime[maxsize];//定义一个时间类SYSTEMTIME对象数组，而且是全局的
int opr(SYSTEMTIME x)//定义一个一般函数，提取时间类对象的时间，返回秒数
{
	return(x.wHour*3600+x.wMinute*60+x.wSecond);
}
void color(int a)//定义设置颜色函数，带参数，参数控制颜色，用了句柄
	{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);//头文件也可以是ConsoleColor.h
	}
class sqstack //车场的车位类定义，栈，
{
public:
	int * elem;//用elem指针，以数组方式存放停车场车的车牌号
	int top;//栈的头指针，整型，始终指向栈顶元素
	sqstack()//构造函数，给elem开空间，空间大小为maxnumber，以及给top赋初值-1
	{
		top=-1;
        elem=new int [maxnumber];
	}
	void push(int x)//进栈函数
	{
		top++;
		elem[top]=x;
	}
	int pop()//出栈函数，返回栈顶元素
	{
		int x;
		x=elem[top];
		return x;
	}
	int gettop()//获取当前栈顶元素的值
	{
		return elem[top];
	}
	int regard()//判断是否栈满，满了返回值为0，未满返回值为1
	{
		if(top==maxnumber-1)
			return 0;
		else return 1;
	}
	void print()//输出函数，用来输出当前栈顶元素的值
	{
		cout<<elem[top];
	}

};
class sequeue  //车场等候通道类，循环队列，
{
public:
	int *base;//用整型指针以数组方式存放通道中的车的车牌号
	int front;
	int rear;
	sequeue()//构造函数
	{
		base=new int [maxsize];
		front=rear=0;
	}
	void enqueue(int e)//进队函数
	{
		base[rear]=e;
		rear=(rear+1)%maxsize;
	}
	int dequeue(int *e)//删除首元素，若删除成功返回1
	{
		*e=base[front];
		front=(front+1)%maxsize;
		return 1;
	}
	void print()//输出函数，输出队列所有元素
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
class carstop: public sequeue,public sqstack//停车场管理类,多重继承类基类为sequeue和sqstack，公有继承方式
{
public:
    int ac;                      //其他以下变量都是控制循环而用的
	int ad; 
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
    
	carstop()//构造函数，把那些控制循环用的变量赋值为0，给车场中的车位赋值
	{
		abc=aj=ai=ag=af=ik=ac=ae=ad=0;
		for(int j=0;j<maxnumber;j++)
			number[j]=j+1;
	}
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
	void present()//主界面显示函数，用了字体颜色控制指令，用了switch语句来接受键盘输入，而进入相应界面
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
    void set()//参数设置界面函数，用了switch语句来接受键盘输入指令，从而进入另一界面
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
    void watch()//查看当前所有参数数据函数，并调用watchop()函数来接收键盘输入，而进入下一界面
	{
		cout<<setw(15)<<" ";
		cout<<"车场最大停位数"<<setw(3)<<" "<<maxnumber;
        cout<<setw(3)<<" ";
		cout<<"通道最大停车数"<<setw(3)<<" "<<maxsize-1;
        cout<<setw(3)<<" ";
		cout<<"停车价格"<<setw(3)<<" "<<Price<<endl;
        watchop();
	}
	void watchop()//用来接收键盘输入而进入下一相应界面
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

	void carsearch()//查询显示界面函数，用switch接收键盘输入而进入相应下一界面
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
	void wait()//进入通道车查询函数，查询通道中是否有该车
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
				cout<<setw(25)<<" "<<"通道中，车牌号是"<<aj<<endl;
			}
		}
		if(jj==0)
			cout<<setw(30)<<" "<<"抱歉，通道中没有"<<endl;
       waitop();
	}
	void waitop()//用来接收键盘输入而进入下一界面
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
	void onnumber()//根据车位号，而查询相应车场中该车的数据，车牌号，车位号，已停放时间，和现在应叫的费用
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
                SYSTEMTIME outtime;
				cout<<setw(30)<<" "<<"找到了"<<endl;
                cout<<setw(25)<<" "<<"在车场中,车牌号是"<<elem[j]<<setw(3)<<" ";
                GetLocalTime(&outtime); 
                int cd=opr(outtime);
			    int ce=opr(sysTime[j]);
                cout<<setw(3)<<" "<<"已停放"<<(cd-ce)<<"秒";
			    cout<<setw(3)<<" "<<"费用"<<(cd-ce)*Price<<endl;break;
			}
		}
		if(kk==0)
			cout<<setw(30)<<" "<<"抱歉，车场中没有"<<endl;
        onnumberop();
	}
	void onnumberop()//用来接收键盘输入而进入下一界面
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
	void oncarnumber()//依据车牌号，而查找该车，现在车场中查找，然后再在通道中查找，若有就输出相应信息
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
            SYSTEMTIME outtime;
            cout<<setw(30)<<" "<<"找到了"<<endl;
		    cout<<setw(25)<<" "<<"在车场中,车位号是"<<number[jj];
            GetLocalTime(&outtime); 
            int cd=opr(outtime);
			int ce=opr(sysTime[jj]);
            cout<<setw(3)<<" "<<"已停放"<<(cd-ce)<<"秒";
			cout<<setw(3)<<" "<<"费用"<<(cd-ce)*Price<<endl;
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
			    cout<<setw(25)<<" "<<"在通道中，车牌号是"<<aj<<endl;break;
			}
		}
		if(gk==0)
		{
            cout<<setw(30)<<" "<<"抱歉，通道中也没有"<<endl;
		}
		}
        oncarnumberop();

	}
	void oncarnumberop()//用来接收键盘输入而进入下一界面
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
    void allpresent()//全部显示车场中的车的数据信息函数
	{
		int j=0;
		cout<<setw(30)<<" "<<"车场中的车信息如下"<<endl;
		for(;j<=top;j++)
		{
			cout<<setw(25)<<" "<<"车牌号"<<elem[j];
		    cout<<setw(3)<<" "<<"车位号"<<number[j];
            SYSTEMTIME outtime;
            GetLocalTime(&outtime); 
            int cd=opr(outtime);
			int ce=opr(sysTime[j]);
            cout<<setw(3)<<" "<<"已停放"<<(cd-ce)<<"秒";
			cout<<setw(3)<<" "<<"费用"<<(cd-ce)*Price<<endl;
		}
        cout<<setw(30)<<" "<<"通道中的车信息如下"<<endl;;
        for(j=front;j<rear;j++)
			cout<<setw(25)<<" "<<"车牌号为"<<base[j]<<endl;
        allpresentop();

	}
	void allpresentop()//用来接收键盘输入而进入下一界面
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
    void carinout()//车辆进出界面函数，用switch语句接收键盘输入而进入相应界面
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
    void carout()//车辆离开车场函数，并输出该车的信息，车牌号和进场时间，当前出车时间，停放时间，和应交的费用
	{
        system("cls");
        cout<<setw(30)<<" ";
	    cout<<"请输入要离去的车牌号,或车位号";
		cout<<setw(3)<<" ";
		cin>>ah;
		int k=0;
		int j=0;
		int m=0;
		for(;j<=top;j++)
		{
	        if(elem[j]==ah||number[j]==ah)
			{
			    k++;
				int n=j;
                SYSTEMTIME outtime;//定义一个时间类对象outtime来记录当前时间
                GetLocalTime(&outtime); 
                cout<<setw(30)<<" ";
				int cd=opr(outtime);//调用转换时间值函数，把时间化为秒数
				int ce=opr(sysTime[j]);
				cout<<"找到了"<<endl;
                cout<<setw(30)<<" ";
				cout<<"车牌号为"<<setw(3)<<" "<<elem[j]<<endl;
				cout<<setw(30)<<" "<<"车位号为"<<setw(3)<<" "<<number[j]<<endl;
                cout<<setw(30)<<" ";
                cout<<"该车进入停车场时间为";	
				cout<<sysTime[j].wHour << "时" <<sysTime[j].wMinute;
				cout<<"分" <<sysTime[j].wSecond <<"秒"<<endl;
                cout<<setw(30)<<" ";
                cout<<"该车离开停车场时间为";	
				cout<<outtime.wHour << "时" <<outtime.wMinute;
				cout<<"分" << outtime.wSecond <<"秒"<<endl;
                cout<<setw(30)<<" ";
                cout<<"该车已停放"<<(cd-ce)<<"秒"<<endl;
				cout<<setw(30)<<" "<<"应缴费"<<setw(3)<<" "<<(cd-ce)*Price<<endl;
                for(j;j<top;j++)
		            sysTime[j]=sysTime[j+1];
                for(n;n<top;n++)
		            elem[n]=elem[n+1];
                int m=0;
			    m=dependnul();
			    if(m==1)
				{
			        elem[top]=base[front];
                    cout<<setw(30)<<" ";
				    cout<<"通道车补进，车牌号为"<<setw(3)<<" "<<base[front]<<endl;
                    front=(front+1)%maxsize;                    
                    GetLocalTime(&sysTime[top]); 
                    cout<<setw(30)<<" ";
					cout<<"进入停车场时间为";	
					cout<<sysTime[top].wHour << "时" <<sysTime[top].wMinute;
					cout<<"分" << sysTime[top].wSecond <<"秒"<<endl;
				}
			    else
				{
				    top--;
				}
				break;
			}
		}
	    caroutop();
	}
	void caroutop()//用来接收键盘输入而进入下一界面
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
    void carin()//车辆进入函数，先判断车场是否已满，若未满就进入车场，若满了就查询通道是否已满，若未满就进入通道
	{                                       //若通道也满了就欢迎下次光临了
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
                GetLocalTime(&sysTime[ik]); 
			    cout<<"进入停车场时间为";	
				cout<<sysTime[ik].wHour << "时" <<sysTime[ik].wMinute;
				cout<<"分" << sysTime[ik].wSecond <<"秒"<<endl;
				enqueue(carnumber);
			    push(carnumber);
                ik++;
		}
        carinop();
	}
	void carinop()//用来接收键盘输入而进入下一界面
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
    void retu()//主界面中的返回上级函数
	{
		goin();
	}
    void leave()//立即退出当前系统的退出函数
	{
		exit(1);
	}

};
int main()//主函数
{
    carstop car;//定义一个carstop 对象
    car.goin();//调用登录系统函数
	return 0;
}
