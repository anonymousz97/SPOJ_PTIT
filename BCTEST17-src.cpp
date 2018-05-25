#include <iostream>
using namespace std;
long test, n, g;
long doc[30001], ngang[30001], phu[60001], chinham[30001], chinhduong[30001];
long res;
main()
{
	cin >> test;
	for (long q = 1; q <= test; q++)
	{
		cin >> n >> g;
		for (long i = 1; i <= n; i++)
		{
			doc[i] = 0;
			ngang[i] = 0;
		}
		for (long i = 0; i <= 2 * n; i++) phu[i] = 0;
		for (long i = 0; i <= n; i++)
		{
			chinhduong[i] = 0;
			chinham[i] = 0;
		}
		for (long i = 1; i <= g; i++)
		{
			long k, x, y, s, t;
			cin >> k >> x >> y >> s >> t;
			long u, v;
			for (long j = 0; j < k; j++)
			{
				u = x + j * s;
				v = y + j * t;
				doc[v]++;
				ngang[u]++;
				phu[u + v]++;
				long m = u - v;
				if (m >= 0) chinhduong[m]++; else chinham[-m]++;
			}
		} 
		res = 0;
		for (long i = 1; i <= n; i++)
		{
			if (ngang[i] > 1) res += ngang[i] - 1;
			if (doc[i] > 1) res += doc[i] - 1;
		}
		for (long i = 2; i <= 2 * n; i++)
		  if (phu[i] > 1) res += phu[i] - 1;
		for (long i = 0; i <= n; i++)
		{
			if (chinham[i] > 1) res += chinham[i] - 1;
			if (chinhduong[i] > 1) res += chinhduong[i] - 1;
		}
		cout << res << endl;
	}
}