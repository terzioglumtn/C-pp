#include"stdafx.h"
#include <iostream>

using namespace std;
int main() {
	int sayi1 = 0, sayi2 = 1, atama;
	cout << 0<<endl;
	for (int i = 1; i <= 3; i++) {
		atama = sayi1 + sayi2;
		sayi1 = sayi2 + atama;
		sayi2 = atama+sayi1;
		cout<<atama<<endl<< sayi1 << endl << sayi2 << endl;
	}

	system("PAUSE");

}