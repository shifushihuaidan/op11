#include<windows.h>
#include "mmsystem.h"//��������ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��������ͷ�ļ���
#include<iostream>
using namespace std;
int main()
{
    PlaySound(TEXT("mu.wav"),NULL,SND_FILENAME|SND_SYNC);
	return 0;
}