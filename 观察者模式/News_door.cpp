#include"News_door.h"
#include"People.h"

void One_News::Say_People(string msg)
{
	cout << "One���翪ʼ����" << "һ��" << m_list.size() << "��" << endl;
	for (const auto& p : m_list) {
		p->recv(msg);
	}
}
void Two_News::Say_People(string msg)
{
	cout << "One���翪ʼ����" << "һ��" << m_list.size() << "��" << endl;
	for (const auto& p : m_list) {
		p->recv(msg);
	}
}
