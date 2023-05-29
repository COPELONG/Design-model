#include<iostream>
#include<string>
using namespace std;
enum class Request_Type { ���,��н, ��ְ };

class Company {
public:
	void set_next(Company* company) {
		m_next = company;
	}
	virtual~Company() {}
	virtual void Handler_Request(Request_Type type) = 0;
protected:
	Company* m_next = nullptr;
};
class Manager:public Company {
public:
	void Handler_Request(Request_Type type) {
		switch (type)
		{
		case Request_Type::���:
			cout << "Manager����׼�������" << endl;
			break;
		case Request_Type::��н:
			cout << "Manger��Ȩ�ޣ������ϼ�����" << endl;
			m_next->Handler_Request(type);
			break;
		case Request_Type::��ְ:
			cout << "Manger��Ȩ�ޣ������ϼ�����" << endl;
			m_next->Handler_Request(type);
			break;
		default:
			break;
		}
	}

};
class CEO :public Company {
public:
	void Handler_Request(Request_Type type) {
		switch (type)
		{
		case Request_Type::���:
			cout << "CEO����׼�������" << endl;
			break;
		case Request_Type::��н:
			cout << "CEO�ܾ���������н����" << endl;
			break;
		case Request_Type::��ְ:
			cout << "CEO��Ȩ�ޣ������ϼ�����" << endl;
			m_next->Handler_Request(type);
			break;
		default:
			break;
		}
	}
};
class CTO :public Company {
public:
	void Handler_Request(Request_Type type) {
		switch (type)
		{
		case Request_Type::���:
			cout << "CTO����׼�������" << endl;
			break;
		case Request_Type::��н:
			cout << "CTO�ܾ���������н����" << endl;
			break;
		case Request_Type::��ְ:
			cout << "CTOͬ�������Ĵ�ְ����" << endl;
			break;
		default:
			break;
		}
	}
};

class Worker {
public:
	void Request(Request_Type type,Company *company) {
		company->Handler_Request(type);
	}
};

int main() {
	Company* manger = new Manager;
	Company* ceo = new CEO;
	Company* cto = new CTO;

	//����������:��Ӧ��ϵ
	manger->set_next(ceo);
	ceo->set_next(cto);

	Worker* worker = new Worker;
	worker->Request(Request_Type::���, manger);
	cout << "***********************************" << endl;
	worker->Request(Request_Type::��ְ, manger);
	cout << "***********************************" << endl;
	worker->Request(Request_Type::��н, ceo);

	delete manger;
	delete ceo;
	delete cto;
	delete worker;
}


