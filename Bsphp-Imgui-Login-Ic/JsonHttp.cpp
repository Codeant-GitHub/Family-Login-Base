
#include "JsonHttp.hpp"
#include <fstream>
#include <tchar.h>
#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展
#pragma comment(lib, "Wininet.lib")
using namespace std;
  
CWininetHttp::CWininetHttp(void):m_hSession(NULL),m_hConnect(NULL),m_hRequest(NULL)
{
}
 
CWininetHttp::~CWininetHttp(void)
{
    Release();
}
 
//  通过HTTP请求：Get或Post方式获取JSON信息
const std::string CWininetHttp::RequestJsonInfo(const std::string& lpUrl,
                                                HttpRequest type/* = Hr_Get*/,
                                                std::string strHeader/*=""*/,
                                                std::string strPostData/*=""*/)
{
    std::string strRet = "";
    try
    {
        if ( lpUrl.empty())
        {
            throw Hir_ParamErr;
        }
        Release();
        m_hSession = InternetOpen(_T("Http-connect"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, NULL);    //局部
 
        if ( NULL == m_hSession )
        {
            throw Hir_InitErr;
        }
 
        INTERNET_PORT port    = INTERNET_DEFAULT_HTTP_PORT;
        std::string strHostName = "";
        std::string strPageName = "";
 
        ParseURLWeb(lpUrl, strHostName, strPageName, port);
        //printf("lpUrl:%s,\nstrHostName:%s,\nstrPageName:%s,\nport:%d\n",lpUrl.c_str(),strHostName.c_str(),strPageName.c_str(),(int)port);
 
        m_hConnect = InternetConnectA(m_hSession, strHostName.c_str(), port, NULL, NULL, INTERNET_SERVICE_HTTP, NULL, NULL);
 
        if ( NULL == m_hConnect )
        {
            throw Hir_ConnectErr;
        }
 
        std::string strRequestType;
        if ( Hr_Get == type )
        {
            strRequestType = "GET";
        }
        else
        {
            strRequestType = "POST";
        }
 
        m_hRequest = HttpOpenRequestA(m_hConnect,strRequestType.c_str(), strPageName.c_str(),"HTTP/1.1", NULL, NULL, INTERNET_FLAG_RELOAD, NULL);
        if ( NULL == m_hRequest )
        {
            throw Hir_InitErr;
        }
 
        DWORD dwHeaderSize = (strHeader.empty()) ? 0 : strlen(strHeader.c_str());
        BOOL bRet = FALSE;
        if ( Hr_Get == type )
        {
            bRet = HttpSendRequestA(m_hRequest,strHeader.c_str(),dwHeaderSize,NULL, 0);
        }
        else
        {
            DWORD dwSize = (strPostData.empty()) ? 0 : strlen(strPostData.c_str());
            bRet = HttpSendRequestA(m_hRequest,strHeader.c_str(),dwHeaderSize,(LPVOID)strPostData.c_str(), dwSize);
        }
        if ( !bRet )
        {
            throw Hir_SendErr;
        }
 
        char szBuffer[READ_BUFFER_SIZE + 1] = {0};
        DWORD dwReadSize = READ_BUFFER_SIZE;
        if ( !HttpQueryInfoA(m_hRequest, HTTP_QUERY_RAW_HEADERS, szBuffer, &dwReadSize, NULL) )
        {
            throw Hir_QueryErr;
        }
        if ( NULL != strstr(szBuffer, "404") )
        {
            throw Hir_404;
        }
 
        while( true )
        {
            bRet = InternetReadFile(m_hRequest, szBuffer, READ_BUFFER_SIZE, &dwReadSize);
            if ( !bRet || (0 == dwReadSize) )
            {
                break;
            }
            szBuffer[dwReadSize]='\0';
            strRet.append(szBuffer);
        }
    }
    catch(HttpInterfaceError error)
    {
        m_error = error;
    }
    return std::move(strRet);
}
 
// 解析URL地址
void CWininetHttp::ParseURLWeb( std::string strUrl, std::string& strHostName, std::string& strPageName, WORD& sPort)
{
    sPort = 80;
    string strTemp(strUrl);
    std::size_t nPos = strTemp.find("https://");
    if (nPos != std::string::npos)
    {
        strTemp = strTemp.substr(nPos + 8, strTemp.size() - nPos - 8);
    }
    nPos = strTemp.find('/');
    if ( nPos == std::string::npos )    //没有找到
    {
        strHostName = strTemp;
    }
    else
    {
        strHostName = strTemp.substr(0, nPos);
    }
    std::size_t nPos1 = strHostName.find(':');
    if ( nPos1 != std::string::npos )
    {
        std::string strPort = strTemp.substr(nPos1 + 1, strHostName.size() - nPos1 - 1);
        strHostName = strHostName.substr(0, nPos1);
        sPort = (WORD)atoi(strPort.c_str());
    }
    if ( nPos == std::string::npos )
    {
        return ;
    }
    strPageName = strTemp.substr(nPos, strTemp.size() - nPos);
}
// 关闭句柄
void CWininetHttp::Release()
{
    ReleaseHandle(m_hRequest); 
    ReleaseHandle(m_hConnect); 
    ReleaseHandle(m_hSession);
}
// 释放句柄
void CWininetHttp::ReleaseHandle( HINTERNET& hInternet )
{
    if (hInternet) 
    { 
        InternetCloseHandle(hInternet); 
        hInternet = NULL; 
    }
}
// UTF-8转为GBK2312 
char* CWininetHttp::UtfToGbk(const char* utf8)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
    wchar_t* wstr = new wchar_t[len+1];
    memset(wstr, 0, len+1);
    MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
    len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
    char* str = new char[len+1];
    memset(str, 0, len+1);
    WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
    if(wstr) delete[] wstr;
    return str;
}

