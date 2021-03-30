#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream f;
	f.open("Fisier1.txt");

	if (f.is_open())
	{
		f << "prima linie\n";
		f.close();
	}
	else
	{
		cout << "nu s-a deschis fisierul";
	}

	return 0;
}