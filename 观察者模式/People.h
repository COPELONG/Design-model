#pragma once
#include"News_door.h"
#include <string>
#include <iostream>
using namespace std;
class people {
public:
	people(string name, News* news) {
		m_news = news;
		m_name = name;
		m_news->add(this);
	}
	void un_add(News* news) {
		m_news->unadd(this);
	}
	virtual void recv(string msg) = 0;
	virtual ~people(){}
protected:
	News* m_news = nullptr;
	string m_name;
};

class One_People :public people{
public:
	using people::people;

	void recv(string msg) {
		cout << m_name <<"收到信息：" << msg << endl;
	}

};
class Two_People :public people {
public:
	using people::people;

	void recv(string msg) {
		cout << m_name << "收到信息：" << msg << endl;
	}

};