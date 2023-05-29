#include"News_door.h"
#include"People.h"

void One_News::Say_People(string msg)
{
	cout << "One报社开始报道" << "一共" << m_list.size() << "人" << endl;
	for (const auto& p : m_list) {
		p->recv(msg);
	}
}
void Two_News::Say_People(string msg)
{
	cout << "One报社开始报道" << "一共" << m_list.size() << "人" << endl;
	for (const auto& p : m_list) {
		p->recv(msg);
	}
}
