#include <iostream>
using namespace std;
long t, n;

long res(long n)
{
	if (n < 3) return (n * n);
	if (n % 2 == 0)	return (n * n / 2);
	return (n * n / 2 + 1);
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> n;
		cout << res(n) << endl;
	}
}