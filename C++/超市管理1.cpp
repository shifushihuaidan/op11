#include<iostream>//Ԥ����ָ�����ͷ�ļ�
#include<string>//string��������Ͷ�����������
#include<fstream>//�ļ�������ͷ�ļ�
#include<iomanip>//setw()��ʽ���ƺ���ͷ�ļ�
#include <ctime>//ʱ����SYSTEMTIME�Լ�ʱ����ȡ����locate()ͷ�ļ�
using namespace std;//ʹ�����������ռ䣬�ڲ�ͬ��������������ظ�����
#include<windows.h>//system("cls")��syetem("pause")�����������ˣ�����Ҫ�������
#include<stdlib.h>//system("color xy")ͷ�ļ���x��y ��ʮ����������x��ʾ������ɫ��y��ʾ������ɫ
#define N 3//�궨�壬��Ʒ�������������
#define M 100//�궨�壬һ��M
void color(int a)//����������ɫ������������������������ɫ�����˾��
	{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);//ͷ�ļ�Ҳ������ConsoleColor.h
	}
int opr(SYSTEMTIME x)//����һ��һ�㺯������ȡʱ��������ʱ�䣬��������
{
	return(x.wHour*3600+x.wMinute*60+x.wSecond);
}
void f1()//һ�㺯��������
{
	system("color 0b");//����ϵͳ�������ı䱳����ɫ��������ɫ
    void f2(int);//f2����������
    cout<<setw(15)<<" ";//����setw()���������Ƹ�ʽ
    cout<<"****************************************"<<endl;//ԭ�����
    cout<<endl;
    cout<<setw(25)<<" ";
	cout<<"����ʳƷ����ϵͳ"<<endl;
    cout<<endl;
    cout<<setw(15)<<" ";
    cout<<"****************************************"<<endl;
    cout<<setw(27)<<" ";
    cout<<"1,�����Ʒ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"2,������Ʒ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"3,��ʾ��Ʒ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"4,�˳�ϵͳ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"���������ѡ��";
    cout<<setw(3)<<" ";
	int a;//����һ���ֲ�����
	cin>>a;//��������ֵ
	f2(a);//���ú���f2
}
class good//��Ʒ��
{
protected://��������������protected�����Ա����ࣨ�����ࣩ���ʣ�����粻�ܷ���
    string name[N];//����string��������������Ʒ������
	int num[N];//�������飬�����洢����
    SYSTEMTIME sysTime[N];//ʱ����������飬������Ÿ���Ʒ���볬��ʱ��
	int count;//��ǰ��Ʒ����������
public:
	virtual void addg()=0;//���麯�����壬�������ٶ��壬�ڴ˴�ֻ������
	virtual void saleg()=0;//����ϵͳ���һ����ν���麯�����������Щ�����׵�ַ
	virtual void showg()=0;//Ҳ������=0ǰ�����const
	good()//Ĭ�Ϲ��캯�����޲�����
	{
		count=0;//��ʼ��countΪ0
	}
};
class day:public good//�ճ���Ʒ�࣬����good�����࣬���м̳�
{
public:
	void addg();//�麯������
	void saleg();
	void showg();
	day():good()//�޲������캯������ʵҲ���Բ�Ҫ��
	{}
};
void day::addg()//�����ճ���Ʒ�����Ʒ�����ⶨ�壬ע�����ⶨ��Ҫ�ǵü�����������
{
    cout<<endl;
    cout<<setw(27)<<" ";
	cout<<"1�������"<<endl;
    Sleep(1000);//����sleep�����ó�����ͣ3�룬ע��κ���������λ�Ǻ���
    system("cls");//����������Ļ�ϵĶ���ȫ�����
	cout<<setw(27)<<" ";
	cout<<"������Ҫ��ӵ��ճ���Ʒ���������"<<endl;
	int a,i=0,j=0,ab;//���弸���ֲ�������ע�ⶨ��ֲ�������ó�ʼ���ˣ���Ȼ��ʱ����ֿռ�������
    cout<<setw(27)<<" ";
	cin>>a;//��������ֵ
    string aa[M];//�����ַ�������
    cout<<setw(27)<<" ";
    cout<<"����������ֺ�����"<<endl;;
	for(;i<a;i++)//forѭ����䣬������Ԫ�ؿ��Ƿ��Ѵ��ڸ���Ʒ��������ֻ�Ǽ���������������������
	{
        cout<<setw(27)<<" ";
        cout<<"�������"<<i+1<<"�����������"<<endl;
        cout<<setw(27)<<" ";
	    cin>>aa[i];
	    ab=-1;
	    for(j=0;j<count;j++)
		{
		    if(name[j]==aa[i])
			{
                cout<<setw(27)<<" ";
		        cout<<"�Ѿ����ڸ�����Ʒ"<<endl;
                cout<<setw(27)<<" ";
                cout<<"������볬��ʱ��Ϊ";	
		        cout<<sysTime[j].wHour << "ʱ" <<sysTime[j].wMinute;		        
		        cout<<"��"<<sysTime[j].wSecond <<"��"<<endl;
                cout<<setw(27)<<" ";
		        cout<<"��������Ҫ��Ӹ���"<<endl;
                cout<<setw(27)<<" ";
	            cin>>ab;
			    num[j]+=ab;
                GetLocalTime(&sysTime[j]);//��ȡ��ǰ����ʱ�䣬
			    break;
			}
		}
		if(count==N)//�ж��Ƿ�ﵽ������
		{
            cout<<setw(27)<<" ";
            cout<<"�Բ��������Ʒ������Ŀ�ѵ����ޣ������ټ������������"<<endl;
		    break;
		}
		if(ab==-1)//�������ڸ���Ʒ������������ҲҪ����
		{
			name[count]=aa[i];
            cout<<setw(27)<<" ";
            cout<<"��������Ӹ���"<<endl;
            cout<<setw(27)<<" ";
	        cin>>num[count];
            GetLocalTime(&sysTime[count]);
		    cout<<setw(27)<<" ";
			cout<<"���볬��ʱ��Ϊ";	
		    cout<<sysTime[count].wHour << "ʱ" <<sysTime[count].wMinute;
		    cout<<"��" << sysTime[count].wSecond <<"��"<<endl;
            count++;
		}
	}
    ofstream outfile("day.txt",ios::app);  //�ļ���������壬ios::app��˼�����ļ�ĩβ����������
    for(i=0;i<count;i++)
	{
        outfile<<name[i]<<" ";//һ��һ��д���ļ�
        outfile<<num[i]<<" ";
	}
    cout<<setw(27)<<" ";
	cout<<"1�����ɫ"<<endl;
    Sleep(1000);
    system("color 04");
    void turn2();//turn2��������
	turn2();//����turn2����
}
void day::saleg()//�����ճ�����Ʒ����Ʒ
{
    cout<<endl;
    cout<<setw(27)<<" ";
	cout<<"1�������"<<endl;
    Sleep(1000);
    system("cls");
	string aa;
    int j=0,k=0,ee=0;
    cout<<setw(27)<<" ";
	cout<<"��������Ҫ���۵���Ʒ������"<<endl;//����Ҫ���۵���Ʒ���ƣ�Ȼ��������ҿ����޴���Ʒ��
    cout<<setw(27)<<" ";                      //���У��������ǰ�������ж��Ƿ����������Ŀ��
	cin>>aa;                                  //�����㣬������û����ֱ���������Ʒ����
	for(;j<count;j++)
	{
		if(aa==name[j])
		{
            ee=1;
            cout<<setw(27)<<" ";
            cout<<"�и���Ʒ,������ƷĿǰ����"<<num[j]<<endl;
            cout<<setw(27)<<" ";
            cout<<"��������Ҫ���۵�����"<<endl;
            cout<<setw(27)<<" ";
			cin>>k;
			if(k<0||k>num[j])
			{
                cout<<setw(27)<<" ";
				cout<<"��Ǹ������û����ô�࣬����Ʒ����"<<num[j]<<endl;break;
			}
			else
			{
                cout<<setw(27)<<" ";
				cout<<"�����㹻,��͸���"<<endl;
				num[j]-=k;
                cout<<setw(27)<<" ";
				cout<<"������ƷĿǰ����"<<num[j]<<endl;
				if(num[j]==0)
				{
					count--;
				}
				break;
			}
		}
	}
	if(ee==0)
	{
        cout<<setw(27)<<" ";
        cout<<"��Ǹ��û�и���Ʒ"<<endl;
	}
    cout<<setw(27)<<" ";
	cout<<"1�����ɫ"<<endl;
    Sleep(1000);
    system("color 37");
    void turn3();//����turn3����
	turn3();//����turn3����
}
void day::showg()//����ճ�����Ʒ����Ʒ��Ϣ
{
    cout<<endl;
    cout<<setw(27)<<" ";
	cout<<"1�������"<<endl;
    Sleep(1000);//��Ļ��ͣ3��
    system("cls");//����
    cout<<setw(27)<<" ";
	cout<<"������Ʒ��Ϣ����"<<endl;
    cout<<setw(27)<<" ";
    cout<<"������ƷĿǰ��������Ϊ";
    cout<<setw(3)<<" ";
    cout<<count<<endl;
	for(int i=0;i<count;i++)//�����Ʒ�����Ϣ�����ƣ���Ŀ�����ʱ��
	{
        cout<<setw(27)<<" ";
		cout<<"����"<<name[i]<<' '<<"����"<<num[i]<<endl;
        cout<<setw(27)<<" ";
        cout<<"������볬��ʱ��Ϊ";	
	    cout<<sysTime[i].wHour << "ʱ" <<sysTime[i].wMinute;
	    cout<<"��" << sysTime[i].wSecond <<"��"<<endl;
	}
    cout<<setw(27)<<" ";
	cout<<"1�����ɫ"<<endl;
    Sleep(1000);
    system("color 28");
	void turn4();//turn4��������
	turn4();//����turn4����
}
class food:public good//ʳ������Ʒ�࣬good�������࣬���м̳�
{
	int time[N];//��������
public:
    void addg();//�麯������
	void saleg();
	void showg();
};
void food::addg()//����ʳ������Ʒ
{
	cout<<endl;
    cout<<setw(27)<<" ";
    cout<<"1�������"<<endl;
    Sleep(1000);
    system("cls");
	cout<<setw(27)<<" ";
    cout<<"������Ҫ��ӵ�ʳƷ����Ʒ���������"<<endl;
	    int a,i=0,j=0,ab;
        cout<<setw(27)<<" ";
	    cin>>a;
		string aa[M];
        cout<<setw(27)<<" ";
        cout<<"����������ֺ�����"<<endl;        //forѭ����䣬������Ԫ�ؿ��Ƿ��Ѵ��ڸ���Ʒ��������ֻ�Ǽ��������������������� 
	    for(;i<a;i++)
		{
            cout<<setw(27)<<" ";
            cout<<"�������"<<i+1<<"�����������"<<endl;
            cout<<setw(27)<<" ";
			cin>>aa[i];
			ab=-1;
			for(j=0;j<count;j++)
			{
				if(name[j]==aa[i])
                {
                    cout<<setw(27)<<" ";
					cout<<"�Ѿ����ڸ�����Ʒ"<<endl;
                    cout<<setw(27)<<" ";
                    cout<<"������볬��ʱ��Ϊ";	
				    cout<<sysTime[j].wHour << "ʱ" <<sysTime[j].wMinute;		        
		            cout<<"��"<<sysTime[j].wSecond <<"��"<<endl;      
                    cout<<setw(27)<<" ";
					cout<<"��������Ҫ��Ӹ���"<<endl;                  
                    cout<<setw(27)<<" ";
	                cin>>ab;
					num[j]+=ab;
                    GetLocalTime(&sysTime[j]); 
					break;
				}
			}
		    if(count==N)
			{
                cout<<setw(27)<<" ";
                cout<<"�Բ��������Ʒ������Ŀ�ѵ����ޣ������ټ������������"<<endl;
				break;
			}
			if(ab==-1)
			{
				name[count]=aa[i];
                cout<<setw(27)<<" ";
                cout<<"��������Ӹ���"<<endl;
                cout<<setw(27)<<" ";
	            cin>>num[count];
                GetLocalTime(&sysTime[count]);
				cout<<setw(27)<<" ";
			    cout<<"���볬��ʱ��Ϊ";	
				cout<<sysTime[count].wHour << "ʱ" <<sysTime[count].wMinute;
				cout<<"��" << sysTime[count].wSecond <<"��"<<endl;
                cout<<setw(27)<<" ";
                cout<<"�����뱣���ڣ������£�"<<endl;
                cout<<setw(27)<<" ";
				cin>>time[count];
                count++;
			}
		}
    ofstream outfile("food.txt",ios::app);   //�ļ���������壬ios::app��˼�����ļ�ĩβ����������
    for(i=0;i<count;i++)
	{
        outfile<<name[i]<<" ";//һ��һ��д���ļ�
        outfile<<num[i]<<" ";
	}
    cout<<setw(27)<<" ";
	cout<<"1�����ɫ"<<endl;
    Sleep(1000);
    system("color 14");
    void turn2();//����turn2����
	turn2();//����turn2����
}
void food::saleg()//����ʳ������Ʒ
{
    cout<<endl;
    cout<<setw(27)<<" ";
	cout<<"1�������"<<endl;
    Sleep(1000);
    system("cls");//����
	string aa;//����һ���ַ��������������ж��ǹ��Ѵ��ڸ���Ʒ
    int j=0,k=0,ee=0;
    cout<<setw(27)<<" ";
	cout<<"��������Ҫ���۵���Ʒ������"<<endl;
    cout<<setw(27)<<" ";
	cin>>aa;
	for(;j<count;j++)//����Ҫ���۵���Ʒ���ƣ�Ȼ��������ҿ����޴���Ʒ
	{
		if(aa==name[j])
		{
            ee=1;
            cout<<setw(27)<<" ";
            cout<<"�и���Ʒ,������ƷĿǰ����"<<num[j]<<endl;
            cout<<setw(27)<<" ";
            cout<<"��������Ҫ���۵�����"<<endl;
            cout<<setw(27)<<" ";
			cin>>k;
			if(k<0||k>num[j])//���У��������ǰ�������ж��Ƿ����������Ŀ
			{
                cout<<setw(27)<<" ";
				cout<<"��Ǹ������û����ô�࣬����Ʒ����"<<num[j]<<endl;break; //�����㣬������û����ֱ���������Ʒ����
			}
			else
			{
                cout<<setw(27)<<" ";
				cout<<"�����㹻,��͸���"<<endl;
				num[j]-=k;
                cout<<setw(27)<<" ";
				cout<<"������ƷĿǰ����"<<num[j]<<endl;
				if(num[j]==0)
				{
					count--;
				}
				break;
			}
		}
	}
	if(ee==0)
	{
        cout<<setw(27)<<" ";
        cout<<"��Ǹ��û�и���Ʒ"<<endl;
	}
    cout<<setw(27)<<" ";
	cout<<"1�����ɫ"<<endl;
    Sleep(1000);
    system("color 07");
    void turn3(); //����turn3����
	turn3();//���ú���turn3
}
void food::showg()//���ʳ������Ʒ����Ʒ��Ϣ
{
    cout<<endl;
    cout<<setw(27)<<" ";
	cout<<"1�������"<<endl;
    Sleep(1000);//������ͣ3��
    system("cls");//����
    cout<<setw(27)<<" ";
    cout<<"������Ʒ��Ϣ����"<<endl;
    cout<<setw(27)<<" ";
    cout<<"������ƷĿǰ��������Ϊ";
    cout<<setw(3)<<" ";
    cout<<count<<endl;
	for(int i=0;i<count;i++)//for���ѭ�������Ʒ�����Ϣ�������ʳ���࣬��Ȼ���к���Ҫ�ı�����
	{
        cout<<setw(27)<<" ";
		cout<<"����"<<name[i]<<' '<<"����"<<num[i]<<"������"<<time[i]<<endl;
        SYSTEMTIME outtime;
        GetLocalTime(&outtime);
        cout<<setw(27)<<" ";
		cout<<"��ǰʱ��Ϊ";
        cout<<outtime.wHour << "ʱ" <<outtime.wMinute;
        cout<<"��" << outtime.wSecond <<"��"<<endl;
        int cd=opr(outtime);
	    int ce=opr(sysTime[i]);
		int ae=cd-ce;
        cout<<setw(27)<<" ";
        cout<<"�Ѵ��"<<ae<<"��";
		if(ae<time[i]*120)
		{
            cout<<setw(3)<<" ";
			cout<<"���ڱ�������"<<endl;
		}
		else
		{
            cout<<setw(27)<<" ";
			cout<<"��Ǹ���ѹ��ڣ�����յ�"<<endl;
		}
	}
    cout<<setw(27)<<" ";
	cout<<"1�����ɫ"<<endl;
    Sleep(1000);
    system("color 31");
    void turn4();//����turn4����
	turn4();//���ú���turn4
}
class elec:public good//��������Ʒ��,good��������࣬���м̳�
{
	string color[N];//���������Ա
public:
    void addg();//�麯�����壬���ⶨ�壬ע����������
	void saleg();
	void showg();
};
void elec::addg()//���ӵ�������Ʒ
{
	cout<<endl;
    cout<<setw(27)<<" ";
    cout<<"1�������"<<endl;
    Sleep(1000);//��Ļ��ͣ3��
    system("cls");
	cout<<setw(27)<<" ";
    cout<<"������Ҫ��ӵĵ�������Ʒ���������"<<endl;
	    int a,i=0,j=0,ab;
        cout<<setw(27)<<" ";
	    cin>>a;
		string aa[M];
        cout<<setw(27)<<" ";
        cout<<"����������ֺ�����"<<endl;
	    for(;i<a;i++)                      //forѭ����䣬������Ԫ�ؿ��Ƿ��Ѵ��ڸ���Ʒ��������ֻ�Ǽ��������������������� 
		{
            cout<<setw(27)<<" ";
            cout<<"�������"<<i+1<<"�����������"<<endl;
            cout<<setw(27)<<" ";
			cin>>aa[i];
			ab=-1;
			for(j=0;j<count;j++)
			{
				if(name[j]==aa[i])
                {
                    cout<<setw(27)<<" ";
					cout<<"�Ѿ����ڸ�����Ʒ"<<endl;
                    cout<<setw(27)<<" ";
                    cout<<"������볬��ʱ��Ϊ";
				    cout<<sysTime[j].wHour << "ʱ" <<sysTime[j].wMinute;
				    cout<<"��" << sysTime[j].wSecond <<"��"<<endl;
                    cout<<setw(27)<<" ";
					cout<<"��������Ҫ��Ӹ���"<<endl;
                    cout<<setw(27)<<" ";
	                cin>>ab;
					num[j]+=ab;
                    GetLocalTime(&sysTime[j]); 
					break;
				}
			}
		    if(count==N)
			{
                cout<<setw(27)<<" ";
                cout<<"�Բ��������Ʒ������Ŀ�ѵ����ޣ������ټ������������"<<endl;
				break;
			}
			if(ab==-1)
			{
				name[count]=aa[i];
                cout<<setw(27)<<" ";
                cout<<"��������Ӹ���"<<endl;
                cout<<setw(27)<<" ";
	            cin>>num[count];
                GetLocalTime(&sysTime[count]);
				cout<<setw(27)<<" ";
			    cout<<"���볬��ʱ��Ϊ";	
				cout<<sysTime[count].wHour << "ʱ" <<sysTime[count].wMinute;
				cout<<"��" << sysTime[count].wSecond <<"��"<<endl;
                cout<<setw(27)<<" ";
                cout<<"�����������Ʒ����ɫ"<<endl;
                cout<<setw(27)<<" ";
				cin>>color[count];
                count++;
			}
		}
    ofstream outfile("elec.txt",ios::app); //�ļ���������壬ios::app��˼�����ļ�ĩβ���������� 
    for(i=0;i<count;i++)
	{
        outfile<<name[i]<<" ";//һ��һ��д���ļ�
        outfile<<num[i]<<" ";
	}
    cout<<setw(27)<<" ";
	cout<<"1�����ɫ"<<endl;
    Sleep(1000);
    system("color 23");
    void turn2();//����turn2����
	turn2();//���ú���turn2
}
void elec::saleg()//���۵�������Ʒ
{
    cout<<endl;
    cout<<setw(27)<<" ";
	cout<<"1�������"<<endl;
    Sleep(1000);
    system("cls");
	string aa;
    int j=0,k=0,ee=0;
    cout<<setw(27)<<" ";
	cout<<"��������Ҫ���۵���Ʒ������"<<endl;
    cout<<setw(27)<<" ";
	cin>>aa;                             //����Ҫ���۵���Ʒ���ƣ�Ȼ��������ҿ����޴���Ʒ   
	for(;j<count;j++)
	{
		if(aa==name[j])
		{
            ee=1;
            cout<<setw(27)<<" ";
            cout<<"�и���Ʒ,������ƷĿǰ����"<<num[j]<<endl;
            cout<<setw(27)<<" ";
            cout<<"��������Ҫ���۵�����"<<endl;//���У��������ǰ�������ж��Ƿ����������Ŀ
			cout<<setw(27)<<" ";
			cin>>k;
			if(k<0||k>num[j])
			{
                cout<<setw(27)<<" ";
				cout<<"��Ǹ������û����ô�࣬����Ʒ����"<<num[j]<<endl;break; //�����㣬������û����ֱ���������Ʒ����
			}
			else
			{
                cout<<setw(27)<<" ";
				cout<<"�����㹻,��͸���"<<endl;
				num[j]-=k;
                cout<<setw(27)<<" ";
				cout<<"������ƷĿǰ����"<<num[j]<<endl;
				if(num[j]==0)
				{
					count--;
				}
				break;
			}
		}
	}
	if(ee==0)
	{
        cout<<setw(27)<<" ";
        cout<<"��Ǹ��û�и���Ʒ"<<endl;
	}
    cout<<setw(27)<<" ";
	cout<<"1�����ɫ"<<endl;
    Sleep(1000);
    system("color 17");
    void turn3(); //����turn3����
	turn3();//���ú���turn3
}
void elec::showg()//�����������Ʒ����Ʒ��Ϣ
{
    cout<<endl;
    cout<<setw(27)<<" ";
    cout<<"1�������"<<endl;
    Sleep(1000);
    system("cls");
    cout<<setw(27)<<" ";
    cout<<"������Ʒ��Ϣ����"<<endl;
    cout<<setw(27)<<" ";
    cout<<"������ƷĿǰ��������Ϊ";
    cout<<setw(3)<<" ";
    cout<<count<<endl;
	for(int i=0;i<count;i++)//for���ѭ�������Ʒ�����Ϣ�����ƣ���Ŀ����ɫ
	{
        cout<<setw(27)<<" ";
		cout<<"����"<<name[i]<<' '<<"����"<<num[i]<<"��ɫ"<<color[i]<<endl;
        cout<<setw(27)<<" ";
        cout<<"������볬��ʱ��Ϊ";	
	    cout<<sysTime[i].wHour << "ʱ" <<sysTime[i].wMinute;
	    cout<<"��" << sysTime[i].wSecond <<"��"<<endl;
	}
    cout<<setw(27)<<" ";
	cout<<"1�����ɫ"<<endl;
    Sleep(1000);
    system("color 45");
    void turn4();//����turn4����
	turn4();//���ú���turn4
}
class sup//������
{
	day d;//���ݳ�Աday�����
	food f;//���ݳ�Աfood�����
	elec e;//���ݳ�Աelec�����
public:
	void add();//��Ա��������
    void f3(int);
	void sale();
	void f4(int);
	void show();
	void f5(int);
};
sup s1;
void sup::add()//�����Ʒ����
{
	cout<<endl;
	cout<<setw(27)<<" ";
    cout<<"1������ճ���Ʒ����Ʒ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"2�����ʳƷ��Ʒ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"3�������������Ʒ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"4�������ϼ��˵�"<<endl;
    cout<<setw(27)<<" ";
    cout<<"5���˳�ϵͳ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"���������ѡ��";
    cout<<setw(3)<<" ";
	int a;
	cin>>a;
	f3(a);
}
void sup::f3(int a)
{
    switch (a)//switch��������ռ��������ֵ��ѡ����������˵�
	{
	case 1:this->d.addg();break;
	case 2:this->f.addg();break;
	case 3:this->e.addg();break;
	case 4: f1();break;
	case 5: exit(1);break;
    default :cout<<setw(27)<<" ";cout<<"�Բ���û�����ѡ�����������"<<endl;system("cls");this->add();
	}	
}
void sup::sale()//������Ʒ����
{
	cout<<endl;
    cout<<setw(27)<<" ";
    cout<<"1�������ճ���Ʒ����Ʒ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"2������ʳƷ��Ʒ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"3��������������Ʒ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"4�������ϼ��˵�"<<endl;
    cout<<setw(27)<<" ";
    cout<<"5���˳�ϵͳ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"���������ѡ��"<<endl;
	int a;
    cout<<setw(27)<<" ";
	cin>>a;
	f4(a);
}
void sup::f4(int a)//sup���Ա�������ⶨ��
{
    switch (a)
	{
	case 1:this->d.saleg();break;
	case 2:this->f.saleg();break;
	case 3:this->e.saleg();break;
	case 4: f1();break;
	case 5: exit(1);break;
    default :cout<<setw(27)<<" ";cout<<"�Բ���û�����ѡ�����������"<<endl;system("cls");this->sale();
	}	
}
void sup::show()//��ʾ��Ʒ����
{
	cout<<endl;
    cout<<setw(27)<<" ";
    cout<<"1,��ʾ�ճ���Ʒ����Ʒ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"2,��ʾʳƷ��Ʒ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"3,��ʾ��������Ʒ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"4,�����ϼ��˵�"<<endl;
    cout<<setw(27)<<" ";
    cout<<"5,�˳�ϵͳ"<<endl;
    cout<<setw(27)<<" ";
    cout<<"���������ѡ��";
    cout<<setw(3)<<" ";
	int a;
	cin>>a;
	f5(a); 
}
void sup::f5(int a)//sup���Ա�������ⶨ��
{
    switch (a)
	{
	case 1:this->d.showg();break;
	case 2:this->f.showg();break;
	case 3:this->e.showg();break;
	case 4: f1();break;
	case 5: exit(1);break;
    default :cout<<setw(27)<<" ";cout<<"�Բ���û�����ѡ�����������"<<endl;system("cls");this->show();
	}	
}
void f2(int a)//һ�㺯������
{
	switch (a)
	{
	case 1: s1.add();break;
	case 2: s1.sale();break;
	case 3: s1.show();break;
	case 4: exit(1);break;
    default :cout<<setw(27)<<" ";cout<<"�Բ���û�����ѡ�����������"<<endl;system("cls");f1();
	}	
}
void turn2()//һ�㺯�����壬����s1.add����
{
	s1.add();
}
void turn3()//һ�㺯�����壬����s1.sale����
{
	s1.sale();
}
void turn4()//һ�㺯�����壬����s1.show����
{
	s1.show();
}
int abc=0;
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
		    cout<<"��ӭ���٣����ǺϷ��û�"<<endl;
            cout<<setw(30)<<" ";
			system("pause");
			system("cls");
			f1();
		}
		else
		{
	        cout<<setw(30)<<" ";
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
int main()
{
	goin();//���ú���goin
	return 0;//���ظ�������ģ����ǿ�����
}
