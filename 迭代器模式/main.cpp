#include<iostream>
#include<vector>
#include "Mylist.h"
#include"iterator.h"
class Iterator;
using namespace std;


int main()
{
    vector<string> nameList{
        "��", "����", "�ܿ�", "���ȡ���", "X�����׿�",
        "��ɫ������", "�Gľ", "��q", "�弪��",
        "һ��", "����", "����", "�Ĺ�", "���",
        "����", "�߹�", "�˲�", "����","ʮ��"
    };
    Mylist mylist;
    for (int i = 0; i < nameList.size(); ++i)
    {
        mylist.pushback(nameList.at(i));
    }
    // ����
    Iterator* it = mylist.getIterator(true);
    cout << "���Ŀ�ʼ, ����: ͬ־��������~~~~~" << endl;
    for (auto Head = it->first(); !it->isDone(); it->next())
    {
        cout << "   " << it->current()->name << "say: Ϊ�ϴ����!!! " << endl;
    }
    cout << endl;
    delete it;
    return 0;
}