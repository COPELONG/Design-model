#include<iostream>
#include<string>
using namespace std;
class singleton {
public:
	static singleton* Getinstance() {
		static singleton single;
		return &single;
	}
	void show() {
		cout << "ÀÁººµ¥ÀýÄ£Ê½" << endl;
	}
private:
	singleton() = default;
	singleton& operator=(const singleton&) = delete;
	singleton(const singleton&) = delete;
};
int main() {
	singleton* instance = singleton::Getinstance();
	instance->show();
}