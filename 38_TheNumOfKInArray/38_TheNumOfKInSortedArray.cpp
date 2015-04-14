/************************************************************************/
/* 38:���������������г��ֵĴ���
/* ˼·���ö��ֲ���
/* 1.�ҵ�һ��K��λ�ã�������ǰ���������֪������K��ͳ��K�ĸ���
/* 2.ͨ�����ֲ��ң�ȷ����һ��K��λ�ú����һ��K��λ�ã�ֱ���������ô���
/* 20140903
/************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

//��������ͨ�����ֲ���ȷ����һ��K�����һ��K��λ�ã������ô���
int GetFirstPos(int* Arr, int length, int left, int right, int k);
int GetLastPos(int* Arr, int length, int left, int right, int k);
int GetNumOfKInSortedArray(int* Arr, int length, int k)
{
	if (Arr == NULL || length <= 0)
	{
		return 0;
	}
	int firstPos = GetFirstPos(Arr, length, 0, length - 1, k);
	int lastPos = GetLastPos(Arr, length, 0, length - 1, k);

	if (firstPos > -1 && lastPos > -1)
	{
		return lastPos - firstPos + 1;
	}
	return 0;
}
//ȷ����һ��K��λ��
int GetFirstPos(int* Arr, int length, int left, int right, int k)
{
	if (left > right)
	{
		return -1;
	}
	int mid = left + (right - left)/2;
	int midData = Arr[mid];
	if (midData == k)
	{
		if (mid > 0 && Arr[mid - 1] != k || mid == 0)
		{
			return mid;
		}
		else
			right = mid - 1;
	}
	else if (midData > k)
	{
		right = mid - 1;
	}
	else
		left = mid + 1;

	return GetFirstPos(Arr, length, left, right, k);
}
//ȷ�����һ��k��λλ��
int GetLastPos(int* Arr, int length, int left, int right, int k)
{
	if (left > right)
	{
		return -1;
	}
	int mid = left + (right - left)/2;
	int midData = Arr[mid];
	if (midData == k)
	{
		if (mid < length - 1 && Arr[mid + 1] != k || mid == length - 1)
		{
			return mid;
		}
		else
			left = mid + 1;
	}
	else if (midData > k)
	{
		right = mid - 1;
	}
	else
		left = mid + 1;

	return GetLastPos(Arr, length, left, right, k);
}

 //====================���Դ���====================
void Test(char* testName, int data[], int length, int k, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    int result = GetNumOfKInSortedArray(data, length, k);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// ���ҵ����ֳ�����������м�
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ��������������Ŀ�ͷ
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ��������������Ľ�β
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ����ֲ�����
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// ���ҵ����ֱȵ�һ�����ֻ�С��������
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// ���ҵ����ֱ����һ�����ֻ��󣬲�����
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// �����е����ִ�ͷ��β���ǲ��ҵ�����
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// �����е����ִ�ͷ��βֻ��һ���ظ������֣����ǲ��ҵ�����
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// ������ֻ��һ�����֣��ǲ��ҵ�����
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// ������ֻ��һ�����֣����ǲ��ҵ�����
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// ³���Բ��ԣ������ָ��
void Test11()
{
    Test("Test11", NULL, 0, 0, 0);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();

    return 0;
}


