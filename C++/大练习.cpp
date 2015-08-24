#include<iostream.h>//预处理指令，输入输出头文件
#include<windows.h>//定位函数中的SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos)的头文件
                     //设置颜色函数中的SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a)头文件
#include<stdlib.h>//随机函数头文件
#include<time.h>//时间函数头文件
#include<conio.h>//控制缓冲区间输入输出头文件，getche(void);
#define N 21     //宏定义  N是围墙的大小
class snake      //类snake的声明
{
public:            //访问权限
    int gift[2];   //定义一个一维数组来控制小蛇的食物
    void pos(int x,int y)//定义定位函数，带参数
	{
        COORD pos;      //定义一个COOD对象来确定位置
        pos.X=2*x;        //给pos的横坐标赋值
        pos.Y=y;          //给pos的纵坐标赋值
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);//调用缓冲函数
	}
    void color(int a)//定义设置颜色函数，带参数，参数控制颜色
	{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);//头文件也可以是ConsoleColor.h
	}
	snake()       //定义构造函数snake，不带参数，可以说是默认的构造函数
	{
		int i,j;    //定义两个局部变量，控制下面要用的循环
		
		int a[N+1][N+1];    //定义一个二维数组，其实就是小色的活动范围面积
		for( i=0;i<N+1;i++)    //用两个for语句来给二维数组赋初值为0
			for( j=0;j<N+1;j++)
				a[i][j]=0;
       for( i=1;i<N;i++)
			for( j=1;j<N;j++)    //用两个for语句来给小色真真的活动区间重新赋值为1
				a[i][j]=1;
       for( i=0;i<N+1;i++)
	   {
			for( j=0;j<N+1;j++)
			{
                color(33);         //调用颜色函数color，使其颜色为33号的颜色
                if(a[i][j]==1)     //判断是否是围墙，还是真真区间，若是区间，泽输出 ◆，以示区别
					cout<<"◆";
			    else
					cout<<"◇";     //若是围墙，泽输出另一方块，来表示
			}
			cout<<endl;           	 //注意这句用的很妙的，是用来控制输出格式的       

	   }
	   color(44);                     //加上帮助和游戏说明
	   pos(N+3,2);
	   cout<<"欢迎来到"<<endl;
	   pos(N+3,3);
	   cout<<"改良版贪吃蛇"<<endl;
       pos(N+3,5);
	   cout<<"制作人白一泽Jesus"<<endl;
       pos(N+3,7);
	   cout<<"键1,2,3,4控制上下左移动"<<endl;
       gift[0]=rand()%(N-1)+1;         //给礼物的值赋值，用的随机取值函数，因为下面要用来，控制礼物出现的位置，
       gift[1]=rand()%(N-1)+1;
       pos(gift[0],gift[1]);          //确定礼物出现的位置
       color(66);
       cout<<"◎"<<endl;               //用这个来代表礼物
	}
	void makesna(snake s )             // 定义一个带参数的成员函数，来具体操作
	{
        int tail[2];                   // 定义一个一位数组，来控制下面小色的移动，其实不是小色在移动而是输出的东西
		                                //  和背景颜色在变化而已
		int ** sna=NULL;                 //定义一个指针的指针，其实下面试用来代表二维数组的指针
	    int i=0,lengh=1;                 //定义了两个局部变量i(下面是用来控制循环语句的),lengh(小色的长度)，
        sna=(int**)realloc(sna,sizeof(int*)*lengh);//给sna加空间，因为不知道c++中有这个功能的东西，所以在这用的是
                                                        //C语言的
		for(i=0;i<lengh;i++)                       // 用for语句来让sna指向新开的空间
        sna[i]=new int [2];                    
        for(i=0;i<lengh;i++)                     //用for语句来控制小色首先出现的地方 ，当然要小色的长度控制
		{
            sna[i][0]=N/2;
            sna[i][1]=N/2+i;                        
            s.pos(sna[i][0],sna[i][1]);
            s.color(14);
            cout<<"☆"<<endl;
		}
        while(1)                                        //用了while循环语句进入循环
		{
            tail[0]=sna[lengh-1][0];                    //控制小色的旁边输出东西
            tail[1]=sna[lengh-1][1];
            s.pos(tail[0],tail[1]);
            s.color(33);
            cout<<"◆"<<endl;
		char c;                                          //定义了一个字符型局部变量，下面用来控制小色的移动  
		if(kbhit())                                  
		{                                                  //kbhit()这是c语言中用来判断是否有数据冲键盘输入
           s.pos(0,N+2);
           c=getche();                                   //给C赋值，从键盘接收
		}
        switch(c)
		{
            case '1':sna[0][1]--;break;                    //用switch语句来判断小色的上下左右移动 
            case '2':sna[0][1]++;break;
            case '3':sna[0][0]--;break;
            case '4':sna[0][0]++;break;
            default: break;
		}
        s.pos(sna[0][0],sna[0][1]);                         
        color(14);                                    //小色移动
        cout<<"☆"<<endl;
		int score=0;
        Sleep(abs(200-0.5*score));                         //降低小色移动速度，不加这句，则你随意按一键则游戏结束
        if(sna[0][0]==gift[0]&&sna[0][1]==gift[1])          //判断游戏是否该结束了，
        {
            s.pos(N/2,N/2);                                       
            s.color(30);
            cout<<"你输了，不要什么都吃，这是改版了的"<<endl;
            for(i=0;i<lengh;i++)
            free(sna[i]);                         //释放空间，用delete也可以的
            Sleep(INFINITE);                       //无休止睡眠
            exit(0);                               //游戏结束，用abore()也可以的
		}
        if(sna[0][1]==0||sna[0][1]==N||sna[0][0]==0||sna[0][0]==N)//撞到围墙后游戏结束
		{
            s.pos(N/2,N/2);
            s.color(30);
            cout<<"哈哈，你输了,请重新打开游戏再玩"<<endl;
            for(i=0;i<lengh;i++)
            free(sna[i]);                        //释放空间，用delete也可以的
            Sleep(INFINITE);                     //无休止睡眠
            exit(0);                              //游戏结束，用abore()也可以的
		}
		}
	}
	   


};                                             // 注意这只是累的声明，要记得加分号
int main()                                      //定义主函数
{
	srand((unsigned)time(NULL));                 //这是用来控制随机数的，不加这句，则产生的随机数可能一样
	snake snake;                              //定义一个类对象
	snake.makesna(snake);                        //调用了类对象的成员函数
	return 0;                                      //返回值
}