#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

class persoana
{
	string nume;
	string prenume;
	unsigned int varsta;
public:
	//definirea constructorului clasei
	persoana(string n, string p, int v);
	
	//functie de afisare
	void afisare_date()
	{
		cout << "nume: " << nume << endl;
		cout << "prenume: " << prenume << endl;
		cout << "carsta: " << varsta << endl;
	}
};

//constructor
persoana::persoana(string n, string p, int v)
{
	nume = n;
	prenume = p;
	varsta = v;
}

int main()
{
	string n1;
	string pren1;
	int v1;

	//crearea a 3 obiecte de tip persoana
	persoana p1("Popescu", "Marian", 20);
	persoana p2("Ionescu", "Daria", 21);
	persoana p3("Filipescu", "Dana", 25);

	p1.afisare_date();
	p2.afisare_date();
	p3.afisare_date();

	//crearea unui obiect cu variabile citite de la tastatura
	cout << "\nnume 1: ";
	getline(cin, n1);
	cout << "prenume 1: ";
	getline(cin, pren1);
	cout << "varsta 1: ";
	cin >> v1;

	persoana p(n1, pren1, v1);
	p.afisare_date();

	getchar();
	return 0;
}