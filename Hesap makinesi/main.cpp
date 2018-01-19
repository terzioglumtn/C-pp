#include <iostream>
using namespace std;
int main() 
{
	float s1,s2,sonuc;
	char cevap='e',islem;
	while(cevap=='e')
	{
		cout<<"islem giriniz:(2+3)";
		cin>>s1>>islem>>s2;
		if(islem=='+')
		{
			sonuc=s1+s2;
		}
		else if(islem=='-')
		{
			sonuc=s1-s2;
		}
		else if(islem=='*')
		{
			sonuc=s1*s2;
		}
		else if(islem=='/')
		{
			sonuc=s1/s2;
		}
		cout<<"SONUC:"<<endl;
		cout<<s1<<islem<<s2<<"="<<sonuc<<endl;
		cout<<"Baska islem yapmak ister misin?(evet:e hayir:h)";
		cin>>cevap;
	}
	return 0;
}
