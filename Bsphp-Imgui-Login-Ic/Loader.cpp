#pragma once
#include "Loader.hpp"
#include "auth.hpp"
#include "json/json/json.h"
//#include "JsonHttp.hpp"
#include <comdef.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

#include <cctype>
#include <iostream>
#include <cstring>
#include <ShellAPI.h>
#pragma execution_character_set("utf-8")

// Our state
bool show_demo_window = true;
bool show_demo_window_2 = false;
static bool Enabled = true;
HWND Window = nullptr;

LPDIRECT3DDEVICE9        g_pd3dDevice;
D3DPRESENT_PARAMETERS    g_d3dpp;
LPDIRECT3D9              g_pD3D;
LPDIRECT3DTEXTURE9       g_texture;
ImFont* childHeaderFont{};

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

extern void LoginDemo();

int client_width;
int client_height;

static int 默认线路 = 1;

CString 加载游戏大写 = "GTA5.exe";
CString 加载游戏小写 = "gta5.exe";
CString 默认游戏文件 = "";
CString 获取当前版本 = "";
CString 默认GTA5版本 = "0.0.0";
CString 默认RDR2版本 = "0.0.0";
CString 设置加载文件 = "";

int 游戏名字数据 = 0;
int 游戏邮箱数据 = 0;

bool 会员登录 = false;
bool 注册会员 = false;
bool 续费充值 = false;
bool 变更密码 = false;
bool 记住卡密 = true;
bool 登录完成 = false;
// 定义按钮的状态

static char 请填写账号[256] = "";
static char 请填写密码[256] = "";
static char 请填写新密码[256] = "";
static char 请填写确认密码[256] = "";
static char 请填写卡号[256] = "";
static char 请填写卡密[256] = "";
static char 请填写邮箱[256] = "";

CString 首次激活绑定QQ = "";
CString 首次激活绑定邮箱 = "";

int 信息属性高度 = 120.0f;

CString 激活时间 = "1900-01-01 12:12:12";//0
CString 激活时Ip = "255.255.255.255";//1
CString 用户状态 = "";//2
CString 登录时间 = "1900-01-01 12:12:12";//3
CString 登录Ip = "255.255.255.255";//4
CString 到期时间 = "1900-01-01 12:12:12";//5
CString 绑定特征 = "";//6
CString 用户分组名称 = "";//7
CString 用户分组别名 = "";//8
CString 用户QQ = "";//9
CString 用户邮箱 = "";//10
CString 用户名称 = "";//19

namespace Settings
{
    static int Tab = 1;
}

void 读取账号()
{
    std::ostringstream ss;
    ss << getenv("PUBLIC") << "\\Family_Key.ini";
    GetPrivateProfileString("Key", "username", "", 请填写账号, 256, ss.str().c_str());
    GetPrivateProfileString("Key", "password", "", 请填写密码, 256, ss.str().c_str());
}

void 保存账号()
{
    std::ostringstream ss;
    ss << getenv("PUBLIC") << "\\Family_Key.ini";
    WritePrivateProfileString("Key", "username", 请填写账号, ss.str().c_str());
    WritePrivateProfileString("Key", "password", 请填写密码, ss.str().c_str());
}

std::string 辅助名字;

std::string 纳扎尔夫人数据获取失败 = "纳扎尔夫人数据获取失败";
std::string 收藏家数据获取失败 = "收藏家数据获取失败";
std::string 创建配置文件失败 = "创建配置文件失败";
std::string 保存默认线路成功 = "保存成功,重新打开登陆器生效";
std::string 获取云数据完成 = "获取云数据完成";
std::string 获取云数据失败 = "获取云数据失败";
std::string 正在获取云数据 = "正在获取云数据";
std::string 网络链接成功 = "网络链接成功";
std::string 辅助加载失败 = "辅助加载失败";
std::string 辅助加载完成 = "辅助加载完成";
std::string 编辑框不能为空 = "编辑框不能为空";
std::string 获取游戏信息失败 = "获取游戏信息失败";
std::string 未检测到游戏程序 = "未检测到游戏程序";
std::string 请勿重复点击按钮 = "请勿重复点击按钮";
std::string 用户信息不能为空 = "用户信息不能为空";
std::string 已清理请重新打开登陆器 = "已清理请重新打开登陆器";
std::string 账号长度限制位数 = "账号长度限制 8-16位数";
std::string 密码长度限制位数 = "密码长度限制 6-25位数";
std::string 当获取云数据失败时清理 = "当获取云数据失败时清理";
std::string 清理云缓存文件 = "清理云缓存文件";
std::string 打开程序目录 = "打开程序目录";
std::string 菜单按键自定义 = "菜单按键自定义";
std::string 菜单界面自定义 = "菜单界面自定义";
std::string 查看运行日志 = "查看运行日志";
std::string 这里填写会员账号 = "这里填写会员账号";
std::string 这里填写会员密码 = "这里填写会员密码";
std::string 注册账号建议长度位数 = "注册账号建议长度8-15位数";
std::string 注册密码建议长度位数 = "注册密码建议长度在8-15位数";
std::string 填写购买的卡号 = "填写购买的卡号";
std::string 填写购买的卡密 = "填写购买的卡密";
std::string 保存为默认线路 = "保存为默认游戏";
std::string 账号 = "账号";
std::string 密码 = "密码";
std::string 卡号 = "卡号";
std::string 卡密 = "卡密";
std::string 确定注册 = "确定注册";
std::string 重新绑定 = "重新绑定";
std::string 用户登录 = "用户登录";
std::string 修改密码 = "修改密码";
std::string 账号登录 = "账号登录";
std::string 会员注册 = "会员注册";
std::string 充值续费 = "充值续费";
std::string 常规设置 = "常规设置";
std::string 设置线路 = "默认游戏";
std::string 线路一 = "Grand Theft Auto V";
std::string 线路二 = "Red Dead Redemption 2";
std::string 提示文本信息 = "正在请求服务器数据";
std::string 用户名已存在 = "用户名已存在";
std::string 用户名可以用 = "用户名可以用";
std::string 密码验证错误 = "密码验证错误";
std::string 账号长度受限 = "账号长度受限";
std::string 账号格式错误 = "账号格式错误";
std::string 注册成功 = "注册成功";
std::string 注册失败 = "注册失败";
std::string 密码长度受限 = "密码长度受限";
std::string 账号错误 = "账号错误";
std::string 密码错误 = "密码错误";
std::string 用户名不存在 = "用户名不存在";
std::string 登陆成功 = "登陆成功";
std::string 登陆失败 = "登陆失败";
std::string QQ号错误 = "QQ号错误";
std::string 邮箱错误 = "邮箱错误";
std::string 手机号码错误 = "手机号码错误";
std::string 保存成功 = "保存成功";
std::string 保存失败 = "保存失败";
std::string 不能输入空格 = "不能输入空格";
std::string 请输入密保问题 = "请输入密保问题";
std::string 用户名被冻结了 = "用户名被冻结了";
std::string 记录查询失败 = "记录查询失败";
std::string 你的密保信息已经填写 = "你的密保信息已经填写";
std::string 密保信息添加成功 = "密保信息添加成功";
std::string 密保添加失败 = "密保添加失败";
std::string 密码不可以空格 = "密码不可以空格";
std::string 请输入旧密码 = "请输入旧密码";
std::string 旧密码不能和新密码一致 = "旧密码不能和新密码一致";
std::string 密码修改失败 = "密码修改失败";
std::string 旧密码不正确 = "旧密码不正确";
std::string 密码修改成功 = "密码修改成功";
std::string 表单信息不能为空 = "表单信息不能为空";
std::string 密码已经成功通过密保信息修改 = "密码已经成功通过密保信息修改";
std::string 密保信息错误 = "密保信息错误";
std::string 密码找回失败 = "密码找回失败";
std::string 验证码不能为空 = "验证码不能为空";
std::string 验证码正确 = "验证码正确";
std::string 验证码错误 = "验证码错误";
std::string 用户名不能为空 = "用户名不能为空";
std::string 用户名不能含空格 = "用户名不能含空格";
std::string 长时空闲超时执行正常 = "长时空闲超时执行正常";
std::string 长时空闲超时执行异常 = "长时空闲超时执行异常";
std::string 用户名被冻结登陆 = "用户名被冻结登陆";
std::string 登陆超时 = "登陆超时";
std::string 你在别处已经登陆被迫登出 = "你在别处已经登陆被迫登出";
std::string 已经登陆 = "已经登陆";
std::string 你需要登陆才可以访问 = "你需要登陆才可以访问";
std::string 没有登录或登录已超时 = "没有登录或登录已超时";
std::string 密保不能少于要求字符 = "密保不能少于要求字符";
std::string 密保信息未填写 = "密保信息未填写";
std::string 充值账号不能为空 = "充值账号不能为空";
std::string 充值卡号不能为空 = "充值卡号不能为空";
std::string 充值卡密码不能为空 = "充值卡密码不能为空";
std::string 充值账号不能包含空格 = "充值账号不能包含空格";
std::string 充值卡号不能包含空格 = "充值卡号不能包含空格";
std::string 充值卡密码不能包含空格 = "充值卡密码不能包含空格";
std::string 充值卡号或充值卡密码错误 = "充值卡号或充值卡密码错误";
std::string 充值的用户账号不存在 = "充值的用户账号不存在";
std::string 充值卡账号密码错误或者不存在 = "充值卡账号密码错误或者不存在";
std::string 用户没有使用过要充值软件 = "用户没有使用过要充值软件";
std::string 激活成功赶快去使用吧 = "激活成功赶快去使用吧";
std::string 充值失败 = "充值失败";
std::string 充值卡已经充值过了 = "充值卡已经充值过了";
std::string 你留言和反馈我们已经收到 = "你留言和反馈我们已经收到";
std::string 提交留言失败 = "提交留言失败";
std::string 请输入标题 = "请输入标题";
std::string 请输入留言内容 = "请输入留言内容";
std::string 激活成功 = "激活成功";
std::string 添加失败 = "添加失败";
std::string 糟糕激活码已经存在了 = "糟糕激活码已经存在了";
std::string 还没有存在 = "还没有存在";
std::string 激活码不存在 = "激活码不存在";
std::string 你使用激活串已到期作废 = "你使用激活串已到期作废";
std::string 激活码已经存在 = "激活码已经存在";
std::string 执行错误 = "执行错误";
std::string 请检查激活码号或者密码错误 = "请检查激活码号或者密码错误";
std::string 你使用权已经被冻结 = "你使用权已经被冻结";
std::string 验证失败 = "验证失败";
std::string 验证成功 = "验证成功";
std::string 登录验证成功 = "登录验证成功";
std::string 你的使用期已到 = "你的使用期已到";
std::string 没有查询到用户信息 = "没有查询到用户信息";
std::string 该用户不是使用本软件的 = "该用户不是使用本软件的";
std::string 用户名已经被冻结 = "用户名已经被冻结";
std::string 激活码被冻结 = "激活码被冻结";
std::string 帐号已经到期请充值再使用 = "帐号已经到期请充值再使用";
std::string 请输入一个邮箱作为你的帐号 = "请输入一个邮箱作为你的帐号";
std::string 恭喜你注册成功 = "恭喜你注册成功";
std::string 密保邮箱不能为空 = "密保邮箱不能为空";
std::string 密保邮箱格式不正确 = "密保邮箱格式不正确";
std::string QQ号不能为空 = "QQ号不能为空";
std::string QQ号格式输入不正确 = "QQ号格式输入不正确";
std::string 你的帐号还没激活 = "你的帐号还没激活";
std::string 请输入你联系方式 = "请输入你联系方式";
std::string 账号余额不足 = "账号余额不足";
std::string 执行扣点成功 = "执行扣点成功";
std::string 执行扣点失败 = "执行扣点失败";
std::string 扣除金额不能为零或小于零 = "扣除金额不能为零或小于零";
std::string 记录日志标题不可为空 = "记录日志标题不可为空";
std::string 用户数已经达最大限制 = "用户数已经达最大限制";
std::string 当前账号包含禁止关键字 = "当前账号包含禁止关键字";
std::string 手机号码不能为空 = "手机号码不能为空";
std::string 账号注册成功 = "账号注册成功";
std::string 找回的账号错误 = "找回的账号错误";
std::string 已经关闭账号注册 = "已经关闭账号注册";
std::string 注册账号过于频繁 = "注册账号过于频繁";
std::string 激活码与软件不相符 = "激活码与软件不相符";
std::string 模式不符合请选择对应软件使用 = "模式不符合请选择对应软件使用";
std::string 激活码不能为空 = "激活码不能为空";
std::string 注销成功 = "注销成功";
std::string 注销失败 = "注销失败";
std::string 代理商账号 = "代理商账号";
std::string 接口调用失败 = "接口调用失败";
std::string 当前账号禁止修改密码 = "当前账号禁止修改密码";
std::string 用户关联账户不存在 = "用户关联账户不存在";
std::string 激活邮件已经发送 = "激活邮件已经发送";
std::string 邮件发送失败 = "邮件发送失败";
std::string 注册账号已经锁定 = "注册账号已经锁定";
std::string 重置密码邮件已经发出 = "重置密码邮件已经发出";
std::string 当前邮箱已经注册过 = "当前邮箱已经注册过";
std::string 邀请人不存在 = "邀请人不存在";
std::string 邀请人不能为空 = "邀请人不能为空";
std::string 系统超出授权最大限制 = "系统超出授权最大限制";
std::string 充值账号已经被冻结 = "充值账号已经被冻结";
std::string 修改密码账户不存在 = "修改密码账户不存在";
std::string 修改密码账户没有绑定邮箱 = "修改密码账户没有绑定邮箱";
std::string 无法检索到您激活码信息有误 = "无法检索到您激活码信息有误";
std::string 请到对应软件下使用 = "请到对应软件下使用";
std::string 到对应软件下使用并充值 = "到对应软件下使用并充值";
std::string 输入的激活码不存在 = "输入的激活码不存在";
std::string 输入的卡模式激活码 = "输入的卡模式激活码";
std::string 输入的充值卡为登陆模式使用 = "输入的充值卡为登陆模式使用";
std::string 充值卡不存在 = "充值卡不存在";
std::string 无法接收到数据包 = "无法接收到数据包";
std::string 数据包内出现系统屏蔽字符串 = "数据包内出现系统屏蔽字符串";
std::string 请将系统时间设置为北京时间 = "请将系统时间设置为北京时间";
std::string 接口不存在连接失败 = "接口不存在连接失败";
std::string 访问软件不存在 = "访问软件不存在";
std::string 软件验证失败请重新下载 = "软件验证失败请重新下载";
std::string 非法的请求身份验证失败 = "非法的请求身份验证失败";
std::string 欢迎你首次使用请重新登陆 = "欢迎你首次使用请重新登陆";
std::string 特征码已经有人绑定过了 = "特征码已经有人绑定过了";
std::string 绑定成功 = "绑定成功";
std::string 绑定失败 = "绑定失败";
std::string 绑定特征不能为空 = "绑定特征不能为空";
std::string 已经绑定了不需要再绑定 = "已经绑定了不需要再绑定";
std::string 使用软件登录模式不相符 = "使用软件登录模式不相符";
std::string 卡密受限制无法登录 = "卡密受限制无法登录";
std::string 解除绑定将受限制无法解除绑定 = "解除绑定将受限制无法解除绑定";
std::string 解除绑定失败 = "解除绑定失败";
std::string 解除绑定成功 = "解除绑定成功";
std::string 已经是解除绑定状态 = "已经是解除绑定状态";
std::string 绑定不能为空 = "绑定不能为空";
std::string 账号登录超时 = "账号登录超时";
std::string 登录状态更新失败 = "登录状态更新失败";
std::string 登录状态更新成功 = "登录状态更新成功";
std::string 帐号没有到期 = "帐号没有到期";
std::string 登录帐号已经到期 = "登录帐号已经到期";
std::string 执行正常 = "执行正常";
std::string 扣点模式之扣点执行失败 = "扣点模式之扣点执行失败";
std::string 无法获取重要的验证数据 = "无法获取重要的验证数据";
std::string 请重新绑定后使用 = "请重新绑定后使用";
std::string 执行正常扣点API调用被动 = "执行正常扣点API调用被动";
std::string 登录模式计点模式扣点执行正常 = "登录模式计点模式扣点执行正常";
std::string 登录模式计点模式扣点执行失败 = "登录模式计点模式扣点执行失败";
std::string 扣点点数不能小于或者等于0 = "扣点点数不能小于或者等于0";
std::string 模式不匹配 = "模式不匹配";
std::string 软件非扣点模式 = "软件非扣点模式";
std::string 使用软件不属于卡串计时扣点模式 = "使用软件不属于卡串计时扣点模式";
std::string 点数不足 = "点数不足";
std::string 登录限制验证通过登录继续 = "登录限制验证通过登录继续";
std::string 在线使用数量已经达到上限 = "在线使用数量已经达到上限";
std::string 机器标记没有不可空 = "机器标记没有不可空";
std::string 签名验证失败 = "签名验证失败";
std::string 签名参数不能为空 = "签名参数不能为空";
std::string 无法识别的通信方式 = "无法识别的通信方式";
std::string 激活码被冻结禁止 = "激活码被冻结禁止";
std::string 多开控制无法获取用户信息 = "多开控制无法获取用户信息";
std::string 绑定不能空 = "绑定不能空";
std::string 系统没有开启邮件功能 = "系统没有开启邮件功能";
std::string 账号没有设置邮箱信息 = "账号没有设置邮箱信息";
std::string 输入邮箱跟已设置邮箱不符合 = "输入邮箱跟已设置邮箱不符合";
std::string 找回账号不存在 = "找回账号不存在";
std::string 该账号没有设置邮箱发件失败 = "该账号没有设置邮箱发件失败";
std::string 邮件已经发出 = "邮件已经发出";
std::string 系统邮件失败 = "系统邮件失败";
std::string 请输入充值卡号 = "请输入充值卡号";
std::string 请输入要获取数据类型 = "请输入要获取数据类型";
std::string 已经是解除绑定了 = "已经是解除绑定了";
std::string 解除绑定拒绝 = "解除绑定拒绝";
std::string 已被强制解绑 = "已被强制解绑";
std::string 请输入激活码 = "请输入激活码";
std::string 请输入账号 = "请输入账号";
std::string 请输入密码 = "请输入密码";
std::string 注册新用户失败 = "注册新用户失败";
std::string 账号被冻结禁止 = "账号被冻结禁止";
std::string 还没有绑定请绑定在登录 = "还没有绑定请绑定在登录";
std::string 充值账号不存在 = "充值账号不存在";
std::string 充值卡错误或者不存在 = "充值卡错误或者不存在";
std::string 充值卡已经冻结 = "充值卡已经冻结";
std::string 充值卡已经充值作废 = "充值卡已经充值作废";
std::string 充值成功 = "充值成功";
std::string 推荐人错误没有请不要填写 = "推荐人错误没有请不要填写";
std::string 激活码无效或者错误 = "激活码无效或者错误";
std::string 请再次输入密码 = "请再次输入密码";
std::string 请输入密保 = "请输入密保";
std::string 请输入答案 = "请输入答案";
std::string 使用已经到期 = "使用已经到期";
std::string 邮箱 = "邮箱";
std::string 新密码 = "新密码";
std::string 确认密码 = "确认密码";

