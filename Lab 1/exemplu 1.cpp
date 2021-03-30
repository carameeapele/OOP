#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int nr;
	cout << "nr intreg: ";
	cin >> nr;
	
	int s = 0, p = 1;
	while (nr != 0)
	{
		if (nr % 2 == 0)
			s = s + nr;
		else
			p = p * nr;

		cout << "nr intreg: "; cin >> nr;
	}

	cout << "suma numerelor: " << s << endl;
	cout << "produsul numerelor: " << p;

	getchar();
	return 0;
}