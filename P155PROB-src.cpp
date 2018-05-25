#include <iostream>
using namespace std;
int a, x, s;
main()
{
	cin >> x >> s;
	x *= s;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		cout << (a - x) << " ";
	}
}
