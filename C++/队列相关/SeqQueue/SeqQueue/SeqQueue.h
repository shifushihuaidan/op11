
template<typename Type> 
class SeqQueue
{
private:
	int m_nrear;            //队尾
	int m_nfront;           //队头
	int m_ncount;           //元素数量
	int m_nMaxSize;         //最大容量
	Type *m_pelements;      //队内的数组指针
public:
	SeqQueue(int sz):m_nrear(0),m_nfront(0),m_ncount(0),m_nMaxSize(sz)
	{
		m_pelements=new Type[sz];
		if(m_pelements==NULL)
		{
			cout<<"创建队列不成功!"<<endl;
			exit(1);
		}
	}
	~SeqQueue()
	{
		delete[] m_pelements;
	}
	void MakeEmpty();               //make the queue empty
	bool IsEmpty();
	bool IsFull();
	bool EnQueue(const Type item);   //入队 data
	Type DeQueue();                  //出队 data
	Type Get();                     //获取队头元素
	void Print();                   //print the queue
};

template<typename Type> 
void SeqQueue<Type>::MakeEmpty()
{
	this->m_ncount=0;
	this->m_nfront=0;
	this->m_nrear=0;
}

template<typename Type> 
bool SeqQueue<Type>::IsEmpty()
{
	return m_ncount==0;
}

template<typename Type> 
bool SeqQueue<Type>::IsFull()
{
	return m_ncount==m_nMaxSize;
}

template<typename Type> 
bool SeqQueue<Type>::EnQueue(const Type item)
{
	if(IsFull()){
		cout<<"The queue is full!"<<endl;
		return 0;
	}
	m_pelements[m_nrear]=item;
	m_nrear=(m_nrear+1)%m_nMaxSize;
	m_ncount++;
	return 1;
}

template<typename Type> 
Type SeqQueue<Type>::DeQueue()
{
	if(IsEmpty()){
		cout<<"队列中没有元素!"<<endl;
		exit(1);
	}
	Type temp=m_pelements[m_nfront];
	m_nfront=(m_nfront+1)%m_nMaxSize;
	m_ncount--;
	return temp;
}

template<typename Type> 
Type SeqQueue<Type>::Get()
{
	if(IsEmpty()){
		cout<<"队列中没有元素!"<<endl;
		exit(1);
	}
	return m_pelements[m_nfront];
}

template<typename Type> 
void SeqQueue<Type>::Print()
{
	cout<<"front";
	for(int i=0;i<m_ncount;i++){
		cout<<"--->"<<m_pelements[(m_nfront+i+m_nMaxSize)%m_nMaxSize];
	}
	cout<<"--->rear"<<endl<<endl<<endl;
}
