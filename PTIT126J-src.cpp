#include <iostream>
using namespace std;
long long n, m, a[1000001];
long long hmin, hmax;

long ok(long h)
{
	long long d = 0;
	for (long i = 1; i <= n; i++)
	  if (a[i] > h) d += (a[i] - h);
	  
	return (d >= m);
}

long findH()
{
	long long res;
	long long l = 0, r = hmax;
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		if (ok(mid))
		{
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return res;
}
main()
{
	cin >> n >> m;
	for (long i = 1; i <= n; i++) cin >> a[i];
	hmin = a[1];
	hmax = a[1];
	for (long i = 2; i <= n; i++)
	{
		if (a[i] > hmax) hmax = a[i];
		if (a[i] < hmin) hmin = a[i];
	}
	cout << findH();
}