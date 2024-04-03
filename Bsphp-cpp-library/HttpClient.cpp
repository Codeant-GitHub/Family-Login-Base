#pragma once
#include "auth.hpp"
#include <time.h> 
#include <stdlib.h>

#define  BUFFER_SIZE       1024

#define  NORMAL_CONNECT             INTERNET_FLAG_KEEP_CONNECTION
#define  SECURE_CONNECT                NORMAL_CONNECT | INTERNET_FLAG_SECURE
#define  NORMAL_REQUEST             INTERNET_FLAG_RELOAD | INTERNET_FLAG_DONT_CACHE 
#define  SECURE_REQUEST             NORMAL_REQUEST | INTERNET_FLAG_SECURE | INTERNET_FLAG_IGNORE_CERT_CN_INVALID

CHttpClient::CHttpClient(LPCTSTR strAgent)
{
    m_pSession = new CInternetSession(strAgent);
    m_pConnection = NULL;
    m_pFile = NULL;
}


CHttpClient::~CHttpClient(void)
{
    Clear();
    if (NULL != m_pSession)
    {
        m_pSession->Close();
        delete m_pSession;
        m_pSession = NULL;
    }
}

void CHttpClient::Clear()
{
    if (NULL != m_pFile)
    {
        m_pFile->Close();
        delete m_pFile;
        m_pFile = NULL;
    }

    if (NULL != m_pConnection)
    {
        m_pConnection->Close();
        delete m_pConnection;
        m_pConnection = NULL;
    }
}

int CHttpClient::ExecuteRequest(LPCTSTR strMethod, LPCTSTR strUrl, LPCTSTR strPostData, string& strResponse)
{
    CString strServer;
    CString strObject;
    DWORD dwServiceType;
    INTERNET_PORT nPort;
    strResponse = "";

    AfxParseURL(strUrl, dwServiceType, strServer, strObject, nPort);

    if (AFX_INET_SERVICE_HTTP != dwServiceType && AFX_INET_SERVICE_HTTPS != dwServiceType)
    {
        return FAILURE;
    }

    try
    {
        m_pConnection = m_pSession->GetHttpConnection(strServer,
            dwServiceType == AFX_INET_SERVICE_HTTP ? NORMAL_CONNECT : SECURE_CONNECT,
            nPort);
        m_pFile = m_pConnection->OpenRequest(strMethod, strObject,
            NULL, 1, NULL, NULL,
            (dwServiceType == AFX_INET_SERVICE_HTTP ? NORMAL_REQUEST : SECURE_REQUEST));

        //DWORD dwFlags;
        //m_pFile->QueryOption(INTERNET_OPTION_SECURITY_FLAGS, dwFlags);
        //dwFlags |= SECURITY_FLAG_IGNORE_UNKNOWN_CA;
        ////set web server option
        //m_pFile->SetOption(INTERNET_OPTION_SECURITY_FLAGS, dwFlags);

        m_pFile->AddRequestHeaders("Accept: *,*/*");
        m_pFile->AddRequestHeaders("Accept-Language: zh-cn");
        m_pFile->AddRequestHeaders("Content-Type: application/x-www-form-urlencoded");
        //m_pFile->AddRequestHeaders("Accept-Encoding: gzip, deflate");		// 返回乱码 请注释

        m_pFile->SendRequest(NULL, 0, (LPVOID)(LPCTSTR)strPostData, strPostData == NULL ? 0 : _tcslen(strPostData));

        char szChars[BUFFER_SIZE + 1] = { 0 };
        string strRawResponse = "";
        UINT nReaded = 0;
        while ((nReaded = m_pFile->Read((void*)szChars, BUFFER_SIZE)) > 0)
        {
            szChars[nReaded] = '\0';
            strRawResponse += szChars;
            memset(szChars, 0, BUFFER_SIZE + 1);
        }

        int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, strRawResponse.c_str(), -1, NULL, 0);
        WCHAR* pUnicode = new WCHAR[unicodeLen + 1];
        memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));

        MultiByteToWideChar(CP_UTF8, 0, strRawResponse.c_str(), -1, pUnicode, unicodeLen);
        CString cs(pUnicode);
        delete[]pUnicode;
        pUnicode = NULL;

        strResponse = cs;

        Clear();
    }
    catch (CInternetException* e)
    {
        Clear();
        DWORD dwErrorCode = e->m_dwError;


        DWORD dwError = GetLastError();

        //		PRINT_LOG("dwError = %d", dwError, 0);

        if (ERROR_INTERNET_TIMEOUT == dwErrorCode)
        {
            //throw;
            e->Delete();
            return OUTTIME;
        }
        else
        {
            //throw;
            e->Delete();
            return FAILURE;

        }
    }
    return SUCCESS;
}

