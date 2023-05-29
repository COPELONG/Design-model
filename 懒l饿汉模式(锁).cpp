#include<iostream>
#include<string>
#include <mutex>
using namespace std;

class singleton {
public:
	static singleton* Getsingleton() {
		if (m_singleton == nullptr) {//˫������֤�̰߳�ȫ
			m_mutex.lock();
			if (m_singleton == nullptr) {
				return new singleton();
			}
			m_mutex.unlock();
		}
		return m_singleton;
	}
private:
	static singleton* m_singleton;
	static mutex m_mutex;
private:
	singleton() 
	{ cout << "������һ����������" << endl; };
	singleton(const singleton&) = delete;
	singleton& operator =(const singleton&) = delete;
};
//����ģʽ������ص�ʱ��ֱ�Ӵ�����������
//singleton* singleton:: m_singleton=new singleton();
//����ģʽ��ʹ�õ�ʱ����ȥ����
singleton* singleton::m_singleton = nullptr;
mutex singleton::m_mutex;
int main() {
	singleton::Getsingleton();
	singleton::Getsingleton();
}



