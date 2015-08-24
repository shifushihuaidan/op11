#include <windows.h>
#include <stdio.h>

void main()
{
 HWND hConsoleWindow;
 HBITMAP hBitmap;
 HDC hMemoryDC;
    BITMAP bmp; 
 hConsoleWindow=GetForegroundWindow();
 hBitmap=(HBITMAP)LoadImage(GetModuleHandle(NULL),"my.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
 hMemoryDC=CreateCompatibleDC(GetDC(hConsoleWindow));
 SelectObject(hMemoryDC,hBitmap);
    GetObject(hBitmap,sizeof(BITMAP),&bmp);
 BitBlt(GetDC(hConsoleWindow),0,0,bmp.bmWidth,bmp.bmHeight,hMemoryDC,0,0,SRCCOPY);
 DeleteObject(hBitmap);
    DeleteDC(hMemoryDC);
 ReleaseDC(hConsoleWindow,GetDC(hConsoleWindow));
    system("pause>null");
}