const char* items[] = { 线路一.c_str(), 线路二.c_str() };

struct Object_List_Info
{
    int model;
    const char* model_name;
};

Object_List_Info Objects_Lockers_Types[]{
{ 1000,用户名已存在.c_str() },
{ 1001,用户名可以用.c_str() },
{ 1002,密码验证错误.c_str() },
{ 1003,账号长度受限.c_str() },
{ 1004,账号格式错误.c_str() },
{ 1005,注册成功.c_str() },
{ 1006,注册失败.c_str() },
{ 1007,密码长度受限.c_str() },
{ 1008,账号错误.c_str() },
{ 1009,密码错误.c_str() },
{ 1010,用户名不存在.c_str() },
{ 1011,登陆成功.c_str() },
{ 1012,密码错误.c_str() },
{ 1013,登陆失败.c_str() },
{ 1014,QQ号错误.c_str() },
{ 1015,邮箱错误.c_str() },
{ 1016,手机号码错误.c_str() },
{ 1017,保存成功.c_str() },
{ 1018,保存失败.c_str() },
{ 1019,不能输入空格.c_str() },
{ 1020,请输入密保问题.c_str() },
{ 1021,用户名被冻结了.c_str() },
{ 1022,记录查询失败.c_str() },
{ 1023,你的密保信息已经填写.c_str() },
{ 1024,密保信息添加成功.c_str() },
{ 1025,密保添加失败.c_str() },
{ 1026,密码不可以空格.c_str() },
{ 1027,请输入旧密码.c_str() },
{ 1028,旧密码不能和新密码一致.c_str() },
{ 1029,密码修改失败.c_str() },
{ 1030,旧密码不正确.c_str() },
{ 1031,密码修改成功.c_str() },
{ 1032,表单信息不能为空.c_str() },
{ 1033,密码已经成功通过密保信息修改.c_str() },
{ 1034,密保信息错误.c_str() },
{ 1035,密码找回失败.c_str() },
{ 1036,验证码不能为空.c_str() },
{ 1037,验证码正确.c_str() },
{ 1038,验证码错误.c_str() },
{ 1039,用户名不能为空.c_str() },
{ 1040,用户名不能含空格.c_str() },
{ 1041,长时空闲超时执行正常.c_str() },
{ 1042,长时空闲超时执行异常.c_str() },
{ 1043,用户名不存在.c_str() },
{ 1044,用户名被冻结登陆.c_str() },
{ 1045,登陆超时.c_str() },
{ 1046,你在别处已经登陆被迫登出.c_str() },
{ 1047,已经登陆.c_str() },
{ 1048,你需要登陆才可以访问.c_str() },
{ 1049,没有登录或登录已超时.c_str() },
{ 1050,密保不能少于要求字符.c_str() },
{ 1051,密保信息未填写.c_str() },
{ 1052,充值账号不能为空.c_str() },
{ 1053,充值卡号不能为空.c_str() },
{ 1054,充值卡密码不能为空.c_str() },
{ 1055,充值账号不能包含空格.c_str() },
{ 1056,充值卡号不能包含空格.c_str() },
{ 1057,充值卡密码不能包含空格.c_str() },
{ 1058,充值卡号或充值卡密码错误.c_str() },
{ 1059,充值的用户账号不存在.c_str() },
{ 1060,充值卡账号密码错误或者不存在.c_str() },
{ 1061,用户没有使用过要充值软件.c_str() },
{ 1062,激活成功赶快去使用吧.c_str() },
{ 1063,充值失败.c_str() },
{ 1064,充值卡已经充值过了.c_str() },
{ 1065,你留言和反馈我们已经收到.c_str() },
{ 1066,提交留言失败.c_str() },
{ 1067,请输入标题.c_str() },
{ 1068,请输入留言内容.c_str() },
{ 1069,激活成功.c_str() },
{ 1070,添加失败.c_str() },
{ 1071,糟糕激活码已经存在了.c_str() },
{ 1072,还没有存在.c_str() },
{ 1073,激活码不存在.c_str() },
{ 1074,你使用激活串已到期作废.c_str() },
{ 1075,激活码已经存在.c_str() },
{ 1076,执行错误.c_str() },
{ 1077,请检查激活码号或者密码错误.c_str() },
{ 1078,你使用权已经被冻结.c_str() },
{ 1079,验证失败.c_str() },
{ 1080,验证成功.c_str() },
{ 1081,登录验证成功.c_str() },
{ 1082,你的使用期已到.c_str() },
{ 1083,没有查询到用户信息.c_str() },
{ 1084,该用户不是使用本软件的.c_str() },
{ 1085,用户名已经被冻结.c_str() },
{ 1086,激活码被冻结.c_str() },
{ 1087,帐号已经到期请充值再使用.c_str() },
{ 1088,请输入一个邮箱作为你的帐号.c_str() },
{ 1089,恭喜你注册成功.c_str() },
{ 1090,密保邮箱不能为空.c_str() },
{ 1091,密保邮箱格式不正确.c_str() },
{ 1092,QQ号不能为空.c_str() },
{ 1093,QQ号格式输入不正确.c_str() },
{ 1094,你的帐号还没激活.c_str() },
{ 1095,请输入你联系方式.c_str() },
{ 1096,账号余额不足.c_str() },
{ 1097,账号余额不足.c_str() },
{ 1098,执行扣点成功.c_str() },
{ 1099,执行扣点失败.c_str() },
{ 1100,扣除金额不能为零或小于零.c_str() },
{ 1101,记录日志标题不可为空.c_str() },
{ 1102,用户数已经达最大限制.c_str() },
{ 1103,账号格式错误.c_str() },
{ 1104,账号格式错误.c_str() },
{ 1105,当前账号包含禁止关键字.c_str() },
{ 1106,手机号码不能为空.c_str() },
{ 1107,账号注册成功.c_str() },
{ 1108,账号注册成功.c_str() },
{ 1109,找回的账号错误.c_str() },
{ 1110,已经关闭账号注册.c_str() },
{ 1111,注册账号过于频繁.c_str() },
{ 1112,充值失败.c_str() },
{ 1113,激活码与软件不相符.c_str() },
{ 1114,模式不符合请选择对应软件使用.c_str() },
{ 1115,激活码不能为空.c_str() },
{ 1116,注销成功.c_str() },
{ 1117,注销失败.c_str() },
{ 1118,代理商账号.c_str() },
{ 1119,接口调用失败.c_str() },
{ 1120,当前账号禁止修改密码.c_str() },
{ 1121,用户关联账户不存在.c_str() },
{ 1122,激活成功.c_str() },
{ 1123,激活邮件已经发送.c_str() },
{ 1124,邮件发送失败.c_str() },
{ 1125,注册账号已经锁定.c_str() },
{ 1126,重置密码邮件已经发出.c_str() },
{ 1127,当前邮箱已经注册过.c_str() },
{ 1128,邀请人不存在.c_str() },
{ 1129,邀请人不能为空.c_str() },
{ 1130,邀请人不能为空.c_str() },
{ 1131,系统超出授权最大限制.c_str() },
{ 1132,充值账号已经被冻结.c_str() },
{ 1133,修改密码账户不存在.c_str() },
{ 1134,修改密码账户没有绑定邮箱.c_str() },
{ 1135,无法检索到您激活码信息有误.c_str() },
{ 1136,请到对应软件下使用.c_str() },
{ 1137,到对应软件下使用并充值.c_str() },
{ 1138,输入的激活码不存在.c_str() },
{ 1139,输入的卡模式激活码.c_str() },
{ 1140,输入的充值卡为登陆模式使用.c_str() },
{ 1141,充值卡不存在.c_str() },
{ 5000,无法接收到数据包.c_str() },
{ 5001,无法接收到数据包.c_str() },
{ 5002,数据包内出现系统屏蔽字符串.c_str() },
{ 5003,请将系统时间设置为北京时间.c_str() },
{ 5004,接口不存在连接失败.c_str() },
{ 5005,访问软件不存在.c_str() },
{ 5006,软件验证失败请重新下载.c_str() },
{ 5007,非法的请求身份验证失败.c_str() },
{ 5008,欢迎你首次使用请重新登陆.c_str() },
{ 5009,特征码已经有人绑定过了.c_str() },
{ 5010,特征码已经有人绑定过了.c_str() },
{ 5011,特征码已经有人绑定过了.c_str() },
{ 5012,特征码已经有人绑定过了.c_str() },
{ 5013,绑定成功.c_str() },
{ 5014,绑定失败.c_str() },
{ 5015,绑定特征不能为空.c_str() },
{ 5016,已经绑定了不需要再绑定.c_str() },
{ 5017,使用软件登录模式不相符.c_str() },
{ 5018,卡密受限制无法登录.c_str() },
{ 5019,解除绑定将受限制无法解除绑定.c_str() },
{ 5020,解除绑定失败.c_str() },
{ 5021,解除绑定成功.c_str() },
{ 5022,已经是解除绑定状态.c_str() },
{ 5023,绑定不能为空.c_str() },
{ 5024,绑定成功.c_str() },
{ 5025,绑定失败.c_str() },
{ 5026,账号登录超时.c_str() },
{ 5027,登录状态更新失败.c_str() },
{ 5028,登录状态更新成功.c_str() },
{ 5029,帐号没有到期.c_str() },
{ 5030,登录帐号已经到期.c_str() },
{ 5031,执行正常.c_str() },
{ 5032,扣点模式之扣点执行失败.c_str() },
{ 5033,无法获取重要的验证数据.c_str() },
{ 5034,请重新绑定后使用.c_str() },
{ 5035,请重新绑定后使用.c_str() },
{ 5036,执行正常扣点API调用被动.c_str() },
{ 5037,登录模式计点模式扣点执行正常.c_str() },
{ 5038,登录模式计点模式扣点执行失败.c_str() },
{ 5039,扣点点数不能小于或者等于0.c_str() },
{ 5040,模式不匹配.c_str() },
{ 5041,软件非扣点模式.c_str() },
{ 5042,使用软件不属于卡串计时扣点模式.c_str() },
{ 5043,模式不匹配.c_str() },
{ 5044,点数不足.c_str() },
{ 5045,模式不匹配.c_str() },
{ 5046,模式不匹配.c_str() },
{ 5047,登录限制验证通过登录继续.c_str() },
{ 5048,在线使用数量已经达到上限.c_str() },
{ 5049,在线使用数量已经达到上限.c_str() },
{ 5050,在线使用数量已经达到上限.c_str() },
{ 5051,机器标记没有不可空.c_str() },
{ 5052,签名验证失败.c_str() },
{ 5053,签名参数不能为空.c_str() },
{ 5054,无法识别的通信方式.c_str() },
{ 5055,激活码被冻结禁止.c_str() },
{ 5056,多开控制无法获取用户信息.c_str() },
{ 7000,绑定不能空.c_str() },
{ 7001,系统没有开启邮件功能.c_str() },
{ 7002,账号没有设置邮箱信息.c_str() },
{ 7003,输入邮箱跟已设置邮箱不符合.c_str() },
{ 7004,找回账号不存在.c_str() },
{ 7005,该账号没有设置邮箱发件失败.c_str() },
{ 7006,邮件已经发出.c_str() },
{ 7007,系统邮件失败.c_str() },
{ 7008,请输入充值卡号.c_str() },
{ 7009,请输入要获取数据类型.c_str() },
{ 7010,已经是解除绑定了.c_str() },
{ 7011,解除绑定拒绝.c_str() },
{ 7012,解除绑定成功.c_str() },
{ 7013,解除绑定失败.c_str() },
{ 7014,已被强制解绑.c_str() },
{ 7015,请输入激活码.c_str() },
{ 7016,请输入账号.c_str() },
{ 7017,请输入密码.c_str() },
{ 7018,注册新用户失败.c_str() },
{ 7019,账号被冻结禁止.c_str() },
{ 7020,还没有绑定请绑定在登录.c_str() },
{ 7021,充值账号不存在.c_str() },
{ 7022,充值卡错误或者不存在.c_str() },
{ 7023,充值卡已经冻结.c_str() },
{ 7024,充值卡已经充值作废.c_str() },
{ 7025,充值成功.c_str() },
{ 7026,充值失败.c_str() },
{ 7027,推荐人错误没有请不要填写.c_str() },
{ 7028,激活码无效或者错误.c_str() },
{ 7029,请再次输入密码.c_str() },
{ 7030,请输入密保.c_str() },
{ 7031,请输入答案.c_str() },
{ 9908,使用已经到期.c_str() }
};

