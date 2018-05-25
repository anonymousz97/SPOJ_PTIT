#include <iostream>
#include <math.h>
using namespace std;
long m, n;
double a[1001][21], d[21];
long dau[21], ires;

long lonHon(long i, long ires)
{
	if (dau[i] > dau[ires]) return 1;
	if (dau[ires] > dau[i]) return 0;
	if (dau[i] + dau[ires] == 2) 
	  if (d[i] > d[ires]) return 1;
	if (dau[i] + dau[ires] == -2)
	  if (d[i] < d[ires]) return 1;
	return 0;
}

main()
{
	while ((cin >> m >> n) && (m != 0))
	{
		for (long i = 1; i <= n; i++)
		  for (long j = 1; j <= m; j++) cin >> a[i][j];
		for (long i = 1; i <= m; i++)
		{
			d[i] = 0;
			dau[i] = 0;
		}
		for (long i = 1; i <= n; i++)
		  for (long j = 1; j <= m; j++)
		  {
		  	if (a[i][j] < 0)
		  	{
		  		dau[j]++;
		  		a[i][j] *= -1;
		  	}
		  	a[i][j] = log(a[i][j]);
		  }
		for (long i = 1; i <= m; i++)
		  if (dau[i] % 2 == 0) dau[i] = 1;
		  else dau[i] = -1;
		for (long j = 1; j <= m; j++)
		  for (long i = 1; i <= n; i++) d[j] += a[i][j];
		ires = m;
		for (long i = m - 1; i >= 1; i--)
		  if (lonHon(i, ires)) ires = i;
		cout << ires << endl;
	}
}
