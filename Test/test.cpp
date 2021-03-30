#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

class Lista;

class Parfumuri
{
private:
	int tip;
	unsigned int pret;
	Parfumuri* next;
public:
	Parfumuri(int t, unsigned int p)
	{
		tip = t;
		pret = p;
		next = NULL;
	}

	virtual void display()
	{

		cout << "\n----------------------------\n";
		cout << "pret: " << pret << endl;
	}

	friend class Lista;
};

class parfumuriBarbati :public Parfumuri
{
	string forma;
public:
	parfumuriBarbati(int t, unsigned int p, string f) :Parfumuri(t, p)
	{
		forma = f;
	}

	void display()
	{
		Parfumuri::display();
		cout << "forma: " << forma << endl;
	}

	friend class Lista;
};

class parfumuriFemei :public Parfumuri
{
	string categorieOlfactiva;
public:
	parfumuriFemei(int t, unsigned int p, string c) :Parfumuri(t, p)
	{
		categorieOlfactiva = c;
	}

	void display()
	{
		Parfumuri::display();
		cout << "categorie: " << categorieOlfactiva << endl;
	}

	friend class Lista;
};

class Lista
{
public:
	Parfumuri* head;
	void add(Parfumuri* parfum);
	void displayList(int x);
	void cautare(int x);
	void minim();
	void scriereFisier();
};

void Lista::add(Parfumuri* nou)
{
	Parfumuri* parfum;
	parfum = head;

	if (parfum)
	{
		if (nou->pret < parfum->pret)
		{
			nou->next = head;
			head = nou;
		}
		else
		{
			while (parfum->next && (parfum->next)->pret < nou->pret)
				parfum = parfum->next;

			nou->next = parfum->next;
			parfum->next = nou;
		}
	}
	else
		head = nou;
}

void Lista::displayList(int x)
{
	Parfumuri* parfum;
	parfum = head;

	if (!parfum)
	{
		cout << "\nLista este vida" << endl;
		return;
	}

	for (parfum = head; parfum != NULL; parfum = parfum->next)
	{
		if (parfum->tip == x)
			parfum->display();
	}
}

void Lista::cautare(int x)
{
	Parfumuri* parfum;
	int gasit = 0;

	for (parfum = head; parfum != NULL; parfum = parfum->next)
	{
		if (parfum->pret == x)
		{
			cout << "\nSe gaseste in lista" << endl;
			parfum->display();
			gasit = 1;
		}
	}

	if (gasit == 0)
		cout << "\nNu se gaseste in lista" << endl;
}

void Lista::minim()
{
	Parfumuri* parfum;
	Parfumuri* min = head;

	for (parfum = head; parfum != NULL; parfum = parfum->next)
	{
		if (parfum->pret < min->pret)
			min = parfum;
	}

	cout << "\nParfumul cu pretul minim: " << endl;
	min->display();
}

void Lista::scriereFisier()
{
	Parfumuri* parfum;
	parfum = head;

	ofstream f("fisier.txt");
	if (!parfum)
	{
		cout << "\nLista este vida" << endl;
			return;
	}

	while (parfum)
	{
		f << parfum->tip << " " << parfum->pret << " ";

		if (parfum->tip == 1)
		{
			parfumuriBarbati* pB = (parfumuriBarbati*)parfum;

			f << pB->forma << endl;
		}

		if (parfum->tip == 2)
		{
			parfumuriFemei* pF = (parfumuriFemei*)parfum;

			f << pF->categorieOlfactiva << endl;
		}

		parfum = parfum->next;
	}

	cout << "\nDatele s-au scris" << endl;

	f.close();
}

class myException
{
public:
	string What;
	int what;

	myException()
	{
		What = "0";
		what = 0;
	}

	myException(string s, int i)
	{
		What = s;
		what = i;
	}
};

void adding(Lista& l, int x)
{
	int pret;
	string forma, categorieOlfactiva;

	Parfumuri* parfum;
	do
	{
		try
		{
			cout << "dati pret: ";
			cin >> pret;
			cin.get();

			if (pret < 0)
				throw myException("\nPretul trebuie sa fie pozitiv", pret);
		}

		catch (myException e)
		{
			cout << e.What << ":";
			cout << e.what << "\n";
		}
	} while (pret < 0);

	if (x == 1)
	{
		parfumuriBarbati* pB;
		cout << "dati forma: ";
		getline(cin, forma);

		pB = new parfumuriBarbati(1, pret, forma);
		parfum = pB;
		l.add(parfum);
	}
	else if (x == 2)
	{
		parfumuriFemei* pF;
		cout << "dati categorie olfactiva: ";
		getline(cin, categorieOlfactiva);

		pF = new parfumuriFemei(2, pret, categorieOlfactiva);
		parfum = pF;
		l.add(parfum);
	}

}

int main()
{
	int opt;
	Lista l;
	l.head = NULL;

	do
	{
		cout << "\n1. introducere parfum barbati" << endl;
		cout << "2. introducere parfum femei" << endl;
		cout << "3. afisare parfumuri barbati" << endl;
		cout << "4. afisare parfumuri femei" << endl;
		cout << "5. cautare parfum dupa pret" << endl;
		cout << "6. afisarea parfumului cu pretul cel mai mic" << endl;
		cout << "7. introducere parfumuri in fisier" << endl;
		cout << "0. iesire" << endl;

		cout << "\ndati optiune: ";
		cin >> opt;
		cin.get();

		switch (opt)
		{
		case 1:
			adding(l, 1);
			break;
		case 2:
			adding(l, 2);
			break;
		case 3:
			l.displayList(1);
			break;
		case 4:
			l.displayList(2);
			break;
		case 5:
			cout << "dati pretul parfumului cautat: ";
			int x;
			cin >> x;
			l.cautare(x);
			break;
		case 6:
			l.minim();
			break;
		case 7:
			l.scriereFisier();
			break;
		case 0:
			break;
		default:
			cout << "\nOptiune gresita" << endl;
			break;
		}
	} while (opt != 0);

	getchar();
	return 0;
}