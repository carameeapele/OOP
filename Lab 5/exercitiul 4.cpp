#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class list;

class articol
{
	int tip;
	string producator;
	int pret;
	int rezolutia;
	articol* next;
public:
	articol(int t, string prod, int p, int r)
	{
		tip = t;
		producator = prod;
		pret = p;
		rezolutia = r;
		next = NULL;
	}
	virtual void display()
	{
		cout << "---------------------------------\n";
		cout << "producator: " << producator << endl;
		cout << "pret: " << pret << endl;
		cout << "rezolutia: " << rezolutia << endl;
	}
	friend class list;
};

class rama_foto :public articol
{
	int diagonala;
	int format_afisare;
public:
	rama_foto(int t, string prod, int p, int r, int d, int fa) :articol(t, prod, p, r)
	{
		diagonala = d;
		format_afisare = fa;
	}

	void display()
	{
		articol::display();
		cout << "diagonala: " << diagonala << endl;
		cout << "format afisare: " << format_afisare << endl;
	}

	friend class list;
};

class aparat_foto:public articol
{
	string tip_aparat;
	string tip_senzor;
public:
	aparat_foto(int t, string prod, int p, int r, string a, string s) :articol(t, prod, p, r)
	{
		tip_aparat = a;
		tip_senzor = s;
	}

	void display()
	{
		articol::display();
		cout << "tip aparat: " << tip_aparat << endl;
		cout << "tip senzor: " << tip_senzor << endl;
	}

	friend class list;
};

class list
{
public:
	articol* head;
	void add(articol* a);
	void display_list(int x);
};

void list::add(articol* a)
{
	articol* p;
	p = head;
	if (p)
	{
		if (a->producator <= p->producator)
		{
			a->next = head;
			head = a;
		}
		else
		{
			while (p->next && (p->next)->producator == a->producator)
				p = p->next;
			a->next = p->next;
			p->next = a;
		}
	}
	else
		head = a;
}

void list::display_list(int x)
{
	articol* a;
	a = head;
	if (!a)
	{
		cout << "lista e vida" << endl;
	}
	
	if (x == 0)
	{
		for (a = head; a != NULL; a = a->next)
			if (a->tip == 1)
				a->display();
	}
	else
	{
		if (x == 1)
		{
			for (a = head; a != NULL; a = a->next)
				if (a->tip == 2)
					a->display();
		}
	}

	cin.get();
}

void adding(list& l, int x)
{
	string producator, tip_aparat, tip_senzor;
	int pret, rezolutia, diagonala, format_afisare;

	articol* art;
	cin.get();
	cout << "\tdati producator: ";
	cin >> producator;
	cout << "\tdati pret: ";
	cin >> pret;
	cout << "\tdati rezolutia: ";
	cin >> rezolutia;
	
	if (x == 0)
	{
		rama_foto* rf;
		cin.get();

		cout << "\tdati diagonala: ";
		cin >> diagonala;
		cout << "\tdati format afisare: ";
		cin >> format_afisare;

		rf = new rama_foto(1, producator, pret, rezolutia, diagonala, format_afisare);
		art = rf;
		l.add(art);
	}
	else
	{
		if (x == 1)
		{
			aparat_foto* af;
			cin.get();

			cout << "\tdati tip aparat: ";
			cin >> tip_aparat;
			cout << "\tdati tip senzor: ";
			cin >> tip_senzor;

			af = new aparat_foto(2, producator, pret, rezolutia, tip_aparat, tip_senzor);
			art = af;
			l.add(art);
		}
	}
}

int main()
{
	int opt;
	list l;
	l.head = NULL;

	do
	{
		/*cout << "\napasati enter pentru a continua";
		cin.get();*/
		system("CLS");

		cout << "\n1. adaugare rama foto" << endl;
		cout << "2. adaugare aparat foto" << endl;
		cout << "3. afisare rame foto" << endl;
		cout << "4. afisare aparate foto" << endl;
		cout << "5. iesire" << endl;
		
		cout << "\ndati optiune: ";
		cin >> opt;

		switch (opt)
		{
		case 1:
			cout << "\n--------RAMA FOTO--------\n";
			adding(l, 0);
			break;
		case 2:
			cout << "\n--------APARAT FOTO--------\n";
			adding(l, 1);
			break;
		case 3:
			cout << "\nRAME FOTO: \n";
			l.display_list(0);
			cin.get();
			break;
		case 4:
			cout << "\nAPARATE FORO: \n";
			l.display_list(1);
			cin.get();
			break;
		case 5:
			break;
		default:
			cout << "optiune gresita" << endl;
			break;
		}
	} while (opt != 5);

	getchar();
	return 0;
}