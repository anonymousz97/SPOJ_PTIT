#include <iostream>
#include <math.h>
using namespace std;
long n, x[4], k1[4], k2[4], res = 0;

long cl(long x, long y)
{
	if ((x == n) && (y == 2)) return 1;
	if ((x == n) && (y == 1)) return 1;
	if ((x == 2) && (y == n)) return 1;
	if ((x == 1) && (y == n)) return 1;
	if ((x == n - 1) && (y == 1)) return 1;
	if ((x == 1) && (y == n - 1)) return 1;
	
	if (fabs(x - y) <= 2) return 1;
	return 0;	
}

long check(long x[], long k[])
{
	for (long i = 1; i < 4; i++)
	  if (!cl(x[i], k[i])) return 0;
	 return 1;	
}

main()
{
	cin >> n;
	for (long i = 1; i < 4; i++) cin >> k1[i];
	for (long i = 1; i < 4; i++) cin >> k2[i];
	
	for (long i = 1; i <= n; i++)
	{
		x[1] = i;
		for (long j = 1; j <= n; j++)
		{
			x[2] = j;
			for (long k = 1; k <= n; k++)
			{
				x[3] = k;
				if (check(x, k1) || (check(x, k2))) res++;
			}
		}
	}
	cout << res;
}