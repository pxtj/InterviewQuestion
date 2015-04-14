//************************************************************************/
/* 9:斐波那契数
/* 输入n，求斐波那契数列的第n项。
/************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

//1.递归
int GetFibonacciArray(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return GetFibonacciArray(n-1) + GetFibonacciArray(n - 2);
}

//循环：
int GetFibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	int f1 = 0;
	int f2 = 1;
	for (int i = 2; i <= n; ++i)
	{
		int temp = f1 + f2;
		f1 = f2;
		f2 = temp;
	}
	return f2;
}

void Test()
{
	int f = GetFibonacci(10);
	cout << f << endl;

	int f1 = GetFibonacciArray(10);
	cout << f1 << endl;

	return ;
}

int main()
{
	Test();
	return 0;
}