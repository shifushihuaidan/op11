#include<iostream>//����ļ�����Ԥ����ָ��������������ͷ�ļ�
#include<fstream>//�ļ�������ͷ�ļ�
#include<string> //�ַ���ͷ�ļ�                           
#include<iomanip>//setw()��ʽ���ƺ���ͷ�ļ�
#include <ctime>//ʱ����SYSTEMTIME�Լ�ʱ����ȡ����locate()ͷ�ļ�
using namespace std;//ʹ�����������ռ�
#include<windows.h>//system()ָ�color()����ͷ�ļ�
#include<stdlib.h>//system("color xy")ͷ�ļ���x��y ��ʮ����������x��ʾ������ɫ��y��ʾ������ɫ
#define maxnumber 2 //ջ�Ŀռ����ֵ���������ͣ�������궨��
#define maxsize 2 //ͨ�����ͣ���������еĿռ����ֵ���궨��
#define Price 3//ͣ���۸񣬺궨��
SYSTEMTIME sysTime[maxsize];//����һ��ʱ����SYSTEMTIME�������飬������ȫ�ֵ�
int opr(SYSTEMTIME x)//����һ��һ�㺯������ȡʱ��������ʱ�䣬��������
{
	return(x.wHour*3600+x.wMinute*60+x.wSecond);
}
void color(int a)//����������ɫ������������������������ɫ�����˾��
	{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);//ͷ�ļ�Ҳ������ConsoleColor.h
	}
class sqstack //�����ĳ�λ�ඨ�壬ջ��
{
public:
	int * elem;//��elemָ�룬�����鷽ʽ���ͣ�������ĳ��ƺ�
	int top;//ջ��ͷָ�룬���ͣ�ʼ��ָ��ջ��Ԫ��
	sqstack()//���캯������elem���ռ䣬�ռ��СΪmaxnumber���Լ���top����ֵ-1
	{
		top=-1;
        elem=new int [maxnumber];
	}
	void push(int x)//��ջ����
	{
		top++;
		elem[top]=x;
	}
	int pop()//��ջ����������ջ��Ԫ��
	{
		int x;
		x=elem[top];
		return x;
	}
	int gettop()//��ȡ��ǰջ��Ԫ�ص�ֵ
	{
		return elem[top];
	}
	int regard()//�ж��Ƿ�ջ�������˷���ֵΪ0��δ������ֵΪ1
	{
		if(top==maxnumber-1)
			return 0;
		else return 1;
	}
	void print()//������������������ǰջ��Ԫ�ص�ֵ
	{
		cout<<elem[top];
	}

};
class sequeue  //�����Ⱥ�ͨ���࣬ѭ�����У�
{
public:
	int *base;//������ָ�������鷽ʽ���ͨ���еĳ��ĳ��ƺ�
	int front;
	int rear;
	sequeue()//���캯��
	{
		base=new int [maxsize];
		front=rear=0;
	}
	void enqueue(int e)//���Ӻ���
	{
		base[rear]=e;
		rear=(rear+1)%maxsize;
	}
	int dequeue(int *e)//ɾ����Ԫ�أ���ɾ���ɹ�����1
	{
		*e=base[front];
		front=(front+1)%maxsize;
		return 1;
	}
	void print()//��������������������Ԫ��
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
class carstop: public sequeue,public sqstack//ͣ����������,���ؼ̳������Ϊsequeue��sqstack�����м̳з�ʽ
{
public:
    int ac;                      //�������±������ǿ���ѭ�����õ�
	int ad; 
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
    
