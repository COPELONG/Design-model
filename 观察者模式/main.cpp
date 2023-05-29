#include<iostream>
#include<string>
#include"News_door.h"
#include"People.h"
using namespace std;


int main() {

    News* one_news = new One_News;
    News* two_news = new Two_News;

    One_People* one_people1 = new One_People("一号粉丝", one_news);
    One_People* one_people2 = new One_People("二号粉丝", one_news);

    Two_People* two_people = new Two_People("三号粉丝", two_news);

    one_news->Say_People("今天是5.21号");
    two_news->Say_People("昨天是5.20号");
    return 0;
}

