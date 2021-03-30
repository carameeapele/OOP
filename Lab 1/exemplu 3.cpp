#include <iostream>
using namespace std;

int suma(int a, int b)
{
	return a + b;
}

float suma(float a, float b)
{
	return a + b;
}

int main()
{
	int a, b;
	cout << "intreg a = ";
	cin >> a;
	cout << "intreg b = ";
	cin >> b;
	cout << "suma a si b: " << suma(a, b) << endl;

	float x, y;
	cout << "real x = ";
	cin >> x;
	cout << "real y = ";
	cin >> y;
	cout << "suma x si y: " << suma(x, y);

	getchar();
	return 0;
}