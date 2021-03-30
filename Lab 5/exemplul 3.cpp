#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

//prototipul clasei lista
class lista;

//clasa de baza
class produse_magazin
{
private:
	int tip_derivat;
	string producator;
	int cod_produs;
	produse_magazin* urm;
public:
	//construcotrul clasei de baza
	produse_magazin(int t, string prod, int cod)
	{
		tip_derivat = t;
		producator = prod;
		cod_produs = cod;
		urm = NULL;
	}

	virtual void afisare()
	{
		cout << "----------------------------------------\n";
		cout << "producator: " << producator << endl;
		cout << "cod produs: " << cod_produs << endl;
	}

	//declararea clasei Lista friend la clasa produse_magazin pt a avea acces la campurile acesteia
	friend class lista;
};

//prima clasa derivata
class scanere :public produse_magazin
{
	string soft_inclus;
public:
	scanere(int t, string prod, int cod, string soft) :produse_magazin(t, prod, cod)
	{
		soft_inclus = soft;
	}

	void afisare()
	{
		produse_magazin::afisare();
		cout << "soft inclus: " << endl;
	}

	friend class lista;
};

// a doua clasa derivata
class imprimante :public produse_magazin
{
private:
	string format;
public:
	imprimante(int t, string prod, int cod, string form) :produse_magazin(t, prod, cod)
	{
		format = form;
	}

	void afisare()
	{
		produse_magazin::afisare();
		cout << "format: " << format << endl;
	}

	friend class lista;
};

class lista
{
public:
	produse_magazin* head;
	void adaugare(produse_magazin* prod);
	void afisare_lista();
};

void lista::adaugare(produse_magazin* a)
{
	produse_magazin* p;

	p = head;
	if (p)
	{
		if (a->producator == p->producator)
		{
			a->urm = head;
			head = a;
		}
		else
		{
			while (p->urm && (p->urm)->producator == a->producator)
				p = p->urm;
			a->urm = p->urm;
			p->urm = a;
		}
	}
	else
		head = a;
}

void lista::afisare_lista()
{
	produse_magazin* a;

	a = head;

	if (!a)
		cout << "lista vida";
	else
		while (a)
		{
			a->afisare();
			a = a->urm;
			getchar();
		}
}

void introducere(lista& l, int x)
{
	int tip_derivat;
	string producator;
	int cod_produs;
	string soft_inclus;
	string format;
	produse_magazin* prodMag;

	cout << "introduceti producatorul: ";
	cin >> producator;
	cout << "introduceti codul de produs: ";
	cin >> cod_produs;

	if (x == 0)
	{
		scanere* sc;
		cout << "introduceti softul inclus: ";
		cin >> soft_inclus;
		cout << "introduceti viteza de scanare: ";

		sc = new scanere(1, producator, cod_produs, soft_inclus);
		prodMag = sc;
		l.adaugare(prodMag);
	}
	else if (x == 1)
	{
		imprimante* im;

		cout << "introduceti formatul imprimante: ";
		cin >> format;
		im = new imprimante(2, producator, cod_produs, format);
		prodMag = im;
		l.adaugare(prodMag);
	}
}

void main()
{
	int opt;
	lista l;
	l.head = NULL;

	do
	{
		//system("CLS");

		cout << "\n1. adugare scanere in lista, ordonat dupa producator" << endl;
		cout << "2. adaugare imprimante in lista, ordonat dupa producator" << endl;
		cout << "3. afisare articole din magazin" << endl;
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
			l.afisare_lista();
			break;
		case 0:
			break;
		default:
			cout << "optiune gresita" << endl;
		}
	} while (opt != 0);

	getchar();
}