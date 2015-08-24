#include<iostream>
using namespace std;


template<typename Type> 
class SeqStack
{
private:
	int m_ntop;
	Type *m_pelements;
	int m_nMaxSize;
public:
	SeqStack(int size):m_ntop(-1),m_nMaxSize(size)
	{
		m_pelements=new Type[size];
		if(m_pelements==NULL){
			cout<<"Application Error!"<<endl;
			exit(1);
		}
	}
	~SeqStack(){
		delete[] m_pelements;
	}

public:
	void Push(const Type item); //元素入栈
	Type Pop();                 //元素出栈
	Type GetTop() const;        //获取栈顶元素
    void Print();               //打印栈元素
	void MakeEmpty()            //清空栈内元素
	{           
		m_ntop=-1;
	}
	bool IsEmpty() const       //判断栈空
	{
		return m_ntop==-1;
	}
	bool IsFull() const       //判断栈满
	{
		return m_ntop==m_nMaxSize-1;
	}
	



};

template<typename Type> 
void SeqStack<Type>::Push(const Type item)
{
	if(IsFull())
	{
		cout<<"栈满了!"<<endl;
		return;
	}
	m_pelements[++m_ntop]=item;
}

template<typename Type> 
Type SeqStack<Type>::Pop()
{
	if(IsEmpty()){
		cout<<"栈空的!"<<endl;
		exit(1);
	}
	return m_pelements[m_ntop--];
}

template<typename Type> 
Type SeqStack<Type>::GetTop() const
{
	if(IsEmpty()){
		cout<<"栈内没有元素!"<<endl;
		exit(1);
	}
	return m_pelements[m_ntop];
}

template<typename Type> 
void SeqStack<Type>::Print()
{
	cout<<"top";
	for(int i=m_ntop-1;i>=0;i--){
		cout<<"--->"<<m_pelements[i];
	}
	cout<<"--->bottom\n"<<endl;
}
