// am gasit o mica greseala in timp ce ma uitam peste el acum seara si am corectat-o daca se mai poate

#include<iostream>
#include<string>

using namespace std;

class monitor
{
protected:
	string producator;
	int diagonala;
	int pret;
public:
	monitor(string producator, int diagonala, int pret)
	{
		monitor::producator = producator;
		monitor::diagonala = diagonala;
		monitor::pret = pret;
	}
	
	virtual void display() = 0;
};

class lcd :public monitor
{
	int timp_raspuns;
	string tip_ecran;
	string conectori;
	//lcd* lcd_root;
	lcd* next;
public:
	lcd(string producator, int diagonala, int pret, int timp_raspuns, string tip_ecran, string conectori) :monitor(producator, diagonala, pret)
	{
		lcd::timp_raspuns = timp_raspuns;
		lcd::tip_ecran = tip_ecran;
		lcd::conectori = conectori;
	}

	void display();
	void add();
	void delete_m();
	int search();
	void order();
};

lcd* lcd_root = NULL;
lcd* lcd_last = NULL;

class led :public monitor
{
	string format_ecran;
	int iluminare;
	int boxe_integrate;
	led* next;
public:
	led(string producator, int diagonala, int pret, string format_ecran, int iluminare, int boxe_integrate) :monitor(producator, diagonala, pret)
	{
		led::format_ecran = format_ecran;
		led::iluminare = iluminare;
		led::boxe_integrate = boxe_integrate;
	}

	void display();
	void add();
	void delete_m();
	int search();
	void order();
};

led* led_root = NULL;
led* led_last = NULL;

void lcd::add()
{
	string producator, tip_ecran, conectori;
	int diagonala, pret, timp_raspuns;
	cout << "\ndati producator: ";
	getline(cin, producator);
	cout << "dati diagonala: ";
	cin >> diagonala;
	cout << "dati pret: ";
	cin >> pret;
	cout << "dati timp de raspuns: ";
	cin >> timp_raspuns;
	cin.get();
	cout << "dati tip ecran: ";
	getline(cin, tip_ecran);
	cout << "dati conectori: ";
	getline(cin, conectori);

	lcd* p = new lcd(producator, diagonala, pret, timp_raspuns, tip_ecran, conectori);
	
	//inserare la sfarsitul listei
	if (!lcd_root)
	{
		lcd_root = p;
		lcd_last = lcd_root;
	}
	else
	{
		lcd_last->next = p;
		lcd_last = p;
	}

	lcd_last->next = NULL;
}

void led::add()
{
	string producator, format_ecran;
	int diagonala, pret, iluminare, boxe_integrate;
	cout << "\ndati producator: ";
	getline(cin, producator);
	cout << "dati diagonala: ";
	cin >> diagonala;
	cout << "dati pret: ";
	cin >> pret;
	cin.get();
	cout << "dati format ecran: ";
	getline(cin, format_ecran);
	cout << "dati iluminare: ";
	cin >> iluminare;
	cout << "boxe integrate (da = 1 / nu = 0): ";
	cin >> boxe_integrate;

	led* q = new led(producator, diagonala, pret, format_ecran, iluminare, boxe_integrate);
	q->next = led_root;
	led_root = q;
}

void lcd::display()
{
	lcd* p = lcd_root;
	while (p)
	{
		cout << "--------------------------------\n";
		cout << p->producator << endl;
		cout << "\td: " << p->diagonala << endl;
		cout << "\tp: " << p->pret << endl;
		cout << "\ttimp: " << p->timp_raspuns << endl;
		cout << "\ttip: " << p->tip_ecran << endl;
		cout << "\tc: " << p->conectori << endl;

		p = p->next;
	}
}

void led::display()
{
	led* q = led_root;
	while (q)
	{
		cout << "--------------------------------\n";
		cout << q->producator << endl;
		cout << "\td: " << q->diagonala << endl;
		cout << "\tp: " << q->pret << endl;
		cout << "\tformat: " << q->format_ecran << endl;
		cout << "\ti: " << q->iluminare << endl;
		cout << "\tboxe integrate ( 1 = da  / 0 = nu ): " << q->boxe_integrate << endl;

		q = q->next;
	}
}

