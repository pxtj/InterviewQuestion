/************************************************************************/
/* ��ָoffer��2	ʵ�ֵ���ģʽ
/* ������ʹ�����˽�о�ָ�����ָ�����Ψһ��ʵ��������һ�����еľ�̬����
/*	��ȡ��ʵ��
/* 20140830
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <memory>

using namespace std;

// ������ʹ�����˽�о�ָ�����ָ�����Ψһ��ʵ��������һ�����еľ�̬������ȡ��ʵ��
// ��ȡʵ����Ψһ�������ǵ���getInstance�����������ͨ������������κδ������ʵ���ķ���
// ����ʧ�ܣ���Ϊ��Ĺ��캯����˽�еġ���ָ�����ʵ����ָ�붨��Ϊstatic����getInstace
// ����ֻ�����״α����õ�ʱ��ᴴ�����ʵ�����Ժ�ÿ�ε��ö��᷵����ͬʵ����ָ�룻
class CSingleton
{
private:
	static CSingleton* m_ptrInstance;
private:
	CSingleton()
	{
		cout << "�����˽�еĹ��캯��" << endl;
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
//���еľ�̬���ݳ�Աһ��Ҫ�ڶ�Ӧ��cpp�ļ��ж���
//���еľ�̬���ݳ�Ա���������е�ȫ�ֱ��������������๲�У��������ض��Ķ��󣬱�����cpp�г�ʼ��
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



