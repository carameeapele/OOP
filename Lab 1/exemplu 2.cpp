#include <iostream>
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

		cout << "nr intreg: ";
		cin >> nr;
	}

	cout << "suma nr pare: " << s << endl;
	cout << "produsul nr imapre: " << p;

	getchar();
	return 0;
}