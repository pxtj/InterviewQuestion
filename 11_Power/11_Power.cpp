/************************************************************************/
/* 11:数值的整数次方
/* 20140831
/************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

//此函数不能处理exponent<0时的情况，即exponent为负数时
double Power(double base, int exponent)
{
	double result = 1.0;
	while (exponent--)
	{
		result *= base;
	}
	return result;
}

//需要考虑的因素：
//1.exponent为0或者负数
//2.base为0
//3.base为0且exponent为负数
//4.0的0次方在数学上没有意义，返回0或者1都可以，此处返回0
bool g_InvalidInput = false; //全局变量，标示base==0&&exponent<0,非法输入
double PowerCorrect(double base, int exponent)
{
	g_InvalidInput = false;
	if ((base - 0.0) < 1e-5 )
	{
		if(exponent < 0)g_InvalidInput = true;
		return 0;
	}
	int exp = exponent;
	if (exponent < 0)
	{
		exp = -exp;
	}
	double result = 1.0;
	while (exp--)
	{
		result *= base;
	}

	if (exponent < 0)
	{
		return 1.0/result;
	}
	return result;


}

//书上给的一个算法
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	if (exponent == 1)
	{
		return base;
	}

	double result = PowerWithUnsignedExponent(base, exponent>>1);
	result *= result;
	if (exponent & 0x01 == 1) //即exponent%2 ！= 0	//如果exponent是奇数，最后在乘以base
	{
		result *= base;
	}
	return result;
}

int main()
{
	cout << Power(0,0) << endl;
	cout << PowerCorrect(0,-5) << endl;
	//cout << pow((double)0, 2) << endl;
	cout << g_InvalidInput << endl;


	cout << PowerWithUnsignedExponent(2.5, 2) << endl;
	return 0;

}