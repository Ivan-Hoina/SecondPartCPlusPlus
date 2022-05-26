#include <iostream>
#include <string>

using namespace std;

class Piece 
{
public:
	Piece(string name) {
		this->name = name;
	}

	virtual bool Check(int i, int j, int newI, int newJ)
	{
		return false;
	}

	string getName() {
		return name;
	}

private:
	string name;
};

class Man : public Piece
{
public:
	Man(string name) : Piece(name) {

	}

	bool Check(int i, int j, int newI, int newJ)
	{
		if (abs(i - newI) > 1 || abs(j - newJ) > 1)
			return false;

		if (abs(i - newI) == 1 && j - newJ == 0)
			return true;

		if (i - newI == 0 && abs(i - newI) == 1)
			return true;
	}
};

class King : public Piece
{
public:
	King(string name) : Piece(name) {
		
	}

	bool Check(int i, int j, int newI, int newJ)
	{
		if (abs(i - newI) >= 1 && j - newJ == 0)
			return true;

		if (abs(j - newJ) >= 1 && i - newI == 0)
			return true;
		if (i - newI < 0 && i - newI == j - newJ && j - newJ < 0)
			return true;
		if (i - newI > 0 && i - newI == j - newJ && j - newJ > 0)
			return false;		

		return false;
	}
};