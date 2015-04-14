/************************************************************************/
/* 28:字符串的全排列 
/************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

void Swap(char* str1, char* str2);
void Permutation(char* strSrc, int left, int right);
void StringPermutation(char* strSrc)
{
	if (strSrc == NULL)
	{
		return ;
	}
	Permutation(strSrc, 0, strlen(strSrc));
}
void Permutation(char* strSrc, int left, int right)
{
	if (strSrc == NULL)
	{
		return ;
	}
	if (left == right)
	{
		cout << strSrc << endl;
	}
	else
	{
		for (int i = left; i < right; ++i)
		{
			Swap(&strSrc[i], &strSrc[left]);
			Permutation(strSrc, left + 1, right);
			Swap(&strSrc[i], &strSrc[left]);
		}
	}
	
}
void Swap(char* str1, char* str2)
{
	char temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

//书上给的方法：

void Test()
{
	char str[] = "abcd";
	StringPermutation(str);
}

int main()
{
	Test();
	return 0;
}
