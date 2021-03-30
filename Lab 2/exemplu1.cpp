#include<iostream>
#include<conio.h>
using namespace std;

class dreptunghi
{
	int latime, lungime;
public:
	//constructor
	dreptunghi(int, int);
	int calcul_arie(void)
	{
		return (latime * lungime);
	}
};

//constructor
dreptunghi::dreptunghi(int a, int b)
{
	latime = a;
	lungime = b;
}

int main()
{
	//apelare constructor
	dreptunghi dreptA(3, 4);
	//apelare constructor
	dreptunghi dreptB(5, 6);
	cout << "\naria primului dreptunghi: " << dreptA.calcul_arie() << endl;
	cout << "\naria celui de-al doilea dreptunghi: " << dreptB.calcul_arie() << endl;

	getchar();
	return 0;
}