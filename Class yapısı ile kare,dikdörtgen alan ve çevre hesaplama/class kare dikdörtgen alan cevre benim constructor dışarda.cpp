#include"stdafx.h"
#include<iostream>
using namespace std;

class dortgen {
private:
	int x, y;
public:
	dortgen() {
	};
	dortgen(int a, int b);
	
	int alan() {
		return x*y;
	}
	int cevre() {
		return (2 * x + 2 * y);
	}
};

dortgen::dortgen(int a, int b) {
	x = a;
	y = b;
}

int main() {
	dortgen kare(5, 5), dkt(3, 5);
	cout << "Karenin alani=" << kare.alan() << endl;
	cout << "Karenin cevresi=" << kare.cevre() << endl;
	cout << "Dikdortgenin alani=" << dkt.alan() << endl;
	cout << "Dikdortgenin cevresi=" << dkt.cevre() << endl;

	system("PAUSE");
}
