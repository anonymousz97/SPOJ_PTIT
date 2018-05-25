#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>

using namespace std;
long long n, m, t[100001], tMin;

long ok(long long A)
{
	long long d = 0;
	for (long i = 1;  i <= n; i++) d += A / t[i];
	if (d >= m) return 1;
	return 0;
}

long long Find()
{
	long long res;
	long long l = 1, r = tMin * m;
	long long mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (ok(mid))
		{
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return res;
}

main()
{
	scanf("%lld %lld", &n, &m);
	tMin = 1e9 + 1;
	for (long i = 1; i <= n; i++)
	{
		scanf("%lld", &t[i]);
		tMin = min(tMin, t[i]);
	}
	printf("%lld", Find());
}