#include "LinkList.h"
void f()
{
	int a[]={1,2,3,4,5,6,7,8,9};
	LinkList<int> La(a,9);
	LinkList<int> Lc;
	Lc.first=new Node<int>;
	Lc.first->next=NULL;

    Node<int> *p,*m;
	p=La.first;

	while(p&&p->next)
	{		
		if(p->next->data%2==1)//�����������ȴ�С��
		{
			m=p->next;
			p->next=p->next->next;	 //��La����ȥ���ڵ�p->next
			
			 //�����������Ľڵ����Lc��ͷ��
			m->next=Lc.first->next;   
            Lc.first->next=m;
		}
		else 
			p=p->next;		
	}
	cout<<"La���ڱ���ˣ�\n";
	La.PrintList();
	cout<<"Lc�������ǣ�\n";

	Lc.PrintList();
	getchar();


}
int main( )
{  
	f();
	/*try
	{
		int a[]={1,2,3,4,5,6};
	    LinkList<int> L(a,6);
	    L.PrintList();
		cout<<"********************************\n";
		L.Insert(7,788);
	    L.Insert(4,388);
		L.PrintList();
		cout<<"********************************\n";
	    int x=L.Delete(4);
		L.PrintList();
		cout<<"********************************\n"; 
		getchar();
    }
    catch(char *Error)
	{
		cout<<Error<<endl;
	}*/
	return 0;
}
