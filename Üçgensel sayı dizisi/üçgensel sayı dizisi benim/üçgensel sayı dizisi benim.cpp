#include"stdafx.h"
#include<iostream>
using namespace std;
int main() {
	int b=2,atama,sayý1 = 1;
	cout << 1<<endl;
	for (int i = 1;i<=10 ; i++) {
		atama = sayý1 + b;
		cout << atama<<endl;
		b++;
		sayý1 = atama + b;
		b++;
		cout<<sayý1 << endl;
	}

	system("PAUSE");
}