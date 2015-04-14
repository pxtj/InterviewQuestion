/*********************************************************************************************
* ������4��P44
* ��Ŀ��ʵ��һ�����������ַ����е�ÿ���ո��滻�ɡ�%20����
*	���磺���롰we are happy.",�������"we%20are%20happy."

* 20140806
*********************************************************************************************/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void ReplaceString(string& strSrc, string& strReplace, string& strDest)
{
	assert(strSrc.size() != 0 && strReplace.size() != 0 && strDest.size() != 0);

	while (1)
	{
		int pos = strSrc.find(strReplace);
		if (pos == string::npos) break;
		strSrc.replace(pos, strReplace.size(), strDest);
	}

}


//C���ԣ����ϴ�
void ReplaceBlank(char* str, int len)
{
	if(str == NULL || strlen(str) <= 0)
		return ;
	int originalLen = 0;
	int numOfBlank = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		++originalLen;
		if (str[i] == ' ')
		{
			++numOfBlank;
		}
		++i;
	}

	//newLenΪ���ո񻻳�%20֮��ĳ��ȣ�
	int newLen = originalLen + numOfBlank * 2;
	if (newLen > len)
	{
		return ;
	}

	int idxOfOriginal = originalLen;
	int idxOfNew = newLen;
	while (idxOfOriginal >= 0 && idxOfOriginal < idxOfNew)
	{
		if (str[idxOfOriginal] == ' ')
		{
			str[idxOfNew--] = '0';
			str[idxOfNew--] = '2';
			str[idxOfNew--] = '%';
		}
		else
		{
			str[idxOfNew--] = str[idxOfOriginal];
		}
		
		--idxOfOriginal;
	}
}

void Test()
{
	cout << "in test; " << endl;
	string strSrc, strReplace, strDest;

while(1)
{
	getline(cin, strSrc);
	getline(cin, strReplace);
	getline(cin, strDest);
	cout << "strSrc: " << strSrc << endl;
	cout << "strReplace: " << strReplace << endl;
	cout << "strDest: " << strDest << endl;

	ReplaceString(strSrc, strReplace, strDest);

	cout << "strSrc after replaced: " << strSrc << endl;

}
}

void Test2()
{
	cout << "in test2 " << endl;
	char str[100];
	gets(str);
	cout << "str: " << str <<endl;
	int len = 100;
	ReplaceBlank(str, len);
	cout << "str after replaced: " << str <<endl;
}







int main()
{
	Test();
	Test2();

	return 0;
}
