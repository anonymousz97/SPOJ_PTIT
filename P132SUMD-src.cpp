#include <iostream>
using namespace std;
long a, b, c;
int main()
{
	cin >> a >> b >> c;
	if (a == b + c )
	{
		cout << a << "=" << b << "+" << c;
		return 0;
	}
	if (a == b - c)
	{
		cout << a << "=" << b << "-" << c;
		return 0;
	}
	if (a == b * c)
	{
		cout << a << "=" << b << "*" << c;
		return 0;
	}
	if (a == (float) (b / c))
	{
		cout << a << "=" << b << "/" << c;
		return 0;
	}
	if (a + b == c)
	{
		cout << a << "+" << b << "=" << c;
		return 0;
	}
	if (a - b == c)
	{
		cout << a << "-" << b << "=" << c;
		return 0;
	}
	if (a * b == c)
	{
		cout << a << "*" << b << "=" << c;
		return 0;
	}
	if ((float) (a / b) == c)
	{
		cout << a << "/" << b << "=" << c;
		return 0;
	}
}