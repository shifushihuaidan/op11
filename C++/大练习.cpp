#include<iostream.h>//Ԥ����ָ��������ͷ�ļ�
#include<windows.h>//��λ�����е�SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos)��ͷ�ļ�
                     //������ɫ�����е�SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a)ͷ�ļ�
#include<stdlib.h>//�������ͷ�ļ�
#include<time.h>//ʱ�亯��ͷ�ļ�
#include<conio.h>//���ƻ��������������ͷ�ļ���getche(void);
#define N 21     //�궨��  N��Χǽ�Ĵ�С
class snake      //��snake������
{
public:            //����Ȩ��
    int gift[2];   //����һ��һά����������С�ߵ�ʳ��
    void pos(int x,int y)//���嶨λ������������
	{
        COORD pos;      //����һ��COOD������ȷ��λ��
        pos.X=2*x;        //��pos�ĺ����긳ֵ
        pos.Y=y;          //��pos�������긳ֵ
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);//���û��庯��
	}
    void color(int a)//����������ɫ������������������������ɫ
	{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);//ͷ�ļ�Ҳ������ConsoleColor.h
	}
	snake()       //���幹�캯��snake����������������˵��Ĭ�ϵĹ��캯��
	{
		int i,j;    //���������ֲ���������������Ҫ�õ�ѭ��
		
		int a[N+1][N+1];    //����һ����ά���飬��ʵ����Сɫ�Ļ��Χ���
		for( i=0;i<N+1;i++)    //������for���������ά���鸳��ֵΪ0
			for( j=0;j<N+1;j++)
				a[i][j]=0;
       for( i=1;i<N;i++)
			for( j=1;j<N;j++)    //������for�������Сɫ����Ļ�������¸�ֵΪ1
				a[i][j]=1;
       for( i=0;i<N+1;i++)
	   {
			for( j=0;j<N+1;j++)
			{
                color(33);         //������ɫ����color��ʹ����ɫΪ33�ŵ���ɫ
                if(a[i][j]==1)     //�ж��Ƿ���Χǽ�������������䣬�������䣬����� ������ʾ����
					cout<<"��";
			    else
					cout<<"��";     //����Χǽ���������һ���飬����ʾ
			}
			cout<<endl;           	 //ע������õĺ���ģ����������������ʽ��       

	   }
	   color(44);                     //���ϰ�������Ϸ˵��
	   pos(N+3,2);
	   cout<<"��ӭ����"<<endl;
	   pos(N+3,3);
	   cout<<"������̰����"<<endl;
       pos(N+3,5);
	   cout<<"�����˰�һ��Jesus"<<endl;
       pos(N+3,7);
	   cout<<"��1,2,3,4�����������ƶ�"<<endl;
       gift[0]=rand()%(N-1)+1;         //�������ֵ��ֵ���õ����ȡֵ��������Ϊ����Ҫ����������������ֵ�λ�ã�
       gift[1]=rand()%(N-1)+1;
       pos(gift[0],gift[1]);          //ȷ��������ֵ�λ��
       color(66);
       cout<<"��"<<endl;               //���������������
	}
	void makesna(snake s )             // ����һ���������ĳ�Ա���������������
	{
        int tail[2];                   // ����һ��һλ���飬����������Сɫ���ƶ�����ʵ����Сɫ���ƶ���������Ķ���
		                                //  �ͱ�����ɫ�ڱ仯����
		int ** sna=NULL;                 //����һ��ָ���ָ�룬��ʵ���������������ά�����ָ��
	    int i=0,lengh=1;                 //�����������ֲ�����i(��������������ѭ������),lengh(Сɫ�ĳ���)��
        sna=(int**)realloc(sna,sizeof(int*)*lengh);//��sna�ӿռ䣬��Ϊ��֪��c++����������ܵĶ��������������õ���
                                                        //C���Ե�
		for(i=0;i<lengh;i++)                       // ��for�������snaָ���¿��Ŀռ�
        sna[i]=new int [2];                    
        for(i=0;i<lengh;i++)                     //��for���������Сɫ���ȳ��ֵĵط� ����ȻҪСɫ�ĳ��ȿ���
		{
            sna[i][0]=N/2;
            sna[i][1]=N/2+i;                        
            s.pos(sna[i][0],sna[i][1]);
            s.color(14);
            cout<<"��"<<endl;
		}
        while(1)                                        //����whileѭ��������ѭ��
		{
            tail[0]=sna[lengh-1][0];                    //����Сɫ���Ա��������
            tail[1]=sna[lengh-1][1];
            s.pos(tail[0],tail[1]);
            s.color(33);
            cout<<"��"<<endl;
		char c;                                          //������һ���ַ��;ֲ�������������������Сɫ���ƶ�  
		if(kbhit())                                  
		{                                                  //kbhit()����c�����������ж��Ƿ������ݳ��������
           s.pos(0,N+2);
           c=getche();                                   //��C��ֵ���Ӽ��̽���
		}
        switch(c)
		{
            case '1':sna[0][1]--;break;                    //��switch������ж�Сɫ�����������ƶ� 
            case '2':sna[0][1]++;break;
            case '3':sna[0][0]--;break;
            case '4':sna[0][0]++;break;
            default: break;
		}
        s.pos(sna[0][0],sna[0][1]);                         
        color(14);                                    //Сɫ�ƶ�
        cout<<"��"<<endl;
		int score=0;
        Sleep(abs(200-0.5*score));                         //����Сɫ�ƶ��ٶȣ�������䣬�������ⰴһ������Ϸ����
        if(sna[0][0]==gift[0]&&sna[0][1]==gift[1])          //�ж���Ϸ�Ƿ�ý����ˣ�
        {
            s.pos(N/2,N/2);                                       
            s.color(30);
            cout<<"�����ˣ���Ҫʲô���ԣ����Ǹİ��˵�"<<endl;
            for(i=0;i<lengh;i++)
            free(sna[i]);                         //�ͷſռ䣬��deleteҲ���Ե�
            Sleep(INFINITE);                       //����ֹ˯��
            exit(0);                               //��Ϸ��������abore()Ҳ���Ե�
		}
        if(sna[0][1]==0||sna[0][1]==N||sna[0][0]==0||sna[0][0]==N)//ײ��Χǽ����Ϸ����
		{
            s.pos(N/2,N/2);
            s.color(30);
            cout<<"������������,�����´���Ϸ����"<<endl;
            for(i=0;i<lengh;i++)
            free(sna[i]);                        //�ͷſռ䣬��deleteҲ���Ե�
            Sleep(INFINITE);                     //����ֹ˯��
            exit(0);                              //��Ϸ��������abore()Ҳ���Ե�
		}
		}
	}
	   


};                                             // ע����ֻ���۵�������Ҫ�ǵüӷֺ�
int main()                                      //����������
{
	srand((unsigned)time(NULL));                 //������������������ģ�������䣬����������������һ��
	snake snake;                              //����һ�������
	snake.makesna(snake);                        //�����������ĳ�Ա����
	return 0;                                      //����ֵ
}