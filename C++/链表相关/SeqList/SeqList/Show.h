template <class T>           //ģ����
class SeqList   //�������ʾ��˳���������˳��洢
{
private:
	 int MaxSize;                   //�洢���������
     int length;                    //�洢���ʵ�ʳ���
     T *data;                        //�洢����ĳ���ַ
public:
	 SeqList( )                     //���캯��
     SeqList(int m);
	 
	 void PrintList( );                 //�������
	 int Length( );      //��ȡ˳�����
	 T Get(int i)                        //��ȡ��i��Ԫ�ص�ֵ
	 void Insert(int i, T x)             //�ڵ�i��λ���ϲ���һ��Ԫ��x
	 T Delete(int i)                     //ɾ����i��Ԫ��
}
	 