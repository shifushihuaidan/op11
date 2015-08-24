#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

	//宏定义
#define MAX_NUM 20		//用来限定每大类商品可以有多少种
	//全局变量
int DailyGoods_i=0;		//用来记录DailyGoods类商品种类个数
int Food_i=0;			//用来记录Food类商品种类个数
int	Elect_i=0;			//用来记录ElectricalAppliance类商品种类个数
	//声明类
class Goods;
class DailyGoods;
class Food;
class ElectricalAppliance;

int num_judge(){				//判定是否输入的是数字
	char *p=new char;
	int temp,i,flag=1;
	while(flag){
		i=0;cin>>p;
		int max=strlen(p);		//strlen计算字符串长度
		while(i<max){
			if(p[i]>='0'&&p[i]<='9') temp=1;
			else{
				temp=0;
				i=max;
			}i++;
		}
		if(temp==1&&max<=10) {return atoi(p);}	//atoi实现char转换为int
		else if(temp==1&&max>10) cout<<"数字太大，请重新输入"<<endl<<"重新输入的数为：";
		else cout<<"输入的数字不合法，请重新输入"<<endl<<"重新输入的数为：" ;
	}
}  
int is_no(){					//判定是否继续
	int n;
	cout<<"是否继续"<<endl;
	cout<<"1.是 2.否"<<endl;
	cout<<"请选择<1~2>:";
	n=num_judge();
	if(n==1) return 1;
	else if(n==2) return 0;
	else{
		cout<<"你的输入有误，默认为不继续"<<endl;
		return 0;
	}
}

//(1)商品类
class Goods {
public:
	Goods(){ };
	virtual void addGoods() = 0;	//增加商品
	virtual void saleGoods() = 0;	//出售商品
	virtual void showGoods() = 0;	//显示商品信息
	virtual void add_am(int) = 0;	//增加商品数量
	friend class SuperMarket;
protected:
	char name[MAX_NUM][20];
	int amount[MAX_NUM];
	int count[MAX_NUM];
};
//(2)日用品类
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
			cout<<"输入商品信息，形如：xiyifen 60 15"<<endl;
			cout<<"输入商品名字"<<endl<<"名字为：";
			cin>>na[20];
			cout<<"输入商品总数"<<endl<<"总数为：";
			amoun=num_judge();
			cout<<"输入商品单价"<<endl<<"单价为：";
			coun=num_judge();
			for(int i=0;i<DailyGoods_i;i++)
			if(strcmp(name[i],na)==0)
				cout<<"该商品已存在"<<endl;
			else{
				strcpy(name[DailyGoods_i],na);
				amount[DailyGoods_i]=amoun;
				count[DailyGoods_i]=coun;
				i=DailyGoods_i;
				DailyGoods_i++;
			}
		}
		else cout<<"仓库已无法存放该类商品"<<endl;
		flag=is_no();
	}	
}
void DailyGoods::saleGoods(){
	int co,temp=0;
	char na[20];
	cout<<"***********************************************"<<endl;
	cout<<"输入你要出售的商品名"<<endl;
	cin>>na;
	for(int i=0;i<DailyGoods_i;i++){
		if(strcmp(na,name[i])==0){
			cout<<"输入你要出售的数量为：";
			co=num_judge();
			temp=1;
			if(amount[i]>=co) amount[i]=amount[i]-co;
			else{
				cout<<"商品数量不足，一下出售完"<<endl;
				amount[i]=0;
			}
		}
	}
	if(temp==0)
		cout<<endl<<"没找到该类商品"<<endl;
}
void DailyGoods::showGoods(){
	if(DailyGoods_i==0) cout<<endl<<"没有日常类商品"<<endl;
	else{
	cout<<"***********************************************"<<endl;
	cout<<"日常类商品信息"<<endl;
	cout<<"名字	数量	单价"<<endl;
	for(int i=0;i<DailyGoods_i;i++)
	cout<<name[i]<<"	"<<amount[i]<<"	"<<count[i]<<endl;
	}
}
void DailyGoods::add_am(int i){	
	int n;
	cout<<"***********************************************"<<endl;
	cout<<"要增加的商品的数量为："<<endl;
	n=num_judge();
	amount[i]=amount[i]+n;
}
 
