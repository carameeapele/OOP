#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Lista;

class electrocasnice
{
private:
	int tip;
	string producator;
	int pret;
	electrocasnice* next;
public:
	electrocasnice(int t, string pd, int p)
	{
		tip = t;
		producator = pd;
		pret = p;
		next = NULL;
	}

	virtual void display()
	{
		cout << "\n---------------------------\n";
		cout << "producator: " << producator << endl;
		cout << "pret: " << pret << endl;
	}

	virtual string returnArzator()
	{
		return "0";
	}

	friend class Lista;
};

class masinaSpalat : public electrocasnice
{
	int nrPrograme;
public:
	masinaSpalat(int t, string pd, int p, int nr) :electrocasnice(t, pd, p)
	{
		nrPrograme = nr;
	}

	void display()
	{
		electrocasnice::display();
		cout << "numar de  programe: " << nrPrograme << endl;
	}

	friend class Lista;
};

class aragaz :public electrocasnice
{
	string tipArzator;
public:
	aragaz(int t, string pd, int p, string a) :electrocasnice(t, pd, p)
	{
		tipArzator = a;
	}

	void display()
	{
		electrocasnice::display();
		cout << "tip arzator: " << tipArzator << endl;
	}

	string returnArzator()
	{
		electrocasnice::returnArzator();
		return tipArzator;
	}

	friend class Lista;
};

class Lista
{
public:
	electrocasnice* head;
	void add(electrocasnice* e);
	void displayList();
	void searchAragaz();
	void writeFile();
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

void readFile(Lista &l)
{
	electrocasnice* e;

	ifstream f("fisier.txt");
	string producator, tipArzator;
	int tip, pret, nrPrograme;

	if (f.is_open())
	{
		while(!f.eof())
		{
			f >> tip >> producator >> pret;

			if (tip == 1)
			{
				masinaSpalat* m;

				f >> nrPrograme;
				m = new masinaSpalat(1, producator, pret, nrPrograme);
				e = m;
				l.add(e);
			}
			else if (tip == 2)
			{
				aragaz* a;

				f >> tipArzator;
				a = new aragaz(2, producator, pret, tipArzator);
				e = a;
				l.add(e);
			}
		}

		printf("\ndatele s-au citit\n");
	}
	else
	{
		cout << "\nnu s-a putut deschide fisierul";
	}

	f.close();
}

void Lista::add(electrocasnice* e)
{
	electrocasnice* p;
	p = head;

	if (p)
	{
		if (e->producator < p->producator)
		{
			e->next = head;
			head = e;
		}
		else
		{
			while (p->next && (p->next)->producator < e->producator)
				p = p->next;

			e->next = p->next;
			p->next = e;
		}
	}
	else
		head = e;
}

void Lista::displayList()
{
	electrocasnice* e;
	e = head;

	if (!e)
		cout << "\nlista este vida" << endl;
	else
	{
		while (e)
		{
			e->display();
			e = e->next;
		}
	} 
}

void Lista::writeFile()
{
	electrocasnice* e;
	ofstream g("fisier.txt");
	e = head;

	if (!e)
		cout << "\nlista este vida" << endl;
	else
	{
		while (e)
		{
			g << e->tip << " " << e->producator << " " << e->pret << " ";

			if (e->tip == 1)
			{
				masinaSpalat* m = (masinaSpalat*)e;
				g << m->nrPrograme << endl;
			}

			else if (e->tip == 2)
			{
				aragaz* a = (aragaz*)e;
				g << a->tipArzator << endl;
			}

			e = e->next;
		}

		cout << "\ndatele s-au scris\n";
	}

	g.close();
}

void Lista::searchAragaz()
{
	electrocasnice* e;
	e = head;
	string tA, tA_cautat;
	int found = 0;

	cout << "\ndati tip arzator pentru aragazul cautat: ";
	getline(cin, tA);

	while (e)
	{
		if (e->tip == 2)
		{
			tA_cautat = e->returnArzator();
			if (tA == tA_cautat)
			{
				printf("\naragazul cautat: ");
				e->display();
				found = 1;
			}
		}

		e = e->next;
	}

	if (found == 0)
		printf("\naragazul nu exista");
}

void adding(Lista& l, int x)
{
	string producator, tipArzator;
	int pret, nrPrograme;

	electrocasnice* e;

	cin.get();
	cout << "\ndati producator: ";
	getline(cin, producator);

	do
	{
		try
		{
			cout << "dati pret: ";
			cin >> pret;
			if (pret < 0)
				throw myException("pretul nu este pozitiv", pret);
		}
		catch (myException ex)
		{
			cout << ex.strWhat << ":";
			cout << ex.what << "\n";
		}
	} while (pret < 0);

	if (x == 1)
	{
		masinaSpalat* m;

		do
		{
			try
			{
				cout << "dati numar programe: ";
				cin >> nrPrograme;
				if (nrPrograme < 0)
					throw myException("nr programe nu este pozitiv", pret);
			}
			catch (myException ex)
			{
				cout << ex.strWhat << ":";
				cout << ex.what << "\n";
			}
		} while (nrPrograme < 0);

		m = new masinaSpalat(1, producator, pret, nrPrograme);
		e = m;
		l.add(e);
	}
	else if (x == 2)
	{
		aragaz* a;
		cin.get();
		cout << "dati tip arzator: ";
		getline(cin, tipArzator);

		a = new aragaz(2, producator, pret, tipArzator);
		e = a;
		l.add(a);
	}
}

int main()
{
	int opt;
	Lista l;
	l.head = NULL;
	string tipArzator;

	do
	{
		system("CLS");

		cout << "\n1. citire informatii din fisier" << endl;
		cout << "2. adaugare masina de spalata sau aragaz" << endl;
		cout << "3. afisare electrocasnice" << endl;
		cout << "4. cautare aragaz dupa tip arzator" << endl;
		cout << "5. salvare date in fisier" << endl;
		cout << "6. iesire" << endl;
		cout << "\ndati optiune: ";
		cin >> opt;
		cin.get();

		switch (opt)
		{
		case 1:
			readFile(l);
			cin.get();
			break;
		case 2:
			cout << "\nmasina de spalat - 1 / aragaz - 2: ";
			int x; cin >> x;
			adding(l, x);
			break;
		case 3:
			l.displayList();
			cin.get();
			break;
		case 4:
			l.searchAragaz();
			cin.get();
			break;
		case 5:
			l.writeFile();
			cin.get();
			break;
		case 6:
			break;
		default:
			cout << "optiune gresita\n";
			cin.get();
			break;
		}
	} while (opt != 6);

	getchar();
	return 0;
}