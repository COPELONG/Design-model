#include<iostream>
#include<string>
using namespace std;
enum class Request_Type { 请假,张薪, 辞职 };

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
		case Request_Type::请假:
			cout << "Manager已批准您的请假" << endl;
			break;
		case Request_Type::张薪:
			cout << "Manger无权限，请求上级处理" << endl;
			m_next->Handler_Request(type);
			break;
		case Request_Type::辞职:
			cout << "Manger无权限，请求上级处理" << endl;
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
		case Request_Type::请假:
			cout << "CEO已批准您的请假" << endl;
			break;
		case Request_Type::张薪:
			cout << "CEO拒绝了您的张薪请求" << endl;
			break;
		case Request_Type::辞职:
			cout << "CEO无权限，请求上级处理" << endl;
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
		case Request_Type::请假:
			cout << "CTO已批准您的请假" << endl;
			break;
		case Request_Type::张薪:
			cout << "CTO拒绝了您的张薪请求" << endl;
			break;
		case Request_Type::辞职:
			cout << "CTO同意了您的辞职请求" << endl;
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

	//设置责任链:对应关系
	manger->set_next(ceo);
	ceo->set_next(cto);

	Worker* worker = new Worker;
	worker->Request(Request_Type::请假, manger);
	cout << "***********************************" << endl;
	worker->Request(Request_Type::辞职, manger);
	cout << "***********************************" << endl;
	worker->Request(Request_Type::张薪, ceo);

	delete manger;
	delete ceo;
	delete cto;
	delete worker;
}


