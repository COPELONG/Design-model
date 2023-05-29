
#include"iterator.h"
Node* Mylist::insert(Node* item, string data)
{
	if (item == m_head) {
		return pushfront(data);
	}
	else {
		Node* node = new Node(data);
		node->m_next = item;
		
		node->m_pre = item->m_pre;
		item->m_pre->m_next = node;
		item->m_pre = node;
		m_count++;
		return node;
	}
}

Node* Mylist::pushback(string data)
{
	Node* node = new Node(data);
	if (m_tail == nullptr) {
		m_head = m_tail = node;
	}
	else {
		m_tail->m_next = node;
		node->m_pre = m_tail;
		m_tail = node;
	}
	m_count++;
	return node;
}

Node* Mylist::pushfront(string data)
{
	Node* node = new Node(data);
	if (m_head == nullptr) {
		m_head = node;
		m_tail = m_head;
	}
	else {
		node->m_next = m_head;
		m_head->m_pre = node;
		m_head = node;
	}
	m_count++;
	return node;
}

Iterator* Mylist::getIterator(bool isReverse)
{
	if (isReverse) {
		return new backward(this);
	}
	else {
		return new goward(this);
	}
	
}
