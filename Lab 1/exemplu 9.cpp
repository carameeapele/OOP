#include <iostream>

using namespace std;

class exemplu
{
	int x, y;
public:
	void initializare(int, int);
	void afisare();
};

inline void exemplu::initializare(int a, int b)
{
	x = a;
	y = b;
}

inline void exemplu::afisare()
{
	cout << "x = " << x << endl;
	cout << "y = " << y;
}

int main()
{
	exemplu ex;
	int var1, var2;
	cout << "prima valoare: ";
	cin >> var1;
	cout << "a doua valoare: ";
	cin >> var2;

	ex.initializare(var1, var2);
	ex.afisare();

	getchar();
	return 0;
}