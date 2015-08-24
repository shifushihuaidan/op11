#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
 void get_value()
 {cin>>num>>name>>sex;}
 void display()
 {
	 cout<<"number:"<<num<<endl;
     cout<<"name:"<<name<<endl;
     cout<<"sex:"<<sex<<endl;
 }
private:
	int number;
	string name;
	char sex;
};
 class Student1:public Student
 {
 public:
 void get_vaule_1()
 {
     get_value();
	 cin>>age>>addr;}
 void display_1()
 {
	 display();
     cout<<"age:"<<age<<endl;
     cout<<"adress:"<<addr<<endl;
 }
 private:
	 int age;
	 string addr;
 };
 int main()
 {
	 Student1 stud1;
	 cout<<"ÔÚÕâÀï"<<endl;
	 stud1.get_value_l();
	 stud1.display_1();
	 return 0;
 }