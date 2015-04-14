/************************************************************************/
/* 10:��������1�ĸ���
/* 
/************************************************************************/
#include <iostream>
using namespace std;

//1.��2ȡ���ж��Ƿ���Ϊ1��������
//���ܴ����������
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

//2.����
//���ܲ�����ѭ�����������nΪһ��������ʱ�򣬻�������ѭ��
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

//3.����flag����flag���ƣ����������ж�n��ÿһλ�Ƿ�Ϊ1
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

//4.��һ��������ȥ1���ں�ԭ���������������㣬
//��Ѹ��������ұߵ�һ��1���0����������Ķ��������ж���λ1��
//�Ϳ��������ٴ�λ����
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