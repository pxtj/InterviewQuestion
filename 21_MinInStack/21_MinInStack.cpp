/************************************************************************/
/* 21:包含min函数的栈
/* 要求在O(1)的时间内得到min
/* 利用辅助栈记录min
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <exception>

using namespace std;

template<typename T> class CStackWithMin
{
private:
	stack<T> m_data;
	stack<T> m_min;
	
public:
	CStackWithMin(){}
	~CStackWithMin(){}
	void Push(T value);
	T Pop();
	T Min();
};

template<typename T> void CStackWithMin<T>::Push(T value)
{
	m_data.push(value);
	if (m_min.empty())
	{
		m_min.push(value);
	}
	else
	{
		if (value <= m_min.top())
		{
			m_min.push(value);
		}
		else
		{
			m_min.push(m_min.top());
		}
	}
}

template<typename T> T CStackWithMin<T>::Pop()
{
	if (m_data.empty())
	{
		cout << "m_data is empty." << endl;
		exception("m_data is empty.");
	}

	m_min.pop();
	T temp = m_data.top();
	m_data.pop();
	return temp;
}


template<typename T> T CStackWithMin<T>::Min()
{
	if (m_min.empty())
	{
		cout << "m_min is empty." << endl;
		exception("m_min is empty.");
	}
	return m_min.top();
}


void Test()
{
	CStackWithMin<int> s;
	s.Push(3);
	s.Push(4);
	s.Push(2);
	s.Push(5);
	s.Push(1);

	cout << s.Min() << endl;
	s.Pop();
	cout << s.Min() << endl;
	s.Pop();
	cout << s.Min() << endl;
	s.Pop();
	cout << s.Min() << endl;
	s.Pop();


}

int main()
{
	Test();
	return 0;
}