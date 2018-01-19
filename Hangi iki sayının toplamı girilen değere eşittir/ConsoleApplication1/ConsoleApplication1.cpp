#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int x;
	cout << "Toplamini bulmak istediginiz sayiyi giriniz=";
	cin >> x;
	for (int i = 0; i <= x; i++) 
	{
		for(int k=0; k<=x; k++)
		{
			if(i+k==x)
			{ 
				if (i < k) 
				{
					cout << i << "+" << k << "=" << x << endl;
				}
				
			}
		}

	}

    return 0;
}

