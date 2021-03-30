#include<iostream>
#include<string>

using namespace std;

class persoana
{
	string nume, prenume;
	unsigned int varsta;
public:
	persoana(){}
	persoana(string nume, string prenume, unsigned int varsta)
	{
		persoana::nume = nume;
		persoana::prenume = prenume;
		persoana::varsta = varsta;
	}

	void afisare()
	{
		cout << ".............................." << endl;
		cout << "nume: " << persoana::nume << endl;
		cout << "prenume: " << persoana::prenume << endl;
		cout << "varsta: " << persoana::varsta << endl;
	}

	string returnare_nume()
	{
		return persoana::nume;
	}

	string returnare_prenume()
	{
		return persoana::prenume;
	}
};

class student :public persoana
{
	unsigned int grupa;
public:
	student(){}
	student(string nume, string prenume, unsigned int varsta, 
		unsigned int grupa) :persoana(nume, prenume, varsta)
	{
		student::grupa = grupa;
	}

	void afisare()
	{
		persoana::afisare();
		cout << "grupa: " << student::grupa << endl;
	}
};

class student_licenta : public student
{
	unsigned int an;
public:
	student_licenta(){}
	student_licenta(string nume, string prenume, unsigned int varsta,
		unsigned int grupa, unsigned int an) :student(nume, prenume, varsta, grupa)
	{
		student_licenta::an = an;
	}

	void afisare()
	{
		student::afisare();
		cout << "an: " << student_licenta::an << endl;
	}
};

class masterand : public student
{
	string specializare;
public:
	masterand(){}
	masterand(string nume, string prenume, unsigned int varsta,
		unsigned int grupa, string specializare) : student(nume, prenume, varsta, grupa)
	{
		masterand::specializare = specializare;
	}

	void afisare()
	{
		student::afisare();
		cout << "specializare: " << masterand::specializare << endl;
	}
};

class doctorand :public student
{
	string domeniu;
public:
	doctorand(){}
	doctorand(string nume, string prenume, unsigned int varsta,
		unsigned int grupa, string domeniu) :student(nume, prenume, varsta, grupa)
	{
		doctorand::domeniu = domeniu;
	}

	void aisare()
	{
		student::afisare();
		cout << "domeniu: " << doctorand::domeniu << endl;
	}
};

class angajat :public persoana
{
	unsigned int salar;
public:
	angajat(){}
	angajat(string nume, string prenume, unsigned int varsta,
		unsigned int salar) :persoana(nume, prenume, varsta)
	{
		angajat::salar = salar;
	}

	void afisare()
	{
		persoana::afisare();
		cout << "salar: " << angajat::salar << endl;
	}
};

class profesor :public angajat
{
	unsigned int an_vechime;
public:
	profesor(){}
	profesor(string nume, string prenume, unsigned int varsta,
		unsigned int salar, unsigned int an_vechime) :angajat(nume, prenume, varsta, salar)
	{
		profesor::an_vechime = an_vechime;
	}

	void afisare()
	{
		angajat::afisare();
		cout << "an vechime: " << profesor::an_vechime << endl;
	}
};

class inginer :public angajat
{
	string domeniu;
public:
	inginer(){}
	inginer(string nume, string prenume, unsigned int varsta,
		unsigned int salar, string domeniu) :angajat(nume, prenume, varsta, salar)
	{
		inginer::domeniu = domeniu;
	}

	void afisare()
	{
		angajat::afisare();
		cout << "domeniu: " << inginer::domeniu << endl;
	}
};


