#include <iostream>
#include <string>

using namespace std;

class carte
{
	string titlu;
	string autor;
	string editura;
	unsigned int an_publicare;
public:
	//definire constructor
	carte(string t, string a, string e, int an);

	//functia de afisare
	void afisare()
	{
		cout << "\n" << titlu;
		cout << "\n\t" << autor;
		cout << "\n\t" << editura;
		cout << "\n\t" << an_publicare;
	}
};

//constructor
carte::carte(string t, string a, string e, int an)
{
	titlu = t;
	autor = a;
	editura = e;
	an_publicare = an;
}

int main()
{
	string aux_t;
	string aux_a;
	string aux_e;
	int aux_an;
	int n;

	cout << "numarul de carti: "; cin >> n;
	while (n)
	{
		cout << "\ntitlu: "; cin >> aux_t;
		cout << "autor: "; cin >> aux_a;
		cout << "editura: "; cin >> aux_e;
		cout << "an publicare: "; cin >> aux_an;

		carte c(aux_t, aux_a, aux_e, aux_an);
		c.afisare();
		n--;
	}
}