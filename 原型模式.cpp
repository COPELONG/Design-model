#include<iostream>
#include<string>
using namespace std;

class Dad {
public:
	virtual Dad* clone() = 0;
	virtual void show_info() = 0;
	virtual~Dad(){}
};

class Son1 :public Dad {
public:
	Dad* clone() {
		return new Son1(*this);
	}
	void show_info() {
		cout << "我是Son1" << endl;
	}
};
class Son2 :public Dad {
public:
	Dad* clone() {
		return new Son2(*this);
	}
	void show_info() {
		cout << "我是Son2" << endl;
	}
};


int main() {

	Dad* obj = new Son1;
	Dad* son1_clone=obj->clone();
	son1_clone->show_info();
	delete obj;
	delete son1_clone;

	obj = new Son2;
	Dad* son2_clone = obj->clone();
	son2_clone->show_info();
	delete obj;
	delete son2_clone;

}