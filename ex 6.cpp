#include <iostream>

using namespace std;

class dreptunghi
{
	int latime, lungime;
public:
	dreptunghi();
	dreptunghi(int, int);
	int aria(void)
	{
		return (latime * lungime);
	}
};

dreptunghi::dreptunghi()
{
	latime = 5;
	lungime = 5;
}

dreptunghi::dreptunghi(int a, int b)
{
	latime = a;
	lungime = b;
}

int main()
{
	dreptunghi drept(3, 4);
	dreptunghi dreptB;

	cout << drept.aria() << endl;
	cout << dreptB.aria() << endl;

	getchar();
	return 0;
}