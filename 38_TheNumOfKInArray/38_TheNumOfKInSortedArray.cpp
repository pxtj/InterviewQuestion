/************************************************************************/
/* 38:数组在排序数组中出现的次数
/* 思路：用二分查找
/* 1.找到一个K的位置，依次往前往后遍历，知道不是K，统计K的个数
/* 2.通过二分查找，确定第一个K的位置和最后一个K的位置，直接相减，求得次数
/* 20140903
/************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

//方法二：通过二分查找确定第一个K及最后一个K的位置，相减求得次数
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
//确定第一个K的位置
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
//确定最后一个k单位位置
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

 //====================测试代码====================
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

// 查找的数字出现在数组的中间
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
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


