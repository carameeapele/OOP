#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>


using namespace std;

class BazaDate;
class Vacanta;
class Circuit;
class Croaziera;

int Numar(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]) == false)
			return 0;
	}

	return 1;
}

//clasa de baza
class Pachet
{
	unsigned int categorie;
	unsigned int durata;
	unsigned int pret;

public:

	Pachet* next;

	Pachet(unsigned int c, unsigned int d, unsigned int p)
	{
		categorie = c;
		durata = d;
		pret = p;

		next = NULL;
	}

	virtual void display();

	friend class BazaDate;
};

void Pachet::display()
{
	cout << durata << " zile" << endl;
	cout << pret << "/persoana" << endl;
}

//------------------------------------------------------------------------------

class Hotel
{
	string nume;
	unsigned int nrStele;

public:

	Hotel* next;

	Hotel(string n, unsigned int s)
	{
		nume = n;
		nrStele = s;
		next = NULL;
	}

	void display()
	{
		cout << "\t" << nume << " " << nrStele << " stele" << endl;
	}

	friend class Vacanta;
	friend class Circuit;
	friend class BazaDate;
};

//------------------------------------------------------------------------------

//prima clasa derivata
class Vacanta: public Pachet
{
	string tara, oras;

	//fiecare pachet de vacanta are lista lui de optiuni de hoteluri
	Hotel* hotelRoot; 

public:

	Vacanta* next;

	Vacanta(unsigned int c, unsigned int d, unsigned int p, string t, string o):Pachet(c, d, p)
	{
		tara = t;
		oras = o;

		hotelRoot = NULL;
		next = NULL;
	}

	void addHotel(Hotel* newHotel);
	int deleteHotel(string);
	void writeHotel(Hotel* h);
	virtual void display();
	virtual void sortHotel();

	friend class BazaDate;
};

//pentru adaugarea unui nou hotel la un pachet de vacanta
void Vacanta::addHotel(Hotel* newHotel)
{
	if (hotelRoot)
	{
		newHotel->next = hotelRoot;
		hotelRoot = newHotel;
	}
	else
		hotelRoot = newHotel;
}

//functie pentru scriere in fisierul STERSE
void Vacanta::writeHotel(Hotel* h)
{
	ofstream g;
	//pentru scrierea in continuarea fisierului fara sa faca OVERWRITING
	g.open("STERSE.txt", ofstream::app);

	g << h->nume << " " << h->nrStele << " stele" << endl;

	g.close();
}

//pentru stergerea unui hotel de la un pachet de vacanta
int Vacanta::deleteHotel(string numeTheOne)
{
	// the One va fi nodul sters
	Hotel* theOne, * h;

	if (hotelRoot == NULL)
	{
		cout << "Nu sunt inregistrate hoteluri" << endl;
		return 0;
	}

	//cazul in care nodul dorit sters este radacina listei de hoteluri
	if (hotelRoot->nume == numeTheOne)
	{
		theOne = hotelRoot;
		hotelRoot = hotelRoot->next;

		writeHotel(theOne);
		delete theOne;
		return 1;
	}
	
	//se parcurge lista pana se gaseste hotelul dorit sters
	for(h = hotelRoot; h->next != NULL; h = h->next)
		if (h->next->nume == numeTheOne)
		{
			theOne = h->next;
			h->next = h->next->next;

			writeHotel(theOne);
			delete theOne;
			return 1;
		}

	return 0;
}

//afisarea pachetelor de vacanta si lista de hoteluri a fiecaruia
void Vacanta::display()
{
	cout << "\n----------------------------------------" << endl;
	cout << tara << " " << oras << endl;
	Pachet::display();

	cout << "\n\tHOTELURI: \n" << endl;

	Hotel* h = hotelRoot;
	while (h)
	{
		h->display();
		h = h->next;
	}
}

