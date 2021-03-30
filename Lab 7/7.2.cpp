#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream f("fisier.txt");
	string linie;

	if (f.is_open())
	{
		while (getline(f, linie))
		{
			cout << linie << endl;
		}

		f.close();
	}
	else
		cout << "nu s-a deschis fisierul";

	return 0;
}