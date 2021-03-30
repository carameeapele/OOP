#include<iostream>
using namespace std;

typedef struct
{
	int numar;
	string strada;
}adresa;

class sofer
{
	string nume;
	string cnp;
	unsigned int varsta;
	adresa adr;
public:
	void initializare();
	void afisare();
};

inline void sofer::initializare()
{
	cout << "nume: ";
	cin >> nume;
	cout << "cnp: ";
	cin >> cnp;
	cout << "varsta: ";
	cin >> varsta;
	cout << "adresa: ";
	cin >> adr.strada;
	cin >> adr.numar;

}

inline void sofer::afisare()
{
	cout << nume << "\n\tCNP " << cnp << "\n\t" << varsta <<" ani\n\tstr. " << adr.strada << " nr. " << adr.numar << endl;
}

class masina
{
	string producator;
	string model;
	int an;
	sofer s;
public:
	void initializare();
	void afisare();
};

inline void masina::initializare()
{
	cout << "producator: ";
	cin >> producator;
	cout << "model :";
	cin >> model;
	cout << "an: ";
	cin >> an;
	s.initializare();
}

inline void masina::afisare()
{
	cout << "\n" <<producator << "\n\tmodel " << model << "\n\tfabricat in " << an << endl;
	s.afisare();
}

int main()
{
	masina m;
	m.initializare();
	m.afisare();

	getchar();
	return 0;
}