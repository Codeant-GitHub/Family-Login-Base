//Codeant - DaMaYi 15:05 ���ڶ� 2023��3��21��
//https://github.com/Codeant-GitHub

#pragma once
#include "auth.hpp"
#include "VMProtectSDK.h"
#include <tlhelp32.h>
#include <shlobj.h>
#include <sstream>
#include <iostream>
#include <filesystem>

namespace Bsphp
{
	CString ServerUrl;
	CString MesKey;
	CString SeSsL;
	CString PcHWID;
	CString MyMD5;

	DWORD ȡ��Ϸ����(const char* pName)
	{
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (INVALID_HANDLE_VALUE == hSnapshot) {
			return NULL;
		}
		PROCESSENTRY32 pe = { sizeof(pe) };
		for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
			if (strcmp(pe.szExeFile, pName) == 0) {
				CloseHandle(hSnapshot);
				return pe.th32ProcessID;
			}
		}
		CloseHandle(hSnapshot);
		return 0;
	}

	CString ������Ϸ��(int index)
	{
		VMProtectBeginUltra("������Ϸ��");

		string ������Ϣ;
		return ������Ϣ.c_str();

		VMProtectEnd();
	}

	CString δ������Ϸ��(int index)
	{
		VMProtectBeginUltra("δ������Ϸ��");

		string ������Ϣ;
		return ������Ϣ.c_str();

		VMProtectEnd();
	}

	CString R�������(int index)
	{
		VMProtectBeginUltra("R�������");

		string ������Ϣ;
		return ������Ϣ.c_str();

		VMProtectEnd();
	}

	CString ��ȡ��ǰQQ����()
	{
		VMProtectBeginUltra("szQQNumber");
		std::ostringstream ss;
		return ss.str().c_str();
		VMProtectEnd();
	}

	CString ��ȡ��ǰ����·��()
	{
		VMProtectBeginUltra("��ȡ��ǰ����·��");
		char ExeFile[200];
		GetModuleFileName(NULL, ExeFile, 200);
		string path = ExeFile;
		return path.c_str();
		VMProtectEnd();
	}

	CString ��ȡ��ǰ����·�������ļ���()
	{
		VMProtectBeginUltra("��ȡ��ǰ����·�������ļ���");
		TCHAR szFilePath[MAX_PATH + 1] = { 0 };
		GetModuleFileName(NULL, szFilePath, MAX_PATH);
		(_tcsrchr(szFilePath, _T('\\')))[1] = 0;
		CString str_url = szFilePath;
		return str_url;
		VMProtectEnd();
	}

	CString ��ȡ��ǰ�ļ���()
	{
		VMProtectBeginUltra("��ȡ��ǰ�ļ���");
		char ExeFile[200];
		GetModuleFileName(NULL, ExeFile, 200);
		string path = ExeFile;
		string::size_type iPos = path.find_last_of('\\') + 1;
		string filename = path.substr(iPos, path.length() - iPos);
		string name = filename.substr(0, filename.rfind("."));
		return name.c_str();
		VMProtectEnd();
	}

	CString ��ȡ��ǰ�ļ�������׺()
	{
		VMProtectBeginUltra("��ȡ��ǰ�ļ�������׺");
		char ExeFile[200];
		GetModuleFileName(NULL, ExeFile, 200);
		string path = ExeFile;
		string::size_type iPos = path.find_last_of('\\') + 1;
		string filename = path.substr(iPos, path.length() - iPos);
		return filename.c_str();
		VMProtectEnd();
	}

	CString ��ȡ����MD5()
	{
		VMProtectBeginUltra("��ȡ����MD5");
		char ExeFile[200];
		GetModuleFileName(NULL, ExeFile, 200);
		MD5 md5;
		CString m_szMD5;
		m_szMD5 = md5.FileDigest(ExeFile).c_str();
		return m_szMD5;
		VMProtectEnd();
	}

	CString �ַ�����MD5(const char* text)
	{
		VMProtectBeginUltra("�ַ�����MD5");

		string m_szMD5 = MD5(text).toString();
		return m_szMD5.c_str();
		VMProtectEnd();
	}

	CString �ƶ��ļ�У��MD5(string dll)
	{
		VMProtectBeginUltra("�ƶ��ļ�У��MD5");
		MD5 md5;
		string m_szMD5;
		m_szMD5 = md5.FileDigest(dll).c_str();
		return m_szMD5.c_str();
		VMProtectEnd();
	}

	CString ��ȡ����ʱ��()
	{
		VMProtectBeginUltra("��ȡ����ʱ��");
		time_t t = time(NULL);
		struct tm* stime = localtime(&t);
		char tmp[32] = { NULL };
		sprintf(tmp, "%04d-%02d-%02d %02d:%02d:%02d", 1900 + stime->tm_year, 1 + stime->tm_mon, stime->tm_mday, stime->tm_hour, stime->tm_min, stime->tm_sec);
		return tmp;
		VMProtectEnd();
	}

	string ��֤����ʱ��()
	{
		time_t t = time(NULL);
		struct tm* stime = localtime(&t);
		char tmp[32] = { NULL };
		sprintf(tmp, "%04d%02d%02d", 1900 + stime->tm_year, 1 + stime->tm_mon, stime->tm_mday);
		return tmp;
	}

	CString ȡ�������()
	{
		VMProtectBeginUltra("ȡ�������");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=miao.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));
		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ȡBSphpSeSsL()
	{
		VMProtectBeginUltra("ȡBSphpSeSsL");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=BSphpSeSsL.in&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));
		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString �û�����(CString UserName, CString PassWorld, CString Table, CString UserQQ, CString Leix, CString Txt)
	{
		VMProtectBeginUltra("�û�����");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=liuyan.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5="+ MyMD5 +"&user=BBC_" + UserName + "&pwd=" + PassWorld + "&table=" + Table + "&qq=" + UserQQ + "&leix=" + Leix + "&txt=" + Txt));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ȡ�����߼�ֵA����()
	{
		VMProtectBeginUltra("ȡ�����߼�ֵA����");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=logicinfoa.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ȡ�����߼�ֵA()
	{
		VMProtectBeginUltra("ȡ�����߼�ֵA");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=logica.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ȡ�����߼�ֵB()
	{
		VMProtectBeginUltra("ȡ�����߼�ֵB");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=logicb.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ȡ����汾��Ϣ()
	{
		VMProtectBeginUltra("ȡ����汾��Ϣ");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=v.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ������֤()
	{
		VMProtectBeginUltra("������֤");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=internet.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	BOOL ��ʼ��������Ϣ()
	{
		VMProtectBeginUltra("��ʼ��������Ϣ");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=internet.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));
		Http.HttpPost(ServerUrl, Data, RetData);

		if (RetData == "1") {
			return true;
		}
		return false;
		VMProtectEnd();
	}

	CString ���ƽⶳ����־�ύ(CString User, CString Log)
	{
		VMProtectBeginUltra("���ƽⶳ����־�ύ");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=pushlog.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=" + "&log=" + Log));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ȡԤ��URL��ַ()
	{
		VMProtectBeginUltra("ȡԤ��URL��ַ");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=url.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ȡ������ϵͳʱ��(CString Date)
	{
		VMProtectBeginUltra("ȡ������ϵͳʱ��");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=date.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&date=" + Date));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ȡ�����߼�ֵB����()
	{
		VMProtectBeginUltra("ȡ�����߼�ֵB����");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=logicinfob.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ȡ����Ĺ���()
	{
		VMProtectBeginUltra("ȡ����Ĺ���");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=gg.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ȡ���������Ϣ��(CString Info)
	{
		VMProtectBeginUltra("ȡ���������Ϣ��");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=globalinfo.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&info=" + Info));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ȡWeb�����ַ()
	{
		VMProtectBeginUltra("ȡWeb�����ַ");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=weburl.in&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_����˺��Ƿ����(CString User)
	{
		VMProtectBeginUltra("��¼_����˺��Ƿ����");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=GetPleaseregister.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + User));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_�������˺�ע��(CString UserName, CString PassWorld, CString KH, CString KM, CString UserQQ, CString Mail, CString Mobile, CString Mibao_wenti, CString Mibao_daan, CString Extension)
	{
		VMProtectBeginUltra("��¼_�������˺�ע��");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=registrationaska.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld + "&pwdb=" + PassWorld + "&kaid=" + KH + "&kapwd=" + KM + "&qq=" + UserQQ + "&mail=" + Mail + "&key=" + PcHWID + "&mobile=" + Mobile + "&mibao_wenti=" + Mibao_wenti + "&mibao_daan=" + Mibao_daan + "&extension=" + Extension));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_�����ֵvip����(CString UserName, CString PassWorld, CString KH, CString KM)
	{
		VMProtectBeginUltra("��¼_�����ֵvip����");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=chong.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&userpwd=" + PassWorld + "&userset=" + PassWorld + "&ka=" + KH + "&pwd=" + KM));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_ע���˺�(CString UserName, CString PassWorld, CString UserQQ, CString Mail, CString Mobile, CString Mibao_wenti, CString Mibao_daan, CString Extension)
	{
		VMProtectBeginUltra("��¼_ע���˺�");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=registration.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld + "&pwdb=" + PassWorld + "&qq=" + UserQQ + "&mail=" + Mail + "&key=" + PcHWID + "&mobile=" + Mobile + "&mibao_wenti=" + Mibao_wenti + "&mibao_daan=" + Mibao_daan + "&extension=" + Extension));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_�޸�����(CString UserName, CString PassWorld, CString Mibao_wenti, CString Mibao_daan)
	{
		VMProtectBeginUltra("��¼_�޸�����");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=backto.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld + "&pwdb=" + PassWorld + "&wenti=" + Mibao_wenti + "&daan=" + Mibao_daan));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_ȡ�û�����ʱ��()
	{
		VMProtectBeginUltra("��¼_ȡ�û�����ʱ��");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=vipdate.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_ͨ�������޸�����(CString UserName, CString Mail)
	{
		VMProtectBeginUltra("��¼_ͨ�������޸�����");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=BackMailPwd.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&mail=" + Mail));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_�û���¼(CString UserName, CString PassWorld)
	{
		VMProtectBeginUltra("��¼_�û���¼");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=login.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld + "&key=" + PcHWID + "&maxoror=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	//=====================�û���½ʱ��-�û���Ϣ==========================
	CString g_szAccountUserInfo[] = {
		"UserReDate",//����ʱ�� 0
		"UserReIp",//����ʱIp 1
		"UserIsLock",//�û�״̬ 2
		"UserLogInDate",//��¼ʱ�� 3
		"UserLogInIp",//��¼Ip 4
		"UserVipDate",//����ʱ 5
		"UserKey",//������ 6
		"Class_Nane",//�û��������� 7
		"Class_Mark",//�û�������� 8
		"UserQQ",//�û�QQ 9
		"UserMAIL",//�û����� 10
		"UserPayZhe",//�����ۿ� 11
		"UserTreasury",//�Ƿ���� ����=1 12
		"UserMobile",//�绰 13
		"UserRMB",//�ʺŽ�� 14
		"UserPoint",//�ʺŻ��� 15
		"Usermibao_wenti",//�ܱ����� 16
		"UserVipDate",//VIP����ʱ��(�ظ�) 17
		"UserVipWhether",//vip�Ƿ��� û�е��ڷ���1 ���ڷ���2 18
		"UserName"//�û����� 19
	};

	CString ��¼_ȡ�û���Ϣ(int Info)
	{
		VMProtectBeginUltra("��¼_ȡ�û���Ϣ");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getuserinfo.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&info=" + g_szAccountUserInfo[Info]));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_״̬����������()
	{
		VMProtectBeginUltra("��¼_״̬����������");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=timeout.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_ȡ�û�������key()
	{
		VMProtectBeginUltra("��¼_ȡ�û�������key");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=userkey.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_�����ܱ���Ϣ(CString Problem, CString Answer)
	{
		VMProtectBeginUltra("��¼_�����ܱ���Ϣ");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=setthesecuritycode.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&problem=" + Problem + "&answer=" + Answer));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_ȡ��֤����()
	{
		VMProtectBeginUltra("��¼_ȡ��֤����");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=lgkey.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&key=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_���˺�����(CString UserName, CString PassWorld)
	{
		VMProtectBeginUltra("��¼_���˺�����");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=bang.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld + "&key=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_��¼ģʽ�۵�ר��_�۵�(CString Balance, CString Onetime)
	{
		VMProtectBeginUltra("��¼_��¼ģʽ�۵�ר��_�۵�");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=pointsdeduction.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&balance=" + Balance + "&pwd=" + Onetime));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_����˺Ű�(CString UserName, CString PassWorld)
	{
		VMProtectBeginUltra("��¼_����˺Ű�");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=jiekey.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_����ܱ���Ϣ�Ƿ���д()
	{
		VMProtectBeginUltra("��¼_����ܱ���Ϣ�Ƿ���д");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=setcode.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_�жϰ�KEY�Ƿ����()
	{
		VMProtectBeginUltra("��¼_�жϰ�KEY�Ƿ����");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getnotkey.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&key=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_ע����½()
	{
		VMProtectBeginUltra("��¼_ע����½");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=cancellation.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_ȡ�õ�½״̬��Ϣ()
	{
		VMProtectBeginUltra("��¼_ȡ�õ�½״̬��Ϣ");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=lginfo.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_�����û�����(CString UserQQ, CString Mail, CString Mobile)
	{
		VMProtectBeginUltra("��¼_�����û�����");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=Perfect.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&qq=" + UserQQ + "&mail=" + Mail + "&mobile=" + Mobile));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ��¼_Զ��ע����¼״̬(CString UserName, CString PassWorld, CString Type, CString Biaoji)
	{
		VMProtectBeginUltra("��¼_Զ��ע����¼״̬");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=remotecancellation.lg&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld + "&type=" + Type + "&biaoji=" + Biaoji));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ����_״̬����������()
	{
		VMProtectBeginUltra("����_״̬����������");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=timeout.ic&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ����_ȡ��֤����()
	{
		VMProtectBeginUltra("����_ȡ��֤����");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getdata.ic&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&key=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ����_ע����¼()
	{
		VMProtectBeginUltra("����_ע����¼");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=ע����¼.ic&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ����_����˺Ű�(CString UserName, CString PassWorld)
	{
		VMProtectBeginUltra("����_����˺Ű�");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=setcarnot.ic&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&icid=" + UserName + "&icpwd=" + PassWorld));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ����_ȡ�����û���Ϣ(int Info)
	{
		VMProtectBeginUltra("����_ȡ�����û���Ϣ");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getinfo.ic&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&info=" + g_szAccountUserInfo[Info]));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ����_ȡ��ģʽ����ʱ��()
	{
		VMProtectBeginUltra("����_ȡ��ģʽ����ʱ��");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getdate.ic&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ����_��ģʽ�û���¼��֤(CString UserName, CString PassWorld)
	{
		VMProtectBeginUltra("����_��ģʽ�û���¼��֤");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=login.ic&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&icid=" + UserName + "&icpwd=" + PassWorld + "&key=" + PcHWID + "&maxoror=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ����_ע����ӻ���������֤��¼(CString UserQQ)
	{
		VMProtectBeginUltra("����_ע����ӻ���������֤��¼");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getdate.ic&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&key=" + PcHWID + "&maxoror=" + PcHWID + "&carid=" + UserQQ));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ����_Զ��ע����¼״̬(CString UserName)
	{
		VMProtectBeginUltra("����_Զ��ע����¼״̬");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=remotecancellation.ic&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&icid=" + UserName));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ����_��֤��¼״̬()
	{
		VMProtectBeginUltra("����_��֤��¼״̬");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getlkinfo.ic&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString ����_������Key(CString UserName, CString PassWorld)
	{
		VMProtectBeginUltra("����_������Key");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=setcaron.ic&BSphpSeSsL=" + SeSsL + "&date=" + ��ȡ����ʱ��() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&icid=" + UserName + "&icpwd=" + PassWorld + "&key=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}
}