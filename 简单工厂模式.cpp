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
		
		cout << "����Iml_one" << endl;
	}
};
class Iml_two :public API {
	void test() {
		cout << "����Iml_two" << endl;
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
//�������룬�����
//���Լ������1��д���ļ�����
//����2�Ƕ����ļ�����
//�����Ϳ���ͨ���򵥴��ݲ���ʵ�ֲ�ͬ�Ĳ����������޸��ڲ�ʵ��Ҳ�ܷ���
int main (){
	API* factory1 = Factory::creat(1);
	factory1->test();
	API* factory2 = Factory::creat(2);
	factory2->test();
}