void 写出菜单文字功能(const char* Language)
{
    //根节点
    Json::Value root;

    //root["MENU00001"] = Json::Value(脚本::主菜单);
    root["LOGIN0001"] = Json::Value(纳扎尔夫人数据获取失败);
    root["LOGIN0002"] = Json::Value(收藏家数据获取失败);
    root["LOGIN0003"] = Json::Value(创建配置文件失败);
    root["LOGIN0004"] = Json::Value(保存默认线路成功);
    root["LOGIN0005"] = Json::Value(获取云数据完成);
    root["LOGIN0006"] = Json::Value(获取云数据失败);
    root["LOGIN0007"] = Json::Value(正在获取云数据);
    root["LOGIN0008"] = Json::Value(网络链接成功);
    root["LOGIN0009"] = Json::Value(辅助加载失败);
    root["LOGIN0010"] = Json::Value(辅助加载完成);
    root["LOGIN0011"] = Json::Value(注册账号建议长度位数);
    root["LOGIN0012"] = Json::Value(注册密码建议长度位数);
    root["LOGIN0013"] = Json::Value(填写购买的卡号);
    root["LOGIN0014"] = Json::Value(填写购买的卡密);
    root["LOGIN0015"] = Json::Value(账号长度限制位数);
    root["LOGIN0016"] = Json::Value(密码长度限制位数);
    root["LOGIN0017"] = Json::Value(编辑框不能为空);
    root["LOGIN0018"] = Json::Value(获取游戏信息失败);
    root["LOGIN0019"] = Json::Value(未检测到游戏程序);
    root["LOGIN0020"] = Json::Value(请勿重复点击按钮);
    root["LOGIN0021"] = Json::Value(这里填写会员账号);
    root["LOGIN0022"] = Json::Value(这里填写会员密码);
    root["LOGIN0023"] = Json::Value(用户信息不能为空);
    root["LOGIN0024"] = Json::Value(保存为默认线路);
    root["LOGIN0025"] = Json::Value(清理云缓存文件);
    root["LOGIN0026"] = Json::Value(当获取云数据失败时清理);
    root["LOGIN0027"] = Json::Value(已清理请重新打开登陆器);
    root["LOGIN0028"] = Json::Value(账号);
    root["LOGIN0029"] = Json::Value(密码);
    root["LOGIN0030"] = Json::Value(卡号);
    root["LOGIN0031"] = Json::Value(卡密);
    root["LOGIN0032"] = Json::Value(确定注册);
    root["LOGIN0033"] = Json::Value(注册成功);
    root["LOGIN0034"] = Json::Value(重新绑定);
    root["LOGIN0035"] = Json::Value(用户登录);
    root["LOGIN0036"] = Json::Value(账号登录);
    root["LOGIN0037"] = Json::Value(会员注册);
    root["LOGIN0038"] = Json::Value(常规设置);
    root["LOGIN0039"] = Json::Value(设置线路);
    root["LOGIN0040"] = Json::Value(线路一);
    root["LOGIN0041"] = Json::Value(线路二);
    root["LOGIN0042"] = Json::Value(提示文本信息);
    root["LOGIN0043"] = Json::Value(用户名已存在);
    root["LOGIN0044"] = Json::Value(用户名可以用);
    root["LOGIN0045"] = Json::Value(密码验证错误);
    root["LOGIN0046"] = Json::Value(账号长度受限);
    root["LOGIN0047"] = Json::Value(账号格式错误);
    root["LOGIN0048"] = Json::Value(注册失败);
    root["LOGIN0049"] = Json::Value(密码长度受限);
    root["LOGIN0050"] = Json::Value(账号错误);
    root["LOGIN0051"] = Json::Value(密码错误);
    root["LOGIN0052"] = Json::Value(用户名不存在);
    root["LOGIN0053"] = Json::Value(登陆成功);
    root["LOGIN0054"] = Json::Value(登陆失败);
    root["LOGIN0055"] = Json::Value(QQ号错误);
    root["LOGIN0056"] = Json::Value(邮箱错误);
    root["LOGIN0057"] = Json::Value(手机号码错误);
    root["LOGIN0058"] = Json::Value(保存成功);
    root["LOGIN0059"] = Json::Value(保存失败);
    root["LOGIN0060"] = Json::Value(不能输入空格);
    root["LOGIN0061"] = Json::Value(请输入密保问题);
    root["LOGIN0062"] = Json::Value(用户名被冻结了);
    root["LOGIN0063"] = Json::Value(记录查询失败);
    root["LOGIN0064"] = Json::Value(你的密保信息已经填写);
    root["LOGIN0065"] = Json::Value(密保信息添加成功);
    root["LOGIN0066"] = Json::Value(密保添加失败);
    root["LOGIN0067"] = Json::Value(密码不可以空格);
    root["LOGIN0068"] = Json::Value(请输入旧密码);
    root["LOGIN0069"] = Json::Value(旧密码不能和新密码一致);
    root["LOGIN0070"] = Json::Value(密码修改失败);
    root["LOGIN0071"] = Json::Value(旧密码不正确);
    root["LOGIN0072"] = Json::Value(密码修改成功);
    root["LOGIN0073"] = Json::Value(表单信息不能为空);
    root["LOGIN0074"] = Json::Value(密码已经成功通过密保信息修改);
    root["LOGIN0075"] = Json::Value(密保信息错误);
    root["LOGIN0076"] = Json::Value(密码找回失败);
    root["LOGIN0077"] = Json::Value(验证码不能为空);
    root["LOGIN0078"] = Json::Value(验证码正确);
    root["LOGIN0079"] = Json::Value(验证码错误);
    root["LOGIN0080"] = Json::Value(用户名不能为空);
    root["LOGIN0081"] = Json::Value(用户名不能含空格);
    root["LOGIN0082"] = Json::Value(长时空闲超时执行正常);
    root["LOGIN0083"] = Json::Value(长时空闲超时执行异常);
    root["LOGIN0084"] = Json::Value(用户名被冻结登陆);
    root["LOGIN0085"] = Json::Value(登陆超时);
    root["LOGIN0086"] = Json::Value(你在别处已经登陆被迫登出);
    root["LOGIN0087"] = Json::Value(已经登陆);
    root["LOGIN0088"] = Json::Value(你需要登陆才可以访问);
    root["LOGIN0089"] = Json::Value(没有登录或登录已超时);
    root["LOGIN0090"] = Json::Value(密保不能少于要求字符);
    root["LOGIN0091"] = Json::Value(密保信息未填写);
    root["LOGIN0092"] = Json::Value(充值账号不能为空);
    root["LOGIN0093"] = Json::Value(充值卡号不能为空);
    root["LOGIN0094"] = Json::Value(充值卡密码不能为空);
    root["LOGIN0095"] = Json::Value(充值账号不能包含空格);
    root["LOGIN0096"] = Json::Value(充值卡号不能包含空格);
    root["LOGIN0097"] = Json::Value(充值卡密码不能包含空格);
    root["LOGIN0098"] = Json::Value(充值卡号或充值卡密码错误);
    root["LOGIN0099"] = Json::Value(充值的用户账号不存在);
    root["LOGIN0100"] = Json::Value(充值卡账号密码错误或者不存在);
    root["LOGIN0101"] = Json::Value(用户没有使用过要充值软件);
    root["LOGIN0102"] = Json::Value(激活成功赶快去使用吧);
    root["LOGIN0103"] = Json::Value(充值失败);
    root["LOGIN0104"] = Json::Value(充值卡已经充值过了);
    root["LOGIN0105"] = Json::Value(你留言和反馈我们已经收到);
    root["LOGIN0106"] = Json::Value(提交留言失败);
    root["LOGIN0107"] = Json::Value(请输入标题);
    root["LOGIN0108"] = Json::Value(请输入留言内容);
    root["LOGIN0109"] = Json::Value(激活成功);
    root["LOGIN0110"] = Json::Value(添加失败);
    root["LOGIN0111"] = Json::Value(糟糕激活码已经存在了);
    root["LOGIN0112"] = Json::Value(还没有存在);
    root["LOGIN0113"] = Json::Value(激活码不存在);
    root["LOGIN0114"] = Json::Value(你使用激活串已到期作废);
    root["LOGIN0115"] = Json::Value(激活码已经存在);
    root["LOGIN0116"] = Json::Value(执行错误);
    root["LOGIN0117"] = Json::Value(请检查激活码号或者密码错误);
    root["LOGIN0118"] = Json::Value(你使用权已经被冻结);
    root["LOGIN0119"] = Json::Value(验证失败);
    root["LOGIN0120"] = Json::Value(验证成功);
    root["LOGIN0121"] = Json::Value(登录验证成功);
    root["LOGIN0122"] = Json::Value(你的使用期已到);
    root["LOGIN0123"] = Json::Value(没有查询到用户信息);
    root["LOGIN0124"] = Json::Value(该用户不是使用本软件的);
    root["LOGIN0125"] = Json::Value(用户名已经被冻结);
    root["LOGIN0126"] = Json::Value(激活码被冻结);
    root["LOGIN0127"] = Json::Value(帐号已经到期请充值再使用);
    root["LOGIN0128"] = Json::Value(请输入一个邮箱作为你的帐号);
    root["LOGIN0129"] = Json::Value(恭喜你注册成功);
    root["LOGIN0130"] = Json::Value(密保邮箱不能为空);
    root["LOGIN0131"] = Json::Value(密保邮箱格式不正确);
    root["LOGIN0132"] = Json::Value(QQ号不能为空);
    root["LOGIN0133"] = Json::Value(QQ号格式输入不正确);
    root["LOGIN0134"] = Json::Value(你的帐号还没激活);
    root["LOGIN0135"] = Json::Value(请输入你联系方式);
    root["LOGIN0136"] = Json::Value(账号余额不足);
    root["LOGIN0137"] = Json::Value(执行扣点成功);
    root["LOGIN0138"] = Json::Value(执行扣点失败);
    root["LOGIN0139"] = Json::Value(扣除金额不能为零或小于零);
    root["LOGIN0140"] = Json::Value(记录日志标题不可为空);
    root["LOGIN0141"] = Json::Value(用户数已经达最大限制);
    root["LOGIN0142"] = Json::Value(当前账号包含禁止关键字);
    root["LOGIN0143"] = Json::Value(手机号码不能为空);
    root["LOGIN0144"] = Json::Value(账号注册成功);
    root["LOGIN0145"] = Json::Value(找回的账号错误);
    root["LOGIN0146"] = Json::Value(已经关闭账号注册);
    root["LOGIN0147"] = Json::Value(注册账号过于频繁);
    root["LOGIN0148"] = Json::Value(激活码与软件不相符);
    root["LOGIN0149"] = Json::Value(模式不符合请选择对应软件使用);
    root["LOGIN0150"] = Json::Value(激活码不能为空);
    root["LOGIN0151"] = Json::Value(注销成功);
    root["LOGIN0152"] = Json::Value(注销失败);
    root["LOGIN0153"] = Json::Value(代理商账号);
    root["LOGIN0154"] = Json::Value(接口调用失败);
    root["LOGIN0155"] = Json::Value(当前账号禁止修改密码);
    root["LOGIN0156"] = Json::Value(用户关联账户不存在);
    root["LOGIN0157"] = Json::Value(激活邮件已经发送);
    root["LOGIN0158"] = Json::Value(邮件发送失败);
    root["LOGIN0159"] = Json::Value(注册账号已经锁定);
    root["LOGIN0160"] = Json::Value(重置密码邮件已经发出);
    root["LOGIN0161"] = Json::Value(当前邮箱已经注册过);
    root["LOGIN0162"] = Json::Value(邀请人不存在);
    root["LOGIN0163"] = Json::Value(邀请人不能为空);
    root["LOGIN0164"] = Json::Value(系统超出授权最大限制);
    root["LOGIN0165"] = Json::Value(充值账号已经被冻结);
    root["LOGIN0166"] = Json::Value(修改密码账户不存在);
    root["LOGIN0167"] = Json::Value(修改密码账户没有绑定邮箱);
    root["LOGIN0168"] = Json::Value(无法检索到您激活码信息有误);
    root["LOGIN0169"] = Json::Value(请到对应软件下使用);
    root["LOGIN0170"] = Json::Value(到对应软件下使用并充值);
    root["LOGIN0171"] = Json::Value(输入的激活码不存在);
    root["LOGIN0172"] = Json::Value(输入的卡模式激活码);
    root["LOGIN0173"] = Json::Value(输入的充值卡为登陆模式使用);
    root["LOGIN0174"] = Json::Value(充值卡不存在);
    root["LOGIN0175"] = Json::Value(无法接收到数据包);
    root["LOGIN0176"] = Json::Value(数据包内出现系统屏蔽字符串);
    root["LOGIN0177"] = Json::Value(请将系统时间设置为北京时间);
    root["LOGIN0178"] = Json::Value(接口不存在连接失败);
    root["LOGIN0179"] = Json::Value(访问软件不存在);
    root["LOGIN0180"] = Json::Value(软件验证失败请重新下载);
    root["LOGIN0181"] = Json::Value(非法的请求身份验证失败);
    root["LOGIN0182"] = Json::Value(欢迎你首次使用请重新登陆);
    root["LOGIN0183"] = Json::Value(特征码已经有人绑定过了);
    root["LOGIN0184"] = Json::Value(绑定成功);
    root["LOGIN0185"] = Json::Value(绑定失败);
    root["LOGIN0186"] = Json::Value(绑定特征不能为空);
    root["LOGIN0187"] = Json::Value(已经绑定了不需要再绑定);
    root["LOGIN0188"] = Json::Value(使用软件登录模式不相符);
    root["LOGIN0189"] = Json::Value(卡密受限制无法登录);
    root["LOGIN0190"] = Json::Value(解除绑定将受限制无法解除绑定);
    root["LOGIN0191"] = Json::Value(解除绑定失败);
    root["LOGIN0192"] = Json::Value(解除绑定成功);
    root["LOGIN0193"] = Json::Value(已经是解除绑定状态);
    root["LOGIN0194"] = Json::Value(绑定不能为空);
    root["LOGIN0195"] = Json::Value(账号登录超时);
    root["LOGIN0196"] = Json::Value(登录状态更新失败);
    root["LOGIN0197"] = Json::Value(登录状态更新成功);
    root["LOGIN0198"] = Json::Value(帐号没有到期);
    root["LOGIN0199"] = Json::Value(登录帐号已经到期);
    root["LOGIN0200"] = Json::Value(执行正常);
    root["LOGIN0201"] = Json::Value(扣点模式之扣点执行失败);
    root["LOGIN0202"] = Json::Value(无法获取重要的验证数据);
    root["LOGIN0203"] = Json::Value(请重新绑定后使用);
    root["LOGIN0204"] = Json::Value(执行正常扣点API调用被动);
    root["LOGIN0205"] = Json::Value(登录模式计点模式扣点执行正常);
    root["LOGIN0206"] = Json::Value(登录模式计点模式扣点执行失败);
    root["LOGIN0207"] = Json::Value(扣点点数不能小于或者等于0);
    root["LOGIN0208"] = Json::Value(模式不匹配);
    root["LOGIN0209"] = Json::Value(软件非扣点模式);
    root["LOGIN0210"] = Json::Value(使用软件不属于卡串计时扣点模式);
    root["LOGIN0211"] = Json::Value(点数不足);
    root["LOGIN0212"] = Json::Value(登录限制验证通过登录继续);
    root["LOGIN0213"] = Json::Value(在线使用数量已经达到上限);
    root["LOGIN0214"] = Json::Value(机器标记没有不可空);
    root["LOGIN0215"] = Json::Value(签名验证失败);
    root["LOGIN0216"] = Json::Value(签名参数不能为空);
    root["LOGIN0217"] = Json::Value(无法识别的通信方式);
    root["LOGIN0218"] = Json::Value(激活码被冻结禁止);
    root["LOGIN0219"] = Json::Value(多开控制无法获取用户信息);
    root["LOGIN0220"] = Json::Value(绑定不能空);
    root["LOGIN0221"] = Json::Value(系统没有开启邮件功能);
    root["LOGIN0222"] = Json::Value(账号没有设置邮箱信息);
    root["LOGIN0223"] = Json::Value(输入邮箱跟已设置邮箱不符合);
    root["LOGIN0224"] = Json::Value(找回账号不存在);
    root["LOGIN0225"] = Json::Value(该账号没有设置邮箱发件失败);
    root["LOGIN0226"] = Json::Value(邮件已经发出);
    root["LOGIN0227"] = Json::Value(系统邮件失败);
    root["LOGIN0228"] = Json::Value(请输入充值卡号);
    root["LOGIN0229"] = Json::Value(请输入要获取数据类型);
    root["LOGIN0230"] = Json::Value(已经是解除绑定了);
    root["LOGIN0231"] = Json::Value(解除绑定拒绝);
    root["LOGIN0232"] = Json::Value(已被强制解绑);
    root["LOGIN0233"] = Json::Value(请输入激活码);
    root["LOGIN0234"] = Json::Value(请输入账号);
    root["LOGIN0235"] = Json::Value(请输入密码);
    root["LOGIN0236"] = Json::Value(注册新用户失败);
    root["LOGIN0237"] = Json::Value(账号被冻结禁止);
    root["LOGIN0238"] = Json::Value(还没有绑定请绑定在登录);
    root["LOGIN0239"] = Json::Value(充值账号不存在);
    root["LOGIN0240"] = Json::Value(充值卡错误或者不存在);
    root["LOGIN0241"] = Json::Value(充值卡已经冻结);
    root["LOGIN0242"] = Json::Value(充值卡已经充值作废);
    root["LOGIN0243"] = Json::Value(充值成功);
    root["LOGIN0244"] = Json::Value(推荐人错误没有请不要填写);
    root["LOGIN0245"] = Json::Value(激活码无效或者错误);
    root["LOGIN0246"] = Json::Value(请再次输入密码);
    root["LOGIN0247"] = Json::Value(请输入密保);
    root["LOGIN0248"] = Json::Value(请输入答案);
    root["LOGIN0249"] = Json::Value(使用已经到期);
    root["LOGIN0250"] = Json::Value(修改密码);
    root["LOGIN0251"] = Json::Value(邮箱);
    root["LOGIN0252"] = Json::Value(新密码);
    root["LOGIN0253"] = Json::Value(确认密码);

    //缩进输出
    Json::StyledWriter sw;

    ofstream os;
    //os.open(ss.str().c_str(), std::ios::out | std::ios::app);不清楚原文件
    os.open(Language, std::ios::out | std::ios::trunc);//清除原文件
    if (!os.is_open())
    {
        提示文本信息 = "error：can not find or create";
    }
    os << sw.write(root);
    os.close();
}

