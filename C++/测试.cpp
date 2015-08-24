#include<iostream>
using namespace std;
#include <ctime>
#include<windows.h>
int main ()
{
    SYSTEMTIME sysTime;
    ZeroMemory(&sysTime, sizeof(sysTime));
    GetLocalTime(&sysTime);
    cout << "现在时间为" << sysTime.wYear << "年" << sysTime.wMonth << "月" <<sysTime.wDay<<"日"<<endl;
    cout <<sysTime.wHour << "时" <<sysTime.wMinute << "分" << sysTime.wSecond <<"秒"<<endl;
	return 0;
}