#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class List;

class agency
{
private:
	int type;
	string name;
	int price;
	int tenis;
	agency* next;
public:
	agency(int tp, string n, int p, int t)
	{
		type = tp;
		name = n;
		price = p;
		tenis = t;
		next = NULL;
	}

	virtual void display()
	{
		cout << "\n------------------------\n";
		cout << "nume: " << name << endl;
		cout << "pret: " << price << endl;
		cout << "teren tenis: " << tenis << endl;
	}

	friend class List;
};

class hotel :public agency
{
	int stars, pool, spa;
public:
	hotel(int tp, string n, int p, int t, int s, int po, int sp) :agency(tp, n, p, t)
	{
		stars = s;
		pool = po;
		spa = sp;
	}

	void display()
	{
		agency::display();
		cout << "numar stele: " << stars << endl;
		cout << "piscina: " << pool << endl;
		cout << "sauna: " << spa << endl;
	}

	friend class List;
};

class guestHouse :public agency
{
	int daisies, garden;
public:
	guestHouse(int tp, string n, int p, int t, int d, int g) :agency(tp, n, p, t)
	{
		daisies = d;
		garden = g;
	}

	void display()
	{
		agency::display();
		cout << "numar margarete: " << daisies << endl;
		cout << "gradina: " << garden << endl;
	}

	friend class List;
};

class List
{
public:
	agency* head;
	void add(agency* a);
	void displayList();
};

class myException
{
public:
	string strWhat;
	int what;
	myException()
	{
		strWhat = "0";
		what = 0;
	}
	myException(string s, int c)
	{
		strWhat = s;
		what = c;
	}
};

void List::add(agency* a)
{
	agency* p;
	p = head;
	if (p)
	{
		if (a->name < p->name)
		{
			a->next = head;
			head = a;
		}
		else
		{
			while (p->next && (p->next)->name < a->name)
				p = p->next;

			a->next = p->next;
			p->next = a;
		}
	}
	else
		head = a;
}

void List::displayList()
{
	agency* a;
	a = head;

	if (!a)
	{
		cout << "lista este vida";
	}
	else
	{
		while (a)
		{
			a->display();
			a = a->next;
		}
	}
}

void adding(List& l, int x)
{
	string name;
	int price, tenis, stars, pool, spa, daisies, garden;
	agency* a;

	cout << "dati nume: ";
	getline(cin, name);

	try
	{
		cout << "dati pretul camerei: ";
		cin >> price;

		if (price < 0)
			throw myException("pretul nu este pozitiv", price);
	}
	catch (myException e)
	{
		cout << e.strWhat << ":";
		cout << e.what << "\n";
	}

	cout << "dati teren tenis [0 - nu / 1 - da]: ";
	cin >> tenis;

	if (x == 0)
	{
		hotel* h;
		cout << "dati numar stele: ";
		cin >> stars;
		cout << "dati piscina [0/1]: ";
		cin >> pool;
		cout << "dati sauna [0/1]: ";
		cin >> spa;

		h = new hotel(1, name, price, tenis, stars, pool, spa);
		a = h;
		l.add(a);
	}
	else if (x == 1)
	{
		guestHouse* g;
		cout << "dati numar de margarete: ";
		cin >> daisies;
		cout << "dati gradia [0/1]: ";
		cin >> garden;

		g = new guestHouse(2, name, price, tenis, daisies, garden);
		a = g;
		l.add(a);
	}
}

int main()
{
	int opt;
	List l;
	l.head = NULL;

	do
	{
		cout << "1. adaugare oferta hotel" << endl;
		cout << "2. adaugare oferta pensiune" << endl;
		cout << "3. afisare oferte" << endl;
		cout << "0. iesire" << endl;
		cout << "\ndati optiune: ";
		cin >> opt;
		cin.get();

		switch (opt)
		{
		case 1:
			adding(l, 0);
			break;
		case 2:
			adding(l, 1);
			break;
		case 3:
			l.displayList();
			break;
		case 0:
			break;
		default:
			cout << "optiune gresita" << endl;
			break;
		}
	} while (opt != 0);

	getchar();
	return 0;
}