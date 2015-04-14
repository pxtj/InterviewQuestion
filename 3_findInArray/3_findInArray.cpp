/*********************************************************************************
* ������3:��ά�����в���
* ��Ŀ����һ����ά�����У�ÿһ�а��մ����ҵ�����˳������
*	ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά����
*	��һ���������ж��������Ƿ��и�������
*
* ����һ��ֱ�ӱ�����O(m*n)��
* ������������ѯֵΪ:findNum,�����Ͻǿ�ʼ��������findNum������ǰһ�У�
*	  ��С��findNum��������һ�У����αȽϣ�֪���ҵ�findNum��
*	  ���Ӷȣ�O(m+n)
* 20140805
*
* adding:20140820
* ����1���ڴ��������ҳ���k���ֵ
*	�ⷨ1��ֱ��д��һ��һά���飬��ȡ��K���ֵ���ö�/����ѡ��O(nlogk),O(n)
*	�ⷨ2�����ÿһ�е���λ����Ȼ�����������λ������λ��midNum,
*		(ע�⣬midNum����������ֵ����λ��)
*		�����ϽǱ�midNumС��
*		���½Ǳ�midNum��Ȼ��ȥ���Ͻ������Ͻ���midNum�Ĺ�ϵ��ͳ�ƴ��ڼ�С��
*		midNum�����ĸ���ΪbiggerNum��smallerNum��
*		��biggerNum > k,���Ҵ���midNum���еĵ�biggerNUm-k�����
*		��smallerNum > k, ����С��midNum�еĵ�k�����
*		����midNum��Ϊ��K�������
*
* ����2���ҳ�����ֵ����λ����
*	�ⷨ�������������λ����Ϊ��K=floor(m*n/2)���������������1�����֮��
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


//���ϳ���P41��
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


//�����ϴ���Ĳ��ԣ�
void Test()
{

	int arr[4][4] = {{1,2,8,9},{2,4,9,12}, {4,7,10,13},{6,8,11,15}};
	bool result = Find2((int*)arr, 4, 4, 7); //ע�⴫��
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