	carstop()//���캯��������Щ����ѭ���õı�����ֵΪ0���������еĳ�λ��ֵ
	{
		abc=aj=ai=ag=af=ik=ac=ae=ad=0;
		for(int j=0;j<maxnumber;j++)
			number[j]=j+1;
	}
	void goin()//��¼���溯�������õ�¼���룬��������������Ļ���
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
	void present()//��������ʾ����������������ɫ����ָ�����switch��������ܼ������룬��������Ӧ����
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
    void set()//�������ý��溯��������switch��������ܼ�������ָ��Ӷ�������һ����
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
    void watch()//�鿴��ǰ���в������ݺ�����������watchop()���������ռ������룬��������һ����
	{
		cout<<setw(15)<<" ";
		cout<<"�������ͣλ��"<<setw(3)<<" "<<maxnumber;
        cout<<setw(3)<<" ";
		cout<<"ͨ�����ͣ����"<<setw(3)<<" "<<maxsize-1;
        cout<<setw(3)<<" ";
		cout<<"ͣ���۸�"<<setw(3)<<" "<<Price<<endl;
        watchop();
	}
	void watchop()//�������ռ��������������һ��Ӧ����
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

	void carsearch()//��ѯ��ʾ���溯������switch���ռ��������������Ӧ��һ����
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
	void wait()//����ͨ������ѯ��������ѯͨ�����Ƿ��иó�
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
				cout<<setw(25)<<" "<<"ͨ���У����ƺ���"<<aj<<endl;
			}
		}
		if(jj==0)
			cout<<setw(30)<<" "<<"��Ǹ��ͨ����û��"<<endl;
       waitop();
	}
	void waitop()//�������ռ��������������һ����
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
	void onnumber()//���ݳ�λ�ţ�����ѯ��Ӧ�����иó������ݣ����ƺţ���λ�ţ���ͣ��ʱ�䣬������Ӧ�еķ���
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
                SYSTEMTIME outtime;
				cout<<setw(30)<<" "<<"�ҵ���"<<endl;
                cout<<setw(25)<<" "<<"�ڳ�����,���ƺ���"<<elem[j]<<setw(3)<<" ";
                GetLocalTime(&outtime); 
                int cd=opr(outtime);
			    int ce=opr(sysTime[j]);
                cout<<setw(3)<<" "<<"��ͣ��"<<(cd-ce)<<"��";
			    cout<<setw(3)<<" "<<"����"<<(cd-ce)*Price<<endl;break;
			}
		}
		if(kk==0)
			cout<<setw(30)<<" "<<"��Ǹ��������û��"<<endl;
        onnumberop();
	}
	void onnumberop()//�������ռ��������������һ����
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
	void oncarnumber()//���ݳ��ƺţ������Ҹó������ڳ����в��ң�Ȼ������ͨ���в��ң����о������Ӧ��Ϣ
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
            SYSTEMTIME outtime;
            cout<<setw(30)<<" "<<"�ҵ���"<<endl;
		    cout<<setw(25)<<" "<<"�ڳ�����,��λ����"<<number[jj];
            GetLocalTime(&outtime); 
            int cd=opr(outtime);
			int ce=opr(sysTime[jj]);
            cout<<setw(3)<<" "<<"��ͣ��"<<(cd-ce)<<"��";
			cout<<setw(3)<<" "<<"����"<<(cd-ce)*Price<<endl;
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
			    cout<<setw(25)<<" "<<"��ͨ���У����ƺ���"<<aj<<endl;break;
			}
		}
		if(gk==0)
		{
            cout<<setw(30)<<" "<<"��Ǹ��ͨ����Ҳû��"<<endl;
		}
		}
        oncarnumberop();

	}
	void oncarnumberop()//�������ռ��������������һ����
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
    void allpresent()//ȫ����ʾ�����еĳ���������Ϣ����
	{
		int j=0;
		cout<<setw(30)<<" "<<"�����еĳ���Ϣ����"<<endl;
		for(;j<=top;j++)
		{
			cout<<setw(25)<<" "<<"���ƺ�"<<elem[j];
		    cout<<setw(3)<<" "<<"��λ��"<<number[j];
            SYSTEMTIME outtime;
            GetLocalTime(&outtime); 
            int cd=opr(outtime);
			int ce=opr(sysTime[j]);
            cout<<setw(3)<<" "<<"��ͣ��"<<(cd-ce)<<"��";
			cout<<setw(3)<<" "<<"����"<<(cd-ce)*Price<<endl;
		}
        cout<<setw(30)<<" "<<"ͨ���еĳ���Ϣ����"<<endl;;
        for(j=front;j<rear;j++)
			cout<<setw(25)<<" "<<"���ƺ�Ϊ"<<base[j]<<endl;
        allpresentop();

	}
	void allpresentop()//�������ռ��������������һ����
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
    void carinout()//�����������溯������switch�����ռ��������������Ӧ����
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
    void carout()//�����뿪����������������ó�����Ϣ�����ƺźͽ���ʱ�䣬��ǰ����ʱ�䣬ͣ��ʱ�䣬��Ӧ���ķ���
	{
        system("cls");
        cout<<setw(30)<<" ";
	    cout<<"������Ҫ��ȥ�ĳ��ƺ�,��λ��";
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
                SYSTEMTIME outtime;//����һ��ʱ�������outtime����¼��ǰʱ��
                GetLocalTime(&outtime); 
                cout<<setw(30)<<" ";
				int cd=opr(outtime);//����ת��ʱ��ֵ��������ʱ�仯Ϊ����
				int ce=opr(sysTime[j]);
				cout<<"�ҵ���"<<endl;
                cout<<setw(30)<<" ";
				cout<<"���ƺ�Ϊ"<<setw(3)<<" "<<elem[j]<<endl;
				cout<<setw(30)<<" "<<"��λ��Ϊ"<<setw(3)<<" "<<number[j]<<endl;
                cout<<setw(30)<<" ";
                cout<<"�ó�����ͣ����ʱ��Ϊ";	
				cout<<sysTime[j].wHour << "ʱ" <<sysTime[j].wMinute;
				cout<<"��" <<sysTime[j].wSecond <<"��"<<endl;
                cout<<setw(30)<<" ";
                cout<<"�ó��뿪ͣ����ʱ��Ϊ";	
				cout<<outtime.wHour << "ʱ" <<outtime.wMinute;
				cout<<"��" << outtime.wSecond <<"��"<<endl;
                cout<<setw(30)<<" ";
                cout<<"�ó���ͣ��"<<(cd-ce)<<"��"<<endl;
				cout<<setw(30)<<" "<<"Ӧ�ɷ�"<<setw(3)<<" "<<(cd-ce)*Price<<endl;
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
				    cout<<"ͨ�������������ƺ�Ϊ"<<setw(3)<<" "<<base[front]<<endl;
                    front=(front+1)%maxsize;                    
                    GetLocalTime(&sysTime[top]); 
                    cout<<setw(30)<<" ";
					cout<<"����ͣ����ʱ��Ϊ";	
					cout<<sysTime[top].wHour << "ʱ" <<sysTime[top].wMinute;
					cout<<"��" << sysTime[top].wSecond <<"��"<<endl;
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
	void caroutop()//�������ռ��������������һ����
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
    void carin()//�������뺯�������жϳ����Ƿ���������δ���ͽ��복���������˾Ͳ�ѯͨ���Ƿ���������δ���ͽ���ͨ��
	{                                       //��ͨ��Ҳ���˾ͻ�ӭ�´ι�����
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
                GetLocalTime(&sysTime[ik]); 
			    cout<<"����ͣ����ʱ��Ϊ";	
				cout<<sysTime[ik].wHour << "ʱ" <<sysTime[ik].wMinute;
				cout<<"��" << sysTime[ik].wSecond <<"��"<<endl;
				enqueue(carnumber);
			    push(carnumber);
                ik++;
		}
        carinop();
	}
	void carinop()//�������ռ��������������һ����
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
    void retu()//�������еķ����ϼ�����
	{
		goin();
	}
    void leave()//�����˳���ǰϵͳ���˳�����
	{
		exit(1);
	}

};
int main()//������
{
    carstop car;//����һ��carstop ����
    car.goin();//���õ�¼ϵͳ����
	return 0;
}
