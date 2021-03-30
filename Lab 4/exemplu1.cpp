#include<iostream>
#include<conio.h>

using namespace std;

class A
{
private:
	int m;
public:
	//clasa B prietena a clasei A
	friend class B;
	//g_print_m ca si functie prietena cu clasa A
	friend void g_print_m();
};

class B
{
public:
	//functia de afisare
	void print_m()
	{
		A a;
		a.m = 255;
		cout << "clasa B este prietena cu clasa A" << endl;
		cout << "poate accesa membrul privat A::m" << endl << a.m << endl;
	}
};

//functia de afisare care este functie friend cu clasa A
void g_print_m()
{
	A a;
	a.m = 300;
	cout << "functia g_print_m nu este un membru al clasei A dar este prieten" << endl;
	cout << "poate accesa membrul privat A::m" << endl << a.m << endl;
}

int main()
{
	//crearea unui obiect de tipul clasei B
	B b;
	//apelarea celor doua functii de afisare
	b.print_m();
	g_print_m();

	getchar();
	return 0;
}