//functie de sortare descrescatoare a hotelurilor dupa numarul de stele
void Vacanta::sortHotel()
{
	Hotel* h, * aux = new Hotel("", 0);
	int ord;

	do
	{
		h = hotelRoot;
		ord = 1;

		while (h->next)
		{
			if (h->nrStele < h->next->nrStele)
			{
				aux->nume = h->nume;
				aux->nrStele = h->nrStele;
				
				h->nume = h->next->nume;
				h->nrStele = h->next->nrStele;

				h->next->nume = aux->nume;
				h->next->nrStele = aux->nrStele;

				ord = 0;
			}

			h = h->next;
		}

	} while (ord == 0);
}

//----------------------------------------------------------------------------

//a doua clasa derivata
class Circuit: public Pachet
{
	string tara;
	int transport;

	//radacina listei de hoteluri de la pachetele de circuit
	Hotel* hotelRoot;

public:

	Circuit* next;

	Circuit(unsigned int c, unsigned int d, unsigned int p, string t, int tr): Pachet(c, d, p)
	{
		tara = t;
		transport = tr;

		hotelRoot = NULL;
		next = NULL;
	}

	void addHotel(Hotel* newHotel);
	virtual void display();

	friend class BazaDate;
};

//functie pentru adaugarea de optiuni de hoteluri la pachetele de circuit
void Circuit::addHotel(Hotel* newHotel)
{
	if (hotelRoot)
	{
		newHotel->next = hotelRoot;
		hotelRoot = newHotel;
	}
	else
		hotelRoot = newHotel;
	
}

void Circuit::display()
{
	cout << "\n----------------------------------------" << endl;
	cout << tara << " cu ";

	if (transport == 1)
		cout << "autocarul" << endl;
	else
		cout << "avionul" << endl;

	Pachet::display();

	cout << "\n\tHOTELURI: \n" << endl;

	Hotel* h = hotelRoot;
	while (h)
	{
		h->display();
		h = h->next;
	}
}

//----------------------------------------------------------------------------

//a treia clasa derivata
class Croaziera: public Pachet
{
	string vas, pornire, sosire;

public:

	Croaziera* next;

	Croaziera(unsigned int c, unsigned int d, unsigned int p, string v, string po, string s): Pachet(c, d, p)
	{
		vas = v;
		pornire = po;
		sosire = s;

		next = NULL;
	}	
	
	virtual void display();

	friend class BazaDate;
};

void Croaziera::display()
{
	cout << "\n----------------------------------------" << endl;
	cout << vas << endl;
	cout << "PORNIRE: " << pornire << " \nSOSIRE: " << sosire << endl;
	Pachet::display();

}

//----------------------------------------------------------------------------

//clasa lista
class BazaDate
{
public:
	Pachet* root; //radacina tuturor pachetelor
	Vacanta* vacantaRoot, * lastVacanta; //radacina pachetelor de vacanta si pointer catre ultima vacanta
	Circuit* circuitRoot, * lastCircuit; //radacina pachetelor de circuit si pointer catre ultimul circuit
	Croaziera* croazieraRoot; //radacina croazierelor

	void add(Pachet* newPachet);

	//functie pentru cautarea unei vacante 
	Vacanta* searchVacanta()
	{
		Pachet* p = root;
		Vacanta* v;

		string tara, oras;
		cout << "Tara: "; cin >> tara;
		cout << "Oras: "; cin >> oras;

		int ok = 0;

		while (p)
		{
			if (p->categorie == 1)
			{
				v = (Vacanta*)p;

				if (v->tara == tara && v->oras == oras)
				{
					//s-a gasit vacanta si se returneaza pointer catre ea
					ok = 1; 
					return v;
				}
			}

			p = p->next;
		}

		if (ok == 0)
			return NULL; //nu s-a gasit vacanta
	}

	//acelasi lucru pentru circuite
	Circuit* searchCircuit()
	{
		Pachet* p = root;
		Circuit* ci;

		string tara;
		int ok = 0, transport;

		cout << "Tara: "; cin >> tara;
		cout << "Transport: "; cin >> transport;

		while (p)
		{
			if (p->categorie == 2)
			{
				ci = (Circuit*)p;

				if (ci->tara == tara && ci->transport == transport)
				{
					ok = 1;
					return ci;
				}
			}

			p = p->next;
		}

		if (ok == 0)
			return NULL;
	}

