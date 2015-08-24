#ifndef SEQLIST_H
#define SEQLIST_H

#include <iostream>    //IO流
using namespace std;         //使用名称空间std 

template <class T>           //模板类
class SeqList   //用数组表示的顺序表，物理上顺序存储
{
private:
	 int MaxSize;                   //存储表的允许长度
     int length;                    //存储表的实际长度
     T *data;                        //存储数组的初地址
public:
/************************************************************/
     SeqList( )                     //构造函数
	 {
		 data=new T[100];    
		 MaxSize=100;  
		 length=0; 
	 }
     SeqList(int m)
	 {
		 if (m<=0) throw  "参数错误"; //失败？ 
			 data=new T[m];                      
		 MaxSize=m;    
		 length=0; 
	 }
/************************************************************/
     ~SeqList( )                  //析构函数
	 {
		 delete this->data;
		 this->data=NULL; 
	 }
	 /************************************************************/
     void PrintList( )                 //输出函数
	 {
		 for(int i=0;i<length;i++)   
		  cout<<data[i]<<"  ";
	 }
	 /************************************************************/
	 int Length( ) {return length;}      //获取顺序表长度
	 /************************************************************/
     T Get(int i)                        //获取第i个元素的值
	 {
		 if  (i<1||i>length) throw "位置参数错误"; 
		   return data[i-1]; 
	 }
	 /************************************************************/
     int Locate(T x )                    //查询x元素在表中的位置i         
	 {
		 for (int i=1;i<=length;i++)
		   if  (data[i-1]==x) return i; 
	     return 0; 
	 }
	 /************************************************************/
     void Insert(int i, T x)             //在第i个位置上插入一个元素x
	 {
		 if (length>=MaxSize) throw "上溢";
		 if (i<1||i>length+1) throw "位置错误"; 
		 for(int j=length;j>=i;j--) 
			 data[j]=data[j-1];
		 data[i-1]=x;
		 length++;
	 }
	 /************************************************************/
     T Delete(int i)                     //删除第i个元素
	 {
		 if (length==0) throw "下溢"; 
		 if (i<1||i>length) throw "位置错误";
		 T x=data[i-1];
		 for(int j=i;j<length;j++) 
			data[j-1]=data[j];
		 length--;
		 return x;
	 }
};
#endif
