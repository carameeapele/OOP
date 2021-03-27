#include <iostream>
#include <cstring>

using namespace std;

class student
{
	string nume;
	string prenume;
	unsigned int varsta;
	int nr_matricol;
public:
	//constructor
	student(string n, string p, unsigned int v, int nr)
	{
		nume = n;
		prenume = p;
		varsta = v;
		nr_matricol = nr;
	}

	//functia pentru supraincarcarea operatorului de iesire
	friend ostream& operator<<(ostream& iesire, student st);
};

//afisarea datelor
ostream& operator<<(ostream& iesire, student st)
{
	iesire << st.nume << " " << st.prenume;
	iesire << " are " << st.varsta << " ani";
	iesire << " numar matricol " << st.nr_matricol << "\n";
	return iesire;
}

int main()
{
	//crearea a 2 obiecte de tip student
	student a("Popescu", "Ioana", 19, 2345);
	student b("Lupse", "Oana", 21, 1359);

	//apelarea functiei supraincarcate
	cout << a << b;
	
	getchar();
	return 0;
}