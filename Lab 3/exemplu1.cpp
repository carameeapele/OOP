#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

//clasa de baza
class carte
{
	char titlu[64];
public:
	//constructorul clasei de baza
	carte(char* titlu)
	{
		strcpy(carte::titlu, titlu);
	}
	void afisare_carte()
	{
		cout << "titlul: " << titlu << endl;
	}
protected:
	float cost;
	void afisare_cost()
	{
		cout << "cost: " << cost << endl;
	}
};

//class derivata
class fisa_biblioteca :public carte
{
	char autor[64], editura[64];
public:
	//constructorul clasei derivate
	fisa_biblioteca(char* titlu, char* autor, char* editura):carte(titlu)
	{
		//initializarea variabilelor
		strcpy(fisa_biblioteca::autor, autor);
		strcpy(fisa_biblioteca::editura, editura);
		cost = 49.98;
	}
	void afisare_biblioteca()
	{
		afisare_carte();
		afisare_cost();
		cout << "autor: " << autor << "editura: " << editura << endl;
	}
};

void main()
{
	//crearea unui obiect
	fisa_biblioteca fisa("Programare Orientat pe Obiecte", "Vasile Stoicu-Tivadar", "Politehnica");

	//afisarea obiectului
	fisa.afisare_biblioteca();

	getchar();
}