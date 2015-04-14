/************************************************************************/
/* ������ջʵ�ֶ��У�
/* �ֱ�ʵ����ͷ�����Ӻ�β�����
/* 20140830
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

//������ջ��ʵ��һ������
template<typename T> class CQueue
{
private:
	stack<T> stack1;
	stack<T> stack2;

public:
	CQueue(){}
	~CQueue(){}
	void appendTail(const T& node);
	T deleteHead();
};

template<typename T> void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}

	if (stack2.empty())
	{
		cout << "queue is empty." << endl;
		throw new exception("queue is empty.");
	}

	T stack2Top = stack2.top();
	stack2.pop();
	return stack2Top;
}
////////////////////////////////////////////////////////////////////////////////


//������������ʵ��һ��ջ
template<typename T> class CStack
{
private:
	queue<T> queue1;
	queue<T> queue2;

public:
	CStack(){}
	~CStack(){}
	void push(const T& node);
	T pop();
};

template<typename T> void CStack<T>::push(const T& node)
{
	queue1.push(node);
}

template<typename T> T CStack<T>::pop()
{
	if (!queue1.empty())
	{
		while(queue1.size() != 1)
		{
			queue2.push(queue1.front());
			queue1.pop();
		}
		T head = queue1.front();
		queue1.pop();
		return head;
	}
	else
	{
		if (!queue2.empty())
		{
			while (queue2.size() != 1)
			{
				queue1.push(queue2.front());
				queue2.pop();
			}
			T head = queue2.front();
			queue2.pop();
			return head;
		}
		else
		{
			cout << "stack is empty." << endl;
			throw new exception("stack is empty.");
		}
	}
}


int main()
{
	cout << "������ջ��ʵ��һ�����У� " << endl;
	CQueue<int> q;
	for (int i = 0; i < 10; ++i)
	{
		q.appendTail(i+1);
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << q.deleteHead() << " ";
	}
	cout << endl;



	//������������ʵ��һ��ջ
	cout << endl;
	cout << "����������ʵ��һ��ջ��" << endl; 
	CStack<int> s;
	for (int i = 0; i < 10; ++i)
	{
		s.push(i+1);
	}
	for (int i = 0; i < 3; ++i)
	{
		cout << s.pop() << endl;
	}
	s.push(11);
	s.push(12);

	cout << s.pop() << endl;
	cout << s.pop() << endl;


	return 0;
}