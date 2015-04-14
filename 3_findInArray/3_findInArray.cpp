/*********************************************************************************
* 面试题3:二维数组中查找
* 题目：在一个二维数组中，每一行按照从左到右递增的顺序排序，
*	每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组
*	和一个整数，判断数组中是否含有该整数；
*
* 方法一：直接遍历，O(m*n)；
* 方法二：若查询值为:findNum,从右上角开始，若大于findNum，则往前一列，
*	  若小于findNum，则网下一行，依次比较，知道找到findNum。
*	  复杂度：O(m+n)
* 20140805
*
* adding:20140820
* 问题1：在此数组中找出第k大的值
*	解法1：直接写成一个一维数组，求取第K大的值，用堆/快速选择，O(nlogk),O(n)
*	解法2：求出每一行的中位数，然后求出整个中位数的中位数midNum,
*		(注意，midNum不是整个数值的中位数)
*		则左上角比midNum小；
*		右下角比midNum大，然后去右上角与左上角与midNum的关系，统计大于及小于
*		midNum的数的个数为biggerNum及smallerNum，
*		若biggerNum > k,则找大于midNum数中的第biggerNUm-k大的数
*		若smallerNum > k, 则找小于midNum中的第k大的数
*		否则，midNum即为第K大的数；
*
* 问题2：找出此数值的中位数；
*	解法：整个数组的中位数即为第K=floor(m*n/2)大的数，根据问题1，求解之；
*******************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

int Find(int arr[][4], int row, int column, int n)
{
	assert(arr != NULL && row > 0 && column > 0);
	int i = 0, j = 0;

	for (i = 0, j = column - 1; i < row && j >= 0; i++, j--)
	{
		if (arr[i][j] > n)
		{
			i--;
		}
		else if (arr[i][j] < n)
		{
			j++;
		}
		else
		{
			cout <<"i: " << i <<"  j: " << j << "   ";
			return arr[i][j];
		}
	}

	return -1;
}


//书上程序：P41：
bool Find2(int* matrix, int rows, int columns, int number)
{
	bool found = false;

	if (matrix != NULL && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{
			if (matrix[row * columns + column] == number)
			{
				found = true;
				cout <<"row: " << row <<"  colum: " << column << "   ";
				break;
			}
			else if(matrix[row * columns + column] > number)
				--column;
			else
				++row;
		}
	}

	return found;
}


//对书上代码的测试：
void Test()
{

	int arr[4][4] = {{1,2,8,9},{2,4,9,12}, {4,7,10,13},{6,8,11,15}};
	bool result = Find2((int*)arr, 4, 4, 7); //注意传参
	if(result)
		cout << "found!"<<endl;
	else
		cout << "no this number!" << endl;
}



int main()
{
	int arr[4][4] = {{1,2,8,9},{2,4,9,12}, {4,7,10,13},{6,8,11,15}};
	int found = Find(arr, 4, 4, 6);
	if (found == -1)
	{
		cout << "no this number in array." << endl;
	}
	else
		cout << found <<endl;


	Test();

	return 0;
}

