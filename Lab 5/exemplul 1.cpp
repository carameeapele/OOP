#include <iostream>
#include <conio.h>

using namespace std;

class Forma
{
public:
	virtual void afisare()
	{
		cout << "forma->clasa de baza" << endl;
	}
};

class Punct:public Forma
{
public:
	void afisare()
	{
		cout << "punct->clasa derivata punct" << endl;
	}
};

int main()
{
	cout << "functii apelate prin pointer la forma: " << endl;

	Forma* ptrForma = new Forma();
	ptrForma->afisare();

	cout << "\nfunctii apelate prin pointer la forma initializata prin pointer la punct: " << endl;
	Punct* ptrPunct = new Punct();
	ptrForma = ptrPunct;
	cout << "comportament polimorfic: ";
	ptrForma->afisare();

	cout << "\nfunctii apelate prin obiecte de tip forma: " << endl;
	Forma forma;
	forma.afisare();

	cout << "\nfunctii apelate prin obiect de tip Punct: " << endl;
	Punct punct;
	punct.afisare();

	getchar();
	return 0;
}