int CHttpClient::HttpGet(LPCTSTR strUrl, LPCTSTR strPostData, string& strResponse)
{
    return ExecuteRequest("GET", strUrl, strPostData, strResponse);
}


inline BYTE toHex(const BYTE& x)
{
    return x > 9 ? x + 55 : x + 48;
}

CString CHttpClient::UrlEncode(CString sIn)
{
    CString sOut;

    const int nLen = sIn.GetLength() + 1;

    register LPBYTE pOutTmp = NULL;
    LPBYTE pOutBuf = NULL;
    register LPBYTE pInTmp = NULL;
    LPBYTE pInBuf = (LPBYTE)sIn.GetBuffer(nLen);
    BYTE b = 0;

    //alloc out buffer
    pOutBuf = (LPBYTE)sOut.GetBuffer(nLen * 3 - 2);//new BYTE [nLen  * 3];

    if (pOutBuf)
    {
        pInTmp = pInBuf;
        pOutTmp = pOutBuf;

        // do encoding
        while (*pInTmp)
        {
            if (isalnum(*pInTmp))
                *pOutTmp++ = *pInTmp;
            else
                if (isspace(*pInTmp))
                    *pOutTmp++ = '+';
                else
                {
                    *pOutTmp++ = '%';
                    *pOutTmp++ = toHex(*pInTmp >> 4);
                    *pOutTmp++ = toHex(*pInTmp % 16);
                }
            pInTmp++;
        }
        *pOutTmp = '\0';
        //sOut=pOutBuf;
        //delete [] pOutBuf;
        sOut.ReleaseBuffer();
    }
    sIn.ReleaseBuffer();
    return sOut;
}

int ReadNum()
{
    srand((unsigned)time(NULL));

    return rand();
}


int CHttpClient::HttpPost(LPCTSTR strUrl, LPCTSTR strPostData, string& strResponse)
{
    string Pass = "";
    CString Data = strPostData;
    CString Num;
    Num.Format("%d", ReadNum());
    Num = "m" + Num;
    string EnData = "";

    //MessageBox(0, Num, "0", MB_OK);
    //appsafecode=安全防封包劫持，发送服务器原文返回，不是原文返回说明被劫持了
    Data = _T("<httpdatas>" + Data + "&appsafecode=" + Num + "</httpdatas>");
    //MessageBox(0, Data, "0", MB_OK);
    Data = _T(Bsphp::EncryptionAES(Data.GetBuffer(0)).c_str());
    Data = _T(UrlEncode(Data));
    Data = _T("&parameter=" + Data);
    //MessageBox(0, Data, "0", MB_OK);
    int Post = ExecuteRequest("POST", strUrl, Data, Pass);
    EnData = Bsphp::DecryptionAES(Pass);
    //appsafecode=安全防封包劫持，发送服务器原文返回，不是原文返回说明被劫持了
    int a = EnData.find("<appsafecode>");
    int b = EnData.find("</appsafecode>");
    if (EnData.substr(a + 13, b - a - 13).c_str() == Num)
    {
        a = EnData.find("<data>");
        b = EnData.find("</data>");
        strResponse = EnData.substr(a + 6, b - a - 6).c_str();
    }

    return 1;
}
