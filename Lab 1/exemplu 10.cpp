#include <iostream>

using namespace std;

class exemplu
{
	int x, y;
public:
	void initiaizare(int a, int b)
	{
		x = a;
		y = b;
	}

	void afisare()
	{
		cout << "x = " << x << endl;
		cout << "y = " << y;
	}
};

int main()
{
	exemplu ex;
	int var1, var2;
	cout << "prima valoare: ";
	cin >> var1;
	cout << "a doua valoare: ";
	cin >> var2;

	ex.initiaizare(var1, var2);
	ex.afisare();

	getchar();
	return 0;
}