void 读取菜单文字功能(const char* Language)
{
    Json::Reader reader;
    Json::Value root;
    ifstream ifs;

    ifs.open(Language);

    if (reader.parse(ifs, root))
    {
        //主菜单 = root["MENU00001"].asString();
        纳扎尔夫人数据获取失败 = root["LOGIN0001"].asString().c_str();
        收藏家数据获取失败 = root["LOGIN0002"].asString().c_str();
        创建配置文件失败 = root["LOGIN0003"].asString().c_str();
        保存默认线路成功 = root["LOGIN0004"].asString().c_str();
        获取云数据完成 = root["LOGIN0005"].asString().c_str();
        获取云数据失败 = root["LOGIN0006"].asString().c_str();
        正在获取云数据 = root["LOGIN0007"].asString().c_str();
        网络链接成功 = root["LOGIN0008"].asString().c_str();
        辅助加载失败 = root["LOGIN0009"].asString().c_str();
        辅助加载完成 = root["LOGIN0010"].asString().c_str();
        注册账号建议长度位数 = root["LOGIN0011"].asString().c_str();
        注册密码建议长度位数 = root["LOGIN0012"].asString().c_str();
        填写购买的卡号 = root["LOGIN0013"].asString().c_str();
        填写购买的卡密 = root["LOGIN0014"].asString().c_str();
        账号长度限制位数 = root["LOGIN0015"].asString().c_str();
        密码长度限制位数 = root["LOGIN0016"].asString().c_str();
        编辑框不能为空 = root["LOGIN0017"].asString().c_str();
        获取游戏信息失败 = root["LOGIN0018"].asString().c_str();
        未检测到游戏程序 = root["LOGIN0019"].asString().c_str();
        请勿重复点击按钮 = root["LOGIN0020"].asString().c_str();
        这里填写会员账号 = root["LOGIN0021"].asString().c_str();
        这里填写会员密码 = root["LOGIN0022"].asString().c_str();
        用户信息不能为空 = root["LOGIN0023"].asString().c_str();
        保存为默认线路 = root["LOGIN0024"].asString().c_str();
        清理云缓存文件 = root["LOGIN0025"].asString().c_str();
        当获取云数据失败时清理 = root["LOGIN0026"].asString().c_str();
        已清理请重新打开登陆器 = root["LOGIN0027"].asString().c_str();
        账号 = root["LOGIN0028"].asString().c_str();
        密码 = root["LOGIN0029"].asString().c_str();
        卡号 = root["LOGIN0030"].asString().c_str();
        卡密 = root["LOGIN0031"].asString().c_str();
        确定注册 = root["LOGIN0032"].asString().c_str();
        注册成功 = root["LOGIN0033"].asString().c_str();
        重新绑定 = root["LOGIN0034"].asString().c_str();
        用户登录 = root["LOGIN0035"].asString().c_str();
        账号登录 = root["LOGIN0036"].asString().c_str();
        会员注册 = root["LOGIN0037"].asString().c_str();
        常规设置 = root["LOGIN0038"].asString().c_str();
        设置线路 = root["LOGIN0039"].asString().c_str();
        线路一 = root["LOGIN0040"].asString().c_str();
        线路二 = root["LOGIN0041"].asString().c_str();
        提示文本信息 = root["LOGIN0042"].asString().c_str();
        用户名已存在 = root["LOGIN0043"].asString().c_str();
        用户名可以用 = root["LOGIN0044"].asString().c_str();
        密码验证错误 = root["LOGIN0045"].asString().c_str();
        账号长度受限 = root["LOGIN0046"].asString().c_str();
        账号格式错误 = root["LOGIN0047"].asString().c_str();
        注册失败 = root["LOGIN0048"].asString().c_str();
        密码长度受限 = root["LOGIN0049"].asString().c_str();
        账号错误 = root["LOGIN0050"].asString().c_str();
        密码错误 = root["LOGIN0051"].asString().c_str();
        用户名不存在 = root["LOGIN0052"].asString().c_str();
        登陆成功 = root["LOGIN0053"].asString().c_str();
        登陆失败 = root["LOGIN0054"].asString().c_str();
        QQ号错误 = root["LOGIN0055"].asString().c_str();
        邮箱错误 = root["LOGIN0056"].asString().c_str();
        手机号码错误 = root["LOGIN0057"].asString().c_str();
        保存成功 = root["LOGIN0058"].asString().c_str();
        保存失败 = root["LOGIN0059"].asString().c_str();
        不能输入空格 = root["LOGIN0060"].asString().c_str();
        请输入密保问题 = root["LOGIN0061"].asString().c_str();
        用户名被冻结了 = root["LOGIN0062"].asString().c_str();
        记录查询失败 = root["LOGIN0063"].asString().c_str();
        你的密保信息已经填写 = root["LOGIN0064"].asString().c_str();
        密保信息添加成功 = root["LOGIN0065"].asString().c_str();
        密保添加失败 = root["LOGIN0066"].asString().c_str();
        密码不可以空格 = root["LOGIN0067"].asString().c_str();
        请输入旧密码 = root["LOGIN0068"].asString().c_str();
        旧密码不能和新密码一致 = root["LOGIN0069"].asString().c_str();
        密码修改失败 = root["LOGIN0070"].asString().c_str();
        旧密码不正确 = root["LOGIN0071"].asString().c_str();
        密码修改成功 = root["LOGIN0072"].asString().c_str();
        表单信息不能为空 = root["LOGIN0073"].asString().c_str();
        密码已经成功通过密保信息修改 = root["LOGIN0074"].asString().c_str();
        密保信息错误 = root["LOGIN0075"].asString().c_str();
        密码找回失败 = root["LOGIN0076"].asString().c_str();
        验证码不能为空 = root["LOGIN0077"].asString().c_str();
        验证码正确 = root["LOGIN0078"].asString().c_str();
        验证码错误 = root["LOGIN0079"].asString().c_str();
        用户名不能为空 = root["LOGIN0080"].asString().c_str();
        用户名不能含空格 = root["LOGIN0081"].asString().c_str();
        长时空闲超时执行正常 = root["LOGIN0082"].asString().c_str();
        长时空闲超时执行异常 = root["LOGIN0083"].asString().c_str();
        用户名被冻结登陆 = root["LOGIN0084"].asString().c_str();
        登陆超时 = root["LOGIN0085"].asString().c_str();
        你在别处已经登陆被迫登出 = root["LOGIN0086"].asString().c_str();
        已经登陆 = root["LOGIN0087"].asString().c_str();
        你需要登陆才可以访问 = root["LOGIN0088"].asString().c_str();
        没有登录或登录已超时 = root["LOGIN0089"].asString().c_str();
        密保不能少于要求字符 = root["LOGIN0090"].asString().c_str();
        密保信息未填写 = root["LOGIN0091"].asString().c_str();
        充值账号不能为空 = root["LOGIN0092"].asString().c_str();
        充值卡号不能为空 = root["LOGIN0093"].asString().c_str();
        充值卡密码不能为空 = root["LOGIN0094"].asString().c_str();
        充值账号不能包含空格 = root["LOGIN0095"].asString().c_str();
        充值卡号不能包含空格 = root["LOGIN0096"].asString().c_str();
        充值卡密码不能包含空格 = root["LOGIN0097"].asString().c_str();
        充值卡号或充值卡密码错误 = root["LOGIN0098"].asString().c_str();
        充值的用户账号不存在 = root["LOGIN0099"].asString().c_str();
        充值卡账号密码错误或者不存在 = root["LOGIN0100"].asString().c_str();
        用户没有使用过要充值软件 = root["LOGIN0101"].asString().c_str();
        激活成功赶快去使用吧 = root["LOGIN0102"].asString().c_str();
        充值失败 = root["LOGIN0103"].asString().c_str();
        充值卡已经充值过了 = root["LOGIN0104"].asString().c_str();
        你留言和反馈我们已经收到 = root["LOGIN0105"].asString().c_str();
        提交留言失败 = root["LOGIN0106"].asString().c_str();
        请输入标题 = root["LOGIN0107"].asString().c_str();
        请输入留言内容 = root["LOGIN0108"].asString().c_str();
        激活成功 = root["LOGIN0109"].asString().c_str();
        添加失败 = root["LOGIN0110"].asString().c_str();
        糟糕激活码已经存在了 = root["LOGIN0111"].asString().c_str();
        还没有存在 = root["LOGIN0112"].asString().c_str();
        激活码不存在 = root["LOGIN0113"].asString().c_str();
        你使用激活串已到期作废 = root["LOGIN0114"].asString().c_str();
        激活码已经存在 = root["LOGIN0115"].asString().c_str();
        执行错误 = root["LOGIN0116"].asString().c_str();
        请检查激活码号或者密码错误 = root["LOGIN0117"].asString().c_str();
        你使用权已经被冻结 = root["LOGIN0118"].asString().c_str();
        验证失败 = root["LOGIN0119"].asString().c_str();
        验证成功 = root["LOGIN0120"].asString().c_str();
        登录验证成功 = root["LOGIN0121"].asString().c_str();
        你的使用期已到 = root["LOGIN0122"].asString().c_str();
        没有查询到用户信息 = root["LOGIN0123"].asString().c_str();
        该用户不是使用本软件的 = root["LOGIN0124"].asString().c_str();
        用户名已经被冻结 = root["LOGIN0125"].asString().c_str();
        激活码被冻结 = root["LOGIN0126"].asString().c_str();
        帐号已经到期请充值再使用 = root["LOGIN0127"].asString().c_str();
        请输入一个邮箱作为你的帐号 = root["LOGIN0128"].asString().c_str();
        恭喜你注册成功 = root["LOGIN0129"].asString().c_str();
        密保邮箱不能为空 = root["LOGIN0130"].asString().c_str();
        密保邮箱格式不正确 = root["LOGIN0131"].asString().c_str();
        QQ号不能为空 = root["LOGIN0132"].asString().c_str();
        QQ号格式输入不正确 = root["LOGIN0133"].asString().c_str();
        你的帐号还没激活 = root["LOGIN0134"].asString().c_str();
        请输入你联系方式 = root["LOGIN0135"].asString().c_str();
        账号余额不足 = root["LOGIN0136"].asString().c_str();
        执行扣点成功 = root["LOGIN0137"].asString().c_str();
        执行扣点失败 = root["LOGIN0138"].asString().c_str();
        扣除金额不能为零或小于零 = root["LOGIN0139"].asString().c_str();
        记录日志标题不可为空 = root["LOGIN0140"].asString().c_str();
        用户数已经达最大限制 = root["LOGIN0141"].asString().c_str();
        当前账号包含禁止关键字 = root["LOGIN0142"].asString().c_str();
        手机号码不能为空 = root["LOGIN0143"].asString().c_str();
        账号注册成功 = root["LOGIN0144"].asString().c_str();
        找回的账号错误 = root["LOGIN0145"].asString().c_str();
        已经关闭账号注册 = root["LOGIN0146"].asString().c_str();
        注册账号过于频繁 = root["LOGIN0147"].asString().c_str();
        激活码与软件不相符 = root["LOGIN0148"].asString().c_str();
        模式不符合请选择对应软件使用 = root["LOGIN0149"].asString().c_str();
        激活码不能为空 = root["LOGIN0150"].asString().c_str();
        注销成功 = root["LOGIN0151"].asString().c_str();
        注销失败 = root["LOGIN0152"].asString().c_str();
        代理商账号 = root["LOGIN0153"].asString().c_str();
        接口调用失败 = root["LOGIN0154"].asString().c_str();
        当前账号禁止修改密码 = root["LOGIN0155"].asString().c_str();
        用户关联账户不存在 = root["LOGIN0156"].asString().c_str();
        激活邮件已经发送 = root["LOGIN0157"].asString().c_str();
        邮件发送失败 = root["LOGIN0158"].asString().c_str();
        注册账号已经锁定 = root["LOGIN0159"].asString().c_str();
        重置密码邮件已经发出 = root["LOGIN0160"].asString().c_str();
        当前邮箱已经注册过 = root["LOGIN0161"].asString().c_str();
        邀请人不存在 = root["LOGIN0162"].asString().c_str();
        邀请人不能为空 = root["LOGIN0163"].asString().c_str();
        系统超出授权最大限制 = root["LOGIN0164"].asString().c_str();
        充值账号已经被冻结 = root["LOGIN0165"].asString().c_str();
        修改密码账户不存在 = root["LOGIN0166"].asString().c_str();
        修改密码账户没有绑定邮箱 = root["LOGIN0167"].asString().c_str();
        无法检索到您激活码信息有误 = root["LOGIN0168"].asString().c_str();
        请到对应软件下使用 = root["LOGIN0169"].asString().c_str();
        到对应软件下使用并充值 = root["LOGIN0170"].asString().c_str();
        输入的激活码不存在 = root["LOGIN0171"].asString().c_str();
        输入的卡模式激活码 = root["LOGIN0172"].asString().c_str();
        输入的充值卡为登陆模式使用 = root["LOGIN0173"].asString().c_str();
        充值卡不存在 = root["LOGIN0174"].asString().c_str();
        无法接收到数据包 = root["LOGIN0175"].asString().c_str();
        数据包内出现系统屏蔽字符串 = root["LOGIN0176"].asString().c_str();
        请将系统时间设置为北京时间 = root["LOGIN0177"].asString().c_str();
        接口不存在连接失败 = root["LOGIN0178"].asString().c_str();
        访问软件不存在 = root["LOGIN0179"].asString().c_str();
        软件验证失败请重新下载 = root["LOGIN0180"].asString().c_str();
        非法的请求身份验证失败 = root["LOGIN0181"].asString().c_str();
        欢迎你首次使用请重新登陆 = root["LOGIN0182"].asString().c_str();
        特征码已经有人绑定过了 = root["LOGIN0183"].asString().c_str();
        绑定成功 = root["LOGIN0184"].asString().c_str();
        绑定失败 = root["LOGIN0185"].asString().c_str();
        绑定特征不能为空 = root["LOGIN0186"].asString().c_str();
        已经绑定了不需要再绑定 = root["LOGIN0187"].asString().c_str();
        使用软件登录模式不相符 = root["LOGIN0188"].asString().c_str();
        卡密受限制无法登录 = root["LOGIN0189"].asString().c_str();
        解除绑定将受限制无法解除绑定 = root["LOGIN0190"].asString().c_str();
        解除绑定失败 = root["LOGIN0191"].asString().c_str();
        解除绑定成功 = root["LOGIN0192"].asString().c_str();
        已经是解除绑定状态 = root["LOGIN0193"].asString().c_str();
        绑定不能为空 = root["LOGIN0194"].asString().c_str();
        账号登录超时 = root["LOGIN0195"].asString().c_str();
        登录状态更新失败 = root["LOGIN0196"].asString().c_str();
        登录状态更新成功 = root["LOGIN0197"].asString().c_str();
        帐号没有到期 = root["LOGIN0198"].asString().c_str();
        登录帐号已经到期 = root["LOGIN0199"].asString().c_str();
        执行正常 = root["LOGIN0200"].asString().c_str();
        扣点模式之扣点执行失败 = root["LOGIN0201"].asString().c_str();
        无法获取重要的验证数据 = root["LOGIN0202"].asString().c_str();
        请重新绑定后使用 = root["LOGIN0203"].asString().c_str();
        执行正常扣点API调用被动 = root["LOGIN0204"].asString().c_str();
        登录模式计点模式扣点执行正常 = root["LOGIN0205"].asString().c_str();
        登录模式计点模式扣点执行失败 = root["LOGIN0206"].asString().c_str();
        扣点点数不能小于或者等于0 = root["LOGIN0207"].asString().c_str();
        模式不匹配 = root["LOGIN0208"].asString().c_str();
        软件非扣点模式 = root["LOGIN0209"].asString().c_str();
        使用软件不属于卡串计时扣点模式 = root["LOGIN0210"].asString().c_str();
        点数不足 = root["LOGIN0211"].asString().c_str();
        登录限制验证通过登录继续 = root["LOGIN0212"].asString().c_str();
        在线使用数量已经达到上限 = root["LOGIN0213"].asString().c_str();
        机器标记没有不可空 = root["LOGIN0214"].asString().c_str();
        签名验证失败 = root["LOGIN0215"].asString().c_str();
        签名参数不能为空 = root["LOGIN0216"].asString().c_str();
        无法识别的通信方式 = root["LOGIN0217"].asString().c_str();
        激活码被冻结禁止 = root["LOGIN0218"].asString().c_str();
        多开控制无法获取用户信息 = root["LOGIN0219"].asString().c_str();
        绑定不能空 = root["LOGIN0220"].asString().c_str();
        系统没有开启邮件功能 = root["LOGIN0221"].asString().c_str();
        账号没有设置邮箱信息 = root["LOGIN0222"].asString().c_str();
        输入邮箱跟已设置邮箱不符合 = root["LOGIN0223"].asString().c_str();
        找回账号不存在 = root["LOGIN0224"].asString().c_str();
        该账号没有设置邮箱发件失败 = root["LOGIN0225"].asString().c_str();
        邮件已经发出 = root["LOGIN0226"].asString().c_str();
        系统邮件失败 = root["LOGIN0227"].asString().c_str();
        请输入充值卡号 = root["LOGIN0228"].asString().c_str();
        请输入要获取数据类型 = root["LOGIN0229"].asString().c_str();
        已经是解除绑定了 = root["LOGIN0230"].asString().c_str();
        解除绑定拒绝 = root["LOGIN0231"].asString().c_str();
        已被强制解绑 = root["LOGIN0232"].asString().c_str();
        请输入激活码 = root["LOGIN0233"].asString().c_str();
        请输入账号 = root["LOGIN0234"].asString().c_str();
        请输入密码 = root["LOGIN0235"].asString().c_str();
        注册新用户失败 = root["LOGIN0236"].asString().c_str();
        账号被冻结禁止 = root["LOGIN0237"].asString().c_str();
        还没有绑定请绑定在登录 = root["LOGIN0238"].asString().c_str();
        充值账号不存在 = root["LOGIN0239"].asString().c_str();
        充值卡错误或者不存在 = root["LOGIN0240"].asString().c_str();
        充值卡已经冻结 = root["LOGIN0241"].asString().c_str();
        充值卡已经充值作废 = root["LOGIN0242"].asString().c_str();
        充值成功 = root["LOGIN0243"].asString().c_str();
        推荐人错误没有请不要填写 = root["LOGIN0244"].asString().c_str();
        激活码无效或者错误 = root["LOGIN0245"].asString().c_str();
        请再次输入密码 = root["LOGIN0246"].asString().c_str();
        请输入密保 = root["LOGIN0247"].asString().c_str();
        请输入答案 = root["LOGIN0248"].asString().c_str();
        使用已经到期 = root["LOGIN0249"].asString().c_str();
        修改密码 = root["LOGIN0250"].asString().c_str();
        邮箱 = root["LOGIN0251"].asString().c_str();
        新密码 = root["LOGIN0252"].asString().c_str();
        确认密码 = root["LOGIN0253"].asString().c_str();
    }
}

