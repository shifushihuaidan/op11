#include<iostream>//�������������ռ�
using namespace std;
#include<windows.h>//system("cls")��syetem("pause")�����������ˣ�����Ҫ�������
#include"stdio.h"
#include<iomanip>//setw()��ʽ���ƺ���ͷ�ļ�
//#include"time.h"

#include"malloc.h"
#define M 50
#define N 50
typedef struct node//��ջ�ṹ
{
	int row;  //��
	int col;  //��
	struct node * next;
}mlink;
mlink *stack;//����һ��ջ
int m,n,x1,x2,y1,y2;//����ȫ�����
int mg[M][N];
int aa=1;
void shuru()
{
	cout<<"�������������"<<endl;
	cin>>m;
	cout<<"�������������"<<endl;
	cin>>n;
}
void chushi()
{
	for(int i=0;i<=m+1;i++)
		for(int j=0;j<=n+1;j++)
		{
			mg[i][j]=1;  //��ʼ����֤�������֮Ϊ1
		}

}
void churukou()//������ܺͳ���
{
	cout<<"����������Թ����"<<endl;
	cin>>x1>>y1;
    cout<<"����������Թ�����"<<endl;
	cin>>x2>>y2;  

}
void showplay(int mg[][M+2])//����Թ���
{
	int i,j;
    cout<<"�������Թ�����:��0��ʾʹ�ģ�"<<endl;
	for(i=1;i<=m;i++)//�����֤
	{
		cout<<endl;
		for(j=1;j<=n;j++)
			cout<<mg[i][j];
	}
	cout<<endl;
	cout<<"�������Թ��ر�ͼ����:��ɫ����ʹ��"<<endl;//�������
	for(i=1;i<=m;i++)
	{
		cout<<endl;
		for(j=1;j<=n;j++)
		{
			if(mg[i][j]==0) cout<<"��";//Ϊ0�������
			if(mg[i][j]==1) cout<<"��";//Ϊ1�������
		}
	}

}
int Mazepath(int mg[][N+2])//��·
{
	mlink *p;
	if(mg[x1][y1]==0){
	p=(mlink *)malloc(sizeof(mlink));
	p->row=x1;
	p->col=y1;
	p->next=NULL;
	stack=p; //����ڷ����ջ
	mg[stack->row][stack->col]=1;//��־����ѷ���
	while((!(stack->row==NULL&&stack->col==NULL))&&(!(stack->row==x2&&stack->col==y2)))//ѭ������֪���ҵ�����ĳ���
		{
			if(mg[stack->row][stack->col+1]==0)//�����λ����ͨ��
			{
				p=(mlink *)malloc(sizeof(mlink));
				p->row=stack->row;
				p->col=stack->col+1;
				p->next=stack;           //��ջ
				stack=p;
				mg[stack->row][stack->col]=1;//�����ʹ��ı��Ϊ1
			}
			else if(mg[stack->row][stack->col-1]==0)//�����Ϊ֪��ͨ
			{
				p=(mlink *)malloc(sizeof(mlink));
				p->row=stack->row;
				p->col=stack->col-1;
				p->next=stack;       //��ջ
				stack=p;
				mg[stack->row][stack->col]=1;//�����ʹ��ı��Ϊ1

			}
			else if(mg[stack->row+1][stack->col]==0)//����Ŀ�ͨ
			{
				p=(mlink *)malloc(sizeof(mlink));
				p->row=stack->row+1;
				p->col=stack->col;
				p->next=stack;         //��ջ
				stack=p;
				mg[stack->row][stack->col]=1;//�����ʹ��ı��Ϊ1
			}
			else if(mg[stack->row-1][stack->col]==0)//����Ŀ�ͨ
			{
				p=(mlink *)malloc(sizeof(mlink));
				p->row=stack->row-1;
				p->col=stack->col;
				p->next=stack;        //��ջ
				stack=p;
				mg[stack->row][stack->col]=1;//�����ʹ��ı��Ϊ1
			}
			else   //����ͨ ������һ����
			{
				if (stack->next!=NULL){//��ջ�ﲼ��һ���������ջ������ѭ��
				p=stack;
				stack=stack->next;   //��ջ
				free(p);  //�ͷſռ�
				}
				else                   //��ջ��ֻ��һ�����㼴��ڣ���ʱ���ͷſռ��ջ��ʹѭ��
				{                      //����������Ƚϣ���Ϊstack->col,stack->row���Ѳ����ڣ�)
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
void tonglu()//������Ķ������
{
	mlink *q;
	int i,j;
	int a[M][N];
	for(i=0;i<m;i++)//�����ʼ��
		for(j=0;j<n;j++)
			a[i][j] = 1;
	printf("����ͨ��Ϊ�����¶��ϣ���\n");
	q=stack;		
	while (q!=NULL)//ѭ������
	{
		cout<<"<"<<q->row<<","<<q->col<<">"<<endl;
		q=q->next;
	}
	q=stack;		
	while (q!=NULL)//ѭ������
	{
		a[q->row-1][q->col-1] = 0;//��·���еĵ㸳������a
		q=q->next;
	}
	for(i=0;i<m;i++)//��·��ͼ�εķ�ʽ���
	{
		for(j=0;j<n;j++)
			if(a[i][j])
				cout<<"��";//1�����
			else
				cout<<"��";//0�����
		cout<<endl;
	}
}
void create(int mg[][N+2])//�˵�
{
	int i,j,x,choice,flag1=1;
	chushi();
	while(flag1){
		//if(aa==1)
		//{
	    cout<<"1�������"<<endl;
	    Sleep(1000);//��Ļ��ͣ3��
	    system("cls");
		aa=0;
		//}
        system("color 0b");//����ϵͳ�������ı䱳����ɫ��������ɫ
        cout<<setw(15)<<" ";//����setw()���������Ƹ�ʽ
        cout<<"****************************************"<<endl;//ԭ�����
        cout<<endl;
        cout<<setw(25)<<" ";
	    cout<<"�������Թ�"<<endl;
        cout<<endl;
        cout<<setw(15)<<" ";
        cout<<"****************************************"<<endl;
        cout<<setw(27)<<" ";
        cout<<"1,�ܶ������Թ�"<<endl;
        cout<<setw(27)<<" ";
        cout<<"2,�Զ�����Թ�"<<endl;
        cout<<setw(27)<<" ";
        cout<<"3,�˳�"<<endl;
        cout<<setw(27)<<" ";
        cout<<"���������ѡ��";
        cout<<setw(3)<<" ";
		cin>>choice;
		switch(choice){
		case 1://�ֶ������Թ�
			{
				shuru();
				cout<<"�ֶ������������Թ���֤(0��ʾ���ϰ�1��ʾ���ϰ�)"<<endl;
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
					    cout<<"��Ǹ˼·"<<endl;
                        system("pause");
			} break;
			
		case 2: //�Զ������Թ�
		{
			shuru();
			for(i=1;i<=m;i++)
				for(j=1;j<=n;j++)
					mg[i][j]=(int)(rand()%2);
				cout<<"�����Ӷ�����"<<endl;
				showplay(mg);
				churukou();  
				x=Mazepath(mg);
				if(x==1)
				{
					tonglu();
					cout<<endl;
				}
				else 
					cout<<"��Ǹ˼·"<<endl;
                    system("pause");
		} break;
	
		case 3:cout<<"�������ע������"<<endl;exit(1);
		}
	}

}
int main()//��ں���
{
	int mg[M+2][N+2];//�Թ�����
    create(mg);//��������
	return 0;
}
