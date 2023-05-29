#include<iostream>
#include<string>
using namespace std;
//����ˮ��Ʒ��
class fruit {
public:
	virtual void flavors() = 0;
	virtual ~fruit(){}
};
class apple :public fruit {
public:
	void flavors() {
		cout << "apple�����" << endl;
	}
	~apple(){}
};
class banana :public fruit {
public:
	void flavors() {
		cout << "banana�����" << endl;
	}
	~banana(){}
};
 //����ˮ������
class Factory {
public:
	virtual fruit* get_fruit() = 0;
	virtual ~Factory(){}
};
class apple_factory:public Factory {
public:
	fruit* get_fruit() {
		cout << "���apple" << endl;
		fruit* f = new apple;
		return f;
	}
};
class banana_factory :public Factory {
public:
	fruit* get_fruit() {
		cout << "���banana" << endl;
		fruit* f = new banana;
		return f;
	}
};
int main() {

	Factory* Apple_factory = new apple_factory;
	fruit* apple =Apple_factory->get_fruit();
	apple->flavors();

	Factory* Banana_factory = new banana_factory;
	fruit* banana = Banana_factory->get_fruit();
	banana->flavors();


	
}