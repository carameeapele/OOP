#include <iostream>

using namespace std;

inline int minim(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	int x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "minimul: " << minim(x, y);

	getchar();
	return 0;
}