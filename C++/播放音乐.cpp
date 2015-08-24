#include<windows.h>
#include "mmsystem.h"//导入声音头文件
#pragma comment(lib,"winmm.lib")//导入声音头文件库
#include<iostream>
using namespace std;
int main()
{
    PlaySound(TEXT("mu.wav"),NULL,SND_FILENAME|SND_SYNC);
	return 0;
}