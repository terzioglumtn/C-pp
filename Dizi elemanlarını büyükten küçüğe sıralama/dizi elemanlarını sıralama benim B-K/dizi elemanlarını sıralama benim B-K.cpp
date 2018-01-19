#include"stdafx.h"
#include<iostream>

using namespace std;
int main() {
	int dizim[5], a;
	cout << "dizinin elemanlarini girin!\n";
	for (int i = 0; i < 5; i++) {
		cin >> dizim[i];
	}
	cout << "******************\n";
	for (int j = 0; j < 5; j++) {
		for (int k = j + 1; k < 5; k++) {
			if (dizim[k] > dizim[j]) {
				a = dizim[j];
				dizim[j] = dizim[k];
				dizim[k] = a;
			}
		}
	}
	for (int b = 0; b < 5; b++) {
		cout << dizim[b] << endl;
	}

	system("PAUSE");
}