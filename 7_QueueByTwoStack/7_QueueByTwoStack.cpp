/************************************************************************/
/* 用两个栈实现队列：
/* 分别实现在头部出队和尾部入队
/* 20140830
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

//用两个栈来实现一个队列
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


//用两个队列来实现一个栈
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
	cout << "用两个栈来实现一个队列： " << endl;
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



	//有两个队列来实现一个栈
	cout << endl;
	cout << "用两个队列实现一个栈：" << endl; 
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