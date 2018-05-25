#include <iostream>
#include <math.h>
using namespace std;
long n, m;
long a, b, x;

long uc(long a, long b)
{
	if (b == 0) return a;
	return (uc(b, a % b));
}
main()
{
	cin >> m >> n;
	cin >> a;
	for (long i = 1; i <= m; i++) cin >> x;
	cin >> b;
	for (long i = 1; i <= n; i++) cin >> x;
	if (m < n) cout << "0/1";
	else
	if (m > n)
	{
		if (a * b > 0) cout << "Infinity";
		else cout << "-Infinity";
	}
	else
	{
		long dau = a * b;
		a = fabs(a);
		b = fabs(b);
		long k = uc(a, b);
		if (dau < 0) cout << "-";
		cout << a / k << "/" << b / k;
	}
}