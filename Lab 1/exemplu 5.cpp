#include <iostream>

using namespace std;

int negativ(int& i)
{
	return -i;
}

int main()
{
	int valoare;
	cout << "dati valoare: ";
	cin >> valoare;
	cout << "valoarea negativa: " << negativ(valoare);

	getchar();
	return 0;
}