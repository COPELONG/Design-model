#include<iostream>
#include<string>
#include"News_door.h"
#include"People.h"
using namespace std;


int main() {

    News* one_news = new One_News;
    News* two_news = new Two_News;

    One_People* one_people1 = new One_People("һ�ŷ�˿", one_news);
    One_People* one_people2 = new One_People("���ŷ�˿", one_news);

    Two_People* two_people = new Two_People("���ŷ�˿", two_news);

    one_news->Say_People("������5.21��");
    two_news->Say_People("������5.20��");
    return 0;
}