//functie de stergere
void lcd::delete_m()
{
	lcd* p = lcd_root; // nodul dinaintea celui care se sterge
	lcd* the_one; // nodul care se sterge 
	string pr, te;
	int d, tr;

	//cautarea o fac doar dupa 4 variabile diferite date de la tastatura
	cout << "producator: ";
	getline(cin, pr);
	cout << "diagonala: ";
	cin >> d;
	cin.get();
	cout << "timp de raspuns: ";
	cin >> tr;
	cin.get();
	cout << "tip ecran: ";
	getline(cin, te);

	//daca nodul dorit sters este primul
	if (lcd_root->producator == pr && lcd_root->diagonala == d && lcd_root->timp_raspuns == tr && lcd_root->tip_ecran == te)
	{
		the_one = lcd_root;
		lcd_root = lcd_root->next;
		delete the_one;
	}
	else 
	{
		while (p->next->producator != pr && p->next->diagonala != d && p->next->timp_raspuns != tr && p->next->tip_ecran != te && p)
			p = p->next;

		the_one = p->next;
		p->next = the_one->next;

		if (the_one == lcd_last)
			lcd_last = p;

		delete the_one;
	}
}

void led::delete_m()
{
	led* q = led_root;
	led* the_one;
	string pr, fe;
	int d, i;

	cout << "producator: ";
	getline(cin, pr);
	cout << "diagonala: ";
	cin >> d;
	cin.get();
	cout << "format ecran: ";
	getline(cin, fe);
	cout << "iluminare: ";
	cin >> i;

	if (led_root->producator == pr && led_root->diagonala == d && led_root->format_ecran == fe && led_root->iluminare == i)
	{
		the_one = led_root;
		led_root = led_root->next;
		delete the_one;
	}
	else
	{
		while (q->next->producator != pr && q->next->diagonala != d && q->next->format_ecran != fe && q->next->iluminare != i && q)
			q = q->next;

		the_one = q->next;
		q->next = the_one->next;

		if (the_one == led_last)
			led_last = q;

		delete the_one;
	}
}

int lcd::search()
{
	string pr, te;
	int d, tr;

	//cautarea o fac doar dupa 4 variabile diferite date de la tastatura
	cout << "producator: ";
	getline(cin, pr);
	cout << "diagonala: ";
	cin >> d;
	cout << "timp de raspuns: ";
	cin >> tr;
	cin.get();
	cout << "tip ecran: ";
	getline(cin, te);

	lcd* p;
	for (p = lcd_root; p != NULL; p = p->next)
	{
		if (p->producator == pr && p->diagonala == d && p->timp_raspuns == tr && p->tip_ecran == te)
			return 1;
	}

	return 0;
}

int led::search()
{
	string pr, fe;
	int d, i;

	cout << "producator: ";
	getline(cin, pr);
	cout << "diagonala: ";
	cin >> d;
	cin.get();
	cout << "format ecran: ";
	getline(cin, fe);
	cout << "iluminare: ";
	cin >> i;

	led* q;
	for (q = led_root; q != NULL; q = q->next)
	{
		if (q->producator == pr && q->diagonala == d && q->format_ecran == fe && q->iluminare == i)
			return 1;
	}

	return 0;
}

//ordonarea monitoarelor LCD dupa pret
void lcd::order()
{
	lcd* p;
	lcd *aux = new lcd("", 0, 0, 0, "", "");
	int ord;
	do
	{
		p = lcd_root;
		ord = 1;
		while (p->next)
		{
			if (p->pret > p->next->pret)
			{
				aux->producator = p->producator;
				aux->diagonala = p->diagonala;
				aux->pret = p->pret;
				aux->timp_raspuns = p->timp_raspuns;
				aux->tip_ecran = p->tip_ecran;
				aux->conectori = p->conectori;

				p->producator = p->next->producator;
				p->diagonala = p->next->diagonala;
				p->pret = p->next->pret;
				p->timp_raspuns = p->next->timp_raspuns;
				p->tip_ecran = p->next->tip_ecran;
				p->conectori = p->next->conectori;

				p->next->producator = aux->producator;
				p->next->diagonala = aux->diagonala;
				p->next->pret = aux->pret;
				p->next->timp_raspuns = aux->timp_raspuns;
				p->next->tip_ecran = aux->tip_ecran;
				p->next->conectori = aux->conectori;

				ord = 0;
			}

			p = p->next;
		}
	} while (ord == 0);
}

