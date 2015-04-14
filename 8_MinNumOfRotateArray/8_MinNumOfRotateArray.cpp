/************************************************************************/
/* 8:旋转数组的最小值
/* 旋转数组：把一个数组最开始的若干个元素搬到数组的末尾，称之为数组的旋转
/* 输入一个递增排序的数组的一个旋转，输出旋转数组中的最小的元素。
/* www.leetcode.com中的一个题
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

//方法一：直接遍历一遍，求得最小值
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


//方法二：二分查找
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

		//如果left、right和mid指向同的三个数字相等
		//则只能顺序查找
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
	