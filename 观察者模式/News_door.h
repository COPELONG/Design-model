#pragma once
#include<list>
#include<string>
#include<iostream>
using namespace std;
class people;
class News {
public:
	void add(people*p ) {
		m_list.push_back(p);
	}
	void unadd(people* p) {
		m_list.remove(p);
	}
	virtual void Say_People(string msg) = 0;
	virtual ~News(){}
protected:
	list<people*> m_list;
};
class One_News :public News {
public:
	void Say_People(string msg);
};
class Two_News :public News {
public:
	void Say_People(string msg);
};
