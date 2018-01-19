#include"stdafx.h"
#include<iostream>
using namespace std;

int main() {
	float x, y;
	float result;
	cout << "enter x=";
	cin >> x;
	cout << "enter y=";
	cin >> y;
	try {
		result =x/y;
		if (y == 0) {
			throw 0;
		}
		cout << result;
		}
	catch (int a) {
		cout << "0 a bolme olmaz";
	}

	system("PAUSE");
}