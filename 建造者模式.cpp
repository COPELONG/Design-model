#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class sunny_ship {
public:
   
    void join_part(const string& part) {
        parts.push_back(part);
    }
    void show_ship() {
        for (const string& part : parts) {
            cout << part << "  ";
        }
        cout << endl;
    }
private:
    vector<string> parts;
};

class moon_ship {
public:
    void join_part(string name, string part) {
        parts.insert(make_pair(name, part));
    }
    void show_ship() {
        for (const auto& part : parts) {
            cout << part.first << ":" << part.second << " ";
        }
        cout << endl;
    }
private:
    map<string, string> parts;
};

class builder {
public:
    virtual void reset() = 0;
    virtual void add_weapon() = 0;
    virtual void add_engine() = 0;
    virtual void add_room() = 0;
    virtual void add_body() = 0;

    virtual ~builder() {}
};

class sunny_ship_builder : public builder {
public:
    sunny_ship_builder() {
        reset();
    }
    void reset() {
        
        sunny = new sunny_ship();
    }
    void add_weapon() {
        sunny->join_part("大炮");
    }
    void add_engine() {
        sunny->join_part("可乐驱动");
    }
    void add_room() {
        sunny->join_part("豪华内饰");
    }
    void add_body() {
        sunny->join_part("钢铁");
    }
    ~sunny_ship_builder() {
        if (sunny != nullptr) {
            delete sunny;
        }
        
    }
    sunny_ship* get_ship() {
        sunny_ship* ship = sunny;
        sunny = nullptr;
        return ship;
    }
private:
    sunny_ship* sunny = nullptr;
};

class moon_ship_builder : public builder {
public:
    moon_ship_builder() {
        reset();
    }
    void reset() {
        moon = new moon_ship();
    }
    void add_weapon() {
        moon->join_part("武器", "大炮");
    }
    void add_engine() {
        moon->join_part("引擎", "可乐驱动");
    }
    void add_room() {
        moon->join_part("装修", "豪华内饰");
    }
    void add_body() {
        moon->join_part("船体材料", "钢铁");
    }
    ~moon_ship_builder() {
        delete moon;
    }
    moon_ship* get_ship() {
        moon_ship* ship = moon;
        moon = nullptr;
        return ship;
    }
private:
    moon_ship* moon = nullptr;
};

class worker {
public:
    void set_builder(builder* b) {
        m_builder = b;
    }
    void one_ship() {
        m_builder->add_body();
        m_builder->add_engine();
    }
    void two_ship() {
        one_ship();
        m_builder->add_weapon();
    }
    void three_ship() {
        two_ship();
        m_builder->add_room();
    }
private:
    builder* m_builder = nullptr;
};

void SunnyShip() {
    worker* work = new worker;
    sunny_ship_builder* Builder = new sunny_ship_builder;
    work->set_builder(Builder);
    work->one_ship();
    sunny_ship* ship = Builder->get_ship();
    ship->show_ship();
    delete ship;

    Builder->reset();
    work->set_builder(Builder);
    work->two_ship();
    ship = Builder->get_ship();
    ship->show_ship();
    delete ship;

    Builder->reset();
    work->set_builder(Builder);
    work->three_ship();
    ship = Builder->get_ship();
    ship->show_ship();
    delete ship;

    delete work;
    delete Builder;
}

void MoonShip() {
    worker* work = new worker;
    moon_ship_builder* Builder = new moon_ship_builder;
    work->set_builder(Builder);
    work->one_ship();
    moon_ship* ship = Builder->get_ship();
    ship->show_ship();
    delete ship;

    Builder->reset();
    work->set_builder(Builder);
    work->two_ship();
    ship = Builder->get_ship();
    ship->show_ship();
    delete ship;

    Builder->reset();
    work->set_builder(Builder);
    work->three_ship();
    ship = Builder->get_ship();
    ship->show_ship();
    delete ship;

    delete work;
    delete Builder;
}

int main() {
    SunnyShip();
    MoonShip();
    return 0;
}
