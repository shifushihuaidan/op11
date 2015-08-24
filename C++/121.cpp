#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

	//�궨��
#define MAX_NUM 20		//�����޶�ÿ������Ʒ�����ж�����
	//ȫ�ֱ���
int DailyGoods_i=0;		//������¼DailyGoods����Ʒ�������
int Food_i=0;			//������¼Food����Ʒ�������
int	Elect_i=0;			//������¼ElectricalAppliance����Ʒ�������
	//������
class Goods;
class DailyGoods;
class Food;
class ElectricalAppliance;

int num_judge(){				//�ж��Ƿ������������
	char *p=new char;
	int temp,i,flag=1;
	while(flag){
		i=0;cin>>p;
		int max=strlen(p);		//strlen�����ַ�������
		while(i<max){
			if(p[i]>='0'&&p[i]<='9') temp=1;
			else{
				temp=0;
				i=max;
			}i++;
		}
		if(temp==1&&max<=10) {return atoi(p);}	//atoiʵ��charת��Ϊint
		else if(temp==1&&max>10) cout<<"����̫������������"<<endl<<"�����������Ϊ��";
		else cout<<"��������ֲ��Ϸ�������������"<<endl<<"�����������Ϊ��" ;
	}
}  
int is_no(){					//�ж��Ƿ����
	int n;
	cout<<"�Ƿ����"<<endl;
	cout<<"1.�� 2.��"<<endl;
	cout<<"��ѡ��<1~2>:";
	n=num_judge();
	if(n==1) return 1;
	else if(n==2) return 0;
	else{
		cout<<"�����������Ĭ��Ϊ������"<<endl;
		return 0;
	}
}

//(1)��Ʒ��
class Goods {
public:
	Goods(){ };
	virtual void addGoods() = 0;	//������Ʒ
	virtual void saleGoods() = 0;	//������Ʒ
	virtual void showGoods() = 0;	//��ʾ��Ʒ��Ϣ
	virtual void add_am(int) = 0;	//������Ʒ����
	friend class SuperMarket;
protected:
	char name[MAX_NUM][20];
	int amount[MAX_NUM];
	int count[MAX_NUM];
};
//(2)����Ʒ��
class DailyGoods: public Goods {
public:
	DailyGoods():Goods(){};
	void addGoods();
	void saleGoods();
	void showGoods();
	void add_am(int);
	friend class SuperMarket;
};

void DailyGoods::addGoods(){
	int amoun,coun,flag=1;
	char na[20];
	while(flag){
		if(DailyGoods_i<MAX_NUM){
			cout<<"***********************************************"<<endl;
			cout<<"������Ʒ��Ϣ�����磺xiyifen 60 15"<<endl;
			cout<<"������Ʒ����"<<endl<<"����Ϊ��";
			cin>>na[20];
			cout<<"������Ʒ����"<<endl<<"����Ϊ��";
			amoun=num_judge();
			cout<<"������Ʒ����"<<endl<<"����Ϊ��";
			coun=num_judge();
			for(int i=0;i<DailyGoods_i;i++)
			if(strcmp(name[i],na)==0)
				cout<<"����Ʒ�Ѵ���"<<endl;
			else{
				strcpy(name[DailyGoods_i],na);
				amount[DailyGoods_i]=amoun;
				count[DailyGoods_i]=coun;
				i=DailyGoods_i;
				DailyGoods_i++;
			}
		}
		else cout<<"�ֿ����޷���Ÿ�����Ʒ"<<endl;
		flag=is_no();
	}	
}
void DailyGoods::saleGoods(){
	int co,temp=0;
	char na[20];
	cout<<"***********************************************"<<endl;
	cout<<"������Ҫ���۵���Ʒ��"<<endl;
	cin>>na;
	for(int i=0;i<DailyGoods_i;i++){
		if(strcmp(na,name[i])==0){
			cout<<"������Ҫ���۵�����Ϊ��";
			co=num_judge();
			temp=1;
			if(amount[i]>=co) amount[i]=amount[i]-co;
			else{
				cout<<"��Ʒ�������㣬һ�³�����"<<endl;
				amount[i]=0;
			}
		}
	}
	if(temp==0)
		cout<<endl<<"û�ҵ�������Ʒ"<<endl;
}
void DailyGoods::showGoods(){
	if(DailyGoods_i==0) cout<<endl<<"û���ճ�����Ʒ"<<endl;
	else{
	cout<<"***********************************************"<<endl;
	cout<<"�ճ�����Ʒ��Ϣ"<<endl;
	cout<<"����	����	����"<<endl;
	for(int i=0;i<DailyGoods_i;i++)
	cout<<name[i]<<"	"<<amount[i]<<"	"<<count[i]<<endl;
	}
}
void DailyGoods::add_am(int i){	
	int n;
	cout<<"***********************************************"<<endl;
	cout<<"Ҫ���ӵ���Ʒ������Ϊ��"<<endl;
	n=num_judge();
	amount[i]=amount[i]+n;
}
 
