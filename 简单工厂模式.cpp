#include<iostream>
#include<string>
using namespace std;

class API {
public:
	virtual void test() = 0;
protected:
	API(){}
};
class Iml_one :public API {
	void test() {
		
		cout << "我是Iml_one" << endl;
	}
};
class Iml_two :public API {
	void test() {
		cout << "我是Iml_two" << endl;
	}
};
class Factory {
public:
	static API* creat(int type) {
		if (type == 1) {
			return new Iml_one();
		}
		if (type == 2) {
			return new Iml_two();
		}
		return NULL;
	}
};
//方法隔离，解耦合
//可以假设参数1是写入文件操作
//参数2是读入文件操作
//这样就可以通过简单传递参数实现不同的操作，并且修改内部实现也很方便
int main (){
	API* factory1 = Factory::creat(1);
	factory1->test();
	API* factory2 = Factory::creat(2);
	factory2->test();
}