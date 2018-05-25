#include <iostream>
using namespace std;
long t;

long qhd(long n, long k, long a[])
{
	long f[101][101];
	for (long i = 1; i <= n; i++) f[i][1] = 1;
	for (long j = 2; j <= k; j++) f[1][j] = 0;
	for (long i = 2; i <= n; i++)
	  for (long j = 2; j <= k; j++)
	  	{
	  		f[i][j] = 0;
	  		for (long p = j - 1; p <= i - 1; p++)
	  		  if (a[p] < a[i]) f[i][j] += f[p][j - 1];
	  	}	
	long res = 0;
	for (long i = 1; i <= n; i++) res += f[i][k];
	return res;
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		long n, k, a[101];
		cin >> n >> k;
		for (long i = 1; i <= n; i++) cin >> a[i];
		cout << qhd(n, k, a) << endl;
	}
}
