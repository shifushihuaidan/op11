#include<iostream>
#include<fstream>
#include<string>                            //Ԥ����ָ��
#include<iomanip>
using namespace std;
#include<windows.h>
#include<stdlib.h>
#define maxnumber 2 //ջ�Ŀռ����ֵ
#define maxsize 2 //ͨ�������еĿռ����ֵ
#define Price 3//ͣ���۸�
void color(int a)//����������ɫ������������������������ɫ
	{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);//ͷ�ļ�Ҳ������ConsoleColor.h
	}
class sqstack //�����ĳ�λ�ඨ�壬ջ
{
public:
	int elem[maxnumber];
	int top;
	sqstack()
	{
		top=-1;
	}
	void push(int x)//��ջ
	{
		top++;
		elem[top]=x;
	}
	int pop()//��ջ
	{
		int x;
		x=elem[top];
		return x;
	}
	int gettop()//��ȡջ��Ԫ�أ�ֵ
	{
		return elem[top];
	}
	int regard()//�ж��Ƿ�ջ�������˷���ֵΪ0��δ������ֵΪ1
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
class sequeue  //�����Ⱥ�ͨ���࣬���У�����
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
	void enqueue(int e)//����
	{
		base[rear]=e;
		rear=(rear+1)%maxsize;
	}
	int dequeue(int *e)//����
	{
		*e=base[front];
		front=(front+1)%maxsize;
		return 1;
	}
	void print()//�������
	{
		for(int i=front;i<rear;i++)
			cout<<base[i];
	}
	int dependfull()//�ж϶����Ƿ����������˷���ֵΪ0��δ������ֵΪ1
	{
		if((rear+1)%maxsize==front)
			return 0;
		else
			return 1;
	
	}
	int dependnul()//�ж϶����Ƿ�Ϊ�գ����˷���ֵΪ0��δ������ֵΪ1
	{
		if(rear==front)
			return 0;
		else
			return 1;
	}


};
class carstop: public sequeue,public sqstack//ͣ����������,���ؼ̳���
{
public:
    int ac;
	int ad;
	int time[maxnumber];//ͣ��ʱ��
	int number[maxnumber];//��λ��
	int carnumber;//���ƺ�
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
		cout<<"��ã�����������,3�λ���"<<endl;
		cout<<setw(30)<<" ";
        cin>>secret;
		abc++;
		if(strcmp(secret,ab)==0)
		{
			cout<<setw(30)<<" ";
            color(14);
		    cout<<"��ӭ���٣����ǺϷ��û�"<<endl;
            cout<<setw(30)<<" ";
			system("pause");
			system("cls");
			present();
		}
		else
		{
	        cout<<setw(30)<<" ";
            color(16);
		    cout<<"�Բ����㻹���ǺϷ��û�"<<endl;
			if(abc<=2)
		        goin();
			else
			{
                cout<<setw(30)<<" ";
				cout<<"�Բ��𣬴�������";
				exit(1);
			}
		}
	}
	void present()
	{
		cout<<setw(30)<<" ";
        system("color 33");
		cout<<"ͣ��������ϵͳ"<<endl;
		cout<<setw(15)<<" ";
		cout<<"****************************************"<<endl;
        cout<<setw(15)<<" ";
		cout<<"****************************************"<<endl;
        cout<<setw(15)<<" ";
		cout<<"1��������������"<<setw(10)<<" "<<"2��������ѯ����"<<endl;
		cout<<setw(15)<<" ";
		cout<<"3��������������"<<setw(10)<<" "<<"4���˳�ϵͳ"<<endl;
        cout<<setw(15)<<" ";
		cout<<"5�������ϼ��˵�"<<endl;
        cout<<setw(15)<<" ";
		cout<<"****************************************"<<endl;
        cout<<setw(15)<<" ";
		cout<<"****************************************"<<endl;
        cout<<setw(30)<<" ";
		cout<<"������ѡ���"<<setw(3)<<" ";
		cin>>ac;
		switch(ac)
		{
            case 1: carinout();break;
            case 2: carsearch();break;
	        case 3: set();break;
		    case 4: leave();break;
		    case 5: retu();break;
		    default :cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");present();
		}
	}
    void set()
	{
        cout<<setw(15)<<" ";
		cout<<"1,�޸�ͣ���ռ��С"<<endl;
        cout<<setw(15)<<" ";
		cout<<"2,�޸�ͨ�����ͣ����"<<endl;
        cout<<setw(15)<<" ";
		cout<<"3,�鿴ͣ���ռ��С��ͨ�����ͣ������ͣ���۸�"<<endl;
        cout<<setw(15)<<" ";
		cout<<"4,�޸�ͣ���۸�"<<endl;
        cout<<setw(15)<<" ";
        cout<<"5�������ϼ��˵�"<<endl;
        cout<<setw(15)<<" ";
		cout<<"6,�˳�ϵͳ"<<endl;
        cout<<setw(30)<<" ";
	    cout<<"������ѡ���";
		cout<<setw(3)<<" ";
		cin>>ag;
		switch(ag)
		{
		    case 1 : 
            case 4 : 
			case 2 : cout<<setw(30)<<" ";cout<<"����ʱ��Ȩ�ޣ��뵽�����е�һ���޸�"<<endl;break;
			case 3 : watch();break;
		    case 5 : system("cls");present();break;
		    case 6 : leave();break;
			default : cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");set();
		}
         watchop();
	}
    void watch()
	{
		cout<<setw(15)<<" ";
		cout<<"�������ͣλ��"<<setw(3)<<" "<<maxnumber;
        cout<<setw(3)<<" ";
		cout<<"ͨ�����ͣ����"<<setw(3)<<" "<<maxsize-1;
        cout<<setw(3)<<" ";
		cout<<"ͣ���۸�"<<setw(3)<<" "<<Price<<endl;
        watchop();
	}
	void watchop()
	{
        cout<<setw(30)<<" ";
		cout<<"7�������ϼ��˵�"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,�˳�ϵͳ"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 7 : system("cls");set();break;
		    case 8 : leave();break;
			default : cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");carinop();
		}

	
	}

	void carsearch()
	{
        cout<<setw(15)<<" ";
		cout<<"1,ȫ����ʾ������ʾ���г����ͳ�λ��Ϣ"<<endl;
        cout<<setw(15)<<" ";
		cout<<"2,������Ϣ��ѯ�����ݳ��ƺŶ��������Ϣ��ѯ"<<endl;
        cout<<setw(15)<<" ";
		cout<<"3,��λ��Ϣ��ѯ�����ݳ�λ�Ŷ��������Ϣ��ѯ"<<endl;
        cout<<setw(15)<<" ";
		cout<<"4,�����Ϣ��ѯ�����ݳ��Ŷ��������Ϣ��ѯ"<<endl;
        cout<<setw(15)<<" ";
		cout<<"5�������ϼ��˵�"<<endl;
        cout<<setw(15)<<" ";
		cout<<"6,�˳�ϵͳ"<<endl;
        cout<<setw(30)<<" ";
	    cout<<"������ѡ���";
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
			default : cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");carsearch();
		}
	}
	void wait()
	{
        system("cls");
		cout<<setw(30)<<" "<<"��������Ҫ�ҵĳ��ĳ��ƺ�";
        cout<<setw(3)<<" ";
		cin>>aj;
		int jj=0;
        for(int j=0;j<maxsize;j++)
		{
			if(base[j]==aj)
			{
				jj++;
                cout<<setw(30)<<" "<<"�ҵ���"<<endl;
				cout<<setw(10)<<" "<<"ͨ���У����ƺ���"<<aj<<endl;
			}
		}
		if(jj==0)
			cout<<setw(30)<<" "<<"��Ǹ��ͨ����û��"<<endl;
       waitop();
	}
	void waitop()
	{
        cout<<setw(30)<<" ";
		cout<<"7�������ϼ��˵�"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,�˳�ϵͳ"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 7 : system("cls");carsearch();break;
		    case 8 : leave();break;
			default : cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");carinop();
		}

	}
	void onnumber()
	{
        system("cls");
		cout<<setw(30)<<" "<<"��������Ҫ�ҵĳ��ĳ�λ��";
        cout<<setw(3)<<" ";
		cin>>aj;
		int kk=0;
        for(int j=0;j<=top;j++)
		{
			if(number[j]==aj)
			{
				kk++;
				cout<<setw(30)<<" "<<"�ҵ���"<<endl;
				cout<<setw(25)<<" "<<"�ڳ�����,���ƺ���"<<elem[j]<<setw(3)<<" "<<"ʱ��"<<time[j];
				cout<<setw(3)<<" "<<"Ӧ�ɷ�"<<time[j]*Price<<endl;break;
			}
		}
		if(kk==0)
			cout<<setw(30)<<" "<<"��Ǹ��������û��"<<endl;
        onnumberop();
	}
	void onnumberop()
	{
        cout<<setw(30)<<" ";
		cout<<"7�������ϼ��˵�"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,�˳�ϵͳ"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 7 : system("cls");carsearch();break;
		    case 8 : leave();break;
			default : cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");carinop();
		}

	}
	void oncarnumber()
	{
        system("cls");
		cout<<setw(30)<<" "<<"��������Ҫ�ҵĳ��ĳ��ƺ�";
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
            cout<<setw(30)<<" "<<"�ҵ���"<<endl;
		    cout<<setw(25)<<" "<<"�ڳ�����,��λ����"<<number[jj];
            cout<<setw(3)<<" "<<"ʱ��"<<time[jj];
			cout<<setw(3)<<" "<<"Ӧ�ɷ�"<<time[jj]*Price<<endl;
		}
	    else
		{
            if(kj==0)
			{
                cout<<setw(30)<<" "<<"��Ǹ��������û��"<<endl;
			}
		for(int j=0;j<maxsize;j++)
		{
	        if(base[j]==aj)
			{
				gk++;
                cout<<setw(30)<<" "<<"�ҵ���"<<endl;
			    cout<<setw(10)<<" "<<"��ͨ���У����ƺ���"<<aj<<endl;break;
			}
		}
		if(gk==0)
		{
            cout<<setw(30)<<" "<<"��Ǹ��ͨ����Ҳû��"<<endl;
		}
		}
        oncarnumberop();

	}
	void oncarnumberop()
	{
        cout<<setw(30)<<" ";
		cout<<"7�������ϼ��˵�"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,�˳�ϵͳ"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 7 : system("cls");carsearch();break;
		    case 8 : leave();break;
			default : cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");carinop();
		}


	}
    void allpresent()
	{
		cout<<setw(30)<<" "<<"�����еĳ���Ϣ����"<<endl;
		for(int j=0;j<=top;j++)
		{
		    cout<<setw(25)<<" "<<"��λ��"<<number[j];
            cout<<setw(3)<<" "<<"ʱ��"<<time[j];
			cout<<setw(3)<<" "<<"����"<<time[j]*Price<<endl;
		}
        allpresentop();

	}
	void allpresentop()
	{
        cout<<setw(30)<<" ";
		cout<<"7�������ϼ��˵�"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,�˳�ϵͳ"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 7 : system("cls");carsearch();break;
		    case 8 : leave();break;
			default : cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");carinop();
		}

	}
    void carinout()
	{
        cout<<setw(30)<<" ";
	    cout<<"������������"<<endl;
		cout<<setw(15)<<" ";
		cout<<"1,�����������"<<setw(10)<<" "<<"2,������������"<<endl;
        cout<<setw(15)<<" ";
		cout<<"3,�����ϼ��˵�"<<endl;
        cout<<setw(30)<<" ";
		cout<<"������ѡ���"<<setw(3)<<" ";
		cin>>ad;
	    switch(ad)
		{
		    case 1: carin();break;
			case 2: carout();break;
			case 3:system("cls"); present();break;
			default : cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");present();
		}
		

	}
    void carout()
	{
        system("cls");
        cout<<setw(30)<<" ";
	    cout<<"������Ҫ��ȥ�ĳ��ƺ�,��λ��";
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
				cout<<"�ҵ���"<<endl;
                cout<<setw(30)<<" ";
				cout<<"���ƺ�Ϊ"<<setw(3)<<" "<<elem[j]<<endl;
				cout<<setw(30)<<" "<<"��λ��Ϊ"<<setw(3)<<" "<<number[j]<<endl;
				cout<<setw(30)<<" "<<"Ӧ�ɷ�"<<setw(3)<<" "<<time[j]*Price<<endl;
                for(j;j<top;j++)
		            time[j]=time[j+1];
				break;
			}
		}
        int t=0;
		if(k==0)
		{
	        cout<<setw(30)<<" ";
            cout<<"��Ǹ��������û���⳵"<<endl;
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
				cout<<"ͨ�������������ƺ�Ϊ"<<setw(3)<<" "<<base[front]<<endl;
                front=(front+1)%maxsize;
                cout<<setw(30)<<" ";
                cout<<"�ó���ͣ��ʱ��";
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
		cout<<"7�������ϼ��˵�"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,�˳�ϵͳ"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 7 : system("cls");carinout();break;
		    case 8 : leave();break;
			default : cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");carinop();
		}

	}
    void carin()
	{
		ae=regard();
		ad=dependfull();
		if(ae==0)
		{
			cout<<setw(25)<<" ";
			cout<<"�Բ���,��������,�뵽ͨ���Ⱥ�"<<endl;
			if(ad==0)
			{
                cout<<setw(25)<<" ";
			    cout<<"̫��Ǹ��,ͨ��Ҳ���ˣ���ӭ�´�����"<<endl;
			}
			else
			{
                cout<<setw(30)<<" ";
				cout<<"�������ͨ���ĳ��ƺ�";
                cout<<setw(3)<<" ";
				cin>>carnumber;
				enqueue(carnumber);
			}

		}
		else
		{
                cout<<setw(30)<<" ";
				cout<<"������������ƺ�";
                cout<<setw(3)<<" ";
				cin>>carnumber;
				cout<<setw(30)<<" ";
				cout<<"������ͣ��ʱ��";
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
		cout<<"7�������ϼ��˵�"<<endl;
        cout<<setw(30)<<" ";
		cout<<"8,�˳�ϵͳ"<<endl;
        cout<<setw(30)<<" ";
	    cin>>af;
		switch(af)
		{
		    case 7 : system("cls");carinout();break;
		    case 8 : leave();break;
			default : cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");carinop();
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