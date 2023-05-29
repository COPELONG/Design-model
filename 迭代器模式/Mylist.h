#pragma once
#include<iostream>
#include<string>
using namespace std;
class Iterator;
struct Node {
	Node(string n) :name(n){}
	string name=string();
	Node* m_next = nullptr;
	Node* m_pre = nullptr;
};
class Mylist {
public:
	 Node* insert(Node* item, string data) ;
	 Node* pushback(string data) ;
	 Node* pushfront(string data) ;
	 Iterator* getIterator(bool isReverse = false);
	 inline Node* head() {
		 return m_head;
	}
	 inline Node* tail() {
		 return m_tail;
	 }
	 inline int count() {
		 return m_count;
	 }

protected:
	Node* m_head;
	Node* m_tail;
	int m_count = 0;
};