#include<iostream>

using namespace std;
template <class T>  //结点结构
struct Node
 {
	 T          data;
	 Node<T>  *next;     
 };
/******************************************************/
template <class T>
class LinkList
{
public: 
	Node <T>  *first;               //存储单链表的表头地址
public:	
	LinkList(){}
	LinkList(T a[ ], int n)        //构造函数    
	{
		Node<int> *s;
        int i;
        first=new Node<T>; //建立空单链表
        first->next=NULL;
        for(i=n-1;i>=0;i--)
        {
			s=new Node<T>;               //创建结点并赋值
			s->data=a[i];
            s->next=first->next;         //插入表头中
            first->next=s;               //调整首结点
        }

	}	
    ~LinkList( )                  //析构函数 
	{
		Node<int> *q;
		while (first)
		{   
			q=first;                     
			first=first->next;           
			delete q;                              
		}
	}
	void Insert(int i, T x)      //在指定的第i个位置插入一个节点x
	{
		Node<int> *p,*s;
        int j;
        p=first;
		j=1;
        while (p && j<i)
		{
			p=p->next;  
		    j++;
		}
        if   (!p)   throw "位置异常" ;   
        else
		{
			s=new Node<T>; 
			s->data=x;        //此时的p指向的是第i个位置，在他后面
            s->next=p->next;               //插入新结点
            p->next=s;
		}
	}
	T Delete(int i)              //删除第i个位置的节点
	{
		Node<int> *p,*q;
        int j,x;
        p=first;
		j=1;
        while (p && j<i)
		{
			p=p->next;  
			j++;
		}
        if   (!p||!p->next)   throw "位置异常" ;   
        else   
		{ 
			q=p->next; 
			x=q->data;
            p->next=q->next;
            delete q;
            return x;
		}
	}
	int Locate(T x )                    //查询x元素在表中的位置i         
	{
		Node<int>  *p;
		int i=1;
		p=first; 		
		while( p && p->data!=x)   
		{
			p=p->next;   i++;
		}
		if(p==NULL)  return 0;
		else  return i;
	}
	void PrintList()               //输出所有节点的值
	{ 
		Node<int> *p; 
        p=first;
		p=p->next;
        while (p)  
	    {
			cout<<p->data<<"\n";
	        p=p->next;
		}
	    cout<<endl;
	 }

};