	//si pentru croaziere
	Croaziera* searchCroaziera()
	{
		Pachet* p = root;
		Croaziera* c;

		string vas, pornire;
		int ok = 0;

		cout << "Vas: "; cin >> vas;
		cout << "Pornire: "; cin >> pornire;

		while (p)
		{
			if (p->categorie == 3)
			{
				c = (Croaziera*)p;

				if (c->vas == vas && c->pornire == pornire)
				{
					ok = 1;
					return c;
				}
			}

			p = p->next;
		}

		if (ok == 0)
			return NULL;
	}

	void changePrice(int x);
	//void orderPrice();
	void displayData(int x);
	void writeData();

	//se afiseaza toate pachetele
	void displayAllData()
	{
		Pachet* p = root;

		while (p)
		{
			p->display();
			p = p->next;
		}

		cin.get();
	}
};

//functie de introducere a datelor in lista
void BazaDate::add(Pachet* newPachet)
{
	Pachet* p = root;

	//se introduc ordonat crescator in functie de pret
	if (p)
	{
		if (newPachet->pret < p->pret)
		{
			newPachet->next = root;
			root = newPachet;
		}
		else
		{
			while (p->next && (p->next)->pret < newPachet->pret)
				p = p->next;

			newPachet->next = p->next;
			p->next = newPachet;
		}

	}
	else
		root = newPachet;

	//se introduc si in lista proprie dupa categorie

	if (newPachet->categorie == 1)
	{
		Vacanta* v = (Vacanta*)newPachet;

		if (vacantaRoot)
		{
			v->next = vacantaRoot;
			vacantaRoot = v;
		}
		else
			vacantaRoot = v;

		lastVacanta = v;
	}

	if (newPachet->categorie == 2)
	{
		Circuit* ci = (Circuit*)newPachet;

		if (circuitRoot)
		{
			ci->next = circuitRoot;
			circuitRoot = ci;
		}
		else
			circuitRoot = ci;

		lastCircuit = ci;
	}

	if (newPachet->categorie == 3)
	{
		Croaziera* c = (Croaziera*)newPachet;

		if (croazieraRoot)
		{
			c->next = croazieraRoot;
			croazieraRoot = c;
		}
		else
			croazieraRoot = c;
	}
}

//afisare dupa categoria x
void BazaDate::displayData(int x)
{
	Pachet* p = root;

	if (!p)
	{
		cout << "\nNu exista pachete inregistrate" << endl;
		return;
	}

	for (p = root; p != NULL; p = p->next)
	{
		if (p->categorie == x)
			p->display();
	}

	cin.get();
}

//functie pentru schimbarea pretului unui pachet
void BazaDate::changePrice(int x)
{
	int newPrice;
	Pachet* p = root;
	cout << "Dati pretul NOU: "; cin >> newPrice;

	//se cauta pachetul la care se doreste schimbarea pretului
	do
	{
		switch (x)
		{
		case 1:
			p = searchVacanta();
			break;
		case 2:
			p = searchCircuit();
			break;
		case 3:
			p = searchCroaziera();
			break;
		}

		if (p == NULL)
			cout << "Pachetul nu exista" << endl;

	} while (p == NULL);

	p->pret = newPrice;
	cout << "\nModificat cu succes!";
	cin.get();
}

/*void BazaDate::orderPrice()
{
	Pachet* p1, * p2, * aux;

	for (p1 = p2 = root; p1 != NULL; p2 = p1, p1 = p1->next)
	{
		if(p2->pret > p1->pret)
		{
			aux = p2->next;
			p1 = p1->next;
		}
		
	}
}*/

