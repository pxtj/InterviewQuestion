/************************************************************************/
/* 14:调整数组顺序使奇数位于偶数前面
/* 使得奇数位于数组前面，偶数位于数组后边·
/* 20140901
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory>

using namespace std;

//1.奇偶各放到两个数组中，然后复制会原数组
void ReorderArray(int* arr, int n)
{
	int* arr1 = (int*)calloc(n,sizeof(int));
	int* arr2 = (int*)calloc(n,sizeof(int));
	int i = 0, j = 0;
	int p = 0;
	while(p < n)
	{
		if (arr[p]%2 == 0)
		{
			arr2[i++] = arr[p];
		}
		else
			arr1[j++] = arr[p];
		p++;
	}

	memcpy(arr, arr1, j*sizeof(int));
	memcpy(arr+j, arr2, i*sizeof(int));

	free(arr1);
	free(arr2);
}

//2.根据快速排序算法
int Partion(int* arr, int left, int right);
void ReorderArray(int* arr, int left, int right)
{
	if (left < right)
	{
		int pivot = Partion(arr, left, right);

		ReorderArray(arr, left, pivot - 1);
		ReorderArray(arr, pivot + 1, right);
	}
}
int Partion(int* arr, int left, int right)
{
	int povit = arr[left];
	int i = left;
	int j = right;
	if (left < right)
	{
		while (i < j)
		{
			while (i < j && arr[j]%2 == 0)
			{
				j--;
			}
			arr[i] = arr[j];
			while (i < j && arr[i]%2 != 0)
			{
				i++;
			}
			arr[j] = arr[i];
		}
		arr[i] = povit;
	}
	return i;
}

//3.维护两个指针，一个指向第一个数，一个指向最后一个数，依次判断交换前后位置的数
//快速排序中的Partion就可以
int ReorderArrayByPartion(int*arr, int left, int right);	//见2中Partion
void ReorderArrayByTwoPointer(int*arr, int n)
{
	if (arr == NULL || n <= 0)
	{
		return ;
	}
	int* pBegin = arr;
	int* pEnd = arr + n - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && (*pBegin & 0x01) != 0)
		{
			pBegin++;
		}
		while (pBegin < pEnd && (*pEnd & 0x01) == 0)
		{
			pEnd--;
		}
		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

//4.用函数指针，解决一类问题
void ReorderArrayByFunPointer(int* arr, int n, bool (*fun)(int))
{
	if (arr == NULL || n <= 0)
	{
		return ;
	}
	int* pBegin = arr;
	int* pEnd = arr + n - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !fun(*pBegin))
		{
			pBegin++;
		}
		while (pBegin < pEnd && fun(*pEnd))
		{
			pEnd--;
		}
		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}

	}
}
bool IsEven(int n)
{
	return (n & 1) == 0;
}

void Reorder(int*arr, int n)
{
	//根据不同的要求，更换不同的函数指针
	ReorderArrayByFunPointer(arr, n, IsEven);
}



void Test()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};

	//1.
	//ReorderArray(arr, 10);
	//2.根据快速排序的分割算法
	//ReorderArray(arr, 0, 9);
	//3.两个指针
//	ReorderArrayByTwoPointer(arr, 10);
	//4.根据不同的要求，传入不同函数指针
	Reorder(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	Test();
	return 0;
}
