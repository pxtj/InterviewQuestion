/************************************************************************/
/* 10:二进制中1的个数
/* 
/************************************************************************/
#include <iostream>
using namespace std;

//1.除2取余判断是否是为1，并计数
//不能处理负数的情况
int GetOneNum1(int n)
{
	int num = 0;
	while (n )
	{
		if(n%2 == 1) num++;
		n = n/2;
	}
	return num;
}

//2.右移
//可能产生死循环，当输入的n为一个负数的时候，会引起死循环
int GetOneNum2(int n)
{
	int num = 0;
	while (n)
	{
		if(n & 0x01)
			num++;
		n = n>>1;
	}
	return num;
}

//3.设置flag，将flag左移，用其依次判断n的每一位是否为1
int GetOneNum3(int n)
{
	int num = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (flag & n)
		{
			num++;
		}
		flag = flag << 1;
	}
	return num;
}

//4.把一个整数减去1，在和原来的整数做与运算，
//会把该整数最右边的一个1变成0。则此整数的二进制中有多少位1，
//就可以做多少次位运算
int GetOneNum4(int n)
{
	int num = 0;
	while (n)
	{
		num++;
		n = n & (n - 1);
	}
	return num;
}

void Test()
{
	int n = 31;
	cout << GetOneNum1(n) << endl;
	cout << GetOneNum2(n) << endl;
	cout << GetOneNum3(n) << endl;
	cout << GetOneNum4(n) << endl;

	n = -31;
	cout << GetOneNum1(n) << endl;
	//cout << GetOneNum2(n) << endl;
	cout << GetOneNum3(n) << endl;
	cout << GetOneNum4(n) << endl;
}



int main()
{
	Test();
	return 0;
}