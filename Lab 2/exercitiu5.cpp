#include<iostream>
#include<conio.h>

using namespace std;

class student
{
	string* nume, * rol, * adresa;
	int *cod_postal;
public:
	student(string n, string r, string adr, int cod); //constructor
	~student(); //destructor
	void afisare();
};

//constructor
student::student(string n, string r, string adr, int cod)
{
	nume = new string;
	*nume = n;
	rol = new string;
	*rol = r;
	adresa = new string;
	*adresa = adr;
	cod_postal = new int;
	*cod_postal = cod;
}


void student::afisare()
{
	cout << "\n" << *nume << "\n\t" << *rol;
	cout << "\n\t" << *adresa;
	cout << "\n\t" << *cod_postal;
}

//destructor
student::~student()
{
	cout << "\ndestructor: eliberare memorie";
	delete nume;
	delete rol;
	delete adresa;
	delete cod_postal;
}

void main()
{
	string n, r, adr;
	int nr, cod;
	cout << "constructor:\tinfo despre student: " << endl;
	cout << "\nnume: ";
	cin >> n;
	cout << "rol: ";
	cin >> r;
	cout << "adresa: ";
	cin >> adr;
	cout << "cod postal: ";
	cin >> cod;

	student s(n, r, adr, cod);	
	s.afisare();
	s.~student();

	getchar();
}