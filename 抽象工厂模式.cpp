#include<iostream>
#include<string>
using namespace std;

//����������
class weapon {
public:
	virtual void get_weapon() = 0;
	virtual ~weapon() {};
};
class one_weapon:public weapon {
public:
	void get_weapon() {
		cout << "װ��һ������" << endl;
	}
};
class two_weapon :public weapon {
public:
	void get_weapon() {
		cout << "װ����������" << endl;
	}
};
class three_weapon :public weapon {
public:
	void get_weapon() {
		cout << "װ����������" << endl;
	}
};
//����������
class engine {
public:
	virtual void get_engine() = 0;
	virtual ~engine() {};
};
class one_engine:public engine {
	void get_engine() {
		cout << "ʹ��һ�Ŷ���" << endl;
	}
};
class two_engine :public engine {
	void get_engine() {
		cout << "ʹ�ö��Ŷ���" << endl;
	}
};
class three_engine :public engine {
	void get_engine() {
		cout << "ʹ�����Ŷ���" << endl;
	}
};
//����������
class shipbody {
public:
	virtual void get_shipbody() = 0;
	virtual ~shipbody() {};
};
class one_shipbody:public shipbody {
	void get_shipbody() {
		cout << "һ�Ŵ����Ѿ�λ" << endl;
	}
};
class two_shipbody :public shipbody {
	void get_shipbody() {
		cout << "���Ŵ����Ѿ�λ" << endl;
	}
};
class three_shipbody :public shipbody {
	void get_shipbody() {
		cout << "���Ŵ����Ѿ�λ" << endl;
	}
};
//��ȡ������
class ship {
public:
	ship(shipbody* s, weapon* w, engine* e)
		:m_shipbody(s), m_weapon(w), m_engine(e) {}
	void show_info() {
		m_shipbody->get_shipbody();
		m_weapon->get_weapon();
		m_engine->get_engine();
	}
	~ship() {
		delete m_shipbody;
		delete m_engine;
		delete m_weapon;
	}
private:
	shipbody* m_shipbody = nullptr;
	weapon* m_weapon = nullptr;
	engine* m_engine = nullptr;
};
//�����촬������
class Factory {
public:
	virtual ship* create_ship() = 0;
	virtual ~Factory() {}
};
class one_Factory :public Factory{
public:
	ship* create_ship() {
		ship* m_ship=new ship(new one_shipbody, new one_weapon, new one_engine);
		return m_ship;
	}
};
class two_Factory :public Factory {
public:
	ship* create_ship() {
		ship* m_ship = new ship(new two_shipbody(), new two_weapon(), new two_engine);
		return m_ship;
	}
};
class three_Factory :public Factory {
public:
	ship* create_ship() {
		ship* m_ship = new ship(new three_shipbody(), new three_weapon(), new three_engine);
		return m_ship;
	}
};

int main() {

	Factory* one_factory = new one_Factory;
	ship* one_ship=one_factory->create_ship();
	one_ship->show_info();
	Factory* two_factory = new two_Factory;
	ship* two_ship = two_factory->create_ship();
	two_ship->show_info();
	Factory* three_factory = new three_Factory;
	ship* three_ship = three_factory->create_ship();
	three_ship->show_info();
	

}