//functie de scriere a listei in FISIER
void BazaDate::writeData()
{
	Pachet* p = root;
	ofstream g("fisier.txt");

	if (!g.is_open())
	{
		cout << "\nNu se poate deschide fisierul" << endl;
		return;
	}

	if (!p)
	{
		cout << "\nNu exista inregistrari" << endl;
		return;
	}

	while (p)
	{
		g << "\n----------------------------------------" << endl;

		if (p->categorie == 1)
		{
			Vacanta* v = (Vacanta*)p;

			g << "VACANTA in " << v->tara << ", " << v->oras << endl;
			g << p->durata << " zile" << endl;
			g << p->pret << "/persoana" << endl;
			g << "\n\tHOTELURI: \n" << endl;

			Hotel* h = v->hotelRoot;
			while (h)
			{
				g << "\t" << h->nume << " " << h->nrStele << " stele" << endl;
				h = h->next;
			}
		}

		if (p->categorie == 2)
		{
			Circuit* ci = (Circuit*)p;

			g << "CIRCUIT in " << ci->tara << ", transport cu ";

			if (ci->transport == 1)
				g << "autocarul" << endl;
			else
				g << "avionul" << endl;

			g << p->durata << " zile" << endl;
			g << p->pret << "/persoana" << endl;
			g << "\n\tHOTELURI: \n" << endl;

			Hotel* h = ci->hotelRoot;
			while (h)
			{
				g << "\t" << h->nume << " " << h->nrStele << " stele" << endl;
				h = h->next;
			}
		}

		if (p->categorie == 3)
		{
			Croaziera* c = (Croaziera*)p;

			g <<"CROAZIERA cu "<< c->vas << endl;
			g << "Pornind din " << c->pornire << " pana in " << c->sosire << endl;
			g << p->durata << " zile" << endl;
			g << p->pret << "/persoana" << endl;
		}

		p = p->next;
	}

	g.close();
	cin.get();
}

//----------------------------------------------------------------------------

//functie de citire a datelor dintr-un fisier
void citireDate(BazaDate &BD)
{
	Pachet* pachet;

	int categorie, durata, pret, nrStele, transport;
	string tara, oras, nume, vas, pornire, sosire;

	ifstream f("pachete.txt");

	if (!f.is_open())
	{
		cout << "Nu se poate deschide fisierul" << endl;
		return;
	}

	while (!f.eof())
	{
		// 1 - vacanta / 2 - circuit / 3 - croaziera / 4 - hotel vacanta / 5 - hotel circuit

		f >> categorie;

		if (categorie == 1)
		{
			Vacanta* v;

			f >> durata >> pret >> tara >> oras;
			v = new Vacanta(1, durata, pret, tara, oras);
			pachet = v;

			BD.add(pachet);
		}
		
		if (categorie == 2)
		{
			Circuit* ci;

			f >> durata >> pret >> tara >> transport;
			ci = new Circuit(2, durata, pret, tara, transport);
			pachet = ci;

			BD.add(pachet);
		}

		if (categorie == 3)
		{
			Croaziera* c;

			f >> durata >> pret >> vas >> pornire >> sosire;
			c = new Croaziera(3, durata, pret, vas, pornire, sosire);
			pachet = c;

			BD.add(pachet);
		}

		if (categorie == 4)
		{
			Hotel* h;
			Vacanta* v = BD.lastVacanta;

			f >> nume >> nrStele;
			h = new Hotel(nume, nrStele);
			
			v->addHotel(h);
		}

		if (categorie == 5)
		{
			Hotel* h;
			Circuit* ci = BD.lastCircuit;

			f >> nume >> nrStele;
			h = new Hotel(nume, nrStele);

			ci->addHotel(h);
		}
	}

	cout << "Datele din fisier au fost citite" << endl;
	f.close();
}

//----------------------------------------------------------------------------
//supraincarcarea operatorilor << si  >>

class Supraincarcare
{
public:
	int durata, pret;
public:
	friend ostream& operator<<(ostream* out, Supraincarcare& s);
	friend istream& operator>>(istream* in, Supraincarcare& s);
};

ostream& operator<<(ostream& out, Supraincarcare& s)
{
	cout << "Se citesc datele PACHETULUI" << endl;
	return out;
}

istream& operator>>(istream& in, Supraincarcare& s)
{
	cout << "Durata: "; cin >> s.durata;
	cout << "Pret: "; cin >> s.pret;
	return in;
}

//----------------------------------------------------------------------------
//excepție pentru verificarea categoriei introduse de la tastatura

class myException
{
public:
	string strWhat, What;
	int what;

	myException()
	{
		strWhat = "0";
		What = "0";
		what = 0;
	}

	myException(string s, int i)
	{
		strWhat = s;
		what = i;
	}

