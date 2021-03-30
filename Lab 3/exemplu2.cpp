#include<iostream>
using namespace std;

//clasa de baza
class forma
{
public:
	//functie setare latime
	void set_latime(int w)
	{
		latime = w;
	}
	//functie setare inaltime
	void set_inaltime(int h)
	{
		inaltime = h;
	}
protected:
	int latime;
	int inaltime;
};

//class derivata
class dreptunghi :public forma
{
public:
	//functie de calculat aria
	int get_aria()
	{
		return (latime * inaltime);
	}
};

int main()
{
	//crearea unui obiect
	dreptunghi rect;
	rect.set_latime(5);
	rect.set_inaltime(7);

	//afisarea ariei obiectului
	cout << "aria totala: " << rect.get_aria() << endl;

	return 0;
}