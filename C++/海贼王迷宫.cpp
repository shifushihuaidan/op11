#include<iostream>//引入名字命名空间
using namespace std;
#include<windows.h>//system("cls")和syetem("pause")在类中生命了，所以要导入此类
#include"stdio.h"
#include<iomanip>//setw()格式控制函数头文件
//#include"time.h"

#include"malloc.h"
#define M 50
#define N 50
typedef struct node//链栈结构
{
	int row;  //行
	int col;  //列
	struct node * next;
}mlink;
mlink *stack;//定义一个栈
int m,n,x1,x2,y1,y2;//定义全剧变量
int mg[M][N];
int aa=1;
void shuru()
{
	cout<<"情书入你的行数"<<endl;
	cin>>m;
	cout<<"情书入你的列数"<<endl;
	cin>>n;
}
void chushi()
{
	for(int i=0;i<=m+1;i++)
		for(int j=0;j<=n+1;j++)
		{
			mg[i][j]=1;  //初始化举证，最外城之为1
		}

}
void churukou()//定义入寇和出口
{
	cout<<"情书入你的迷宫入口"<<endl;
	cin>>x1>>y1;
    cout<<"情书入你的迷宫初口"<<endl;
	cin>>x2>>y2;  

}
void showplay(int mg[][M+2])//输出迷宫，
{
	int i,j;
    cout<<"海贼王迷宫如下:（0表示痛的）"<<endl;
	for(i=1;i<=m;i++)//输出举证
	{
		cout<<endl;
		for(j=1;j<=n;j++)
			cout<<mg[i][j];
	}
	cout<<endl;
	cout<<"海贼王迷宫藏宝图如下:白色就是痛的"<<endl;//书出土的
	for(i=1;i<=m;i++)
	{
		cout<<endl;
		for(j=1;j<=n;j++)
		{
			if(mg[i][j]==0) cout<<"□";//为0的输出□
			if(mg[i][j]==1) cout<<"■";//为1的输出■
		}
	}

}
int Mazepath(int mg[][N+2])//找路
{
	mlink *p;
	if(mg[x1][y1]==0){
	p=(mlink *)malloc(sizeof(mlink));
	p->row=x1;
	p->col=y1;
	p->next=NULL;
	stack=p; //吧入口放入堆栈
	mg[stack->row][stack->col]=1;//标志入口已访问
	while((!(stack->row==NULL&&stack->col==NULL))&&(!(stack->row==x2&&stack->col==y2)))//循环条件知道找到输入的出口
		{
			if(mg[stack->row][stack->col+1]==0)//下面的位置是通的
			{
				p=(mlink *)malloc(sizeof(mlink));
				p->row=stack->row;
				p->col=stack->col+1;
				p->next=stack;           //入栈
				stack=p;
				mg[stack->row][stack->col]=1;//将访问过的标记为1
			}
			else if(mg[stack->row][stack->col-1]==0)//上面得为知可通
			{
				p=(mlink *)malloc(sizeof(mlink));
				p->row=stack->row;
				p->col=stack->col-1;
				p->next=stack;       //入栈
				stack=p;
				mg[stack->row][stack->col]=1;//将访问过的标记为1

			}
			else if(mg[stack->row+1][stack->col]==0)//右面的可通
			{
				p=(mlink *)malloc(sizeof(mlink));
				p->row=stack->row+1;
				p->col=stack->col;
				p->next=stack;         //入栈
				stack=p;
				mg[stack->row][stack->col]=1;//将访问过的标记为1
			}
			else if(mg[stack->row-1][stack->col]==0)//做面的可通
			{
				p=(mlink *)malloc(sizeof(mlink));
				p->row=stack->row-1;
				p->col=stack->col;
				p->next=stack;        //入栈
				stack=p;
				mg[stack->row][stack->col]=1;//将访问过的标记为1
			}
			else   //不可通 返回上一个点
			{
				if (stack->next!=NULL){//堆栈里布置一个顶点则出栈并返回循环
				p=stack;
				stack=stack->next;   //出栈
				free(p);  //释放空间
				}
				else                   //堆栈里只有一个顶点即入口，此时若释放空间出栈会使循环
				{                      //控制语句雾化比较（因为stack->col,stack->row都已不存在，)
				stack->row=NULL;
				stack->col=NULL;
				stack->next=NULL;}
			}
		
		}
		if (stack->row==x2&&stack->col==y2) return (1);
			else return (0);
	}
	else return(0);
}
void tonglu()//将坐标的顶点输出
{
	mlink *q;
	int i,j;
	int a[M][N];
	for(i=0;i<m;i++)//数组初始化
		for(j=0;j<n;j++)
			a[i][j] = 1;
	printf("所有通道为（又下而上）：\n");
	q=stack;		
	while (q!=NULL)//循环条件
	{
		cout<<"<"<<q->row<<","<<q->col<<">"<<endl;
		q=q->next;
	}
	q=stack;		
	while (q!=NULL)//循环条件
	{
		a[q->row-1][q->col-1] = 0;//将路径中的点赋给数组a
		q=q->next;
	}
	for(i=0;i<m;i++)//将路以图形的方式输出
	{
		for(j=0;j<n;j++)
			if(a[i][j])
				cout<<"■";//1的情况
			else
				cout<<"□";//0的情况
		cout<<endl;
	}
}
void create(int mg[][N+2])//菜单
{
	int i,j,x,choice,flag1=1;
	chushi();
	while(flag1){
		//if(aa==1)
		//{
	    cout<<"1秒后清屏"<<endl;
	    Sleep(1000);//屏幕暂停3秒
	    system("cls");
		aa=0;
		//}
        system("color 0b");//调用系统函数，改变背景颜色和字体颜色
        cout<<setw(15)<<" ";//调用setw()函数来控制格式
        cout<<"****************************************"<<endl;//原样输出
        cout<<endl;
        cout<<setw(25)<<" ";
	    cout<<"海贼王迷宫"<<endl;
        cout<<endl;
        cout<<setw(15)<<" ";
        cout<<"****************************************"<<endl;
        cout<<setw(27)<<" ";
        cout<<"1,受冻生成迷宫"<<endl;
        cout<<setw(27)<<" ";
        cout<<"2,自动深沉迷宫"<<endl;
        cout<<setw(27)<<" ";
        cout<<"3,退出"<<endl;
        cout<<setw(27)<<" ";
        cout<<"请书入你的选项";
        cout<<setw(3)<<" ";
		cin>>choice;
		switch(choice){
		case 1://手动建立迷宫
			{
				shuru();
				cout<<"手动建立海贼王迷宫举证(0表示无障碍1表示由障碍)"<<endl;
				for(i=1;i<=m;i++)
					for(j=1;j<=n;j++)
					    cin>>mg[i][j];
					showplay(mg);
					churukou();
					x=Mazepath(mg);
					if(x==1)
					{
						tonglu();
						cout<<endl;
					}
					else 
					    cout<<"抱歉思路"<<endl;
                        system("pause");
			} break;
			
		case 2: //自动建立迷宫
		{
			shuru();
			for(i=1;i<=m;i++)
				for(j=1;j<=n;j++)
					mg[i][j]=(int)(rand()%2);
				cout<<"正在子洞生成"<<endl;
				showplay(mg);
				churukou();  
				x=Mazepath(mg);
				if(x==1)
				{
					tonglu();
					cout<<endl;
				}
				else 
					cout<<"抱歉思路"<<endl;
                    system("pause");
		} break;
	
		case 3:cout<<"更多请关注海贼王"<<endl;exit(1);
		}
	}

}
int main()//入口函数
{
	int mg[M+2][N+2];//迷宫矩阵
    create(mg);//函数调用
	return 0;
}
