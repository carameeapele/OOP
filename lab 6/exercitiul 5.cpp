#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

//clasa lista
class List;

//clasa de baza
class Item
{
private:
	int type;
	string producer;
	string name;
	Item* next;
public:
	//constructorul clasei de baza
	Item(int t, string p, string n)
	{
		type = t;
		producer = p;
		name = n;
		next = NULL;
	}

	//afisarea clasei de baza
	virtual void display()
	{
		cout << "---------------------------\n";
		cout << "producator: " << producer << endl;
		cout << "denumire: " << name << endl;
	}

	friend class List;
};

//prima clasa derivata
class Pencil :public Item
{
private:
	string pencilLead;
public:
	//constructorul clasei derivata
	Pencil(int t, string p, string n, string l) :Item(t, p, n)
	{
		pencilLead = l;
	}

	//afisare
	void display()
	{
		Item::display();
		cout << "tip mina: " << pencilLead << endl;
	}

	friend class List;
};

//a doua clasa derivata
class Pen :public Item
{
private:
	string colour;
public:
	//constructor
	Pen(int t, string p, string n, string c) :Item(t, p, n)
	{
		colour = c;
	}

	//afisare
	void display()
	{
		Item::display();
		cout << "culoare: " << colour << endl;
	}

	friend class List;
};

class List
{
public:
	Item* head;
	void add(Item* item);
	void displayList(int x);
};

void List::add(Item* a)
{
	Item* item;
	item = head;
	if (item)
	{
		if (a->producer <= item->producer)
		{
			a->next = head;
			head = a;
		}
		else
		{
			while (item->next && (item->next)->producer < a->producer)
				item = item->next;

			a->next = item->next;
			item->next = a;
		}
	}
	else
		head = a;
}

void List::displayList(int x)
{
	Item* a;
	a = head;
	
	if (!a)
		cout << "\nlista este vida" << endl;
	else
	{
		for (a = head; a != NULL; a = a->next)
		{
			if (a->type == x)
				a->display();
		}
		
		/*if (x == 1)
		{
			for (a = head; a != NULL; a = a->next)
				if (a->type == 1)
					a->display();
		}
		else if (x == 2)
		{
			for (a = head; a != NULL; a = a->next)
				if (a->type == 2)
					a->display();
		}*/
	}
	cin.get();
}

class supraincarcare
{
public:
	string producer;
	string name;
public:
	friend ostream& operator<<(ostream* out, supraincarcare& a);
	friend istream& operator>>(istream* in, supraincarcare& a);
};

ostream& operator<<(ostream& out, supraincarcare& a)
{
	cout << "SE CITESC DATELE PRODUSELOR DIN MAGAZIN\n";
	cout << endl;
	return out;
}

istream& operator>>(istream& in, supraincarcare& a)
{
	cout << "dati producator: ";
	cin >> a.producer;
	cout << "dati denumire: ";
	cin >> a.name;
	return in;
}

void adding(List& l, int x)
{
	string pencilLead;
	string colour;
	Item* item;
	cin.get();

	supraincarcare supr;

	cout << supr;
	cin >> supr;

	if (x == 1)
	{
		Pencil* pencil;
		cin.get();

		cout << "dati tip mina: ";
		cin >> pencilLead;
		
		pencil = new Pencil(1, supr.producer, supr.name, pencilLead);
		item = pencil;
		l.add(item);
	}
	else if (x == 2)
	{
		Pen* pen;
		cin.get();

		cout << "dati culoare: ";
		cin >> colour;

		pen = new Pen(2, supr.producer, supr.name, colour);
		item = pen;
		l.add(item);
	}
}

int main()
{
	int opt;
	List l;
	l.head = NULL;

	do
	{
		system("CLS");

		cout << "1. adaugare creioane intr-o lista ordonata" << endl;
		cout << "2. adaugare pixuri intr-o lista ordonata" << endl;
		cout << "3. afisare creioane" << endl;
		cout << "4. afisare pixuri" << endl;
		cout << "5. iesire" << endl;
		cout << "\ndati optiune: ";
		cin >> opt;

		switch (opt)
		{
		case 1:
			cout << "\n-----------CREION-----------\n";
			adding(l, 1);
			break;
		case 2:
			cout << "\n-----------PIX-----------\n";
			adding(l, 2);
			break;
		case 3:
			cout << "\nCREIOANE: \n";
			l.displayList(1);
			cin.get();
			break;
		case 4:
			cout << "\nPIXURI: \n";
			l.displayList(2);
			cin.get();
			break;
		case 5:
			break;
		default:
			cout << "\noptiune gresita" << endl;
			break;
		}
	} while (opt != 5);

	getchar();
	return 0;
}