//对网页进行转码
wchar_t* Convert(CString str, int targetCodePage)
{

    int iunicodeLen = MultiByteToWideChar(targetCodePage, 0, (LPCTSTR)str.GetBuffer(), -1, NULL, 0);
    wchar_t* pUnicode = NULL;
    pUnicode = new wchar_t[iunicodeLen + 1];
    memset(pUnicode, 0, (iunicodeLen + 1) * sizeof(wchar_t));
    MultiByteToWideChar(targetCodePage, 0, (LPCTSTR)str.GetBuffer(), -1, (LPWSTR)pUnicode, iunicodeLen);//映射一个字符串到一个款字节中
    return pUnicode;
}

/*获取网页的源码，参数1为网页链接，2为缓冲区指针*/
bool GetHtml(LPCTSTR szURL, CString& getbuf)
{
    HINTERNET	hInternet, hUrl;
    char		buffer[1124];
    WCHAR		wBuffer[1124];

    DWORD		dwBytesRead = 0;
    DWORD		dwBytesWritten = 0;
    BOOL		bIsFirstPacket = true;
    BOOL		bRet = true;
    int			nNowcopyDate = 0;

    hInternet = InternetOpen(_T("Mozilla/4.0 (compatible)"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, INTERNET_INVALID_PORT_NUMBER, 0);//初始化应用程序，使用WinNet
    if (hInternet == NULL)
        return FALSE;

    hUrl = InternetOpenUrl(hInternet, szURL, NULL, 0, INTERNET_FLAG_RELOAD, 0);//打开一个资源 ftp，gopher，http开头

    if (hUrl == NULL)
    {

        DWORD m = GetLastError();
        return FALSE;
    }

    do
    {
        memset(buffer, 0, sizeof(char) * 1124);
        InternetReadFile(hUrl, buffer, sizeof(char) * 1024, &dwBytesRead);
        bIsFirstPacket = false;
        nNowcopyDate = +dwBytesRead;
        wchar_t* punicode;
        punicode = Convert(buffer, CP_ACP);// 对源码进行转码   第二个参数为网页的编码格式


        //CString strTmp = CString(buffer);	

        //getbuf += _T("11=234");
        getbuf += punicode;
        delete punicode;
    } while (dwBytesRead > 0);

    InternetCloseHandle(hUrl);
    InternetCloseHandle(hInternet);
    return TRUE;


}