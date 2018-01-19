#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include "hospital.h"

using namespace std;

int selection::operation()
{
	cout<<setw(13)<<""<<"------------------------------"<<endl;
	cout<<setw(15)<<""<<"HOSPITAL MANAGEMENT SYSTEM"<<endl;
	cout<<setw(13)<<""<<"------------------------------"<<endl;
	cout<<endl;
	cout<<setw(22)<<""<<"SELECTIONS"<<endl<<endl;
	cout<<setw(5)<<""<<"1-Create Patient";
	cout<<setw(8)<<""<<"2-Show All Patients";
	cout<<setw(5)<<""<<"3-Show a Patient"<<endl;
	cout<<setw(5)<<""<<"4-Create Doctor";
	cout<<setw(9)<<""<<"5-Show All Doctors"<<endl;
	cout<<setw(5)<<""<<"6-Show All Departments";
	cout<<setw(26)<<""<<"7-EXIT"<<endl<<endl;
	cout<<"\nSelect an operation:"; 
	cin>>select;
	if(select==1)
	{
		system("CLS");
		cout<<"Selected operation:"<<select<<endl<<endl;
		cout<<setw(13)<<""<<"--------Create Patient-------"<<endl<<endl;
		patient p1;
		p1.Add_Patient();
	}
	if(select==2)
	{
		system("CLS");
		cout<<"Selected operation:"<<select<<endl<<endl;
		cout<<setw(13)<<""<<"--------Show All Patients-------"<<endl<<endl;
		cout<<endl<<endl;
		cout<<setw(10)<<"ID"<<setw(10)<<"Name"<<setw(15)<<"Surname"<<setw(12)<<"Age"<<setw(15)<<"Department"<<endl;
		cout<<"        -------------------------------------------------------"<<endl;
		patient p2;
		p2.Show_Patients();
	}
	if(select==3)
	{
		system("CLS");
		cout<<setw(13)<<""<<"Selected operation:"<<select<<endl<<endl;
		cout<<"--------Show a Patient-------"<<endl<<endl;
		patient p3;
		p3.Sel_Patient();
	}
	if(select==4)
	{
		system("CLS");
		cout<<"Selected operation:"<<select<<endl<<endl;
		cout<<setw(13)<<""<<"--------Create Doctor-------"<<endl<<endl;
		doctors doc;
		doc.Add_Doctors();
	}
	if(select==5)
	{
		system("CLS");
		cout<<"Selected operation:"<<select<<endl<<endl;
		cout<<setw(13)<<""<<"--------Show All Doctors-------"<<endl<<endl;
		doctors doc;
		doc.Show_Doctors();
	}
	if(select==6)
	{
		system("CLS");
		cout<<"Selected operation:"<<select<<endl<<endl;
		cout<<setw(13)<<""<<"--------Show All Departments-------"<<endl<<endl;
		departments d;
		d.Show_Departments();
	}
	if(select==7)
	{
		return 0;	
	}
}

void people::getdata()
{	
	cout<<"Enter Name    : ";   	 cin>>name;
	cout<<"Enter Surname : ";		 cin>>surname;
	cout<<"Enter Age     : ";		 cin>>age;	
}

void patient::Add_Patient()
{
	patient::getdata();
}

void patient::getdata()
{
	people::getdata();
	cout <<"Enter Department : "; cin>>department; 
	cout <<"Enter ID         : "; cin>>pid;
	selection s4;
	s4.Create_Patient(pid,name,surname,age,department);
}

void selection::Create_Patient(int pid,char n[],char s[],int a,char i[])
{
	ifstream input;
	ofstream output;
	output.open("patients.txt",ios::app);
	output<<pid<<" "<<n<<" "<<s<<" "<<a<<" "<<i<<endl;
	output.close();
	cout<<endl<<endl;
	selection s1;
	s1.operation();
}

void patient::Show_Patients()
{
	ifstream input;
	ofstream output;
	char name[LEN],surname[LEN],department[LEN];
	int age,pid;
	input.open("patients.txt",ios::in);
		while(!input.eof())
		{
			input>>pid>>name>>surname>>age>>department;
			selection s2;
			s2.Ekran_Yazdir(pid,name,surname,age,department);
		}
		input.close();
		cout<<endl<<endl;
		selection s3;
		s3.operation();
}

void selection::Ekran_Yazdir(int pid,char n[],char s[],int a,char i[])
{

	cout<<setw(10)<<pid<<setw(10)<<n<<setw(15)<<s<<setw(12)<<a<<setw(15)<<i<<endl;	
}

void patient::Sel_Patient()
{
	ifstream input;
	ofstream output;
	char name[LEN],surname[LEN],department[LEN],x[LEN];
	int age,pid,y;
	cout<<"Enter ID :"; cin>>y;
	input.open("patients.txt",ios::in);
		while(!input.eof())
		{
			input>>pid>>name>>surname>>age>>department;
			if(pid==y)
			{
				cout<<endl;
				cout<<setw(10)<<"ID"<<setw(10)<<"Name"<<setw(15)<<"Surname"<<setw(12)<<"Age"<<setw(15)<<"Department"<<endl;
				cout<<"        -------------------------------------------------------"<<endl;
				cout<<setw(10)<<pid<<setw(10)<<name<<setw(15)<<surname<<setw(12)<<age<<setw(15)<<department;
			}
		}
		input.close();
		cout<<endl<<endl;
		selection s3;
		s3.operation();
}

void doctors::Add_Doctors()
{
	doctors::getdata();
}

void doctors::getdata()
{
	people::getdata();
	cout<<"Enter ID         : "; cin>>id;
	cout<<"Enter Department : "; cin>>department;
	selection s5;
	s5.Create_Doctors(name,surname,age,id,department);
}

void selection::Create_Doctors(char na[],char su[],int ag,int id,char de[])
{
	ifstream input;
	ofstream output;
	output.open("doctors.txt",ios::app);
	output<<na<<" "<<su<<" "<<ag<<" "<<id<<" "<<de<<endl;
	output.close();
	cout<<endl<<endl;
	selection s1;
	s1.operation();
}

void doctors::Show_Doctors()
{
	ifstream input;
	ofstream output;
	char name[LEN],surname[LEN],department[LEN];
	int age,id;
	cout<<setw(10)<<"Name"<<setw(15)<<"Surname"<<setw(12)<<"Age"<<setw(12)<<"ID"<<setw(16)<<"Department"<<endl;
	cout<<"      -----------------------------------------------------------"<<endl;
	input.open("doctors.txt",ios::in);
		while(!input.eof())
		{
			input>>name>>surname>>age>>id>>department;
			selection s6;
			s6.Doctor_Yazdir(name,surname,age,id,department);
		}
		input.close();
		cout<<endl<<endl;
		selection s3;
		s3.operation();
}

void selection::Doctor_Yazdir(char na[],char su[],int ag,int id,char de[])
{

	cout<<setw(10)<<na<<setw(15)<<su<<setw(12)<<ag<<setw(12)<<id<<setw(16)<<de<<endl;	
}

void departments::Show_Departments()
{
	ifstream input;
	ofstream output;
	
	input.open("departments.txt");
		string str;
	
		while(true)
		{
			input>>str;
			if(input.eof())
			{
				break;
			}
			cout<<str<<"\n";
		}
	input.close();
	selection s4;
	s4.operation();
}



