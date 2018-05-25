#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

long long t, n, m, a[1000001], b[1000001];

long Find(long k)
{
	long l = k + 1, r = n;
	long res = 0;
	long mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (!b[mid]) r = mid - 1;
		else
		{
			if (a[k] + m <= a[mid]) res = mid;
			l = mid + 1;
		}
	}
	return res;
}

long long ketQua()
{
	long long s = 0;
	sort(a + 1, a + 1 + n);
	for (long i = 1; i <= n; i++)	
	{
		s += a[i];
		b[i] = 1;
	}
	for (long i = n; i > 0; i--)
	{
		long x = Find(i);
		if (x)
		{
			s -= a[i];
			b[x] = 0; 
		}
	}
	return s;
}

main()
{
	cin >> t;
	while (t--)
	{
		scanf("%lld %lld", &n, &m);
		for (long i = 1; i <= n; i++) scanf("%lld", &a[i]);
		printf("%lld\n",ketQua());
	}
}