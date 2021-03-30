#include<iostream>
#include<conio.h>

using namespace std;

class dreptunghi
{
	int* latime, * lungime;
public:
	//declarare constructor
	dreptunghi(int, int);
	//declarare destructor
	~dreptunghi();
	
	int calcul_arie(void)
	{
		return (*latime * *lungime);
	}
};

//constructor
dreptunghi::dreptunghi(int a, int b)
{
	//alocare memorie pentru cele doua variabile
	latime = new int;
	lungime = new int;
	*latime = a;
	*lungime = b;
}

//destructor
dreptunghi::~dreptunghi()
{
	//eliberare memorie
	delete latime;
	delete lungime;
	printf("\nam eliberat memoria");
}

int main()
{
	//apelare constructor pentru anumite valori
	dreptunghi dreptA(3, 4), dreptB(5, 6);
	cout << "aria primului dreptunghi: " << dreptA.calcul_arie() << endl;
	cout << "aria celui de-al doilea dreptunghi: " << dreptB.calcul_arie() << endl;

	//apelare destructor
	dreptA.~dreptunghi();
	dreptB.~dreptunghi();

	getchar();
	return 0;
}