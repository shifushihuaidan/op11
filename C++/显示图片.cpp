#include<iostream.h>
#include<cstring.h>


ShowJpgGif(CDC* pDC,CString strPath, int x, int y)  
{  
      IStream *pStm;   
      CFileStatus fstatus;   
      CFile file;   
      LONG cb;   
      if (file.Open(strPath,CFile::modeRead)&&file.GetStatus(strPath,fstatus)&&((cb = fstatus.m_size) != -1))   
      {   
            HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);   
            LPVOID pvData = NULL;   
            if (hGlobal != NULL)   
            {   
                  pvData = GlobalLock(hGlobal);  
                  if (pvData != NULL)   
                  {   
                        file.Read(pvData, cb);   
                        GlobalUnlock(hGlobal);   
                        CreateStreamOnHGlobal(hGlobal, TRUE, &pStm);   
                  }  
            }  
      }  
      else  
            return false;  
      //��ʾJPEG��GIF��ʽ��ͼƬ��GIFֻ����ʾһ֡����������ʾ������  
      //Ҫ��ʾ����GIF��ʹ��ACTIVE��//����  
      IPicture *pPic;  
      //load image from file stream  
      if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)))  
      {  
            OLE_XSIZE_HIMETRIC hmWidth;   
            OLE_YSIZE_HIMETRIC hmHeight;   
            pPic->get_Width(&hmWidth);   
            pPic->get_Height(&hmHeight);   
            double fX,fY;   
            //get image height and width  
            fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth/((double)pDC->GetDeviceCaps(HORZSIZE)*100.0);   
            fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight/((double)pDC->GetDeviceCaps(VERTSIZE)*100.0);   
            //use render function display image  
            if(FAILED(pPic->Render(*pDC,x,y,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL)))   
            {  
                  pPic->Release();  
                  return false;  
            }  
            pPic->Release();  
      }   
      else   
            return false;   
      return true;  
}  
CDC* pDC = GetDlgItem(IDC_STC_DUMMY)->GetDC();  
ShowJpgGif(pDC,"aa.jpg",0,0);  
