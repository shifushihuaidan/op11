#include<iostream>
using namespace std;
#include <ctime>
#include<windows.h>
int main ()
{
    SYSTEMTIME sysTime;
    ZeroMemory(&sysTime, sizeof(sysTime));
    GetLocalTime(&sysTime);
    cout << "����ʱ��Ϊ" << sysTime.wYear << "��" << sysTime.wMonth << "��" <<sysTime.wDay<<"��"<<endl;
    cout <<sysTime.wHour << "ʱ" <<sysTime.wMinute << "��" << sysTime.wSecond <<"��"<<endl;
	return 0;
}