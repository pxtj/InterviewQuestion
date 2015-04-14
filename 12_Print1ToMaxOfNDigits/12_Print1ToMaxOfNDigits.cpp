/************************************************************************/
/* 12:��ӡ1������nλ��
/* ��������n����˳���ӡ����1������nλ����ʮ��������
/* ��������3�����ӡ1.2.3....һֱ������3λ��999
/* 20140831
/************************************************************************/

#include <iostream>
using namespace std;

//�˷���û�п��Ǵ������⣬���ܻ����
void Print1ToMaxOfNDigits_1(int n)
{
	long long unsigned int number = 1;
	long long unsigned int i = 0;
	while (i++ < n)
	{
		number *= 10;
	}
	for (i = 1; i < number; i++)
	{
		cout << i << endl;
	}
	return;
}

//ȫ����
void PrintNumber(char* number);
void Print1ToMaxNDigitsRecursively(char* number , int length, int index);
void Print1ToMaxNDigits(int n)
{
	if (n <= 0)
	{
		return ;
	}

	char* number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToMaxNDigitsRecursively(number, n, 0);
	}
	delete[] number;
}

void Print1ToMaxNDigitsRecursively(char* number , int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		Print1ToMaxNDigitsRecursively(number, length, index + 1);
	}
}

void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; ++i)
	{
		if (isBeginning0 && number[i] != '0')
		{
			isBeginning0 = false;
		}
		if (!isBeginning0)
		{
			cout << number[i] ;
		}
	}
	cout << endl;
}





int main()
{
	//Print1ToMaxOfNDigits_1(10);//15ʱ��û�������

	Print1ToMaxNDigits(10);

	return 0;
}