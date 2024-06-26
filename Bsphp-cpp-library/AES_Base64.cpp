#pragma once
#include "auth.hpp"
#include <Shlwapi.h>
#include <ShlObj.h>
using namespace std;

char g_key[17] = "1f96139a02e47ac5";
char g_iv[17] = "gfdertfghjkuyrtg";

namespace Bsphp
{
	void 数据加密密码(const char* key) {
		memcpy((char*)g_key, key, 17);
	}

	//AES加密
	string EncryptionAES(const string& strSrc)
	{

		size_t length = strSrc.length();
		int block_num = length / BLOCK_SIZE + 1;
		//明文  
		char* szDataIn = new char[block_num * BLOCK_SIZE + 1];
		memset(szDataIn, 0x00, block_num * BLOCK_SIZE + 1);
		strcpy(szDataIn, strSrc.c_str());

		//进行PKCS7Padding填充。  
		int k = length % BLOCK_SIZE;
		int j = length / BLOCK_SIZE;
		int padding = BLOCK_SIZE - k;
		for (int i = 0; i < padding; i++)
		{
			szDataIn[j * BLOCK_SIZE + k + i] = padding;
		}
		szDataIn[block_num * BLOCK_SIZE] = '\0';

		//加密后的密文  
		char* szDataOut = new char[block_num * BLOCK_SIZE + 1];
		memset(szDataOut, 0, block_num * BLOCK_SIZE + 1);

		//进行进行AES的CBC模式加密  
		AES aes;
		aes.MakeKey(g_key, g_iv, 16, 16);
		aes.Encrypt(szDataIn, szDataOut, block_num * BLOCK_SIZE, AES::CBC);
		string str = base64_encode((unsigned char*)szDataOut,
			block_num * BLOCK_SIZE);
		delete[] szDataIn;
		delete[] szDataOut;
		return str;
	}

	string DecryptionAES(const string& strSrc) //AES解密  
	{
		string strData = base64_decode(strSrc);
		size_t length = strData.length();
		//密文  
		char* szDataIn = new char[length + 1];
		memcpy(szDataIn, strData.c_str(), length + 1);
		//明文  
		char* szDataOut = new char[length + 1];
		memcpy(szDataOut, strData.c_str(), length + 1);

		//进行AES的CBC模式解密  
		AES aes;
		aes.MakeKey(g_key, g_iv, 16, 16);
		aes.Decrypt(szDataIn, szDataOut, length, AES::CBC);
		//去PKCS7Padding填充  
		if (0x00 < szDataOut[length - 1] <= 0x16)
		{
			int tmp = szDataOut[length - 1];
			for (int i = length - 1; i >= length - tmp; i--)
			{
				if (szDataOut[i] != tmp)
				{
					memset(szDataOut, 0, length);
					break;
				}
				else
					szDataOut[i] = 0;
			}
		}
		string strDest(szDataOut);
		delete[] szDataIn;
		delete[] szDataOut;
		return strDest;
	}
}