class CChineseCode
{
public:
    static void UTF_8ToUnicode(wchar_t* pOut, char* pText);  // 把UTF-8转换成Unicode
    static void UnicodeToUTF_8(char* pOut, wchar_t* pText);  //Unicode 转换成UTF-8
    static void UnicodeToGB2312(char* pOut, wchar_t uData);  // 把Unicode 转换成 GB2312 
    static void Gb2312ToUnicode(wchar_t* pOut, char* gbBuffer);// GB2312 转换成　Unicode
    static void GB2312ToUTF_8(string& pOut, char* pText, int pLen);//GB2312 转为 UTF-8
    static void UTF_8ToGB2312(string& pOut, char* pText, int pLen);//UTF-8 转为 GB2312
};

void CChineseCode::UTF_8ToUnicode(wchar_t* pOut, char* pText)
{
    char* uchar = (char*)pOut;

    uchar[1] = ((pText[0] & 0x0F) << 4) + ((pText[1] >> 2) & 0x0F);
    uchar[0] = ((pText[1] & 0x03) << 6) + (pText[2] & 0x3F);

    return;
}

void CChineseCode::UnicodeToUTF_8(char* pOut, wchar_t* pText)
{
    // 注意 WCHAR高低字的顺序,低字节在前，高字节在后
    char* pchar = (char*)pText;

    pOut[0] = (0xE0 | ((pchar[1] & 0xF0) >> 4));
    pOut[1] = (0x80 | ((pchar[1] & 0x0F) << 2)) + ((pchar[0] & 0xC0) >> 6);
    pOut[2] = (0x80 | (pchar[0] & 0x3F));

    return;
}

void CChineseCode::UnicodeToGB2312(char* pOut, wchar_t uData)
{
    WideCharToMultiByte(CP_ACP, NULL, &uData, 1, pOut, sizeof(wchar_t), NULL, NULL);
    return;
}

void CChineseCode::Gb2312ToUnicode(wchar_t* pOut, char* gbBuffer)
{
    ::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, gbBuffer, 2, pOut, 1);
    return;
}

void CChineseCode::GB2312ToUTF_8(string& pOut, char* pText, int pLen)
{
    char buf[4];
    int nLength = pLen * 3;
    char* rst = new char[nLength + 1];

    memset(buf, 0, 4);
    memset(rst, 0, nLength);



    int i = 0;
    int j = 0;
    while (i < pLen)
    {
        //如果是英文直接复制就可以
        if (*(pText + i) >= 0)
        {
            rst[j++] = pText[i++];
        }
        else
        {
            wchar_t pbuffer;
            Gb2312ToUnicode(&pbuffer, pText + i);

            UnicodeToUTF_8(buf, &pbuffer);

            unsigned short int tmp = 0;
            tmp = rst[j] = buf[0];
            tmp = rst[j + 1] = buf[1];
            tmp = rst[j + 2] = buf[2];

            j += 3;
            i += 2;
        }
    }
    rst[j] = '\0';

    //返回结果
    pOut = rst;
    delete[] rst;

    return;
}

void CChineseCode::UTF_8ToGB2312(string& pOut, char* pText, int pLen)
{
    char* newBuf = new char[pLen + 1];
    char Ctemp[4];
    memset(Ctemp, 0, 4);

    int i = 0;
    int j = 0;

    while (i < pLen)
    {
        if (pText[i] > 0)
        {
            newBuf[j++] = pText[i++];
        }
        else
        {
            WCHAR Wtemp;
            UTF_8ToUnicode(&Wtemp, pText + i);

            UnicodeToGB2312(Ctemp, Wtemp);

            newBuf[j] = Ctemp[0];
            newBuf[j + 1] = Ctemp[1];

            i += 3;
            j += 2;
        }
    }
    newBuf[j] = '\0';

    pOut = newBuf;
    delete[] newBuf;

    return;
}

inline char* KS_ANSI_to_UTF8(const char* szAnsi)
{
    if (szAnsi == NULL)
        return NULL;

    _bstr_t   bstrTmp(szAnsi);
    int       nLen = ::WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)bstrTmp, -1, NULL, 0, NULL, NULL);
    char* pUTF8 = new char[nLen + 1];
    ZeroMemory(pUTF8, nLen + 1);
    ::WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)bstrTmp, -1, pUTF8, nLen, NULL, NULL);
    return pUTF8;
}

BOOL bInjectLibrary(HANDLE hProcess, const char* szDllToInjectPath)
{
    LPVOID lpRemoteAddress = VirtualAllocEx(hProcess, NULL, strlen(szDllToInjectPath), MEM_COMMIT, PAGE_READWRITE);

    if (!lpRemoteAddress)
        return FALSE;

    if (!WriteProcessMemory(hProcess, lpRemoteAddress, (LPVOID)szDllToInjectPath, strlen(szDllToInjectPath), NULL))
        return FALSE;

    HANDLE hThread = NULL;

    if (!(hThread = CreateRemoteThread(hProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("KERNEL32.DLL"), "LoadLibraryA"), lpRemoteAddress, NULL, NULL)))
        return FALSE;

    CloseHandle(hThread);
    return TRUE;
}

std::string removeNonPrintableChars(const std::string& str) {
    std::string result;
    std::copy_if(str.begin(), str.end(), std::back_inserter(result), [](char c) {
        return std::isprint(static_cast<unsigned char>(c));
        });
    return result;
}

std::string removeSpaces(const std::string& str) {
    std::string result = str;
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    return result;
}

CString 加密机器码()
{
    VMProtectBeginUltra("加密机器码");

    return "";

    VMProtectEnd();
}

CString 未加密机器码()
{
    VMProtectBeginUltra("未加密机器码");

    return "";

    VMProtectEnd();
}

void FilesRead(string root, string to_search, vector<string>& fileVec)
{
    long long handle = 0;
    struct _finddata_t fileinfo;
    string temp_str;
    if ((handle = _findfirst(temp_str.assign(root).append(to_search).c_str(), &fileinfo)) != -1)
    {
        do
        {
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    FilesRead(temp_str.assign(root).append(fileinfo.name).c_str(), to_search, fileVec);
            }
            else
            {
                fileVec.push_back(temp_str.assign(root).append("\\").append(fileinfo.name));
            }
        } while (_findnext(handle, &fileinfo) == 0);
        _findclose(handle);
    }
}

void 清理云端缓存文件()
{
    std::ostringstream ss;
    ss << "del /f /q " << Bsphp::获取当前运行路径不带文件名() << "*.dll";
    system(ss.str().c_str());

    vector<string> fileVec;

    FilesRead(Bsphp::获取当前运行路径不带文件名().GetBuffer(), "*.dll", fileVec);
    for (int i = 0; i < fileVec.size(); i++)
    {
        DeleteFile(fileVec[i].c_str());
    }
}

void 保存默认线路功能()
{
    //根节点
    Json::Value root;

    //根节点属性
    root[设置线路] = Json::Value(默认线路);

    //缩进输出
    Json::StyledWriter sw;

    //输出到文件
    ostringstream ss;
    ss << getenv("APPDATA") << VMProtectDecryptStringA("\\") << VMProtectDecryptStringA("DefaultSetting.json");

    ofstream os;
    //os.open(ss.str().c_str(), std::ios::out | std::ios::app);不清楚原文件
    os.open(ss.str().c_str(), std::ios::out | std::ios::trunc);//清除原文件
    if (!os.is_open())
    {
        提示文本信息 = VMProtectDecryptStringA(创建配置文件失败.c_str());
    }
    else
    {
        提示文本信息 = VMProtectDecryptStringA(保存默认线路成功.c_str());
    }
    os << sw.write(root);
    os.close();
}

void 下载服务器文件()
{
    std::ostringstream ss;
    ss << Bsphp::获取当前运行路径不带文件名() << 设置加载文件;
    fstream _file;
    _file.open(ss.str(), ios::in);
    if (!_file)
    {
        清理云端缓存文件();

        std::ostringstream aa;
        aa << Bsphp::取软件的公告() << 默认游戏文件 << VMProtectDecryptStringA(".dll");

        DeleteUrlCacheEntry(aa.str().c_str());

        HRESULT hr = URLDownloadToFile(0, aa.str().c_str(), _T(ss.str().c_str()), 0, NULL);

        if (hr == S_OK)
        {
            会员登录 = true;
            注册会员 = true;
            续费充值 = true;
            变更密码 = true;
            提示文本信息 = VMProtectDecryptStringA(获取云数据完成.c_str());
        }
        else
        {
            清理云端缓存文件();
            提示文本信息 = VMProtectDecryptStringA(获取云数据失败.c_str());
        }
    }
    else
    {
        会员登录 = true;
        注册会员 = true;
        续费充值 = true;
        变更密码 = true;
        提示文本信息 = VMProtectDecryptStringA(获取云数据完成.c_str());
    }
}

void 判定默认线路功能()
{
    默认GTA5版本 = Bsphp::取软件版本信息();
    默认RDR2版本 = Bsphp::取软件描述();

    游戏名字数据 = atoi(Bsphp::取Web浏览地址().GetBuffer());
    游戏邮箱数据 = atoi(Bsphp::取预设URL地址().GetBuffer());

    if (游戏名字数据 != 0 && 游戏邮箱数据 != 0)
    {
        提示文本信息 = VMProtectDecryptStringA(正在获取云数据.c_str());

        if (Bsphp::取游戏进程("GTA5.exe") || Bsphp::取游戏进程("gta5.exe"))
        {
            CString InternetinfoRets = Bsphp::取布尔逻辑值A();
            if (InternetinfoRets == std::to_string(1).c_str())
            {
                std::ostringstream aaytd;
                aaytd << Bsphp::获取当前运行路径不带文件名() << VMProtectDecryptStringA("FamilyGTA\\Ytd\\FamilyRes.ytd");

                std::ostringstream abytd;
                abytd << getenv("PUBLIC") << "\\" << VMProtectDecryptStringA("FamilyRes.ytd");

                fstream aaytd_files;
                aaytd_files.open(aaytd.str(), ios::in);
                if (aaytd_files)
                {
                    CopyFile(aaytd.str().c_str(), abytd.str().c_str(), false);//false代表覆盖，true不覆盖

                    加载游戏大写 = VMProtectDecryptStringA("GTA5.exe");
                    加载游戏小写 = VMProtectDecryptStringA("gta5.exe");
                    获取当前版本 = 默认GTA5版本;
                    默认游戏文件 = Bsphp::取布尔逻辑值A内容();
                    设置加载文件 = "FamilyGTA5.dll";
                    下载服务器文件();
                }
                else
                {
                    提示文本信息 = VMProtectDecryptStringA(创建配置文件失败.c_str());
                }
            }
            else
            {
                提示文本信息 = VMProtectDecryptStringA("关闭了该接口文件下载，请稍后联系售后");
            }
        }
        else if (Bsphp::取游戏进程("RDR2.exe") || Bsphp::取游戏进程("rdr2.exe"))
        {
            CString InternetinfoRets = Bsphp::取布尔逻辑值B();
            if (InternetinfoRets == std::to_string(1).c_str())
            {
                std::ostringstream aaytd;
                aaytd << Bsphp::获取当前运行路径不带文件名() << VMProtectDecryptStringA("FamilyRDR\\Ytd\\FamilyRes.ytd");

                std::ostringstream abytd;
                abytd << getenv("PUBLIC") << "\\" << VMProtectDecryptStringA("FamilyRes.ytd");

                fstream aaytd_files;
                aaytd_files.open(aaytd.str(), ios::in);
                if (aaytd_files)
                {
                    CopyFile(aaytd.str().c_str(), abytd.str().c_str(), false);//false代表覆盖，true不覆盖

                    加载游戏大写 = VMProtectDecryptStringA("RDR2.exe");
                    加载游戏小写 = VMProtectDecryptStringA("rdr2.exe");
                    获取当前版本 = 默认RDR2版本;
                    默认游戏文件 = Bsphp::取布尔逻辑值B内容();
                    设置加载文件 = "FamilyRDR2.dll";
                    下载服务器文件();
                }
                else
                {
                    提示文本信息 = VMProtectDecryptStringA(创建配置文件失败.c_str());
                }
            }
            else
            {
                提示文本信息 = VMProtectDecryptStringA("关闭了该接口文件下载，请稍后联系售后");
            }
        }
        else
        {
            提示文本信息 = VMProtectDecryptStringA(未检测到游戏程序.c_str());
        }
    }
    else
    {
        提示文本信息 = VMProtectDecryptStringA(获取游戏信息失败.c_str());
    }
}

bool containsChinese(const std::string& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        if ((unsigned char)str[i] >= 0x80) {
            // 假设所有大于 0x80 的字符都是中文字符
            // 在实际应用中，你可能需要更精确的判断
            return true;
        }
    }
    return false;
}

void 链接服务器数据信息()
{
    Bsphp::ServerUrl = VMProtectDecryptStringA("");
    Bsphp::MesKey = VMProtectDecryptStringA("");
    Bsphp::数据加密密码(VMProtectDecryptStringA(""));

    CString InternetinfoRets = Bsphp::网络验证();
    if (InternetinfoRets == std::to_string(1).c_str())
    {
        提示文本信息 = VMProtectDecryptStringA(网络链接成功.c_str());
        Bsphp::SeSsL = Bsphp::取BSphpSeSsL();

        Bsphp::PcHWID = 加密机器码();

        判定默认线路功能();
    }
    else
    {
        if (containsChinese(Bsphp::获取当前运行路径().GetString()))
        {
            提示文本信息 = VMProtectDecryptStringA("程序不能在中文路径和中文文件夹下运行");
        }
        else
        {
            for (int i = 0; i < IM_ARRAYSIZE(Objects_Lockers_Types); i++)
            {
                if (InternetinfoRets == std::to_string(Objects_Lockers_Types[i].model).c_str())
                {
                    提示文本信息 = VMProtectDecryptStringA(Objects_Lockers_Types[i].model_name);
                }
            }
        }
    }
}

DWORD WINAPI ThreadFun2(LPVOID lpParameter)
{
    VMProtectBeginUltra("ThreadFun2");

    辅助名字 = Bsphp::获取当前文件名();

    Bsphp::MyMD5 = Bsphp::获取程序MD5();

    读取账号();

    链接服务器数据信息();

    VMProtectEnd();
    return 0;
}

void ShowDemoUI()
{
    auto& style = ImGui::GetStyle();
    style.FramePadding = { 8.f, 5.f };
    style.WindowTitleAlign = { 0.0f, 0.5f };//标题居中
    style.ButtonTextAlign = { 0.5f, 0.5f };//按钮文字居左
    style.DisplaySafeAreaPadding = { 3.f, 3.f };

    auto& colors = style.Colors;
    colors[ImGuiCol_Text] = ImColor(153, 153, 153, 255);//字体颜色
    colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 255);//窗口背景颜色
    colors[ImGuiCol_PopupBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.98f);
    colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.30f);
    colors[ImGuiCol_FrameBg] = ImColor(255, 255, 255, 255);//编辑框默认颜色
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.28f, 0.27f, 0.27f, 0.54f);//编辑框悬停颜色
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.21f, 0.21f, 0.21f, 0.78f);//编辑框激活后颜色
    colors[ImGuiCol_TitleBg] = ImColor(33, 143, 255, 255);//窗口默认颜色
    colors[ImGuiCol_TitleBgActive] = ImColor(33, 143, 255, 255);//窗口栏悬停颜色
    colors[ImGuiCol_TitleBgCollapsed] = ImColor(33, 143, 255, 255);//窗口栏激活后颜色
    colors[ImGuiCol_Button] = ImColor(74, 25, 136, 255);//按钮默认颜色
    colors[ImGuiCol_ButtonHovered] = ImColor(255, 41, 145, 255);//按钮悬停颜色
    colors[ImGuiCol_ButtonActive] = ImColor(254, 78, 168, 200);//按钮激活后颜色
    colors[ImGuiCol_Tab] = ImColor(255, 255, 255, 255); //选项按钮默认颜色
    colors[ImGuiCol_TabHovered] = ImColor(0, 191, 255, 255);//选项按钮悬停颜色
    colors[ImGuiCol_TabActive] = ImColor(0, 191, 255, 255);//选项按钮激活后颜色
    colors[ImGuiCol_Separator] = ImColor(0, 191, 255, 255); //线条默认颜色
    colors[ImGuiCol_SeparatorHovered] = ImColor(0, 191, 255, 255);//线条悬停颜色
    colors[ImGuiCol_SeparatorActive] = ImColor(0, 191, 255, 255);//线条激活后颜色
}

