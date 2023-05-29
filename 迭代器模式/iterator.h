#pragma once
#include"Mylist.h"
using namespace std;


class Iterator {
public:
	virtual Node* first() = 0;
	virtual Node* next() = 0;
	virtual bool isDone() = 0;
	Node* current() {
		return m_current;
	}
	Iterator(Mylist* list):mylist(list) {
	}
	virtual ~Iterator(){}
protected:
	Node* m_current = nullptr;
	Mylist* mylist = nullptr;
};


class goward :public Iterator {
public:
	using Iterator::Iterator;
	Node* first() {
		m_current= mylist->head();
		return m_current;
	}
	Node* next() {
		m_current= m_current->m_next;
		return m_current;
	}
	bool isDone() {
		return m_current == mylist->tail()->m_next;
	}
};

class backward :public Iterator {
public:
	using Iterator::Iterator;
	Node* first() {
		m_current= mylist->tail();
		return  m_current;
	}
	Node* next() {
		m_current= m_current->m_pre;
		return m_current;
	}
	bool isDone() {
		return m_current == mylist->head()->m_pre;
	}
};