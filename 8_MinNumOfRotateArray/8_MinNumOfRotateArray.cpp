/************************************************************************/
/* 8:��ת�������Сֵ
/* ��ת���飺��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ����֮Ϊ�������ת
/* ����һ����������������һ����ת�������ת�����е���С��Ԫ�ء�
/* www.leetcode.com�е�һ����
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

//����һ��ֱ�ӱ���һ�飬�����Сֵ
int GetMinNum(int* arr, int n)
{
	int minNum = arr[0];
	for (int i = 0; i < n; ++i)
	{
		if (minNum < arr[i])
		{
			minNum = arr[i];
		}
	}
	return minNum;
}


//�����������ֲ���
int MinInOrder(int* arr, int left, int right);
int GetMinNumInRotateArr(int* arr, int n)
{
	assert(arr != NULL && n > 0);

	int left = 0;
	int right = n - 1;
	int mid = left;
	while(arr[left] >= arr[right])
	{
		if (right - left == 1)
		{
			mid = right;
			break;
		}
		mid = left + (right - left)/2;

		//���left��right��midָ��ͬ�������������
		//��ֻ��˳�����
		if (arr[left] == arr[right] && arr[mid] == arr[left])
		{
			return MinInOrder(arr, left, right);
		}

		if (arr[mid] >= arr[left])
		{
			left = mid ;
		}
		else if (arr[mid] <= arr[right])
		{
			right = mid ;
		}
	}
	return arr[mid];
}

int MinInOrder(int* arr, int left, int right)
{
	int minNum = arr[left];
	for (int i = left; i <= right; ++i)
	{
		if (minNum > arr[i])
		{
			minNum = arr[i];
		}
	}
	return minNum;
}

void Test()
{
	int arr[] = {3,4,5,1,2};
	int minNum = GetMinNumInRotateArr(arr, 5);
	cout << minNum <<endl;


	int arr2[] = {3,4,5,6,7,1,2};
	minNum = GetMinNumInRotateArr(arr2, 7);
	cout << minNum <<endl;
	
	int arr1[] = {8,10,15,1,2,3,4,5,6,7,};
	minNum = GetMinNumInRotateArr(arr1, 10);
	cout << minNum <<endl;

}

int main()
{
	Test();
	return 0;
}
	