//(3)ʳƷ��
class Food: public Goods {
public:
	void addGoods();
	void saleGoods();
	void showGoods();
	void add_am(int);
	friend class SuperMarket;
private:
    char date[MAX_NUM][20];
};
void Food::addGoods(){
	int amoun,coun,flag=1;
	char na[20],dat[20];
	while(flag){
		if(Food_i<MAX_NUM){
			cout<<"***********************************************"<<endl;
			cout<<"������Ʒ��Ϣ�����磺xiaochi 60 15 2012.1.1"<<endl;
			cout<<"������Ʒ����"<<endl<<"����Ϊ��";
			cin>>na;
			cout<<"������Ʒ����"<<endl<<"����Ϊ��";
			amoun=num_judge();
			cout<<"������Ʒ����"<<endl<<"����Ϊ��";
			coun=num_judge();
			cout<<"������Ʒ��������"<<endl<<"��������Ϊ��";
			cin>>dat;
			for(int i=0;i<Food_i;i++)
				if(strcmp(name[i],na)==0)
					cout<<"����Ʒ�Ѵ���"<<endl;
			else{
				strcpy(name[Food_i],na);
				amount[Food_i]=amoun;
				count[Food_i]=coun;
				strcpy(date[Food_i],dat);
				i=Food_i;
				Food_i++;
			}
		}
		else cout<<"�ֿ����޷���Ÿ�����Ʒ"<<endl;
		flag=is_no();
	}
}
void Food::saleGoods(){
	int co,temp=0;
	char na[20];
	cout<<"***********************************************"<<endl;
	cout<<"������Ҫ���۵���Ʒ��"<<endl;
	cin>>na;
	for(int i=0;i<Food_i;i++){
		if(strcmp(na,name[i])==0)
			cout<<"������Ҫ���۵�����Ϊ��";
			co=num_judge();
			temp=1;
		if(amount[i]>=co) amount[i]=amount[i]-co;
		else{
			cout<<"��Ʒ�������㣬һ�³�����"<<endl;
			amount[i]=0;
		}

	}
	if(temp==0)
		cout<<endl<<"û�ҵ�������Ʒ"<<endl;
}
void Food::showGoods(){
	if(Food_i==0) cout<<endl<<"û��ʳƷ����Ʒ"<<endl;
	else{
	cout<<"***********************************************"<<endl;
	cout<<"ʳƷ����Ʒ��Ϣ"<<endl;
	cout<<"����	����	����	��������"<<endl;
	for(int i=0;i<Food_i;i++)
	cout<<name[i]<<"	"<<amount[i]<<"	"<<count[i]<<"	"<<date[i]<<endl;
	}
}
void Food::add_am(int i){	
	int n;
	cout<<"***********************************************"<<endl;
	cout<<"Ҫ���ӵ���Ʒ������Ϊ��"<<endl;
	n=num_judge();
	amount[i]=amount[i]+n;
}

