#include<iostream>
#include<string>
using namespace std;

//创建武器类
class weapon {
public:
	virtual void get_weapon() = 0;
	virtual ~weapon() {};
};
class one_weapon:public weapon {
public:
	void get_weapon() {
		cout << "装备一号武器" << endl;
	}
};
class two_weapon :public weapon {
public:
	void get_weapon() {
		cout << "装备二号武器" << endl;
	}
};
class three_weapon :public weapon {
public:
	void get_weapon() {
		cout << "装备三号武器" << endl;
	}
};
//创建动力类
class engine {
public:
	virtual void get_engine() = 0;
	virtual ~engine() {};
};
class one_engine:public engine {
	void get_engine() {
		cout << "使用一号动力" << endl;
	}
};
class two_engine :public engine {
	void get_engine() {
		cout << "使用二号动力" << endl;
	}
};
class three_engine :public engine {
	void get_engine() {
		cout << "使用三号动力" << endl;
	}
};
//创建船体类
class shipbody {
public:
	virtual void get_shipbody() = 0;
	virtual ~shipbody() {};
};
class one_shipbody:public shipbody {
	void get_shipbody() {
		cout << "一号船体已就位" << endl;
	}
};
class two_shipbody :public shipbody {
	void get_shipbody() {
		cout << "二号船体已就位" << endl;
	}
};
class three_shipbody :public shipbody {
	void get_shipbody() {
		cout << "三号船体已就位" << endl;
	}
};
//获取完整船
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
//建造造船工厂类
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