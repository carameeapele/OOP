#include<iostream>
#include<conio.h>

using namespace std;

class student
{
	char nume[20], pren[20];
	int grupa, cod_postal;
public:
	student(); //constructor
	~student(); //destructor
	void citire();
	void afisare();
};

//constructor
student::student()
{
	cout << "constructor:\tinfo despre student: " << endl;
}

void student::citire()
{
	cout << "nume: ";
	cin >> nume;
	cout << "prenume: ";
	cin >> pren;
	cout << "grupa: ";
	cin >> grupa;
	cout << "cod postal: ";
	cin >> cod_postal;
}

void student::afisare()
{
	cout << "\n" << nume << "\t" << pren << "\t" << grupa << "\t" << cod_postal;
}

//destructor
student::~student()
{
	cout << "\ndestructor: eliberare memorie";
}

void main()
{
	student s;
	s.citire();
	s.afisare();

	getchar();
}