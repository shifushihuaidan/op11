#ifndef SEQLIST_H
#define SEQLIST_H

#include <iostream>    //IO��
using namespace std;         //ʹ�����ƿռ�std 

template <class T>           //ģ����
class SeqList   //�������ʾ��˳���������˳��洢
{
private:
	 int MaxSize;                   //�洢���������
     int length;                    //�洢���ʵ�ʳ���
     T *data;                        //�洢����ĳ���ַ
public:
/************************************************************/
     SeqList( )                     //���캯��
	 {
		 data=new T[100];    
		 MaxSize=100;  
		 length=0; 
	 }
     SeqList(int m)
	 {
		 if (m<=0) throw  "��������"; //ʧ�ܣ� 
			 data=new T[m];                      
		 MaxSize=m;    
		 length=0; 
	 }
/************************************************************/
     ~SeqList( )                  //��������
	 {
		 delete this->data;
		 this->data=NULL; 
	 }
	 /************************************************************/
     void PrintList( )                 //�������
	 {
		 for(int i=0;i<length;i++)   
		  cout<<data[i]<<"  ";
	 }
	 /************************************************************/
	 int Length( ) {return length;}      //��ȡ˳�����
	 /************************************************************/
     T Get(int i)                        //��ȡ��i��Ԫ�ص�ֵ
	 {
		 if  (i<1||i>length) throw "λ�ò�������"; 
		   return data[i-1]; 
	 }
	 /************************************************************/
     int Locate(T x )                    //��ѯxԪ���ڱ��е�λ��i         
	 {
		 for (int i=1;i<=length;i++)
		   if  (data[i-1]==x) return i; 
	     return 0; 
	 }
	 /************************************************************/
     void Insert(int i, T x)             //�ڵ�i��λ���ϲ���һ��Ԫ��x
	 {
		 if (length>=MaxSize) throw "����";
		 if (i<1||i>length+1) throw "λ�ô���"; 
		 for(int j=length;j>=i;j--) 
			 data[j]=data[j-1];
		 data[i-1]=x;
		 length++;
	 }
	 /************************************************************/
     T Delete(int i)                     //ɾ����i��Ԫ��
	 {
		 if (length==0) throw "����"; 
		 if (i<1||i>length) throw "λ�ô���";
		 T x=data[i-1];
		 for(int j=i;j<length;j++) 
			data[j-1]=data[j];
		 length--;
		 return x;
	 }
};
#endif
