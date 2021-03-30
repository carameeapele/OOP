#include <iostream>

using namespace std;

class dreptunghi
{
	int lungime, latime;
public:
	void setare_valori(int, int);
	int aria(void);
};

void dreptunghi::setare_valori(int a, int b)
{
	lungime = a;
	latime = b;
}

int dreptunghi::aria(void)
{
	return (lungime * latime);
}

int main()
{
	dreptunghi drept;
	drept.setare_valori(3, 8);
	cout << "aria: " << drept.aria();

	getchar();
	return 0;
}