//(4)�ҵ���
class ElectricalAppliance: public Goods {
public:
	void addGoods();
	void saleGoods();
	void showGoods();
	void add_am(int);
	friend class SuperMarket;
private:
	char color[MAX_NUM][20];
};
void ElectricalAppliance::addGoods(){
	int amoun,coun,flag=1;
	char na[20],col[20];
	while(flag){
		if(Elect_i<MAX_NUM){
			cout<<"***********************************************"<<endl;
			cout<<"������Ʒ��Ϣ�����磺dianshi 60 15 blue"<<endl;
			cout<<"������Ʒ����"<<endl<<"����Ϊ��";
			cin>>na;
			cout<<"������Ʒ����"<<endl<<"����Ϊ��";
			amoun=num_judge();
			cout<<"������Ʒ����"<<endl<<"����Ϊ��";
			coun=num_judge(); 
			cout<<"������Ʒ��ɫ"<<endl<<"��ɫΪ��";
			cin>>col;
			for(int i=0;i<Elect_i;i++)
			if(strcmp(name[i],na)==0)
				cout<<"����Ʒ�Ѵ���"<<endl;
			else{
				strcpy(name[Elect_i],na);
				amount[Elect_i]=amoun;
				count[Elect_i]=coun;
				strcpy(color[Elect_i],col);
				i=Elect_i;
				Elect_i++;
			}
		}
		else cout<<"�ֿ����޷���Ÿ�����Ʒ"<<endl;
		flag=is_no();
	}
}
void ElectricalAppliance::saleGoods(){
	int co,temp=0;
	char na[20];
	cout<<"***********************************************"<<endl;
	cout<<"������Ҫ���۵���Ʒ��"<<endl;
	cin>>na;
	for(int i=0;i<Elect_i;i++){
		if(strcmp(na,name[i])==0){
			cout<<"������Ҫ���۵�����Ϊ��";
			co=num_judge();
			temp=1;
			if(amount[i]>=co) amount[i]=amount[i]-co;
			else{
				cout<<"��Ʒ�������㣬һ�³�����"<<endl;
				amount[i]=0;
			}
		}

	}
	if(temp==0)
		cout<<endl<<"û�ҵ�������Ʒ"<<endl;
}
void ElectricalAppliance::showGoods(){
	if(Elect_i==0) cout<<endl<<"û�мҵ�����Ʒ"<<endl;
	else{
	cout<<"***********************************************"<<endl;
	cout<<"�ҵ�����Ʒ��Ϣ"<<endl;
	cout<<"����	����	����	��ɫ"<<endl;
	for(int i=0;i<Elect_i;i++)
	cout<<name[i]<<"	"<<amount[i]<<"	"<<count[i]<<"	"<<color[i]<<endl;
	}
}
void ElectricalAppliance::add_am(int i){	
	int n;
	cout<<"***********************************************"<<endl;
	cout<<"Ҫ���ӵ���Ʒ������Ϊ��"<<endl;
	n=num_judge();
	amount[i]=amount[i]+n;
}

//(5)������
class SuperMarket {
private:
	DailyGoods dgs;
	Food fd;
	ElectricalAppliance ea;
public:
	void add();		//������Ʒ
	void sale();	//������Ʒ
	void show();	//��ʾ������Ʒ��Ϣ
	void save();	//������Ʒ��Ϣ
	void read();	//��ȡ����
};
void SuperMarket::add(){
	int n,m;
	char na[20];
	Goods *goods[3];
	goods[0]=&fd; goods[1]=&dgs; goods[2]=&ea;
	cout<<"***********************************************"<<endl;
	cout<<"1.����ʳƷ 2.��������Ʒ"<<endl;
	cout<<"3.���Ӽҵ� 4.������Ʒ��"<<endl;
	cout<<"0.����"<<endl;
	cout<<"��ѡ��<0~4>:";
	n=num_judge();
	if(n==0) system("pause");
	else if(n==1||n==2||n==3){
		goods[n-1]->addGoods();
		this->add();
	}
	else if(n==4){
		cout<<"��Ҫ������Ʒ������Ʒ��Ϊ��"<<endl;
		cin>>na;
		for(int i=0;i<MAX_NUM;i++)
		for(int k=0;k<3;k++)
			if(strcmp(na,goods[k]->name[i])==0)	{
				goods[k]->add_am(i);
				m=1;
			}
		if(m!=1) cout<<"û�и�����Ʒ"<<endl;
	}
	else cout<<"����������󣬷�����һ��"<<endl;
}
void SuperMarket::sale(){
	int n;
	Goods *goods[3];
	goods[0]=&fd; goods[1]=&dgs; goods[2]=&ea;
	cout<<"***********************************************"<<endl;
	cout<<"1.����ʳƷ 2.��������Ʒ"<<endl;
	cout<<"3.���ۼҵ� 0.����"<<endl; 
	cout<<"��ѡ��<0~3>:";
	n=num_judge();
	if(n==0) system("pause");
	else if(n==1||n==2||n==3){
		goods[n-1]->saleGoods();
		this->sale();
	}
	else cout<<"����������󣬷�����һ��"<<endl;
}
void SuperMarket::show(){	
	int n;
	Goods *goods[3];
	goods[0]=&fd; goods[1]=&dgs; goods[2]=&ea;
	cout<<"***********************************************"<<endl;
	cout<<"1.��ʾʳƷ��Ϣ 2.��ʾ����Ʒ��Ϣ"<<endl;
	cout<<"3.��ʾ�ҵ���Ϣ 4.��ʾ������Ϣ"<<endl;
	cout<<"0.����"<<endl;
	cout<<"��ѡ��<0~4>:";
	n=num_judge();
	if(n==0) system("pause");
	else if(n==1||n==2||n==3){
		goods[n-1]->showGoods();
		this->show();
	}
	else if(n==4){
		goods[0]->showGoods();
		goods[1]->showGoods();
		goods[2]->showGoods();
		this->show();
	}
	else cout<<"����������󣬷�����һ��"<<endl;
}
void SuperMarket::save(){
	int i;
	Goods *goods[3];
	goods[0]=&fd; goods[1]=&dgs; goods[2]=&ea;
	ofstream outfile;
	outfile.open("������Ʒ��Ϣ.txt",ios::out);
	if(Food_i>0)
	outfile<<"Food:"<<endl;
	for(i=0;i<Food_i;i++)
		outfile<<goods[0]->name[i]<<"	"<<goods[0]->amount[i]<<"	"<<goods[0]->count[i]<<"	"<<fd.date[i]<<endl;
	if(DailyGoods_i>0)
	outfile<<"DailyGoods:"<<endl;
	for(i=0;i<DailyGoods_i;i++)
		outfile<<goods[1]->name[i]<<"	"<<goods[1]->amount[i]<<"	"<<goods[1]->count[i]<<endl;
	if(Elect_i>0)
	outfile<<"ElectricalAppliance:"<<endl;
	for(i=0;i<Elect_i;i++)
		outfile<<goods[2]->name[i]<<"	"<<goods[2]->amount[i]<<"	"<<goods[2]->count[i]<<"	"<<ea.color[i]<<endl;
	outfile.close();
	cout<<"��Ϣ����ɹ�"<<endl;
	system("pause");
}

