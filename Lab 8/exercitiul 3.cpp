#pragma warning(disable : 4703)
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Telefon;
class telefonFix;
class telefonMobil;
class articoleMagazin;

template <class T>
class Lista
{
	T* root;
	T* point;
public:
	Lista();
	void add(T* telefon);
	void display();
	T* search(string sistemOperare);
	
	T* first()
	{
		point = root;
		return point;
	}

	T* next()
	{
		if (point != NULL)
			point = point->next;
		return point;
	}
};

template<class T>
Lista<T>::Lista()
{
	root = NULL;
}

template<class T>
void Lista<T>::add(T* telefon)
{
	T* tel;

	if (root == NULL)
	{
		root = telefon;
		return;
	}

	root->next = telefon;
}
/*
template<class T>
T* Lista<T>::search(string sistemOperare)
{
	T* tel;
	for (tel = root; tel != NULL; tel = tel->next)
	{
		if (tel->sistemOperare == sistemOperare)
			return tel;
		
	}

	return NULL;
}
*/
template<class T>
void Lista<T>::display()
{
	T* tel;
	for (tel = root; tel != NULL; tel = tel->next)
		tel->display();
}

//clasa de baza
class Telefon
{
private:
	string producator, culoare;
	int tip;
	Telefon* next;

	Lista<telefonFix> telFix;
	Lista<telefonMobil> telMobil;

public:
	Telefon(int, string, string);

	virtual void display();

	friend class Lista<Telefon>;
};

Telefon::Telefon(int t, string p, string c)
{
	tip = t;
	producator = p;
	culoare = c;
	next = NULL;
}

void Telefon::display()
{
	cout << "\n-----------------------------------\n";
	cout << "producator: " << producator << endl;
	cout << "culoare: " << culoare << endl;
}

//prima clasa derivata
class telefonFix:public Telefon
{
	string dimensiune;

public:
	telefonFix(int t, string p, string c, string d) :Telefon(t, p, c)
	{
		dimensiune = d;
	}
	
	void display();

	friend class Lista<telefonFix>;
};

void telefonFix::display()
{
	Telefon::display();
	cout << "dimensiune: " << dimensiune << endl;
}

//a doua clasa derivata
class telefonMobil:public Telefon
{
	string sistemOperare;

public:
	telefonMobil(int t, string p, string c, string s) :Telefon(t, p, c)
	{
		sistemOperare = s;
	}

	void display();

	friend class Lista<telefonMobil>;
};

void telefonMobil::display()
{
	Telefon::display();
	cout << "sistem de operare: " << sistemOperare << endl;
}

class articoleMagazin
{
	Lista<Telefon> tel;
	Lista<telefonMobil>telMobil;

public:
	void addTelefon(Telefon* telefon)
	{
		tel.add(telefon);
	}

	void display()
	{
		tel.display();
	}

	telefonMobil* searchTelefon(string sistemOpeare)
	{
		return telMobil.search(sistemOpeare);
	}

	friend class Lista<articoleMagazin>;
};

Telefon* adding(int tip)
{
	Telefon* telefon;
	string producator, culoare, dimensiune, sistemOperare;

	cout << "dati producator: ";
	cin >> producator;
	cout << "dati culoare: ";
	cin >> culoare;
	
	if (tip == 1)
	{
		telefonFix* telFix;

		cout << "dati dimensiune: ";
		cin >> dimensiune;

		telFix = new telefonFix(1, producator, culoare, dimensiune);
		telefon = telFix;
	}
	else if (tip == 2)
	{
		telefonMobil* telMobil;

		cout << "dati sistem de operare: ";
		cin >> sistemOperare;

		telMobil = new telefonMobil(2, producator, culoare, sistemOperare);
		telefon = telMobil;
	}

	return telefon;
}

void meniu()
{
	cout << "\nMENIU: " << endl;
	cout << "1. adaugare telefon fix in spatele listei" << endl;
	cout << "2. adaugare telefon mobil in spatele listei" << endl;
	cout << "3. afisare telefoane" << endl;
	cout << "4. cautare telefoane mobile dupa SISTEM OPERARE" << endl;
	cout << "5. iesire" << endl;
}

int main()
{
	Telefon* telefon;
	telefonMobil* telMobil;
	articoleMagazin* articole;

	int opt;
	string sistemCautat;

	do
	{
		meniu();
		cout << "\ndati optiune: ";
		cin >> opt;

		switch(opt)
		{
		case 1:
			telefon = NULL;
			articole = NULL;

			telefon = adding(1);
			articole->addTelefon(telefon);

			break;
		case2:
			telefon = NULL;
			articole = NULL;

			telefon = adding(2);
			articole->addTelefon(telefon);

			break;
		case3:
			articole->display();
			break;
		case 4:
			/*
			telMobil = NULL;
			articole = NULL;

			cout << "dati sistemul de operare cautat: ";
			getline(cin, sistemCautat);

			telMobil = articole->searchTelefon(sistemCautat);

			if (telMobil)
			{
				cout << "\ntelefonul se afla in magazin" << endl;
			}
			else
			{
				cout << "\ntelefonul nu se afla in magazin" << endl;
			}
			*/
			break;
		case 5:
			break;
		default:
			cout << "\noptiune gresita" << endl;
			break;
		}
	} while (opt != 5);

	return 0;
}