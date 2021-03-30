#include <iostream>
using namespace std;

typedef struct
{
	char marca[20];
	char model[30];
	float consum, pret;
}masina;

int main()
{
	masina* ma;
	ma = new masina;
	cout << "marca: ";
	cin >> ma->marca;
	cout << "model: ";
	cin >> ma->model;
	cout << "consum: ";
	cin >> ma->consum;
	cout << "pret: ";
	cin >> ma->pret;

	cout << "marca " << ma->marca << "; model " << ma->model << "; consum " << ma->consum << "; pret " << ma->pret;

	delete ma;
	getchar();
	return 0;
}