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
	void Push(const Type item); //Ԫ����ջ
	Type Pop();                 //Ԫ�س�ջ
	Type GetTop() const;        //��ȡջ��Ԫ��
    void Print();               //��ӡջԪ��
	void MakeEmpty()            //���ջ��Ԫ��
	{           
		m_ntop=-1;
	}
	bool IsEmpty() const       //�ж�ջ��
	{
		return m_ntop==-1;
	}
	bool IsFull() const       //�ж�ջ��
	{
		return m_ntop==m_nMaxSize-1;
	}
	



};

template<typename Type> 
void SeqStack<Type>::Push(const Type item)
{
	if(IsFull())
	{
		cout<<"ջ����!"<<endl;
		return;
	}
	m_pelements[++m_ntop]=item;
}

template<typename Type> 
Type SeqStack<Type>::Pop()
{
	if(IsEmpty()){
		cout<<"ջ�յ�!"<<endl;
		exit(1);
	}
	return m_pelements[m_ntop--];
}

template<typename Type> 
Type SeqStack<Type>::GetTop() const
{
	if(IsEmpty()){
		cout<<"ջ��û��Ԫ��!"<<endl;
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
