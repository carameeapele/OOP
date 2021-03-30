#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

//prototipul clasei lista
class lista;

//clasa de baza produse magazin
class produsMagazin
{
private:
	int tipDerivat;
	string producator;
	int codProdus;
	string rezolutie;
	string dimensiuni;
	produsMagazin* next;
public:
	//constructorul clasei de baza
	produsMagazin(int t, string prod, int cod, string rez, string dim)
	{
		tipDerivat = t;
		producator = prod;
		codProdus = cod;
		rezolutie = rez;
		dimensiuni = dim;
		next = NULL;
	}

	//functia de afisare a clasei de baza
	virtual void display()
	{
		cout << "--------------------------------------\n";
		cout << "producator: " << producator << endl;
		cout << "cod produs: " << codProdus << endl;
		cout << "rezolutie: " << rezolutie << endl;
		cout << "dimensiune: " << dimensiuni << endl;
	}

	friend class lista;
};

//prima clasa derivata
class scanere :public produsMagazin
{
private:
	string softInclus;
	int vitezaScanare;
public:
	//constructorul clasei derivate
	scanere(int t, string prod, int cod, string rez, string dim, string soft, int viteza) :produsMagazin(t, prod, cod, rez, dim)
	{
		softInclus = soft;
		vitezaScanare = viteza;
	}

	//afisare elemente clasa scanere
	void display()
	{
		produsMagazin::display();
		cout << "soft inclus: " << softInclus << endl;
		cout << "viteza scanare: " << vitezaScanare << endl;
	}

	friend class lista;
};

// a doua clasa derivta
class imprimante :public produsMagazin
{
private:
	string format;
	string tip;
public:
	imprimante(int t, string prod, int cod, string rez, string dim, string form, string tp) :produsMagazin(t, prod, cod, rez, dim)
	{
		format = form;
		tip = tp;
	}

	//functia de afisare
	void display()
	{
		produsMagazin::display();
		cout << "format: " << format << endl;
		cout << "tip: " << tip << endl;
	}

	friend class lsita;
};

class lista
{
public:
	produsMagazin* head;
	void add(produsMagazin* prod);
	void display_list();
};

void lista::add(produsMagazin* a)
{
	produsMagazin* p;
	p = head;
	if (p)
	{
		if (a->producator < p->producator)
		{
			a->next = head;
			head = a;
		}
		else
		{
			while (p->next && (p->next)->producator < a->producator)
				p = p->next;

			a->next = p->next;
			p->next = a;
		}
	}
	else
		head = a;
}

void lista::display_list()
{
	produsMagazin* a;
	a = head;
	if (!a)
		cout << "lista este vida";
	else
		while (a)
		{
			a->display();
			a = a->next;
		}
}

class supraincarcare
{
public:
	string producator;
	int codProdus;
	string rezolutie;
	string dimensiuni;
public:
	friend ostream& operator<<(ostream* out, supraincarcare& a);
	friend istream& operator>>(istream& in, supraincarcare& a);
};

ostream& operator<<(ostream& out, supraincarcare& a)
{
	cout << "vom citi datele pt scanere si imprimante: " << endl;
	cout << endl;
	return out;
}

istream& operator>>(istream& in, supraincarcare& a)
{
	cout << "dati producator: ";
	cin >> a.producator;
	cout << "dati codul de produs: ";
	cin >> a.codProdus;
	cout << "dati rezolutia: ";
	cin >> a.rezolutie;
	cout << "dati dimensiuni: ";
	cin >> a.dimensiuni;
	return in;
}

void introducere(lista& l, int x)
{
	int tipDerivat;
	string softInclus;
	int vitezaScanare;
	string format;
	string tip;
	produsMagazin* prod;

	supraincarcare supr;

	cout << supr;
	cin >> supr;

	if (x == 0)
	{
		scanere* sc;
		cout << "dati softul inclus: ";
		cin >> softInclus;
		cout << "dati viteza de scanare: ";
		cin >> vitezaScanare;

		sc = new scanere(1, supr.producator, supr.codProdus, supr.rezolutie, supr.dimensiuni, softInclus, vitezaScanare);
		prod = sc;
		l.add(prod);
	}
	else if (x == 1)
	{
		imprimante* im;

		cout << "dati formatul imprimante: ";
		cin >> format;
		cout << "dati tipul imprimantei: ";
		cin >> tip;

		im = new imprimante(2, supr.producator, supr.codProdus, supr.rezolutie, supr.dimensiuni, format, tip);
		prod = im;
		l.add(prod);
	}
}

int main()
{
	int opt;
	lista l;
	l.head = NULL;

	do
	{
		system("CLS");
		cout << "1. adaugare scanere ordonat dupa producator" << endl;
		cout << "2. adaugare imprimante ordonat dupa producator" << endl;
		cout << "3. afisare articole" << endl;
		cout << "0. iesire" << endl;
		cout << "\ndati optiune: ";
		cin >> opt;

		switch (opt)
		{
		case 1:
			introducere(l, 0);
			break;
		case 2:
			introducere(l, 1);
			break;
		case 3:
			l.display_list();
			break;
		case 0:
			break;
		default:
			cout << "\noptiune gresita" << endl;
			break;
		}
	} while (opt != 0);

	getchar();
	return 0;
}