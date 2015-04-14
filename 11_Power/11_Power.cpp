/************************************************************************/
/* 11:��ֵ�������η�
/* 20140831
/************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

//�˺������ܴ���exponent<0ʱ���������exponentΪ����ʱ
double Power(double base, int exponent)
{
	double result = 1.0;
	while (exponent--)
	{
		result *= base;
	}
	return result;
}

//��Ҫ���ǵ����أ�
//1.exponentΪ0���߸���
//2.baseΪ0
//3.baseΪ0��exponentΪ����
//4.0��0�η�����ѧ��û�����壬����0����1�����ԣ��˴�����0
bool g_InvalidInput = false; //ȫ�ֱ�������ʾbase==0&&exponent<0,�Ƿ�����
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

//���ϸ���һ���㷨
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
	if (exponent & 0x01 == 1) //��exponent%2 ��= 0	//���exponent������������ڳ���base
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