#include <iostream>
#include <conio.h>

using namespace std;

class baza
{
	int pret;
public:
	int static suma;
	int static contor;
	
	//constructor
	baza(int p)
	{
		pret = p;
	}

	//functia virtuala care afiseaza contorul si pretul
	virtual void afisare()
	{
		contor++;
		cout << "valoare setata pentru clasa de baza: " << pret << " iar valoarea contorului este: " << contor << endl;
	}

	//functia care calculeaza suma
	void static inc(baza* b)
	{
		suma = suma + b->pret;
	}
};

//initializarea membrilor statici
int baza::suma = 0;
int baza::contor = 0;

int main()
{
	//crearea unor obiecte de tip clasa si afisarea valorilor
	baza* pA1 = new baza(5);
	pA1->afisare();
	baza* pA2 = new baza(7);
	pA2->afisare();
	baza* pA3 = new baza(7);
	pA3->afisare();

	cout << "valoarea sumei este: " << baza::suma << endl;
	getchar();
	return 0;
}