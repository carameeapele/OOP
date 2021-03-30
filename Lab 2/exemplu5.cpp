#include <iostream>

using namespace std;

class dreptunghi
{
	int latime, lungime;
public:
	void setari_valori(int, int);
	int aria(void)
	{
		return (latime * lungime);
	}
};

void dreptunghi::setari_valori(int a, int b)
{
	latime = a;
	lungime = b;
}

int main()
{
	dreptunghi a, * b, * c;
	dreptunghi* d = new dreptunghi[2];

	a.setari_valori(1, 2);
	c = &a;
	b = new dreptunghi;
	b->setari_valori(3, 4);
	d->setari_valori(5, 6);
	d[1].setari_valori(7, 8);

	cout << a.aria() << endl;
	cout << b->aria() << endl;
	cout << c->aria() << endl;
	cout << d[0].aria() << endl;
	cout << d[1].aria() << endl;

	getchar();
	return 0;
}