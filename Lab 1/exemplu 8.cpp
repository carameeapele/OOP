#include <iostream>

using namespace std;

int main()
{
	int x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;

	cout << "minimul este: " << (x < y ? x : y);
	getchar();
	return 0;
}