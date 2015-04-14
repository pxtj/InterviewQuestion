/************************************************************************/
/* 22:ջ��ѹ�뵯������
/* �����������У�һ����ջ��ѹ�����У�һ����ջ�ĵ�������
/* �жϵڶ��������Ƿ�Ϊ��ջ�ĵ�������
/* ˼·������һ������ջ��Ȼ��ѹջ��������ѹ�룬��ѹ��Ĺ����У����ݵ�������
/*	�ж��Ƿ���Ҫ����
/* 20140902
/************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

bool IsPosOrder(int* PushOrder, int* PopOrder, int length)
{
	if (PushOrder == NULL || PopOrder == NULL || length <= 0)
	{
		return false;
	}
	
	bool result = false;

	stack<int> s;
	
	int iPop = 0;
	for (int i = 0; i < length; ++i)
	{
		s.push(PushOrder[i]);
		while (!s.empty() && s.top() == PopOrder[iPop])
		{
			s.pop();
			iPop++;
		}
	}
	
	if (iPop == length)
	{
		result = true;
	}
	
	return result;
}


void Test()
{
	int pushOrder[] = {1,2,3,4,5};
	int popOrder[] = {4,5,3,2,1};

	bool isPopOrder = IsPosOrder(pushOrder, popOrder, 5);
	cout << isPopOrder << endl;

	int popOrder2[] = {4,3,5,1,2};
	isPopOrder = IsPosOrder(pushOrder, popOrder2, 5);
	cout << isPopOrder << endl;
}


void Test1()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};
    bool isPopOrder = IsPosOrder(push, pop, nLength);
    cout << "Test1: " << isPopOrder << endl;
    
}

void Test2()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};
    bool isPopOrder = IsPosOrder(push, pop, nLength);
    cout << "Test2: " << isPopOrder << endl;
    
}

void Test3()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};
    bool isPopOrder = IsPosOrder(push, pop, nLength);
    cout << "Test3: " << isPopOrder << endl;
    
}

void Test4()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};
    
    bool isPopOrder = IsPosOrder(push, pop, nLength);
    cout << "Test4: " << isPopOrder << endl;
}

// push��pop����ֻ��һ������
void Test5()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};
    bool isPopOrder = IsPosOrder(push, pop, nLength);
    cout << "Test5: " << isPopOrder << endl;

}

void Test6()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};
    bool isPopOrder = IsPosOrder(push, pop, nLength);
    cout << "Test6: " << isPopOrder << endl;

}

void Test7()
{
    bool isPopOrder = IsPosOrder(NULL, NULL, 0);
    cout << "Test7: " << isPopOrder << endl;
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

    return 0;
}



