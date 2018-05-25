#include <iostream>
using namespace std;
long n, m, a[1001], b[1001];

long smin()
{
	long s = 0;
	for (long i = 1; i <= n; i++)
	{
		long jr = 0; b[0] = 100000000;
		for (long j = 1; j <= m; j++)
		if (b[j] > 0)
		  if (b[jr] > b[j]) jr = j;
		s += b[jr];
		b[jr]--;
	}	
	return s;
}

long smax()
{
	long s = 0;
	for (long i = 1; i <= n; i++)
	{
		long jr = 0; a[0] = 0;
		for (long j = 1; j <= m; j++)
		if (a[j] > 0)
		  if (a[jr] < a[j]) jr = j;
		s += a[jr];
		a[jr]--;
	}
	return s;
}

main()
{
	cin >> n >> m;
	for (long i = 1; i <= m; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	cout << smax() << " " << smin();
}