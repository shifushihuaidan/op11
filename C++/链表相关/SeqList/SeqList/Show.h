template <class T>           //模板类
class SeqList   //用数组表示的顺序表，物理上顺序存储
{
private:
	 int MaxSize;                   //存储表的允许长度
     int length;                    //存储表的实际长度
     T *data;                        //存储数组的初地址
public:
	 SeqList( )                     //构造函数
     SeqList(int m);
	 
	 void PrintList( );                 //输出函数
	 int Length( );      //获取顺序表长度
	 T Get(int i)                        //获取第i个元素的值
	 void Insert(int i, T x)             //在第i个位置上插入一个元素x
	 T Delete(int i)                     //删除第i个元素
}
	 