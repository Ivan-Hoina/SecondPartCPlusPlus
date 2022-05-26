#include <iostream>
#include <string>

using namespace std;

class IPAddress {
public:
	IPAddress(int part1, int part2, int part3, int part4) {
		ip[0] = part1;
		ip[1] = part2;
		ip[2] = part3;
		ip[3] = part4;
	}

	IPAddress(IPAddress* ip) {
		for(int i = 0; i < 4; i++)
			this->ip[i] = ip->getIpPart(i);
	}

	virtual void Print() {
		cout << ip[0] << '.' << ip[1] << '.' << ip[2] << '.' << ip[3];
	}

	int getIpPart(int i) {
		return ip[i];
	}

private:
	int ip[4];
};

class IPAddressChecker : public IPAddress{
public:
	IPAddressChecker(int part1, int part2, int part3, int part4) : IPAddress(part1, part2, part3, part4) {
		isCorrect = true;
		for (int i = 0; i < 4; i++) 
		{
			auto part = getIpPart(i);
			if (part < 0 || part > 255) {
				isCorrect = false;
				break;
			}
		}							
	}

	IPAddressChecker(IPAddress* ip) : IPAddress(ip) {
		isCorrect = true;
		for (int i = 0; i < 4; i++)
		{
			auto part = getIpPart(i);
			if (part < 0 || part > 255) {
				isCorrect = false;
				break;
			}
		}
	}

	void Print() {
		IPAddress::Print();
		cout << " - " << (isCorrect ? "Correct" : "Incorrect") << '\n';
	}
private:
	bool isCorrect;
};
