#include<iostream.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#define N 21
class snake
{
public:
    void pos(int x,int y)//定位函数
	{
        COORD pos;
        pos.X=2*x;
        pos.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	}
    void color(int a)//设置颜色函数
	{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
	}
	snake()
	{
		int i,j;
		int gift[2];
		int a[N+1][N+1];
		for( i=0;i<N+1;i++)
			for( j=0;j<N+1;j++)
				a[i][j]=0;
       for( i=1;i<N;i++)
			for( j=1;j<N;j++)
				a[i][j]=1;
       for( i=0;i<N+1;i++)
	   {
			for( j=0;j<N+1;j++)
			{
                color(33);
                if(a[i][j]==1)
					cout<<"◆";
			    else
					cout<<"◇";
			}
			cout<<endl;
	   }
	   color(44);
	   pos(N+3,2);
	   cout<<"欢迎来到"<<endl;
	   pos(N+3,3);
	   cout<<"海贼王探险小乐园"<<endl;
       pos(N+3,5);
	   cout<<"键1,2,3,4控制上下左移动"<<endl;
       gift[0]=rand()%(N-1)+1;//礼物
       gift[1]=rand()%(N-1)+1;
       pos(gift[0],gift[1]);
       color(66);
       cout<<"◎"<<endl;
	}
	void makesna(snake s )
	{
		int ** sna=NULL;
	    int i=0,lengh=1;
        sna=(int**)realloc(sna,sizeof(int*)*lengh);
        for(i=0;i<lengh;i++)
        sna[i]=new int [2];
        for(i=0;i<lengh;i++)
		{
            sna[i][0]=N/2;
            sna[i][1]=N/2+i;
            s.pos(sna[i][0],sna[i][1]);
            s.color(14);
            cout<<"☆"<<endl;
		}
	}


};
int main()
{
	srand((unsigned)time(NULL));
	snake snake;
	snake.makesna(snake);
    
	return 0;

}