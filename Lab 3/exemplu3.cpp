#include<iostream>
using namespace std;

//clasa de baza
class forma
{
protected:
	int latime;
	int lungime;
public:
	//constructorul clasei de baza
	forma(int w, int l)
	{
		latime = w;
		lungime = l;
	}
};

//class derivata
class dreptunghi : public forma
{
public:
	//constructorul clasei derivate
	dreptunghi(int w, int l) :forma(w, l) {};
	
	//functia calcului ariei
	int get_aria()
	{
		return (lungime * latime);
	}
};

//clasa derivata
class paralelipiped :public dreptunghi
{
	int inaltime;
public:
public:
	//constructorul clasei derivate
	paralelipiped(int w, int l, int h) :dreptunghi(w, l)
	{
		inaltime = h;
	};

	//functia de calculare a volumului
	int get_volum()
	{
		return (lungime * latime * inaltime);
	}
};

int main()
{
	//crearea unui obiect
	dreptunghi rect(5, 7);
	//afisarea ariei obiectului
	cout << "aria totala dreptunghi: " << rect.get_aria() << endl;
	paralelipiped par(2, 3, 4);
	cout << "aria totala paralelipiped: " << par.get_aria() << endl;
	cout << "volumul total paralelipiped: " << par.get_volum() << endl;

	return 0;
}