void SuperMarket::read(){
	int temp,m,i;
	char Data[20],*p;
	FILE *q;
	q=fopen("������Ʒ��Ϣ.txt","r");
	while(!feof(q)){
		fscanf(q,"%s\n",&Data);	//����ȡ���ַ����浽Data
		if(strcmp(Data,"Food:")==0) {temp=1;i=0;}
		if(strcmp(Data,"DailyGoods:")==0) {temp=2;i=0;}
		if(strcmp(Data,"ElectricalAppliance:")==0) {temp=3;i=0;}

		if(temp==1){
			if(i%4==1)
				strcpy(fd.name[Food_i],Data);
			if(i%4==2){
				p=Data;
				fd.amount[Food_i]=atoi(p);
			}
			if(i%4==3){
				p=Data;
				fd.count[Food_i]=atoi(p);
			}
			if(i/4>0){
				strcpy(fd.date[Food_i],Data);
				Food_i++;
			}
			i++;
		}
		if(temp==2){
			if(i%3==1)
				strcpy(dgs.name[DailyGoods_i],Data);
			if(i%3==2){
				p=Data;
				dgs.amount[DailyGoods_i] =atoi(p);
			}
			if(i/3>0){
				p=Data;
				dgs.count[DailyGoods_i]=atoi(p); DailyGoods_i++;
			}
			i++;
		} 
		if(temp==3){
			if(i%4==1)
				strcpy(ea.name[Elect_i],Data);
			if(i%4==2){
				p=Data;
				ea.amount[Elect_i]=atoi(p);
			}
			if(i%4==3){
				p=Data;
				ea.count[Elect_i] =atoi(p);
			}
			if(i/4>0){
				p=Data;
				strcpy(ea.color[Elect_i],Data);
				Elect_i++;
			}
			i++;
		} 
	}
}

int main(){
	SuperMarket super;
	int n,flag=1;
	super.read();
	cout<<"��ȡ�������"<<endl;
	system("pause");
	while(flag){
		system("cls");
		cout<<endl;
		cout<<"		������Ʒ����ϵͳ"<<endl;
		cout<<"***********************************************"<<endl;
		cout<<"1.������Ʒ 3.��ʾ������Ʒ��Ϣ 0.�˳�"<<endl;
		cout<<"2.������Ʒ 4.����������Ʒ��Ϣ "<<endl;
		cout<<"��ѡ��<0~4>:";
		n=num_judge();
		switch(n){
		case 0:return 0;break;
		case 1:super.add();break;
		case 2:super.sale();break;
		case 3:super.show();break;
		case 4:super.save();break;
		default:cout<<"�����������"<<endl;break;
		}
	}
}