//(3)食品类
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
			cout<<"输入商品信息，形如：xiaochi 60 15 2012.1.1"<<endl;
			cout<<"输入商品名字"<<endl<<"名字为：";
			cin>>na;
			cout<<"输入商品总数"<<endl<<"总数为：";
			amoun=num_judge();
			cout<<"输入商品单价"<<endl<<"单价为：";
			coun=num_judge();
			cout<<"输入商品出厂日期"<<endl<<"出厂日期为：";
			cin>>dat;
			for(int i=0;i<Food_i;i++)
				if(strcmp(name[i],na)==0)
					cout<<"该商品已存在"<<endl;
			else{
				strcpy(name[Food_i],na);
				amount[Food_i]=amoun;
				count[Food_i]=coun;
				strcpy(date[Food_i],dat);
				i=Food_i;
				Food_i++;
			}
		}
		else cout<<"仓库已无法存放该类商品"<<endl;
		flag=is_no();
	}
}
void Food::saleGoods(){
	int co,temp=0;
	char na[20];
	cout<<"***********************************************"<<endl;
	cout<<"输入你要出售的商品名"<<endl;
	cin>>na;
	for(int i=0;i<Food_i;i++){
		if(strcmp(na,name[i])==0)
			cout<<"输入你要出售的数量为：";
			co=num_judge();
			temp=1;
		if(amount[i]>=co) amount[i]=amount[i]-co;
		else{
			cout<<"商品数量不足，一下出售完"<<endl;
			amount[i]=0;
		}

	}
	if(temp==0)
		cout<<endl<<"没找到该类商品"<<endl;
}
void Food::showGoods(){
	if(Food_i==0) cout<<endl<<"没有食品类商品"<<endl;
	else{
	cout<<"***********************************************"<<endl;
	cout<<"食品类商品信息"<<endl;
	cout<<"名字	数量	单价	出厂日期"<<endl;
	for(int i=0;i<Food_i;i++)
	cout<<name[i]<<"	"<<amount[i]<<"	"<<count[i]<<"	"<<date[i]<<endl;
	}
}
void Food::add_am(int i){	
	int n;
	cout<<"***********************************************"<<endl;
	cout<<"要增加的商品的数量为："<<endl;
	n=num_judge();
	amount[i]=amount[i]+n;
}

//(4)家电类
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
			cout<<"输入商品信息，形如：dianshi 60 15 blue"<<endl;
			cout<<"输入商品名字"<<endl<<"名字为：";
			cin>>na;
			cout<<"输入商品总数"<<endl<<"总数为：";
			amoun=num_judge();
			cout<<"输入商品单价"<<endl<<"单价为：";
			coun=num_judge(); 
			cout<<"输入商品颜色"<<endl<<"颜色为：";
			cin>>col;
			for(int i=0;i<Elect_i;i++)
			if(strcmp(name[i],na)==0)
				cout<<"该商品已存在"<<endl;
			else{
				strcpy(name[Elect_i],na);
				amount[Elect_i]=amoun;
				count[Elect_i]=coun;
				strcpy(color[Elect_i],col);
				i=Elect_i;
				Elect_i++;
			}
		}
		else cout<<"仓库已无法存放该类商品"<<endl;
		flag=is_no();
	}
}
void ElectricalAppliance::saleGoods(){
	int co,temp=0;
	char na[20];
	cout<<"***********************************************"<<endl;
	cout<<"输入你要出售的商品名"<<endl;
	cin>>na;
	for(int i=0;i<Elect_i;i++){
		if(strcmp(na,name[i])==0){
			cout<<"输入你要出售的数量为：";
			co=num_judge();
			temp=1;
			if(amount[i]>=co) amount[i]=amount[i]-co;
			else{
				cout<<"商品数量不足，一下出售完"<<endl;
				amount[i]=0;
			}
		}

	}
	if(temp==0)
		cout<<endl<<"没找到该类商品"<<endl;
}
void ElectricalAppliance::showGoods(){
	if(Elect_i==0) cout<<endl<<"没有家电类商品"<<endl;
	else{
	cout<<"***********************************************"<<endl;
	cout<<"家电类商品信息"<<endl;
	cout<<"名字	数量	单价	颜色"<<endl;
	for(int i=0;i<Elect_i;i++)
	cout<<name[i]<<"	"<<amount[i]<<"	"<<count[i]<<"	"<<color[i]<<endl;
	}
}
void ElectricalAppliance::add_am(int i){	
	int n;
	cout<<"***********************************************"<<endl;
	cout<<"要增加的商品的数量为："<<endl;
	n=num_judge();
	amount[i]=amount[i]+n;
}

