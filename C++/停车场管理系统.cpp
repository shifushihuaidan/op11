#include<iostream>
#include<fstream>
#include<string>                            //Ԥ����ָ��
#include<iomanip>
using namespace std;
#include<windows.h>
#define maxnumber 50 //ջ�Ŀռ����ֵ
#define maxsize 10 //ͨ�������еĿռ����ֵ
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
	void pop()//��ջ
	{
		int x;
		x=elem[top];
		//return x;
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
		cout<<"��ã�����������"<<endl;
		cout<<setw(30)<<" ";
        cin>>secret;
		if(strcmp(secret,ab)==0)
		{
			cout<<setw(30)<<" ";
            color(14);
		    cout<<"��ӭ���٣����ǺϷ��û�"<<endl;
			system("cls");
			present();
		}
		else
		{
	        cout<<setw(30)<<" ";
            color(16);
		    cout<<"�Բ����㻹���ǺϷ��û�"<<endl;
		    goin();
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
            /*case 2: carsearch();break;
	        case 3: set();break;*/
		    case 4: leave();break;
		    case 5: retu();break;
		    default :cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");present();
		}
	}
	void carsearch()
	{
        cout<<setw(15)<<" ";
		cout<<"1,ȫ����ʾ������ʾ���г����ͳ�λ��Ϣ";
        cout<<setw(10)<<" ";
		cout<<"2,������Ϣ��ѯ�����ݳ��ƺŶ��������Ϣ��ѯ"<<endl;
        cout<<setw(15)<<" ";
		cout<<"3,��λ��Ϣ��ѯ�����ݳ�λ�Ŷ��������Ϣ��ѯ";
        cout<<setw(10)<<" ";
		cout<<"4,�����Ϣ��ѯ�����ݳ�λ�Ŷ��������Ϣ��ѯ"<<endl;
        cout<<setw(15)<<" ";
		cout<<"5�������ϼ��˵�"<<endl;
        cout<<setw(10)<<" ";
		cout<<"6,�˳�ϵͳ"<<endl;
        cout<<setw(30)<<" ";
	    cout<<"������ѡ���"<<endl;
		cout<<setw(3)<<" ";
		cin>>ag;
		switch(ag)
		{
		    case 1 : 
		    case 5 : system("cls");cout<<setw(15)<<" ";
		
		    case 1 : 
		    case 5 : system("cls");goin();break;
		    case 6 : leave();break;
			default : cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");carinop();
		};break;
		    case 6 : leave();break;
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
	    cout<<"������Ҫ��ȥ�ĳ��ƺ�";
		cout<<setw(3)<<" ";
		cin>>ah;
		int k=0;
		for(int j=0;j<=top;j++)
		{
			if(elem[j]==ah||number[j]==ah)
			{
				k++;
                cout<<setw(30)<<" ";
				cout<<"�ҵ���"<<endl;
                cout<<setw(30)<<" ";
				cout<<"���ƺ�Ϊ"<<setw(3)<<" "<<elem[j]<<endl;
				cout<<setw(30)<<" "<<"��λ��Ϊ"<<setw(3)<<" "<<number[j]<<endl;
				cout<<setw(30)<<" "<<"Ӧ�ɷ�"<<setw(3)<<" "<<time[j]*Price<<endl;break;

			}
		}
		if(k==0)
		{
	        cout<<setw(30)<<" ";
            cout<<"��Ǹ��û���⳵"<<endl;
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
		cout<<"1�������ϼ��˵�"<<endl;
        cout<<setw(30)<<" ";
		cout<<"2,�˳�ϵͳ"<<endl;
        cout<<setw(30)<<" ";
	    cin>>ai;
		switch(ai)
		{
		    case 1 : system("cls");carinout();break;
		    case 2 : leave();break;
			default : cout<<setw(15)<<" "<<"�Բ���û�����ѡ��"<<endl;system("pause");system("cls");carinop();
		}

	}
    void carin()
	{
		ae=regard();
		ad=dependfull();
		if(ae==0)
		{
			cout<<setw(15)<<" ";
			cout<<"�Բ���,��������,�뵽ͨ���Ⱥ�"<<endl;
			if(ad==0)
			{
                cout<<setw(15)<<" ";
			    cout<<"̫��Ǹ��,ͨ��Ҳ���ˣ���ӭ�´�����"<<endl;
			}
			else
			{
				system("cls");
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
				number[i]++;
				cout<<setw(30)<<" ";
				cout<<"������ͣ��ʱ��";
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
		cout<<"1�������ϼ��˵�"<<endl;
        cout<<setw(30)<<" ";
		cout<<"2,�˳�ϵͳ"<<endl;
        cout<<setw(30)<<" ";
	    cin>>af;
		switch(af)
		{
		    case 1 : system("cls");carinout();break;
		    case 2 : leave();break;
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