int main()
{
	string num, pren;
	string n, p, s, d;
	int v, g, a, sal, ani;
	int opt, nr_s, nr_a, tip;
	int ok1 = 0, ok2 = 0;
	student studenti[20];
	angajat angajati[20];

	cout << "1. introducere studenti" << endl;
	cout << "2. introducere angajati" << endl;
	cout << "3. afisare studenti" << endl;
	cout << "4. afisare angajati" << endl;
	cout << "5. cautare dupa nume" << endl;
	cout << "6. stergere dupa prenume" << endl;
	cout << "0. iesire" << endl;

	do
	{
		cout << "\ndati optiunea: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			//citirea studentilor
			cout << "dati numarul de studenti: ";
			cin >> nr_s;
			for (int i = 0; i < nr_s; i++)
			{
				cin.get();
				cout << "numele: "; getline(cin, n);
				cout << "prenumele: "; getline(cin, p);
				cout << "varsta: "; cin >> v; cin.get();
				cout << "grupa: "; cin >> g; cin.get();
				cout << "pentru student licenta apasati 1, pentru masterand 2 si pentru doctorand 3: "; 
				cin >> tip; cin.get();

				switch (tip)
				{
				case 1:
					cout << "an: "; 
					cin >> a;
					studenti[i] = student_licenta(n, p, v, g, a);
					break;
				case 2:
					cout << "specializare: ";
					getline(cin, s);
					studenti[i] = masterand(n, p, v, g, s);
					break;
				case 3:
					cout << "domeniu: ";
					getline(cin, d);
					studenti[i] = doctorand(n, p, v, g, d);
					break;
				default:
					cout << "optiune gresita";
					break;
				}
			}
			break;

		case 2:
			//citirea angajatilor
			cout << "dati numarul de angajati: ";
			cin >> nr_a;
			for (int i = 0; i < nr_a; i++)
			{
				cin.get();
				cout << "numele: "; getline(cin, n);
				cout << "prenumele: "; getline(cin, p);
				cout << "varsta: "; cin >> v; cin.get();
				cout << "salar: "; cin >> sal; cin.get();
				cout << "pentru profesor apasati 1 si pentru inginer 2: ";
				cin >> tip; cin.get();

				switch (tip)
				{
				case 1:
					cout << "ani vechime: ";
					cin >> ani;
					angajati[i] = profesor(n, p, v, sal, ani);
					break;
				case 2:
					cout << "domeniu: ";
					getline(cin, d);
					angajati[i] = inginer(n, p, v, sal, d);
					break;
				default:
					cout << "optiune gresita";
					break;
				}
			}
			break;

		case 3:
			//afisarea studentilor
			for (int i = 0; i < nr_s; i++)
				studenti[i].afisare();
			break;
		case 4:
			//afisare angajati
			for (int i = 0; i < nr_a; i++)
				angajati[i].afisare();
			break;
		case 5:
			//cautare dupa nume
			cin.get();
			cout << "dati numele cautat: ";
			getline(cin, num);

			for (int i = 0; i < nr_s; i++)
				if (num.compare(studenti[i].returnare_nume()) == 0)
				{
					cout << "\nam gasit studentul" << endl;
					ok1 = 1;
					break;
				}

			for(int i = 0; i < nr_a; i++)
				if (num.compare(angajati[i].returnare_nume()) == 0)
				{
					cout << "\nam gasit angajatul" << endl;
					ok1 = 1;
					break;
				}

			if (ok1 == 0)
				cout << "\nnu s-a gasit persoana" << endl;
			break;
		case 6:
			//stergere dupa prenume
			cin.get();
			cout << "\ndati prenumele care doriti sa il stergeti: ";
			getline(cin, pren);

			for(int i = 0; i < nr_s; i++)
				if (pren.compare(studenti[i].returnare_prenume()) == 0)
				{
					for (int j = i; j < nr_s; j++)
						studenti[j] = studenti[j + 1];
					nr_s--;
					ok2 = 1;
					cout << "\ndatele studentului au fost sterse" << endl;
					break;
				}

			for(int i = 0; i < nr_a; i++)
				if (pren.compare(angajati[i].returnare_prenume()) == 0)
				{
					for (int j = i; j < nr_a; j++)
						angajati[j] = angajati[j + 1];
					nr_a--;
					ok2 = 1;
					cout << "\ndatele angajatului au fost sterse" << endl;
					break;
				}

			if (ok2 == 0)
				cout << "\nnu a fost gasita persoana" << endl;
			break;
		case 0:
			break;
		default:
			cout << "\noptiune gresita";
			break;
		}
	} while (opt != 0);

	return 0;
}