#include <iostream>
using namespace std;
long n, m, x, y;
main()
{
	cin >> n >> m;
	x = m; y = n;
	while (y != 0)
	{
	  long t = x % y;
	  x = y;
	  y = t;
	}
	long uc = x;
	cout << (m - uc);
}