//ordonarea monitoarelor LED dupa pret crescator
void led::order()
{
	led* q;
	led *aux = new led("", 0, 0, "", 0, 0);
	int ord;
	do
	{
		q = led_root;
		ord = 1;
		while (q->next != NULL)
		{
			if (q->pret > q->next->pret)
			{
				aux->producator = q->producator;
				aux->diagonala = q->diagonala;
				aux->pret = q->pret;
				aux->format_ecran = q->format_ecran;
				aux->iluminare = q->iluminare;
				aux->boxe_integrate = q->boxe_integrate;

				q->producator = q->next->producator;
				q->diagonala = q->next->diagonala;
				q->pret = q->next->pret;
				q->format_ecran = q->next->format_ecran;
				q->iluminare = q->next->iluminare;
				q->boxe_integrate = q->next->boxe_integrate;

				q->next->producator = aux->producator;
				q->next->diagonala = aux->diagonala;
				q->next->pret = aux->pret;
				q->next->format_ecran = aux->format_ecran;
				q->next->iluminare = aux->iluminare;
				q->next->boxe_integrate = aux->boxe_integrate;

				ord = 0;
			}

			q = q->next;
		}
	} while (ord == 0);
}

int main()
{
	lcd* p = new lcd("", 0, 0, 0, "", "");
	led* q = new led("", 0, 0, "", 0, 0);
	string pr;
	unsigned int opt, nr, ok = 0;


	do
	{
		cout << "\n--------------------- MENIU ---------------------" << endl;
		cout << "\t1. adaugarea unui monitor LCD/LED" << endl;
		cout << "\t2. afisarea monitoarelor LCD/LED" << endl;
		cout << "\t3. stergere monitor LCD/LED" << endl;
		cout << "\t4. cautare monitor LCD/LED" << endl;
		cout << "\t5. ordonare monitoare LCD/LED" << endl;
		cout << "\t6. iesire" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "\ndati optiune: ";
		cin >> opt;
		switch (opt)
		{
		//adauagare monitor LCD/LED
		case 1:
			cout << "ADAUGARE" << endl;
			cout << "\npentru monitoare LCD apasati 1 si pentru LED 2: ";
			cin >> nr;
			cin.get();
			switch (nr)
			{
			case 1:
				p->add();
				break;
			case 2:
				q->add();
				break;
			}
			break;
		//afisare monitoare LCD/LED
		case 2:
			cout << "AFISARE" << endl;
			cout << "\npentru monitoare LCD apasati 1 si pentru LED 2: ";
			cin >> nr;
			switch (nr)
			{
			case 1:
				p->display();
				break;
			case 2:
				q->display();
				break;
			}
			break;
		//stergere monitor LCD/LED
		case 3:
			cout << "DATELE MONITORULUI DORIT STERS: " << endl;
			cout << "\npentru monitoare LCD apasati 1 si pentru LED 2: ";
			cin >> nr;
			cin.get();
			switch (nr)
			{
			case 1:
				p->delete_m();
				break;
			case 2:
				q->delete_m();
				break;
			}
			break;
		//cautarea unui monitor LCD/LED
		case 4:
			cout << "DATELE MONITORULUI CAUTAT: " << endl;
			cout << "\npentru monitoare LCD apasati 1 si pentru LED 2: ";
			cin >> nr;
			cin.get();
			switch (nr)
			{
			case 1:
				ok = p->search();
				if (ok)
					cout << "\nMONITORUL S-A GASIT" << endl;
				else
					cout << "\nMONITORUL NU S-A GASIT" << endl;
				break;
			case 2:
				ok = q->search();
				if (ok)
					cout << "\nMONITORUL S-A GASIT" << endl;
				else
					cout << "\nMONITORUL NU S-A GASIT" << endl;
				break;
			}
			break;
		// ordonare dupa pret
		case 5:
			cout << "MONITOARELE SE VOR ORDONA CRESCATOR DUPA PRET" << endl;
			cout << "\npentru monitoare LCD apasati 1 si pentru LED 2: ";
			cin >> nr;
			switch (nr)
			{
			case 1:
				p->order();
				break;
			case 2:
				q->order();
				break;
			}
			break;
		case 6:
			break;
		default:
			cout << "\noptiune gresita" << endl;
			break;
		}
	} while (opt != 6);

	getchar();
	return 0;
}