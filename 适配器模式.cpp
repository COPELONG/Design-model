#include<iostream>
#include<string>
using namespace std;

class Animal {
public:
	virtual string send_msg()=0;
	void rev_msg(string msg) {
		cout << "people say:" <<msg<< endl;
	}
};
class Bird :public Animal {
public:
	string send_msg() {
		return string("我是一只小鸟");
	}
};
class Monkey :public Animal {
public:
	string send_msg() {
		return string("我是一只猴子");
	}
};
class People {
public:
	string say_msg() {
		return string("你是什么动物");
	}
	void rec_msg(string msg) {
		cout << msg << endl;
	}
};
class Translate {
public:
	Translate(Animal * animal):m_animal(animal){}
	void PtoA() {
		string msg=m_people.say_msg();
		m_animal->rev_msg(msg);
	}
	void AtoP() {
		string animal_msg = m_animal->send_msg();
		m_people.rec_msg(animal_msg);
	}
private:
	People m_people;
	Animal* m_animal = nullptr;
};
int main() {
	Animal* bird = new Bird;
	Translate middle = Translate(bird);
	middle.PtoA();
	middle.AtoP();
	delete bird;
	
	Animal* monkey = new Monkey;
	middle = Translate(monkey);
	middle.PtoA();
	middle.AtoP();
	delete monkey;
}