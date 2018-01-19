#include"stdafx.h"
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
int main() {
	vector<int>x;
	int a;
	srand(time(NULL));
	for (int i = 1; i <= 10; i++) {
		a = rand() % 10 + 1;
		x.push_back(a);
	}
	for (int i = 0; i < x.size(); i++) {
		cout << x.at(i)<<endl;
	}

	system("PAUSE");
}