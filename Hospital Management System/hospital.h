#include <iostream>

const int LEN=25;
using namespace std;

class people
{
	protected:
		char name[LEN];
		char surname[LEN];	
		int age;
	public:
		void getdata();
		
};

class patient :public people
{
	protected:
		int pid;
		char department[LEN];
	public:
		void getdata();	
		void Add_Patient();
		void Show_Patients();
		void Sel_Patient();
};

class doctors :public people
{
	protected:
		int id;
		char department[LEN];
	public:
		void Add_Doctors();
		void Show_Doctors();	
		void getdata();
};

class departments
{
	protected:
		char name[LEN];
		int id;
	public:
		void Show_Departments();
};

class selection
{
	private:
		int select; 
	public:
		int operation();
		void Ekran_Yazdir(int pid,char n[],char s[],int a,char i[]);
		void Doctor_Yazdir(char na[],char su[],int ag,int id,char de[]);
		void Create_Patient(int pid,char n[],char s[],int a,char i[]);
		void Create_Doctors(char na[],char su[],int ag,int id,char de[]);
};
