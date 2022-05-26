#include <iostream>
#include <string>

using namespace std;

class Drawer 
{
public:
	virtual void Draw() {
		cout << "This is Draw Class";
	}
};

class Oak : public Drawer
{
public:
	void Draw() {
		cout << '\n' << " /\\ " << '\n';
		cout << "//\\\\" << '\n';
	}
};

class Apple : public Drawer
{
public:
	void Draw() {
		cout << '\n' << " /\\ " << '\n';
		cout << "/++\\" << '\n';
	}
};

class Orange : public Drawer
{
public:
	void Draw() {
		cout << '\n' << " /\\ " << '\n';
		cout << "/**\\" << '\n';
	}
};