//(5)超市类
class SuperMarket {
private:
	DailyGoods dgs;
	Food fd;
	ElectricalAppliance ea;
public:
	void add();		//增加商品
	void sale();	//卖出商品
	void show();	//显示所有商品信息
	void save();	//保存商品信息
	void read();	//读取数据
};
void SuperMarket::add(){
	int n,m;
	char na[20];
	Goods *goods[3];
	goods[0]=&fd; goods[1]=&dgs; goods[2]=&ea;
	cout<<"***********************************************"<<endl;
	cout<<"1.增加食品 2.增加日用品"<<endl;
	cout<<"3.增加家电 4.增加商品数"<<endl;
	cout<<"0.返回"<<endl;
	cout<<"请选择<0~4>:";
	n=num_judge();
	if(n==0) system("pause");
	else if(n==1||n==2||n==3){
		goods[n-1]->addGoods();
		this->add();
	}
	else if(n==4){
		cout<<"你要增加商品数的商品名为："<<endl;
		cin>>na;
		for(int i=0;i<MAX_NUM;i++)
		for(int k=0;k<3;k++)
			if(strcmp(na,goods[k]->name[i])==0)	{
				goods[k]->add_am(i);
				m=1;
			}
		if(m!=1) cout<<"没有该类商品"<<endl;
	}
	else cout<<"你的输入有误，返回上一层"<<endl;
}
void SuperMarket::sale(){
	int n;
	Goods *goods[3];
	goods[0]=&fd; goods[1]=&dgs; goods[2]=&ea;
	cout<<"***********************************************"<<endl;
	cout<<"1.出售食品 2.出售日用品"<<endl;
	cout<<"3.出售家电 0.返回"<<endl; 
	cout<<"请选择<0~3>:";
	n=num_judge();
	if(n==0) system("pause");
	else if(n==1||n==2||n==3){
		goods[n-1]->saleGoods();
		this->sale();
	}
	else cout<<"你的输入有误，返回上一层"<<endl;
}
void SuperMarket::show(){	
	int n;
	Goods *goods[3];
	goods[0]=&fd; goods[1]=&dgs; goods[2]=&ea;
	cout<<"***********************************************"<<endl;
	cout<<"1.显示食品信息 2.显示日用品信息"<<endl;
	cout<<"3.显示家电信息 4.显示所有信息"<<endl;
	cout<<"0.返回"<<endl;
	cout<<"请选择<0~4>:";
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
	else cout<<"你的输入有误，返回上一层"<<endl;
}
void SuperMarket::save(){
	int i;
	Goods *goods[3];
	goods[0]=&fd; goods[1]=&dgs; goods[2]=&ea;
	ofstream outfile;
	outfile.open("超市商品信息.txt",ios::out);
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
	cout<<"信息保存成功"<<endl;
	system("pause");
}

void SuperMarket::read(){
	int temp,m,i;
	char Data[20],*p;
	FILE *q;
	q=fopen("超市商品信息.txt","r");
	while(!feof(q)){
		fscanf(q,"%s\n",&Data);	//将读取的字符串存到Data
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
	cout<<"读取数据完成"<<endl;
	system("pause");
	while(flag){
		system("cls");
		cout<<endl;
		cout<<"		超市商品管理系统"<<endl;
		cout<<"***********************************************"<<endl;
		cout<<"1.增加商品 3.显示所有商品信息 0.退出"<<endl;
		cout<<"2.卖出商品 4.保存所有商品信息 "<<endl;
		cout<<"请选择<0~4>:";
		n=num_judge();
		switch(n){
		case 0:return 0;break;
		case 1:super.add();break;
		case 2:super.sale();break;
		case 3:super.show();break;
		case 4:super.save();break;
		default:cout<<"你的输入有误"<<endl;break;
		}
	}
}