	//excepție pentru intregi ca sa nu fie un sir de caractere + supraincarcarea functiei myException
	myException(string s, string w)
	{
		strWhat = s;
		What = w;
	}
};

//----------------------------------------------------------------------------
//functie de adaugare de pachete de la tastatura

void addingPachet(BazaDate& BD, int x)
{
	Pachet* pachet;

	int nrStele, transport;
	string tara, oras, nume, vas, pornire, sosire;

	Supraincarcare s;
	cout << s;
	cin >> s;

	if (x == 1)
	{
		Vacanta* v;

		cout << "Tara: "; cin >> tara;
		cout << "Oras: "; cin >> oras;

		v = new Vacanta(1, s.durata, s.pret, tara, oras);

		Hotel* h;

		cout << "Nume HOTEL: "; cin >> nume;
		cout << "Numar stele HOTEL: "; cin >> nrStele;

		h = new Hotel(nume, nrStele);
		v->addHotel(h);

		pachet = v;
		BD.add(pachet);
	}

	if (x == 2)
	{
		Circuit* ci;

		cout << "Tara: "; cin >> tara;
		cout << "Transport (1 - autorcar / 2 - avion): "; cin >> transport;

		ci = new Circuit(2, s.durata, s.pret, tara, transport);

		Hotel* h;

		cout << "Nume HOTEL: "; cin >> nume;
		cout << "Numar stele HOTEL: "; cin >> nrStele;

		h = new Hotel(nume, nrStele);
		ci->addHotel(h);
		
		pachet = ci;
		BD.add(pachet);
	}

	if (x == 3)
	{
		Croaziera* c;

		cout << "Vas: "; cin >> vas;
		cout << "Orasul de pornire: "; cin >> pornire;
		cout << "Orasul de sosire: "; cin >> sosire;

		c = new Croaziera(3, s.durata, s.pret, vas, pornire, sosire);
		pachet = c;

		BD.add(pachet);
	}

	cout << "\nAdaugat!";
	cin.get();
}

//functie de adaugare a hotelurilor de la tastatura
void addingHotel(BazaDate& BD, int x)
{
	string nume, stele;
	int nrStele;

	if (x == 1)
	{
		Vacanta* v;
		do
		{
			v = BD.searchVacanta();

			if (v == NULL)
				cout << "Nu exista VACANTA cautata" << endl;

		} while (v == NULL);

		cout << "Nume HOTEL: ";
		cin >> nume;

		do
		{
			try
			{
				cout << "Numar Stele HOTEL: ";
				cin >> stele;

				if (Numar(stele) == 0)
					throw myException("Contine caractere", stele);
			}
			catch (myException e)
			{
				cout << e.strWhat << ": ";
				cout << e.What << "\n";
			}
		} while (Numar(stele) == 0);

		//convert string to int
		nrStele = stoi(stele);

		Hotel* h = new Hotel(nume, nrStele);

		v->addHotel(h);
	}

	if (x == 2)
	{
		Circuit* c = BD.searchCircuit();

		if (c == NULL)
		{
			cout << "Nu exista CIRCUITUL cautat" << endl;
			return;
		}

		cout << "Nume HOTEL: "; cin >> nume;
		cout << "Numar Stele HOTEL: "; cin >> nrStele;

		Hotel* h = new Hotel(nume, nrStele);

		c->addHotel(h);
	}

	cout << "\nAdaugat!";
	cin.get();
}

//----------------------------------------------------------------------------

void Menu()
{
	cout << endl;

	cout << "0. iesire" << endl;
	cout << "1. Adaugare PACHET" << endl;
	cout << "2. Adaugare HOTEL" << endl;
	cout << "3. Afisare pachete de VACANTA" << endl;
	cout << "4. Afisare pachete de CIRCUIT" << endl;
	cout << "5. Afisare pachete de CROAZIERA" << endl;
	cout << "6. Stergerea unui Hotel de Vacanta" << endl;
	cout << "7. Modificarea pretului unui Pachet" << endl;
	cout << "8. Ordonarea crescatoare dupa pret a Pachetelor" << endl;
	cout << "9. Ordonarea descrescatoare dupa numarul de stele al Hotelurior de Vacanta" << endl;
	cout << "10. Refresh FISIER" << endl;
}

