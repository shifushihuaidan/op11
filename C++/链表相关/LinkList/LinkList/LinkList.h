#include<iostream>

using namespace std;
template <class T>  //���ṹ
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
	Node <T>  *first;               //�洢������ı�ͷ��ַ
public:	
	LinkList(){}
	LinkList(T a[ ], int n)        //���캯��    
	{
		Node<int> *s;
        int i;
        first=new Node<T>; //�����յ�����
        first->next=NULL;
        for(i=n-1;i>=0;i--)
        {
			s=new Node<T>;               //������㲢��ֵ
			s->data=a[i];
            s->next=first->next;         //�����ͷ��
            first->next=s;               //�����׽��
        }

	}	
    ~LinkList( )                  //�������� 
	{
		Node<int> *q;
		while (first)
		{   
			q=first;                     
			first=first->next;           
			delete q;                              
		}
	}
	void Insert(int i, T x)      //��ָ���ĵ�i��λ�ò���һ���ڵ�x
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
        if   (!p)   throw "λ���쳣" ;   
        else
		{
			s=new Node<T>; 
			s->data=x;        //��ʱ��pָ����ǵ�i��λ�ã���������
            s->next=p->next;               //�����½��
            p->next=s;
		}
	}
	T Delete(int i)              //ɾ����i��λ�õĽڵ�
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
        if   (!p||!p->next)   throw "λ���쳣" ;   
        else   
		{ 
			q=p->next; 
			x=q->data;
            p->next=q->next;
            delete q;
            return x;
		}
	}
	int Locate(T x )                    //��ѯxԪ���ڱ��е�λ��i         
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
	void PrintList()               //������нڵ��ֵ
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
