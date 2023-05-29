#include <iostream>
#include <string>
using namespace std;

class Say {
public:
	virtual void speak() = 0;
	virtual ~Say() {}
};

class Speaker :public Say {
public:
	void speak() {
		cout << "���ڽ���" << endl;
	}
};
class Phone :public Say {
public:
	Phone() {
		m_speaker = new Speaker;
		isopen = true;
	}
	~Phone() {
		if (m_speaker != nullptr) {
			delete m_speaker;
		}
	}
	bool get_open() {
		return isopen;
	}
	void speak() {
		if (get_open()) {
			m_speaker->speak();
		}

	}
private:
	Speaker* m_speaker = nullptr;
	bool isopen = false;
};

int main() {
	//ֱ�ӽ���
	Say* speaker = new Speaker;
	speaker->speak();
	delete speaker;
	//�绰����
	Say* phone = new Phone;
	phone->speak();
	delete phone;

}