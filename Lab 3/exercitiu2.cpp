#include<iostream>
#include<string>

using namespace std;

class mamifer
{
	unsigned int varsta;
public:
	mamifer(){}
	mamifer(unsigned int varsta)
	{
		mamifer::varsta = varsta;
	}
	void afisare()
	{
		cout << "\nCLASA MAMIFER................." << endl;
		cout << "\tvarsta: " << mamifer::varsta << endl;
	}
};

class cangur :public mamifer
{
	float greutate;
public:
	cangur(){}
	cangur(unsigned int varsta, float greutate) :mamifer(varsta)
	{
		cangur::greutate = greutate;
	}
	void afisare()
	{
		mamifer::afisare();
		cout << "clasa cangur................." << endl;
		cout << "\tgreutate: " << cangur::greutate << endl;
	}
};

class urs :public mamifer
{
	string specie;
	unsigned int pui;
public:
	urs(){}
	urs(unsigned int varsta, string specie, unsigned int pui) :mamifer(varsta)
	{
		urs::specie = specie;
		urs::pui = pui;
	}
	void afisare()
	{
		mamifer::afisare();
		cout << "clasa urs...................." << endl;
		cout << "\tsecie: " << urs::specie << endl;
		cout << "\tnr pui: " << urs::pui << endl;
	}
};

int main()
{
	int v, p, opt, nr_c, nr_u;
	string s;
	float g;

	cangur canguri[20];
	urs ursi[20];
	do
	{
		cout << "......................................" << endl;
		cout << "1. introducere canguri" << endl;
		cout << "2. introducere ursi" << endl;
		cout << "3. afisare canguri" << endl;
		cout << "4. afisare ursi" << endl;
		cout << "0. iesire" << endl;
		cout << "......................................" << endl;
		cout << "\ndati optiunea: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			//introducere canguri 

			cout << "dati numarul de canguri: ";
			cin >> nr_c;

			for (int i = 0; i < nr_c; i++)
			{
				cin.get();
				cout << "\nvarsta: ";
				cin >> v;
				cout << "greutate: ";
				cin >> g;

				canguri[i] = cangur(v, g);
			}
			break;
		case 2:
			//introducere ursi

			cout << "dati numarul de ursi: ";
			cin >> nr_u;

			for (int i = 0; i < nr_u; i++)
			{
				cin.get();
				cout << "\nspecia: ";
				getline(cin, s);
				cout << "varsta: ";
				cin >> v;
				cout << "numarul de pui: ";
				cin >> p;

				ursi[i] = urs(v, s, p);
			}
			break;
		case 3:
			//afisare canguri

			for (int i = 0; i < nr_c; i++)
				canguri[i].afisare();
			break;
		case 4:
			//afisare ursi

			for (int i = 0; i < nr_u; i++)
				ursi[i].afisare();
			break;
		case 0:
			break;
		default:
			cout << "optiune gresita!" << endl;
			break;
		}
	} while (opt != 0);

	return 0;
}