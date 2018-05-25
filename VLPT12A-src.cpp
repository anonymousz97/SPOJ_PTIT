#include <iostream>
#include <math.h>
using namespace std;
long long t, m, n, a[101][101];

long long kc(long u, long v, long s, long t)
{
	return (fabs(u - s) + fabs(v - t));	
}

long long tinh(long x, long y)
{
	long long s = 0;
	for (long i = 1; i <= n; i++)
	  for (long j = 1; j <= n; j++) s += a[i][j] * kc(x, y, i, j);
	return s;
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> m >> n;
		for (long i = 1; i <= m; i++)
		  for (long j = 1; j <= n; j++) cin >> a[i][j];
		long long res = 200000000000;
		for (long i = 1; i <= m; i++)
		  for (long j = 1; j <= n; j++)
		    {
		    	long long d = tinh(i, j);
		    	if (d < res) res = d;
			}
		cout << res << endl;
	}
}
