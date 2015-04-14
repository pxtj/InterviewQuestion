/************************************************************************/
/* 剑指offer：2	实现单例模式
/* 方法：使用类的私有静指针变量指向类的唯一的实例，并用一个公有的静态方法
/*	获取该实例
/* 20140830
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <memory>

using namespace std;

// 方法：使用类的私有静指针变量指向类的唯一的实例，并用一个公有的静态方法获取该实例
// 获取实例的唯一方法就是调用getInstance函数，如果不通过这个函数，任何创建类的实例的方法
// 都会失败，因为类的构造函数是私有的。将指向类的实例的指针定义为static，则getInstace
// 函数只有在首次被调用的时候会创建类的实例，以后每次调用都会返回相同实例的指针；
class CSingleton
{
private:
	static CSingleton* m_ptrInstance;
private:
	CSingleton()
	{
		cout << "这个是私有的构造函数" << endl;
	}

public:
	static CSingleton* getInstace()
	{
		if (m_ptrInstance == NULL)
		{
			m_ptrInstance = new CSingleton();
		}
		return m_ptrInstance;
	}

	
};
//类中的静态数据成员一定要在对应的cpp文件中定义
//类中的静态数据成员是在类域中的全局变量，属于整个类共有，不属于特定的对象，必须在cpp中初始化
CSingleton* CSingleton::m_ptrInstance = NULL;

class CSingleton2
{
private:
	CSingleton2()
	{
	}
	CSingleton2(const CSingleton2&);
	CSingleton2& operator=(const CSingleton2&);

public:
	static CSingleton2& GetInstance()
	{
		static CSingleton2 sigleInstance;
		return sigleInstance;
	}
	
};


int main()
{
	CSingleton* p1 = CSingleton::getInstace();
	CSingleton* p2 = CSingleton::getInstace();

	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	
	return 0;


}