static void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

void 用户须知(bool* p_open)
{
    VMProtectBeginUltra("用户须知");

    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoCollapse;
    window_flags |= ImGuiWindowFlags_NoResize;
    window_flags |= ImGuiWindowFlags_NoScrollbar;

    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowBorderSize = 0.0f;
    style.WindowPadding = { 0.0f,0.0f };

    auto& colors = style.Colors;
    colors[ImGuiCol_Text] = ImColor(74, 25, 136, 255);
    colors[ImGuiCol_WindowBg] = ImColor(200, 200, 200, 255);

    ImGui::SetNextWindowPos(ImVec2((client_width / 2) - (600.0f / 2), (client_height / 2) - (360.0f / 2)), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(600.0f, 360.0f), ImGuiCond_FirstUseEver);

    if (ImGui::Begin("用户使用须知", p_open, window_flags))
    {
        ImGui::Text("");
        ImGui::Text("   Family游戏菜单制作来自 Rockstar 游戏公司开源提供的SDK和NATIVE DB API整合而来,");
        ImGui::Text("   Family程序功能均是游戏程序本身已经具备的功能整合而来,");
        ImGui::Text("   因此Family的所有功能都是游戏主程序具有的功能,");
        ImGui::Text("   我们不做任何与游戏程序无关的， 或者游戏程序本身不具备的功能,");
        ImGui::Text("   也不对游戏程序进行修改和增加， 所以你使用Family菜单时所用的所有功能,");
        ImGui::Text("   均只是调用游戏主程序包含了的功能，我只是为你整理归类,");
        ImGui::Text("   在使用Family程序过程中，请勿使用程序去影响其他玩家,");
        ImGui::Text("   或者其他人的正常游戏， 根据 Rockstar 用户使用守则,");
        ImGui::Text("   请勿使用Family菜单进行线上模式的破坏行为,");
        ImGui::Text("   如若违规法律与道德行为的使用Family程序,");
        ImGui::Text("   我们有权要求你停止使用，并由你承担一切法律后果,");
        ImGui::Text("   注册和登录时程序会获取电脑登录过的QQ号码,游戏用户名,游戏账号,电脑机器码,网络IP信息,");
        ImGui::Text("   获取的这些信息用于验证用户登录权限使用,同时用于协助用户找回账号密码使用,");
        ImGui::Text("   如果你对以上要求有所异议，请立即删除Family程序，并停止使用.");

        ImGui::SetCursorPos(ImVec2(440.0f, 300.0f));
        if (ImGui::Button("已知晓（确定）", ImVec2(137.0f, 45.0f)))
        {
            show_demo_window_2 = false;
        }
    }
    ImGui::End();

    VMProtectEnd();
}

void 检测到游戏后执行()
{
    首次激活绑定QQ = Bsphp::登录_取用户信息(9);
    首次激活绑定邮箱 = Bsphp::登录_取用户信息(10);

    if (首次激活绑定QQ == "")
    {
        if (首次激活绑定邮箱 == "")
        {
            CString PerfectQQ = Bsphp::登录_完善用户资料(Bsphp::获取当前QQ号码(), Bsphp::R星邮箱号(游戏邮箱数据), "");
        }
        else
        {
            CString PerfectQQ = Bsphp::登录_完善用户资料(Bsphp::获取当前QQ号码(), Bsphp::登录_取用户信息(10), "");
        }
    }
    if (首次激活绑定邮箱 == "")
    {
        if (首次激活绑定QQ == "")
        {
            CString PerfectQQ = Bsphp::登录_完善用户资料(Bsphp::获取当前QQ号码(), Bsphp::R星邮箱号(游戏邮箱数据), "");
        }
        else
        {
            CString PerfectQQ = Bsphp::登录_完善用户资料(Bsphp::登录_取用户信息(9), Bsphp::R星邮箱号(游戏邮箱数据), "");
        }
    }

    std::ostringstream aa;
    aa << Bsphp::获取当前运行路径不带文件名() << 设置加载文件;

    if (Bsphp::云端文件校验MD5(aa.str()) != 默认游戏文件)
    {
        清理云端缓存文件();
        提示文本信息 = VMProtectDecryptStringA(辅助加载失败.c_str());
    }
    else
    {
        DWORD PidRDR;

        if (Bsphp::取游戏进程(加载游戏大写))
        {
            PidRDR = Bsphp::取游戏进程(加载游戏大写);
        }
        else if (Bsphp::取游戏进程(加载游戏小写))
        {
            PidRDR = Bsphp::取游戏进程(加载游戏小写);
        }

        if (PidRDR)
        {
            HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, PidRDR);

            if (!bInjectLibrary(hProcess, aa.str().c_str()))

                CloseHandle(hProcess);

            if (记住卡密)
                保存账号();

            提示文本信息 = VMProtectDecryptStringA(辅助加载完成.c_str());

            激活时间 = Bsphp::登录_取用户信息(0);//0
            激活时Ip = Bsphp::登录_取用户信息(1);//1
            登录时间 = Bsphp::登录_取用户信息(3);//3
            登录Ip = Bsphp::登录_取用户信息(4);//4
            到期时间 = Bsphp::登录_取用户信息(5);//5
            用户分组名称 = Bsphp::登录_取用户信息(7);//7
            用户分组别名 = Bsphp::登录_取用户信息(8);//8
            用户邮箱 = Bsphp::登录_取用户信息(10);//10
            用户名称 = Bsphp::登录_取用户信息(19);//19

            登录完成 = true;
        }
    }
}

void RegDemo()
{
    if (注册会员)
    {
        if (Bsphp::取游戏进程(加载游戏大写) || Bsphp::取游戏进程(加载游戏小写))
        {
            if (Bsphp::未加密游戏名(游戏名字数据) != "0" && Bsphp::R星邮箱号(游戏邮箱数据) != "0")
            {
                if (strncmp(请填写账号, "", 10) != 0 && strncmp(请填写密码, "", 10) != 0 && strncmp(请填写卡号, "", 10) != 0 && strncmp(请填写卡密, "", 10) != 0)
                {
                    CString LoginRets = Bsphp::登录_关联卡账号注册(strlwr(请填写账号), 请填写密码, 请填写卡号, 请填写卡密, Bsphp::获取当前QQ号码(), Bsphp::R星邮箱号(游戏邮箱数据), Bsphp::未加密游戏名(游戏名字数据), "", "", "");
                    if (LoginRets == std::to_string(1005).c_str())
                    {
                        保存账号();
                        提示文本信息 = VMProtectDecryptStringA(注册成功.c_str());
                    }
                    else if (LoginRets == std::to_string(1003).c_str())
                    {
                        提示文本信息 = VMProtectDecryptStringA(账号长度限制位数.c_str());
                    }
                    else if (LoginRets == std::to_string(1007).c_str())
                    {
                        提示文本信息 = VMProtectDecryptStringA(密码长度限制位数.c_str());
                    }
                    else
                    {
                        for (int i = 0; i < IM_ARRAYSIZE(Objects_Lockers_Types); i++)
                        {
                            if (LoginRets == std::to_string(Objects_Lockers_Types[i].model).c_str())
                            {
                                提示文本信息 = VMProtectDecryptStringA(Objects_Lockers_Types[i].model_name);
                            }
                        }
                    }
                }
                else
                {
                    提示文本信息 = VMProtectDecryptStringA(编辑框不能为空.c_str());
                }
            }
            else
            {
                提示文本信息 = VMProtectDecryptStringA(获取游戏信息失败.c_str());
            }
        }
        else
        {
            提示文本信息 = VMProtectDecryptStringA(未检测到游戏程序.c_str());
        }
    }
    else if (会员登录 && 注册会员 && 变更密码 && 续费充值)
    {
        提示文本信息 = VMProtectDecryptStringA(请勿重复点击按钮.c_str());
    }
}

void LongDemo()
{
    if (续费充值)
    {
        if (Bsphp::取游戏进程(加载游戏大写) || Bsphp::取游戏进程(加载游戏小写))
        {
            if (Bsphp::未加密游戏名(游戏名字数据) != "0" && Bsphp::R星邮箱号(游戏邮箱数据) != "0")
            {
                if (strncmp(请填写账号, "", 10) != 0 && strncmp(请填写密码, "", 10) != 0 && strncmp(请填写卡号, "", 10) != 0 && strncmp(请填写卡密, "", 10) != 0)
                {
                    CString LoginRets = Bsphp::登录_软件充值vip续期(strlwr(请填写账号), 请填写密码, 请填写卡号, 请填写卡密);
                    for (int i = 0; i < IM_ARRAYSIZE(Objects_Lockers_Types); i++)
                    {
                        if (LoginRets == std::to_string(Objects_Lockers_Types[i].model).c_str())
                        {
                            提示文本信息 = VMProtectDecryptStringA(Objects_Lockers_Types[i].model_name);
                        }
                    }
                }
                else
                {
                    提示文本信息 = VMProtectDecryptStringA(编辑框不能为空.c_str());
                }
            }
            else
            {
                提示文本信息 = VMProtectDecryptStringA(获取游戏信息失败.c_str());
            }
        }
        else
        {
            提示文本信息 = VMProtectDecryptStringA(未检测到游戏程序.c_str());
        }
    }
    else if (会员登录 && 注册会员 && 变更密码 && 续费充值)
    {
        提示文本信息 = VMProtectDecryptStringA(请勿重复点击按钮.c_str());
    }
}

void BangDemo()
{
    if (变更密码)
    {
        if (Bsphp::取游戏进程(加载游戏大写) || Bsphp::取游戏进程(加载游戏小写))
        {
            if (Bsphp::未加密游戏名(游戏名字数据) != "0" && Bsphp::R星邮箱号(游戏邮箱数据) != "0")
            {
                if (strncmp(请填写账号, "", 10) != 0 && strncmp(请填写密码, "", 10) != 0 && strncmp(请填写新密码, "", 10) != 0 && strncmp(请填写确认密码, "", 10) != 0)
                {
                    CString LoginBang = Bsphp::登录_修改密码(strlwr(请填写账号), 请填写密码, 请填写新密码, 请填写确认密码);

                    for (int i = 0; i < IM_ARRAYSIZE(Objects_Lockers_Types); i++)
                    {
                        if (LoginBang == std::to_string(Objects_Lockers_Types[i].model).c_str())
                        {
                            提示文本信息 = VMProtectDecryptStringA(Objects_Lockers_Types[i].model_name);
                        }
                    }
                }
                else
                {
                    提示文本信息 = VMProtectDecryptStringA(用户信息不能为空.c_str());
                }
            }
            else
            {
                提示文本信息 = VMProtectDecryptStringA(获取游戏信息失败.c_str());
            }
        }
        else
        {
            提示文本信息 = VMProtectDecryptStringA(未检测到游戏程序.c_str());
        }
    }
    else if (会员登录 && 注册会员 && 变更密码 && 续费充值)
    {
        提示文本信息 = VMProtectDecryptStringA(请勿重复点击按钮.c_str());
    }
}

void LoginJamp()
{
    CString GetUserInfo = Bsphp::登录_取用户信息(6);
    CString 取返回机器码 = GetUserInfo.Mid(11);
    if (取返回机器码 == 未加密机器码())
    {
        CString 验证登录状态 = Bsphp::登录_取得登陆状态信息();

        if (验证登录状态 == std::to_string(1).c_str())
        {
            检测到游戏后执行();
        }
        else
        {
            for (int i = 0; i < ARRAYSIZE(Objects_Lockers_Types); i++)
            {
                if (验证登录状态 == std::to_string(Objects_Lockers_Types[i].model).c_str())
                {
                    提示文本信息 = VMProtectDecryptStringA(Objects_Lockers_Types[i].model_name);

                }
                else
                {
                    提示文本信息 = VMProtectDecryptStringA(登陆失败.c_str());
                }
            }
        }
    }
    else
    {
        CString 取返回机器码时间 = GetUserInfo.Left(10);
        CString 取返回服务器时间 = Bsphp::取软件配置信息段("GLOBAL_BSPHPUNIX");
        if (_ttoi(取返回机器码时间) + 3600 < _ttoi(取返回服务器时间))
        {
            CString LoginJie = Bsphp::登录_解除账号绑定(请填写账号, "");
            if (LoginJie == std::to_string(7012).c_str())
            {
                CString LoginBang = Bsphp::登录_绑定账号特征(请填写账号, "");
                if (LoginBang == std::to_string(5013).c_str())
                {
                    LoginDemo();
                }
                else
                {
                    for (int i = 0; i < ARRAYSIZE(Objects_Lockers_Types); i++)
                    {
                        if (LoginBang == std::to_string(Objects_Lockers_Types[i].model).c_str())
                        {
                            提示文本信息 = VMProtectDecryptStringA(Objects_Lockers_Types[i].model_name);
                        }
                        else
                        {
                            提示文本信息 = VMProtectDecryptStringA(绑定失败.c_str());
                        }
                    }
                }
            }
            else
            {
                for (int i = 0; i < ARRAYSIZE(Objects_Lockers_Types); i++)
                {
                    if (LoginJie == std::to_string(Objects_Lockers_Types[i].model).c_str())
                    {
                        提示文本信息 = VMProtectDecryptStringA(Objects_Lockers_Types[i].model_name);
                    }
                    else
                    {
                        提示文本信息 = VMProtectDecryptStringA(解除绑定拒绝.c_str());
                    }
                }
            }
        }
    }
}

void LoginDemo()
{
    if (会员登录)
    {
        if (Bsphp::取游戏进程(加载游戏大写) || Bsphp::取游戏进程(加载游戏小写))
        {
            if (Bsphp::未加密游戏名(游戏名字数据) != "0" && Bsphp::R星邮箱号(游戏邮箱数据) != "0")
            {
                if (strncmp(请填写账号, "", 10) != 0 && strncmp(请填写密码, "", 10) != 0)
                {
                    CString LoginRet = Bsphp::登录_用户登录(strlwr(请填写账号), 请填写密码);

                    CString strTmp = LoginRet.Mid(0, 7);

                    if (strTmp == VMProtectDecryptStringA("01|1011"))
                    {
                        CString GetUserInfoVip = Bsphp::登录_取用户信息(8);

                        if (Bsphp::取游戏进程(VMProtectDecryptStringA("GTA5.exe")) || Bsphp::取游戏进程(VMProtectDecryptStringA("gta5.exe")))
                        {
                            if (GetUserInfoVip != VMProtectDecryptStringA("RDRFM") && GetUserInfoVip != VMProtectDecryptStringA("FGTA5") && GetUserInfoVip != VMProtectDecryptStringA("TESTVIP"))
                            {
                                提示文本信息 = VMProtectDecryptStringA(激活码与软件不相符.c_str());
                            }
                            else
                            {
                                LoginJamp();
                            }
                        }
                        else if (Bsphp::取游戏进程(VMProtectDecryptStringA("RDR2.exe")) || Bsphp::取游戏进程(VMProtectDecryptStringA("rdr2.exe")))
                        {
                            if (GetUserInfoVip != VMProtectDecryptStringA("RDRFM") && GetUserInfoVip != VMProtectDecryptStringA("FRDR2") && GetUserInfoVip != VMProtectDecryptStringA("TESTVIP"))
                            {
                                提示文本信息 = VMProtectDecryptStringA(激活码与软件不相符.c_str());
                            }
                            else
                            {
                                LoginJamp();
                            }
                        }
                        else
                        {
                            提示文本信息 = VMProtectDecryptStringA(激活码与软件不相符.c_str());
                        }
                    }
                    else
                    {
                        for (int i = 0; i < IM_ARRAYSIZE(Objects_Lockers_Types); i++)
                        {
                            if (LoginRet == std::to_string(Objects_Lockers_Types[i].model).c_str())
                            {
                                提示文本信息 = VMProtectDecryptStringA(Objects_Lockers_Types[i].model_name);
                            }
                        }
                    }
                }
                else
                {
                    提示文本信息 = VMProtectDecryptStringA(用户信息不能为空.c_str());
                }
            }
            else
            {
                提示文本信息 = VMProtectDecryptStringA(获取游戏信息失败.c_str());
            }
        }
        else
        {
            提示文本信息 = VMProtectDecryptStringA(未检测到游戏程序.c_str());
        }
    }
    else if (会员登录 && 注册会员 && 变更密码 && 续费充值)
    {
        提示文本信息 = VMProtectDecryptStringA(请勿重复点击按钮.c_str());
    }
}

