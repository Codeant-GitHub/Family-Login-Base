//Codeant - DaMaYi 15:05 星期二 2023年3月21日
//https://github.com/Codeant-GitHub

#pragma once
#include <afxinet.h>
#include <iostream>
using namespace std;

namespace Bsphp
{
	extern CString ServerUrl;
	extern CString MesKey;
	extern CString SeSsL;
	extern CString PcHWID;
	extern CString MyMD5;

	string EncryptionAES(const string& strSrc);
	string DecryptionAES(const string& strSrc);

	DWORD 取游戏进程(const char* pName);
	CString 加密游戏名(int index);
	CString 未加密游戏名(int index);
	CString R星邮箱号(int index);
	CString 获取当前QQ号码();

	CString 获取当前运行路径();
	CString 获取当前运行路径不带文件名();
	CString 获取当前文件名();
	CString 获取当前文件名带后缀();
	CString 获取程序MD5();
	CString 字符加密MD5(const char* text);
	CString 云端文件校验MD5(string dll);
	CString 获取本地时间();

	CString 网络验证();
	BOOL 初始化返回信息();
	CString 取BSphpSeSsL();
	CString 取服务器系统时间(CString Date);
	CString 取软件描述();
	CString 取软件版本信息();
	CString 取软件的公告();
	CString 取预设URL地址();
	CString 取布尔逻辑值A内容();
	CString 取布尔逻辑值A();
	CString 取布尔逻辑值B内容();
	CString 取布尔逻辑值B();
	CString 取软件配置信息段(CString Info);
	CString 取Web浏览地址();
	CString 反破解冻结日志提交(CString User, CString Log);
	CString 用户留言(CString UserName, CString PassWorld, CString Table, CString UserQQ, CString Leix, CString Txt);

	CString 登录_检测账号是否存在(CString User);
	CString 登录_关联卡账号注册(CString UserName, CString PassWorld, CString KH, CString KM, CString UserQQ, CString Mail, CString Mobile, CString Mibao_wenti, CString Mibao_daan, CString Extension);
	CString 登录_软件充值vip续期(CString UserName, CString PassWorld, CString KH, CString KM);
	CString 登录_注册账号(CString UserName, CString PassWorld, CString UserQQ, CString Mail, CString Mobile, CString Mibao_wenti, CString Mibao_daan, CString Extension);
	CString 登录_修改密码(CString UserName, CString PassWorld, CString Mibao_wenti, CString Mibao_daan);
	CString 登录_取用户到期时间();
	CString 登录_通过邮箱修改密码(CString UserName, CString Mail);
	CString 登录_用户登录(CString UserName, CString PassWorld);
	CString 登录_取用户信息(int Info);
	CString 登录_状态心跳包更新();
	CString 登录_设置密保信息(CString Problem, CString Answer);
	CString 登录_取验证数据();
	CString 登录_绑定账号特征(CString UserName, CString PassWorld);
	CString 登录_登录模式扣点专用_扣点(CString Balance, CString Onetime);
	CString 登录_解除账号绑定(CString UserName, CString PassWorld);
	CString 登录_检测密保信息是否填写();
	CString 登录_判断绑定KEY是否存在();
	CString 登录_注销登陆();
	CString 登录_取得登陆状态信息();
	CString 登录_完善用户资料(CString UserQQ, CString Mail, CString Mobile);
	CString 登录_远程注销登录状态(CString UserName, CString PassWorld, CString Type, CString Biaoji);

	CString 卡串_状态心跳包更新();
	CString 卡串_取验证数据();
	CString 卡串_注销登录();
	CString 卡串_解除账号绑定(CString UserName, CString PassWorld);
	CString 卡串_取卡串用户信息(int Info);
	CString 卡串_取卡模式到期时间();
	CString 卡串_卡模式用户登录验证(CString UserName, CString PassWorld);
	CString 卡串_注册添加机器码与验证登录(CString UserQQ);
	CString 卡串_远程注销登录状态(CString UserName);
	CString 卡串_验证登录状态();
	CString 卡串_绑定特征Key(CString UserName, CString PassWorld);

	void 数据加密密码(const char* key);
}