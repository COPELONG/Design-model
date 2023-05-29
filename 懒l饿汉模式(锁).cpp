#include<iostream>
#include<string>
#include <mutex>
using namespace std;

class singleton {
public:
	static singleton* Getsingleton() {
		if (m_singleton == nullptr) {//双重锁保证线程安全
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
	{ cout << "创建了一个单例对象" << endl; };
	singleton(const singleton&) = delete;
	singleton& operator =(const singleton&) = delete;
};
//饿汉模式：类加载的时候直接创建单例对象
//singleton* singleton:: m_singleton=new singleton();
//饱汉模式：使用的时候再去创建
singleton* singleton::m_singleton = nullptr;
mutex singleton::m_mutex;
int main() {
	singleton::Getsingleton();
	singleton::Getsingleton();
}



