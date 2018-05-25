#include <iostream>
using namespace std;
long long n, a[100], cl, res, lt[12];

void build()
{
	lt[0] = 1;
	for (long i = 1; i <= 11; i++) lt[i] = lt[i - 1] * 10;
	a[0] = 0;
	a[1] = 1;
	for (long i = 2; i <= 11; i++) a[i] = lt[i - 1] + 9 * a[i - 1];
}

long chuSo(long long n, long &vt)
{
	vt = 1;
	while (n != 0)
	{
		long x = n % 10;
		if (x != 0) return x;
		vt++;
		n /= 10;
	}
}

long long chenhLech(long long n)
{
	long long s = 0;
	while (n != 0)
	{
		long vt, cs;
		cs = chuSo(n, vt);
		if (cs > 4) s += lt[vt - 1] + (cs - 1) * a[vt - 1];
		else s += cs * a[vt - 1];
		n -= cs * lt[vt - 1];
	}
	return s;
}

main()
{
	build();
	while ((cin >> n) && (n != 0))
	{
		cl = chenhLech(n);
		res = n - cl;
		cout << n << ": " << res << endl;
	}
}