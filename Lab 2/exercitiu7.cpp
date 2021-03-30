#include <iostream>
#include <string>

using namespace std;

class profesor
{
	string nume;
	string departament;
	string grad_didactic;
	int vechime;
public:
	//definire constructor
	profesor(string n, string d, string g, int v);

	//functia de afisare
	void afisare()
	{
		cout << "\n" << nume;
		cout << "\n\t" << departament;
		cout << "\n\t" << grad_didactic;
		cout << "\n\tvechime: " << vechime;
	}
};

//constructor
profesor::profesor(string n, string d, string g, int v)
{
	nume = n;
	departament = d;
	grad_didactic = g;
	vechime = v;
}

int main()
{
	string aux_n;
	string aux_d;
	string aux_g;
	int aux_v;
	int n;

	cout << "numarul de profesori: "; cin >> n;
	while (n)
	{
		cout << "\nnume: "; cin >> aux_n;
		cout << "departament: "; cin >> aux_d;
		cout << "grad didactic: "; cin >> aux_g;
		cout << "vechime: "; cin >> aux_v;
		profesor p(aux_n, aux_d, aux_g, aux_v);
		p.afisare();
		n--;
	}
}