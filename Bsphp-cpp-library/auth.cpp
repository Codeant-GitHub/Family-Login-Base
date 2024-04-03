//Codeant - DaMaYi 15:05 星期二 2023年3月21日
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

	DWORD 取游戏进程(const char* pName)
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

	CString 加密游戏名(int index)
	{
		VMProtectBeginUltra("加密游戏名");

		string 返回信息;
		return 返回信息.c_str();

		VMProtectEnd();
	}

	CString 未加密游戏名(int index)
	{
		VMProtectBeginUltra("未加密游戏名");

		string 返回信息;
		return 返回信息.c_str();

		VMProtectEnd();
	}

	CString R星邮箱号(int index)
	{
		VMProtectBeginUltra("R星邮箱号");

		string 返回信息;
		return 返回信息.c_str();

		VMProtectEnd();
	}

	CString 获取当前QQ号码()
	{
		VMProtectBeginUltra("szQQNumber");
		std::ostringstream ss;
		return ss.str().c_str();
		VMProtectEnd();
	}

	CString 获取当前运行路径()
	{
		VMProtectBeginUltra("获取当前运行路径");
		char ExeFile[200];
		GetModuleFileName(NULL, ExeFile, 200);
		string path = ExeFile;
		return path.c_str();
		VMProtectEnd();
	}

	CString 获取当前运行路径不带文件名()
	{
		VMProtectBeginUltra("获取当前运行路径不带文件名");
		TCHAR szFilePath[MAX_PATH + 1] = { 0 };
		GetModuleFileName(NULL, szFilePath, MAX_PATH);
		(_tcsrchr(szFilePath, _T('\\')))[1] = 0;
		CString str_url = szFilePath;
		return str_url;
		VMProtectEnd();
	}

	CString 获取当前文件名()
	{
		VMProtectBeginUltra("获取当前文件名");
		char ExeFile[200];
		GetModuleFileName(NULL, ExeFile, 200);
		string path = ExeFile;
		string::size_type iPos = path.find_last_of('\\') + 1;
		string filename = path.substr(iPos, path.length() - iPos);
		string name = filename.substr(0, filename.rfind("."));
		return name.c_str();
		VMProtectEnd();
	}

	CString 获取当前文件名带后缀()
	{
		VMProtectBeginUltra("获取当前文件名带后缀");
		char ExeFile[200];
		GetModuleFileName(NULL, ExeFile, 200);
		string path = ExeFile;
		string::size_type iPos = path.find_last_of('\\') + 1;
		string filename = path.substr(iPos, path.length() - iPos);
		return filename.c_str();
		VMProtectEnd();
	}

	CString 获取程序MD5()
	{
		VMProtectBeginUltra("获取程序MD5");
		char ExeFile[200];
		GetModuleFileName(NULL, ExeFile, 200);
		MD5 md5;
		CString m_szMD5;
		m_szMD5 = md5.FileDigest(ExeFile).c_str();
		return m_szMD5;
		VMProtectEnd();
	}

	CString 字符加密MD5(const char* text)
	{
		VMProtectBeginUltra("字符加密MD5");

		string m_szMD5 = MD5(text).toString();
		return m_szMD5.c_str();
		VMProtectEnd();
	}

	CString 云端文件校验MD5(string dll)
	{
		VMProtectBeginUltra("云端文件校验MD5");
		MD5 md5;
		string m_szMD5;
		m_szMD5 = md5.FileDigest(dll).c_str();
		return m_szMD5.c_str();
		VMProtectEnd();
	}

	CString 获取本地时间()
	{
		VMProtectBeginUltra("获取本地时间");
		time_t t = time(NULL);
		struct tm* stime = localtime(&t);
		char tmp[32] = { NULL };
		sprintf(tmp, "%04d-%02d-%02d %02d:%02d:%02d", 1900 + stime->tm_year, 1 + stime->tm_mon, stime->tm_mday, stime->tm_hour, stime->tm_min, stime->tm_sec);
		return tmp;
		VMProtectEnd();
	}

	string 验证本地时间()
	{
		time_t t = time(NULL);
		struct tm* stime = localtime(&t);
		char tmp[32] = { NULL };
		sprintf(tmp, "%04d%02d%02d", 1900 + stime->tm_year, 1 + stime->tm_mon, stime->tm_mday);
		return tmp;
	}

	CString 取软件描述()
	{
		VMProtectBeginUltra("取软件描述");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=miao.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));
		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 取BSphpSeSsL()
	{
		VMProtectBeginUltra("取BSphpSeSsL");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=BSphpSeSsL.in&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));
		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 用户留言(CString UserName, CString PassWorld, CString Table, CString UserQQ, CString Leix, CString Txt)
	{
		VMProtectBeginUltra("用户留言");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=liuyan.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5="+ MyMD5 +"&user=BBC_" + UserName + "&pwd=" + PassWorld + "&table=" + Table + "&qq=" + UserQQ + "&leix=" + Leix + "&txt=" + Txt));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 取布尔逻辑值A内容()
	{
		VMProtectBeginUltra("取布尔逻辑值A内容");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=logicinfoa.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 取布尔逻辑值A()
	{
		VMProtectBeginUltra("取布尔逻辑值A");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=logica.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 取布尔逻辑值B()
	{
		VMProtectBeginUltra("取布尔逻辑值B");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=logicb.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 取软件版本信息()
	{
		VMProtectBeginUltra("取软件版本信息");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=v.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 网络验证()
	{
		VMProtectBeginUltra("网络验证");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=internet.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	BOOL 初始化返回信息()
	{
		VMProtectBeginUltra("初始化返回信息");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=internet.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));
		Http.HttpPost(ServerUrl, Data, RetData);

		if (RetData == "1") {
			return true;
		}
		return false;
		VMProtectEnd();
	}

	CString 反破解冻结日志提交(CString User, CString Log)
	{
		VMProtectBeginUltra("反破解冻结日志提交");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=pushlog.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=" + "&log=" + Log));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 取预设URL地址()
	{
		VMProtectBeginUltra("取预设URL地址");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=url.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 取服务器系统时间(CString Date)
	{
		VMProtectBeginUltra("取服务器系统时间");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=date.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&date=" + Date));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 取布尔逻辑值B内容()
	{
		VMProtectBeginUltra("取布尔逻辑值B内容");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=logicinfob.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 取软件的公告()
	{
		VMProtectBeginUltra("取软件的公告");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=gg.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 取软件配置信息段(CString Info)
	{
		VMProtectBeginUltra("取软件配置信息段");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=globalinfo.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&info=" + Info));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 取Web浏览地址()
	{
		VMProtectBeginUltra("取Web浏览地址");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=weburl.in&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_检测账号是否存在(CString User)
	{
		VMProtectBeginUltra("登录_检测账号是否存在");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=GetPleaseregister.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + User));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_关联卡账号注册(CString UserName, CString PassWorld, CString KH, CString KM, CString UserQQ, CString Mail, CString Mobile, CString Mibao_wenti, CString Mibao_daan, CString Extension)
	{
		VMProtectBeginUltra("登录_关联卡账号注册");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=registrationaska.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld + "&pwdb=" + PassWorld + "&kaid=" + KH + "&kapwd=" + KM + "&qq=" + UserQQ + "&mail=" + Mail + "&key=" + PcHWID + "&mobile=" + Mobile + "&mibao_wenti=" + Mibao_wenti + "&mibao_daan=" + Mibao_daan + "&extension=" + Extension));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_软件充值vip续期(CString UserName, CString PassWorld, CString KH, CString KM)
	{
		VMProtectBeginUltra("登录_软件充值vip续期");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=chong.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&userpwd=" + PassWorld + "&userset=" + PassWorld + "&ka=" + KH + "&pwd=" + KM));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_注册账号(CString UserName, CString PassWorld, CString UserQQ, CString Mail, CString Mobile, CString Mibao_wenti, CString Mibao_daan, CString Extension)
	{
		VMProtectBeginUltra("登录_注册账号");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=registration.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld + "&pwdb=" + PassWorld + "&qq=" + UserQQ + "&mail=" + Mail + "&key=" + PcHWID + "&mobile=" + Mobile + "&mibao_wenti=" + Mibao_wenti + "&mibao_daan=" + Mibao_daan + "&extension=" + Extension));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_修改密码(CString UserName, CString PassWorld, CString Mibao_wenti, CString Mibao_daan)
	{
		VMProtectBeginUltra("登录_修改密码");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=backto.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld + "&pwdb=" + PassWorld + "&wenti=" + Mibao_wenti + "&daan=" + Mibao_daan));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_取用户到期时间()
	{
		VMProtectBeginUltra("登录_取用户到期时间");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=vipdate.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_通过邮箱修改密码(CString UserName, CString Mail)
	{
		VMProtectBeginUltra("登录_通过邮箱修改密码");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=BackMailPwd.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&mail=" + Mail));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_用户登录(CString UserName, CString PassWorld)
	{
		VMProtectBeginUltra("登录_用户登录");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=login.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld + "&key=" + PcHWID + "&maxoror=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	//=====================用户登陆时限-用户信息==========================
	CString g_szAccountUserInfo[] = {
		"UserReDate",//激活时间 0
		"UserReIp",//激活时Ip 1
		"UserIsLock",//用户状态 2
		"UserLogInDate",//登录时间 3
		"UserLogInIp",//登录Ip 4
		"UserVipDate",//到期时 5
		"UserKey",//绑定特征 6
		"Class_Nane",//用户分组名称 7
		"Class_Mark",//用户分组别名 8
		"UserQQ",//用户QQ 9
		"UserMAIL",//用户邮箱 10
		"UserPayZhe",//购卡折扣 11
		"UserTreasury",//是否代理 代理=1 12
		"UserMobile",//电话 13
		"UserRMB",//帐号金额 14
		"UserPoint",//帐号积分 15
		"Usermibao_wenti",//密保问题 16
		"UserVipDate",//VIP到期时间(重复) 17
		"UserVipWhether",//vip是否到期 没有到期返回1 到期返回2 18
		"UserName"//用户名称 19
	};

	CString 登录_取用户信息(int Info)
	{
		VMProtectBeginUltra("登录_取用户信息");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getuserinfo.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&info=" + g_szAccountUserInfo[Info]));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_状态心跳包更新()
	{
		VMProtectBeginUltra("登录_状态心跳包更新");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=timeout.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_取用户绑定特征key()
	{
		VMProtectBeginUltra("登录_取用户绑定特征key");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=userkey.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_设置密保信息(CString Problem, CString Answer)
	{
		VMProtectBeginUltra("登录_设置密保信息");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=setthesecuritycode.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&problem=" + Problem + "&answer=" + Answer));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_取验证数据()
	{
		VMProtectBeginUltra("登录_取验证数据");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=lgkey.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&key=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_绑定账号特征(CString UserName, CString PassWorld)
	{
		VMProtectBeginUltra("登录_绑定账号特征");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=bang.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld + "&key=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_登录模式扣点专用_扣点(CString Balance, CString Onetime)
	{
		VMProtectBeginUltra("登录_登录模式扣点专用_扣点");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=pointsdeduction.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&balance=" + Balance + "&pwd=" + Onetime));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_解除账号绑定(CString UserName, CString PassWorld)
	{
		VMProtectBeginUltra("登录_解除账号绑定");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=jiekey.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_检测密保信息是否填写()
	{
		VMProtectBeginUltra("登录_检测密保信息是否填写");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=setcode.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_判断绑定KEY是否存在()
	{
		VMProtectBeginUltra("登录_判断绑定KEY是否存在");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getnotkey.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&key=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_注销登陆()
	{
		VMProtectBeginUltra("登录_注销登陆");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=cancellation.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_取得登陆状态信息()
	{
		VMProtectBeginUltra("登录_取得登陆状态信息");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=lginfo.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_完善用户资料(CString UserQQ, CString Mail, CString Mobile)
	{
		VMProtectBeginUltra("登录_完善用户资料");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=Perfect.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&qq=" + UserQQ + "&mail=" + Mail + "&mobile=" + Mobile));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 登录_远程注销登录状态(CString UserName, CString PassWorld, CString Type, CString Biaoji)
	{
		VMProtectBeginUltra("登录_远程注销登录状态");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=remotecancellation.lg&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&user=BBC_" + UserName + "&pwd=" + PassWorld + "&type=" + Type + "&biaoji=" + Biaoji));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 卡串_状态心跳包更新()
	{
		VMProtectBeginUltra("卡串_状态心跳包更新");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=timeout.ic&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 卡串_取验证数据()
	{
		VMProtectBeginUltra("卡串_取验证数据");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getdata.ic&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&key=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 卡串_注销登录()
	{
		VMProtectBeginUltra("卡串_注销登录");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=注销登录.ic&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 卡串_解除账号绑定(CString UserName, CString PassWorld)
	{
		VMProtectBeginUltra("卡串_解除账号绑定");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=setcarnot.ic&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&icid=" + UserName + "&icpwd=" + PassWorld));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 卡串_取卡串用户信息(int Info)
	{
		VMProtectBeginUltra("卡串_取卡串用户信息");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getinfo.ic&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&info=" + g_szAccountUserInfo[Info]));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 卡串_取卡模式到期时间()
	{
		VMProtectBeginUltra("卡串_取卡模式到期时间");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getdate.ic&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 卡串_卡模式用户登录验证(CString UserName, CString PassWorld)
	{
		VMProtectBeginUltra("卡串_卡模式用户登录验证");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=login.ic&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&icid=" + UserName + "&icpwd=" + PassWorld + "&key=" + PcHWID + "&maxoror=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 卡串_注册添加机器码与验证登录(CString UserQQ)
	{
		VMProtectBeginUltra("卡串_注册添加机器码与验证登录");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getdate.ic&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&key=" + PcHWID + "&maxoror=" + PcHWID + "&carid=" + UserQQ));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 卡串_远程注销登录状态(CString UserName)
	{
		VMProtectBeginUltra("卡串_远程注销登录状态");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=remotecancellation.ic&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&icid=" + UserName));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 卡串_验证登录状态()
	{
		VMProtectBeginUltra("卡串_验证登录状态");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=getlkinfo.ic&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}

	CString 卡串_绑定特征Key(CString UserName, CString PassWorld)
	{
		VMProtectBeginUltra("卡串_绑定特征Key");
		CHttpClient Http;
		CString Data;
		string RetData;
		Data = _T(VMProtectDecryptStringA("&api=setcaron.ic&BSphpSeSsL=" + SeSsL + "&date=" + 获取本地时间() + "&mutualkey=" + MesKey + "&md5=" + MyMD5 + "&icid=" + UserName + "&icpwd=" + PassWorld + "&key=" + PcHWID));

		Http.HttpPost(ServerUrl, Data, RetData);
		return  RetData.c_str();
		VMProtectEnd();
	}
}