//----------------------------------------------------------------------------

int main()
{
	int opt;

	BazaDate BD;
	BD.root = NULL;
	BD.vacantaRoot = NULL;
	BD.circuitRoot = NULL;
	BD.croazieraRoot = NULL;

	string nume;
	int pretNou;
	int x;

	Vacanta* v;
	Circuit* ci;
	Croaziera* c;

	//fac citirea datelor din fisier de la inceput ca sa nu mai adaug o optiune doar pentru atat
	citireDate(BD);

	do
	{
		system("CLS");
		Menu();

		cout << "\nDati optiune: ";
		cin >> opt;

		switch(opt)
		{
		case 0:
			break;
		case 1:
			do
			{
				try
				{
					cout << "\n1- VACANTA / 2- CIRCUIT / 3- CROAZIERA: ";
					cin >> x;

					if (x < 0 || x > 3)
						throw myException("Nu exista categoria", x);
				}
				catch (myException e)
				{
					cout << e.strWhat << ": ";
					cout << e.what << "\n";
				}
			} while (x < 0 || x > 3);

			addingPachet(BD, x);
			cin.get();
			break;
		case 2:
			do
			{
				try
				{
					cout << "Hotel adaugat la pachet de 1 - VACANTA / 2 - CIRCUIT: ";
					cin >> x;

					if (x < 0 || x > 2)
						throw myException("Nu exista categoria", x);
				}
				catch (myException e)
				{
					cout << e.strWhat << ": ";
					cout << e.what << "\n";
				}
			} while (x < 0 || x > 2);

			addingHotel(BD, x);

			cin.get();
			break;
		case 3:
			cout << endl;
			BD.displayData(1); //1 - VACANTE

			cin.get();
			break;
		case 4:
			cout << endl;
			BD.displayData(2);	//2 - CIRCUITE

			cin.get();
			break;
		case 5:
			cout << endl;
			BD.displayData(3);	//3 - CROAZIERE
			
			cin.get();
			break;
		case 6:
			//se cauta pachetul de vacanta pentru care se doreste stergerea hotelului
			do
			{
				cout << "Vacanta pentru care doriti sortarea HOTELURILOR: " << endl;
				v = BD.searchVacanta();

				if (v == NULL)
					cout << "Nu se gaseste VACANTA" << endl;

				cout << "Numele HOTELULUI: "; cin >> nume;
				int sters = v->deleteHotel(nume);

				if (sters == 1)
				{
					cout << "HOTEL sters si scris in STERSE.txt cu succes" << endl;

					cin.get();
					break;
				}

				cout << "Nu s-a putut sterge" << endl;

			} while (v == NULL); //se cere reintroducerea datelor pana sunt corecte

			cin.get();
			break;
		case 7:
			do
			{
				try
				{
					cout << "\n1- VACANTA / 2- CIRCUIT / 3- CROAZIERA: ";
					cin >> x;

					if (x < 0 || x > 3)
						throw myException("Nu exista categoria", x);
				}
				catch (myException e)
				{
					cout << e.strWhat << ": ";
					cout << e.what << "\n";
				}
			} while (x < 0 || x > 3);

			BD.changePrice(x);

			cin.get();
			break;
		case 8:
			//BD.orderPrice();

			//datele sunt memorate ordonat prin urmare se realizeaza afisarea tuturora ordonat
			BD.displayAllData();

			cin.get();
			break;
		case 9:
			//se cauta pachetul de vacanta pentru care se doreste sortarea hotelurilor
			do
			{
				cout << "Vacanta pentru care doriti sortarea HOTELURILOR: " << endl;
				v = BD.searchVacanta();

				if (v == NULL)
					cout << "Nu se gaseste VACANTA" << endl;

			} while (v == NULL);

			v->sortHotel();
			v->display();

			cin.get();  cin.get();
			break;
		case 10:
			BD.writeData();
			cout << "\nScrise in FISIER cu succes!";

			cin.get();
			break;
		default:
			cout << "Optiune gresita" << endl;

			cin.get();
			break;
		}
	} while (opt != 0);

	return 0;
}
