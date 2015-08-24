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
		if(p->next->data%2==1)//这是条件“比大小”
		{
			m=p->next;
			p->next=p->next->next;	 //从La当中去掉节点p->next
			
			 //将符合条件的节点插入Lc表头中
			m->next=Lc.first->next;   
            Lc.first->next=m;
		}
		else 
			p=p->next;		
	}
	cout<<"La现在变成了：\n";
	La.PrintList();
	cout<<"Lc的内容是：\n";

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