void load_image()
{
    std::ostringstream ss;
    ss << Bsphp::获取当前运行路径不带文件名() << "FamilyGTA\\Image\\" << "Family.jpg";

    int width, height, channel;
    unsigned char* data = stbi_load(ss.str().c_str(), &width, &height, &channel, 3);

    g_pd3dDevice->CreateTexture(width, height, 1, D3DUSAGE_DYNAMIC, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &g_texture, NULL);
    D3DLOCKED_RECT lock_rect;
    unsigned char* buffer = new unsigned char[width * height * (channel + 1)];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer[(i * width + j) * 4 + 0] = data[(i * width + j) * 3 + 2];
            buffer[(i * width + j) * 4 + 1] = data[(i * width + j) * 3 + 1];
            buffer[(i * width + j) * 4 + 2] = data[(i * width + j) * 3 + 0];
            buffer[(i * width + j) * 4 + 3] = 0xff;
        }
    }
    g_texture->LockRect(0, &lock_rect, NULL, 0);
    for (int y = 0; y < height; y++)
        memcpy((unsigned char*)lock_rect.pBits + lock_rect.Pitch * y, buffer + (width * (channel + 1)) * y, (width * (channel + 1)));
    g_texture->UnlockRect(0);
    delete[] buffer;
}

void Imgui_Draw_Image(float x, float y, float sx, float sy)
{
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImGuiContext& gw = *GImGui;
    ImGuiViewportP* viewport = gw.Viewports[2];
    float wx = viewport->Pos.x;
    float wy = viewport->Pos.y;

    draw_list->AddImage(g_texture, ImVec2(wx + x, wy + y), ImVec2(wx + sx, wy + sy), ImVec2(0, 0), ImVec2(1, 1), ImGui::GetColorU32(ImVec4(1.0f, 1.0f, 1.0f, 1.0f)));
}

void Imgui_Draw_Text(std::string text, float font_size, float sx, float sy, ImU32 col, bool right)
{
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImGuiContext& gw = *GImGui;
    ImGuiViewportP* viewport = gw.Viewports[2];
    float wx = viewport->Pos.x;
    float wy = viewport->Pos.y;

    auto textSize = childHeaderFont->CalcTextSizeA(font_size, FLT_MAX, NULL, text.c_str());
    if (right)
        draw_list->AddText(childHeaderFont, font_size, ImVec2(wx + sx - textSize.x, wy + sy), col, text.c_str());
    else
        draw_list->AddText(childHeaderFont, font_size, ImVec2(wx + sx, wy + sy), col, text.c_str());
}

void Imgui_Draw_List(float x, float y, float length, ImU32 col, float line_width)
{
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    // 获取当前窗口的位置
    ImVec2 window_pos = ImGui::GetWindowPos();

    // 设置线条的起点和终点，以确保它是横向的
    ImVec2 start_pos = ImVec2(window_pos.x + x, window_pos.y + y);
    ImVec2 end_pos = ImVec2(window_pos.x + x + length, window_pos.y + y);  // 保持 y 坐标不变

    // 画线
    draw_list->AddLine(start_pos, end_pos, col, line_width);
}

void ShowDemo(bool* p_open)
{
    VMProtectBeginUltra("ShowDemo");

    ShowDemoUI();

    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoCollapse;
    window_flags |= ImGuiWindowFlags_NoResize;
    window_flags |= ImGuiWindowFlags_NoScrollbar;
    window_flags |= ImGuiWindowFlags_NoTitleBar;

    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowBorderSize = 0.0f;
    style.WindowPadding = { 0.0f,0.0f };

    ImGui::SetNextWindowPos(ImVec2((client_width / 2) - (620.0f / 2), (client_height / 2) - (380.0f / 2)), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(620.0f, 380.0f), ImGuiCond_FirstUseEver);

    if (!ImGui::Begin(辅助名字.c_str(), p_open, window_flags))
    {
        ImGui::End();
        return;
    }

    Imgui_Draw_Image(0.0f, 0.0f, 620.0f, 380.0f);

    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);
    ImGui::SetCursorPos(ImVec2(580.0f, 0.0f));
    ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(255, 255, 255, 255)); // 设置文字颜色
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    if (ImGui::Button("##Button1", ImVec2(35.0f, 35.0f)))
    {
        ExitProcess(0);
    }
    ImGui::PopStyleVar();
    ImGui::PopStyleColor();

    Imgui_Draw_Text(VMProtectDecryptStringA("×"), 30.0f, 585.0f, 2.0f, ImColor(0, 0, 0, 150), false);

    //Left side
    static ImVec4 active = imguipp::to_vec4(255, 255, 255, 255);
    static ImVec4 inactive = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);

    static ImColor activeTXT1 = ImColor(162, 62, 216, 255);
    static ImColor inactiveTXT1 = ImColor(255, 255, 255, 255);

    {
        auto textSize1 = childHeaderFont->CalcTextSizeA(17.0f, FLT_MAX, NULL, 账号登录.c_str());

        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
        ImGui::SetCursorPos(ImVec2(200.0f - textSize1.x, 161.0f));

        ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(255, 255, 255, 255));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(255, 255, 255, 100));
        ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? active : inactive);

        if (ImGui::Button("##Button2", ImVec2(30.0f + textSize1.x, 35.0f)))
        {
            Settings::Tab = 1;
        }
        Imgui_Draw_Text(账号登录, 17.0f, 218.0f, 170.0f, Settings::Tab == 1 ? activeTXT1 : inactiveTXT1, true);

        ImGui::PopStyleVar();
        ImGui::PopStyleColor();
    }

    {
        auto textSize2 = childHeaderFont->CalcTextSizeA(17.0f, FLT_MAX, NULL, 会员注册.c_str());

        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
        ImGui::SetCursorPos(ImVec2(200.0f - textSize2.x, 161.0f + (38.0f * 1)));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(255, 255, 255, 255));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(255, 255, 255, 100));

        ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? active : inactive);
        if (ImGui::Button("##Button3", ImVec2(30.0f + textSize2.x, 35.0f)))
        {
            Settings::Tab = 2;
        }
        Imgui_Draw_Text(会员注册, 17.0f, 218.0f, 170.0f + (38.0f * 1), Settings::Tab == 2 ? activeTXT1 : inactiveTXT1, true);

        ImGui::PopStyleVar();
        ImGui::PopStyleColor();
    }

    {
        auto textSize21 = childHeaderFont->CalcTextSizeA(17.0f, FLT_MAX, NULL, 充值续费.c_str());

        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
        ImGui::SetCursorPos(ImVec2(200.0f - textSize21.x, 161.0f + (38.0f * 2)));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(255, 255, 255, 255));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(255, 255, 255, 100));

        ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? active : inactive);
        if (ImGui::Button("##Button31", ImVec2(30.0f + textSize21.x, 35.0f)))
        {
            Settings::Tab = 3;
        }
        Imgui_Draw_Text(充值续费, 17.0f, 218.0f, 170.0f + (38.0f * 2), Settings::Tab == 3 ? activeTXT1 : inactiveTXT1, true);

        ImGui::PopStyleVar();
        ImGui::PopStyleColor();
    }

    {
        auto textSize3 = childHeaderFont->CalcTextSizeA(17.0f, FLT_MAX, NULL, 修改密码.c_str());

        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
        ImGui::SetCursorPos(ImVec2(200.0f - textSize3.x, 161.0f + (38.0f * 3)));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(255, 255, 255, 255));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(255, 255, 255, 100));

        ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 4 ? active : inactive);
        if (ImGui::Button("##Button4", ImVec2(30.0f + textSize3.x, 35.0f)))
        {
            Settings::Tab = 4;
        }
        Imgui_Draw_Text(修改密码, 17.0f, 218.0f, 170.0f + (38.0f * 3), Settings::Tab == 4 ? activeTXT1 : inactiveTXT1, true);

        ImGui::PopStyleVar();
        ImGui::PopStyleColor();
    }

    {
        auto textSize4 = childHeaderFont->CalcTextSizeA(17.0f, FLT_MAX, NULL, 常规设置.c_str());

        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
        ImGui::SetCursorPos(ImVec2(200.0f - textSize4.x, 161.0f + (38.0f * 4)));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(255, 255, 255, 255));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(255, 255, 255, 100));

        ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 5 ? active : inactive);
        if (ImGui::Button("##Button5", ImVec2(30.0f + textSize4.x, 35.0f)))
        {
            Settings::Tab = 5;
        }
        Imgui_Draw_Text(常规设置, 17.0f, 218.0f, 170.0f + (38.0f * 4), Settings::Tab == 5 ? activeTXT1 : inactiveTXT1, true);

        ImGui::PopStyleVar();
        ImGui::PopStyleColor();
    }

    if (Settings::Tab == 1)
    {
        Imgui_Draw_Text(账号登录, 35.0f, 283.0f, 40.0f, ImColor(162, 62, 216, 255), false);
        auto textSize = childHeaderFont->CalcTextSizeA(35.0f, FLT_MAX, NULL, 账号登录.c_str());
        Imgui_Draw_List(283.0f, 75.0f, textSize.x, ImColor(162, 62, 216, 255), 1.0f);

        if (!登录完成)
        {
            {
                ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
                ImGui::SetCursorPos(ImVec2(335, 152));
                ImGui::SetNextItemWidth(205);//Height
                ImGui::InputText("##InputText1", 请填写账号, IM_ARRAYSIZE(请填写账号));
                ImGui::PopStyleColor();

                Imgui_Draw_Text(账号, 20.0f, 335.0f, 158.0f, ImColor(162, 62, 216, 255), true);
                Imgui_Draw_List(340.0f, 176.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);

            }

            {
                ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
                ImGui::SetCursorPos(ImVec2(335, 213));
                ImGui::SetNextItemWidth(205);//Height
                ImGui::InputText("##InputText2", 请填写密码, IM_ARRAYSIZE(请填写密码), ImGuiInputTextFlags_Password);
                ImGui::PopStyleColor();

                Imgui_Draw_Text(密码, 20.0f, 335.0f, 219.0f, ImColor(162, 62, 216, 255), true);
                Imgui_Draw_List(340.0f, 237.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);
            }

            {
                ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
                ImGui::SetCursorPos(ImVec2(405.0f, 270.0f));
                ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(129, 152, 251, 255));
                ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(162, 62, 216, 255));
                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(129, 152, 251, 100));

                if (ImGui::Button(账号登录.c_str(), ImVec2(137.0f, 45.0f)))
                {
                    LoginDemo();
                }

                ImGui::PopStyleVar();
                ImGui::PopStyleColor();
            }
        }
        else
        {
            std::string input = 用户名称.GetBuffer();
            std::string result = input.substr(4);

            Imgui_Draw_Text("会员账号:", 20.0f, 283.0f, 信息属性高度, ImColor(162, 62, 216, 255), false);
            Imgui_Draw_Text(result, 20.0f, 570.0f, 信息属性高度, ImColor(162, 62, 216, 255), true);

            Imgui_Draw_Text("用户分组:", 20.0f, 283.0f, 信息属性高度 + (25.0f * 1), ImColor(162, 62, 216, 255), false);
            Imgui_Draw_Text(KS_ANSI_to_UTF8(用户分组名称), 20.0f, 570.0f, 信息属性高度 + +(25.0f * 1), ImColor(162, 62, 216, 255), true);

            if (用户邮箱 == "")
            {
                Imgui_Draw_Text("用户邮箱:", 20.0f, 283.0f, 信息属性高度 + (25.0f * 2), ImColor(162, 62, 216, 255), false);
                Imgui_Draw_Text("未填写", 20.0f, 570.0f, 信息属性高度 + +(25.0f * 2), ImColor(162, 62, 216, 255), true);
            }
            else
            {
                Imgui_Draw_Text("用户邮箱:", 20.0f, 283.0f, 信息属性高度 + (25.0f * 2), ImColor(162, 62, 216, 255), false);
                Imgui_Draw_Text(KS_ANSI_to_UTF8(用户邮箱), 20.0f, 570.0f, 信息属性高度 + +(25.0f * 2), ImColor(162, 62, 216, 255), true);
            }

            Imgui_Draw_Text("激活时间:", 20.0f, 283.0f, 信息属性高度 + +(25.0f * 3), ImColor(162, 62, 216, 255), false);
            Imgui_Draw_Text(激活时间.GetBuffer(), 20.0f, 570.0f, 信息属性高度 + +(25.0f * 3), ImColor(162, 62, 216, 255), true);

            if (result == "821517977")
            {
                Imgui_Draw_Text("激活时Ip:", 20.0f, 283.0f, 信息属性高度 + +(25.0f * 4), ImColor(162, 62, 216, 255), false);
                Imgui_Draw_Text("139.5.108.81", 20.0f, 570.0f, 信息属性高度 + +(25.0f * 4), ImColor(162, 62, 216, 255), true);

                Imgui_Draw_Text("登录时间:", 20.0f, 283.0f, 信息属性高度 + +(25.0f * 5), ImColor(162, 62, 216, 255), false);
                Imgui_Draw_Text(登录时间.GetBuffer(), 20.0f, 570.0f, 信息属性高度 + +(25.0f * 5), ImColor(162, 62, 216, 255), true);

                Imgui_Draw_Text("登录Ip:", 20.0f, 283.0f, 信息属性高度 + +(25.0f * 6), ImColor(162, 62, 216, 255), false);
                Imgui_Draw_Text("139.5.108.81", 20.0f, 570.0f, 信息属性高度 + +(25.0f * 6), ImColor(162, 62, 216, 255), true);

            }
            else
            {
                Imgui_Draw_Text("激活时Ip:", 20.0f, 283.0f, 信息属性高度 + +(25.0f * 4), ImColor(162, 62, 216, 255), false);
                Imgui_Draw_Text(激活时Ip.GetBuffer(), 20.0f, 570.0f, 信息属性高度 + +(25.0f * 4), ImColor(162, 62, 216, 255), true);

                Imgui_Draw_Text("登录时间:", 20.0f, 283.0f, 信息属性高度 + +(25.0f * 5), ImColor(162, 62, 216, 255), false);
                Imgui_Draw_Text(登录时间.GetBuffer(), 20.0f, 570.0f, 信息属性高度 + +(25.0f * 5), ImColor(162, 62, 216, 255), true);

                Imgui_Draw_Text("登录Ip:", 20.0f, 283.0f, 信息属性高度 + +(25.0f * 6), ImColor(162, 62, 216, 255), false);
                Imgui_Draw_Text(登录Ip.GetBuffer(), 20.0f, 570.0f, 信息属性高度 + +(25.0f * 6), ImColor(162, 62, 216, 255), true);
            }

            if (用户分组别名 == VMProtectDecryptStringA("TESTVIP"))
            {
                Imgui_Draw_Text("到期时间:", 20.0f, 283.0f, 信息属性高度 + +(25.0f * 7), ImColor(162, 62, 216, 255), false);
                Imgui_Draw_Text(到期时间.GetBuffer(), 20.0f, 570.0f, 信息属性高度 + +(25.0f * 7), ImColor(162, 62, 216, 255), true);
            }
            else
            {
                Imgui_Draw_Text("到期时间:", 20.0f, 283.0f, 信息属性高度 + +(25.0f * 7), ImColor(162, 62, 216, 255), false);
                Imgui_Draw_Text("永久免费更新", 20.0f, 570.0f, 信息属性高度 + +(25.0f * 7), ImColor(162, 62, 216, 255), true);
            }
        }
    }
    else if (Settings::Tab == 2)
    {
        Imgui_Draw_Text(会员注册, 35.0f, 283.0f, 40.0f, ImColor(162, 62, 216, 255), false);
        auto textSize = childHeaderFont->CalcTextSizeA(35.0f, FLT_MAX, NULL, 会员注册.c_str());
        Imgui_Draw_List(283.0f, 75.0f, textSize.x, ImColor(162, 62, 216, 255), 1.0f);


        {
            ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
            ImGui::SetCursorPos(ImVec2(335, 117));
            ImGui::SetNextItemWidth(205);//Height
            ImGui::InputText("##InputText1", 请填写账号, IM_ARRAYSIZE(请填写账号));
            ImGui::PopStyleColor();

            Imgui_Draw_Text(账号, 20.0f, 335.0f, 122.0f, ImColor(162, 62, 216, 255), true);
            Imgui_Draw_List(340.0f, 140.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);
        }

        {
            ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
            ImGui::SetCursorPos(ImVec2(335, 161));
            ImGui::SetNextItemWidth(205);//Height
            ImGui::InputText("##InputText2", 请填写密码, IM_ARRAYSIZE(请填写密码), ImGuiInputTextFlags_Password);
            ImGui::PopStyleColor();

            Imgui_Draw_Text(密码, 20.0f, 335.0f, 166.0f, ImColor(162, 62, 216, 255), true);
            Imgui_Draw_List(340.0f, 184.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);
        }

        {
            ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
            ImGui::SetCursorPos(ImVec2(335, 205));
            ImGui::SetNextItemWidth(205);//Height
            ImGui::InputText("##InputText3", 请填写卡号, IM_ARRAYSIZE(请填写卡号));
            ImGui::PopStyleColor();

            Imgui_Draw_Text(卡号, 20.0f, 335.0f, 210.0f, ImColor(162, 62, 216, 255), true);
            Imgui_Draw_List(340.0f, 228.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);

        }

        {
            ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
            ImGui::SetCursorPos(ImVec2(335, 249));
            ImGui::SetNextItemWidth(205);//Height
            ImGui::InputText("##InputText4", 请填写卡密, IM_ARRAYSIZE(请填写卡密));
            ImGui::PopStyleColor();

            Imgui_Draw_Text(卡密, 20.0f, 335.0f, 254.0f, ImColor(162, 62, 216, 255), true);
            Imgui_Draw_List(340.0f, 272.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);

        }

        {
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
            ImGui::SetCursorPos(ImVec2(405.0f, 302.0f));
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(129, 152, 251, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(162, 62, 216, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(129, 152, 251, 100));

            if (ImGui::Button(会员注册.c_str(), ImVec2(137.0f, 45.0f)))
            {
                RegDemo();
            }

            ImGui::PopStyleVar();
            ImGui::PopStyleColor();
        }
    }
    else if (Settings::Tab == 3)
    {
        Imgui_Draw_Text(充值续费, 35.0f, 283.0f, 40.0f, ImColor(162, 62, 216, 255), false);
        auto textSize = childHeaderFont->CalcTextSizeA(35.0f, FLT_MAX, NULL, 充值续费.c_str());
        Imgui_Draw_List(283.0f, 75.0f, textSize.x, ImColor(162, 62, 216, 255), 1.0f);

        {
            ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
            ImGui::SetCursorPos(ImVec2(335, 117));
            ImGui::SetNextItemWidth(205);//Height
            ImGui::InputText("##InputText1", 请填写账号, IM_ARRAYSIZE(请填写账号));
            ImGui::PopStyleColor();

            Imgui_Draw_Text(账号, 20.0f, 335.0f, 122.0f, ImColor(162, 62, 216, 255), true);
            Imgui_Draw_List(340.0f, 140.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);

        }

        {
            ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
            ImGui::SetCursorPos(ImVec2(335, 161));
            ImGui::SetNextItemWidth(205);//Height
            ImGui::InputText("##InputText2", 请填写密码, IM_ARRAYSIZE(请填写密码), ImGuiInputTextFlags_Password);
            ImGui::PopStyleColor();

            Imgui_Draw_Text(密码, 20.0f, 335.0f, 166.0f, ImColor(162, 62, 216, 255), true);
            Imgui_Draw_List(340.0f, 184.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);

        }

        {
            ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
            ImGui::SetCursorPos(ImVec2(335, 205));
            ImGui::SetNextItemWidth(205);//Height
            ImGui::InputText("##InputText3", 请填写卡号, IM_ARRAYSIZE(请填写卡号));
            ImGui::PopStyleColor();

            Imgui_Draw_Text(卡号, 20.0f, 335.0f, 210.0f, ImColor(162, 62, 216, 255), true);
            Imgui_Draw_List(340.0f, 228.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);

        }

        {
            ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
            ImGui::SetCursorPos(ImVec2(335, 249));
            ImGui::SetNextItemWidth(205);//Height
            ImGui::InputText("##InputText4", 请填写卡密, IM_ARRAYSIZE(请填写卡密));
            ImGui::PopStyleColor();

            Imgui_Draw_Text(卡密, 20.0f, 335.0f, 254.0f, ImColor(162, 62, 216, 255), true);
            Imgui_Draw_List(340.0f, 272.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);

        }

        {
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
            ImGui::SetCursorPos(ImVec2(405.0f, 302.0f));
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(129, 152, 251, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(162, 62, 216, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(129, 152, 251, 100));

            if (ImGui::Button(充值续费.c_str(), ImVec2(137.0f, 45.0f)))
            {
                LongDemo();
            }

            ImGui::PopStyleVar();
            ImGui::PopStyleColor();
        }
    }
    else if (Settings::Tab == 4)
    {
        Imgui_Draw_Text(修改密码, 35.0f, 283.0f, 40.0f, ImColor(162, 62, 216, 255), false);
        auto textSize = childHeaderFont->CalcTextSizeA(35.0f, FLT_MAX, NULL, 修改密码.c_str());
        Imgui_Draw_List(283.0f, 75.0f, textSize.x, ImColor(162, 62, 216, 255), 1.0f);


        {
            ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
            ImGui::SetCursorPos(ImVec2(335, 117));
            ImGui::SetNextItemWidth(205);//Height
            ImGui::InputText("##InputText1", 请填写账号, IM_ARRAYSIZE(请填写账号));
            ImGui::PopStyleColor();

            Imgui_Draw_Text(账号, 20.0f, 335.0f, 122.0f, ImColor(162, 62, 216, 255), true);
            Imgui_Draw_List(340.0f, 140.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);

        }

        {
            ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
            ImGui::SetCursorPos(ImVec2(335, 161));
            ImGui::SetNextItemWidth(205);//Height
            ImGui::InputText("##InputText2", 请填写密码, IM_ARRAYSIZE(请填写密码), ImGuiInputTextFlags_Password);
            ImGui::PopStyleColor();

            Imgui_Draw_Text(密码, 20.0f, 335.0f, 166.0f, ImColor(162, 62, 216, 255), true);
            Imgui_Draw_List(340.0f, 184.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);

        }

        {
            ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
            ImGui::SetCursorPos(ImVec2(335, 205));
            ImGui::SetNextItemWidth(205);//Height
            ImGui::InputText("##InputText3", 请填写新密码, IM_ARRAYSIZE(请填写新密码));
            ImGui::PopStyleColor();

            Imgui_Draw_Text(新密码, 20.0f, 335.0f, 210.0f, ImColor(162, 62, 216, 255), true);
            Imgui_Draw_List(340.0f, 228.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);

        }

        {
            ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(153, 153, 153, 255)); // 设置文字颜色
            ImGui::SetCursorPos(ImVec2(335, 249));
            ImGui::SetNextItemWidth(205);//Height
            ImGui::InputText("##InputText4", 请填写确认密码, IM_ARRAYSIZE(请填写确认密码));
            ImGui::PopStyleColor();

            Imgui_Draw_Text(确认密码, 20.0f, 335.0f, 254.0f, ImColor(162, 62, 216, 255), true);
            Imgui_Draw_List(340.0f, 272.0f, 205.0f, ImColor(162, 62, 216, 255), 1.0f);

        }

        {
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
            ImGui::SetCursorPos(ImVec2(405.0f, 302.0f));
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(129, 152, 251, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(162, 62, 216, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(129, 152, 251, 100));

            if (ImGui::Button(修改密码.c_str(), ImVec2(137.0f, 45.0f)))
            {
                BangDemo();
            }

            ImGui::PopStyleVar();
            ImGui::PopStyleColor();
        }
    }
    else if (Settings::Tab == 5)
    {
        Imgui_Draw_Text(常规设置, 35.0f, 283.0f, 40.0f, ImColor(162, 62, 216, 255), false);
        auto textSize = childHeaderFont->CalcTextSizeA(35.0f, FLT_MAX, NULL, 常规设置.c_str());
        Imgui_Draw_List(283.0f, 75.0f, textSize.x, ImColor(162, 62, 216, 255), 1.0f);


        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.5f, 0.5f)); // 设置居中对齐
        ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(255, 255, 255, 255)); // 设置文字颜色
        ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor(129, 152, 251, 255));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor(162, 62, 216, 255));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor(129, 152, 251, 100));

        ImGui::SetCursorPos(ImVec2(286.0f, 110.0f));
        if (ImGui::Button(VMProtectDecryptStringA(菜单按键自定义.c_str()), ImVec2(110, 35)))
        {
            if (Bsphp::取游戏进程("GTA5.exe") || Bsphp::取游戏进程("gta5.exe"))
            {
                CString 按键自定义路径 = Bsphp::获取当前运行路径不带文件名() + "FamilyGTA\\Hotkeys.json";
                // 打开文件夹
                ShellExecute(NULL, "open", "notepad.exe", 按键自定义路径, NULL, SW_SHOWDEFAULT);
            }
            else if (Bsphp::取游戏进程("RDR2.exe") || Bsphp::取游戏进程("rdr2.exe"))
            {
                CString 按键自定义路径 = Bsphp::获取当前运行路径不带文件名() + "FamilyRDR\\Hotkeys.json";
                // 打开文件夹
                ShellExecute(NULL, "open", "notepad.exe", 按键自定义路径, NULL, SW_SHOWDEFAULT);
            }
            else
            {
                提示文本信息 = VMProtectDecryptStringA(未检测到游戏程序.c_str());
            }
        }

        ImGui::SetCursorPos(ImVec2(420.0f, 110.0f));
        if (ImGui::Button(VMProtectDecryptStringA(菜单界面自定义.c_str()), ImVec2(110, 35)))
        {
            if (Bsphp::取游戏进程("GTA5.exe") || Bsphp::取游戏进程("gta5.exe"))
            {
                CString 界面自定义路径 = Bsphp::获取当前运行路径不带文件名() + "FamilyGTA\\Settings.json";
                // 打开文件夹
                ShellExecute(NULL, "open", "notepad.exe", 界面自定义路径, NULL, SW_SHOWDEFAULT);
            }
            else if (Bsphp::取游戏进程("RDR2.exe") || Bsphp::取游戏进程("rdr2.exe"))
            {
                CString 界面自定义路径 = Bsphp::获取当前运行路径不带文件名() + "FamilyRDR\\Settings.json";
                // 打开文件夹
                ShellExecute(NULL, "open", "notepad.exe", 界面自定义路径, NULL, SW_SHOWDEFAULT);
            }
            else
            {
                提示文本信息 = VMProtectDecryptStringA(未检测到游戏程序.c_str());
            }
        }

        ImGui::SetCursorPos(ImVec2(286.0f, 160.0f));
        if (ImGui::Button(VMProtectDecryptStringA(查看运行日志.c_str()), ImVec2(110, 35)))
        {
            if (Bsphp::取游戏进程("GTA5.exe") || Bsphp::取游戏进程("gta5.exe"))
            {
                CString 查看运行日志路径 = Bsphp::获取当前运行路径不带文件名() + "FamilyGTA\\backup\\Family.log";
                // 打开文件夹
                ShellExecute(NULL, "open", "notepad.exe", 查看运行日志路径, NULL, SW_SHOWDEFAULT);
            }
            else if (Bsphp::取游戏进程("RDR2.exe") || Bsphp::取游戏进程("rdr2.exe"))
            {
                CString 查看运行日志路径 = Bsphp::获取当前运行路径不带文件名() + "FamilyRDR\\backup\\Family.log";
                // 打开文件夹
                ShellExecute(NULL, "open", "notepad.exe", 查看运行日志路径, NULL, SW_SHOWDEFAULT);
            }
            else
            {
                提示文本信息 = VMProtectDecryptStringA(未检测到游戏程序.c_str());
            }
        }

        ImGui::SetCursorPos(ImVec2(420.0f, 160.0f));
        if (ImGui::Button(VMProtectDecryptStringA(打开程序目录.c_str()), ImVec2(110, 35)))
        {
            // 打开文件夹
            ShellExecute(NULL, "open", Bsphp::获取当前运行路径不带文件名(), NULL, NULL, SW_SHOWDEFAULT);
        }

        ImGui::SetCursorPos(ImVec2(286.0f, 210.0f));
        if (ImGui::Button(VMProtectDecryptStringA(清理云缓存文件.c_str()), ImVec2(110, 35)))
        {
            会员登录 = false;
            注册会员 = false;
            续费充值 = false;
            变更密码 = false;
            清理云端缓存文件();
            提示文本信息 = VMProtectDecryptStringA(已清理请重新打开登陆器.c_str());
        }

        ImGui::SetCursorPos(ImVec2(420.0f, 210.0f));
        if (ImGui::Button(VMProtectDecryptStringA("用户使用须知"), ImVec2(110, 35)))
        {
            show_demo_window_2 = true;
        }

        ImGui::PopStyleVar();
        ImGui::PopStyleColor();

        ImGui::SetCursorPos(ImVec2(286.0f, 270.0f));
        ImGui::TextColored((ImVec4)ImColor(162, 62, 216, 255), VMProtectDecryptStringA("当前版本"));
        ImGui::SetCursorPos(ImVec2(286.0f, 300.0f));

        auto textSize5 = childHeaderFont->CalcTextSizeA(15.0f, FLT_MAX, NULL, "当前版本");
        Imgui_Draw_List(286.0f, 285.0f, textSize5.x, ImColor(162, 62, 216, 255), 1.0f);

        std::ostringstream aa;
        aa << VMProtectDecryptStringA("GTA5:") << 默认GTA5版本;

        ImGui::TextColored((ImVec4)ImColor(162, 62, 216, 255), aa.str().c_str());

        ImGui::SetCursorPos(ImVec2(440.0f, 300.0f));

        std::ostringstream bb;
        bb << VMProtectDecryptStringA("RDR2:") << 默认RDR2版本;

        ImGui::TextColored((ImVec4)ImColor(162, 62, 216, 255), bb.str().c_str());
    }

    //ImGui::SetCursorPos(ImVec2(13.0f, 350.0f));
    //ImGui::TextColored((ImVec4)ImColor(162, 62, 216, 255), 提示文本信息.c_str());
    Imgui_Draw_Text(提示文本信息, 15.0f, 240.0f, 360.0f, ImColor(162, 62, 216, 255), false);

    ImGui::End();

    VMProtectEnd();
}

