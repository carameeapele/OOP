#include <iostream>

using namespace std;

//creare clasa template
template<class tipVector>class vector
{
	tipVector v[20]; //elementele vectorului
	int index; //indexul elementelor vectorului
public:
	//initializare vector
	vector()
	{
		index = 0;
	}

	void introducere(tipVector ob); //introducere obiect in vector
	void afisare(); //afisare obiect din vector
};

template<class tipVector>void vector<tipVector>::introducere(tipVector ob)
{
	v[index] = ob;
	index++;
}

template<class tipVector>void vector<tipVector>::afisare()
{
	if (index == 0)
	{
		cout << "vectorul este gol\n";
		return;
	}

	for (int i = 0; i < index; i++)
		cout << v[i] << " ";
}

int main()
{
	//creare vectori de caractere
	vector<char>v1, v2;

	v1.introducere('a');
	v2.introducere('@');
	
	v1.introducere('b');
	v2.introducere('*');

	v1.introducere('c');
	v2.introducere('&');

	//afisare vectori
	cout << "vectori cu elemente de tip char: ";
	v1.afisare();
	cout << "\n";
	
	v2.afisare();
	cout << "\n";

	//creare vectori de intregi
	vector<double>x1, x2;

	x1.introducere(1);
	x2.introducere(20);

	x1.introducere(3);
	x2.introducere(40);

	x1.introducere(5);
	x2.introducere(60);

	//afisarevectori
	cout << "vectori cu elemente de tip int: \n";

	x1.afisare();
	cout << "\n";

	x2.afisare();
	cout << "\n";

	getchar();
	return 0;
}