bool isWin7()
{
    OSVERSIONINFOEX osvi;
    BOOL bOsVersionInfoEx;

    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO*)&osvi);

    // win7的系统版本为NT6.1
    if (VER_PLATFORM_WIN32_NT == osvi.dwPlatformId &&
        osvi.dwMajorVersion == 6 &&
        osvi.dwMinorVersion == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CreateDeviceD3D(HWND hWnd)
{
    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;
    return true;
}

void CleanupDeviceD3D()
{
    if (g_pd3dDevice) {
        g_pd3dDevice->Release(); g_pd3dDevice = NULL;
    }
    if (g_pD3D) {
        g_pD3D->Release(); g_pD3D = NULL;
    }
}

void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT Result = g_pd3dDevice->Reset(&g_d3dpp);
    if (Result == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}

DWORD WINAPI ThreadFun1(LPVOID lpParameter)
{
    VMProtectBeginUltra("ThreadFun");

    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandleA(0), 0,0,0, 0, "IMGUI BASE", 0 };
    RegisterClassEx(&wc);
    Window = CreateWindow(wc.lpszClassName, "IMGUI BASE", WS_POPUP, 0, 0, 5, 5, 0, 0, wc.hInstance, 0);

    //窗口总处于最上面
    SetWindowPos(Window, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);

    if (!CreateDeviceD3D(Window))
    {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    ShowWindow(Window, SW_HIDE);
    UpdateWindow(Window);

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();

    ostringstream ss;
    ss << Bsphp::获取当前运行路径不带文件名() << "Login Language.json";
    读取菜单文字功能(ss.str().c_str());

    std::ostringstream aa;
    aa << Bsphp::获取当前运行路径不带文件名() << "FamilyGTA\\Fonts\\" << "Fonts.ttf";

    std::ostringstream bb;
    bb << getenv("PUBLIC") << "\\" << VMProtectDecryptStringA("Fonts.ttf");

    fstream aaytd_files;
    aaytd_files.open(aa.str(), ios::in);
    if (aaytd_files)
    {
        CopyFile(aa.str().c_str(), bb.str().c_str(), false);//false代表覆盖，true不覆盖

        io.Fonts->AddFontFromFileTTF(bb.str().c_str(), 15.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());

        childHeaderFont = io.Fonts->AddFontFromFileTTF(bb.str().c_str(), 35.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    }

    HWND hd = GetDesktopWindow();
    // 方法一
    RECT rect;
    // 只获得窗口客户区的大小
    GetClientRect(hd, &rect);
    client_width = (rect.right - rect.left);
    client_height = (rect.bottom - rect.top);

    io.IniFilename = nullptr;
    io.LogFilename = nullptr;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
    ImFontConfig icons_config;

    io.IniFilename = nullptr;
    io.LogFilename = nullptr;

    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.OversampleH = 3;
    icons_config.OversampleV = 3;

    ImFontConfig CustomFont;
    CustomFont.FontDataOwnedByAtlas = false;

    ImGui_ImplWin32_Init(Window);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    load_image();

    MSG msg;
    memset(&msg, 0, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }

        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        if (show_demo_window_2)
        {
            用户须知(&show_demo_window_2);
        }

        if (show_demo_window)
        {
            ShowDemo(&show_demo_window);
        }
        else
        {
            ExitProcess(0);
        }

        // Rendering
        ImGui::EndFrame();

        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
            ResetDevice();
        }
        if (!Enabled) {
            msg.message = WM_QUIT;
        }
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    DestroyWindow(Window);
    UnregisterClass(wc.lpszClassName, wc.hInstance);

    VMProtectEnd();
    return 0;
}

int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    HANDLE hThread2 = CreateThread(NULL, 0, ThreadFun2, NULL, 0, NULL);
    CloseHandle(hThread2);

    HANDLE hThread1 = CreateThread(NULL, 0, ThreadFun1, NULL, 0, NULL);
    WaitForSingleObject(hThread1, INFINITE);

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU)
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}