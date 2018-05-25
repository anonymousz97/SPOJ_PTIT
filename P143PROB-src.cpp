#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
long t, n, m, ngay, u[10001], v[10001];
double p[10001], c[101], a[101];

void thaydoi()
{
	for (long i = 0; i < n; i++) c[i] = 0;
	for (long i = 1; i <= m; i++)
	{
		c[u[i]] -= a[u[i]] * p[i];
		c[v[i]] += a[u[i]] * p[i];
	}	
	for (long i = 0; i < n; i++) a[i] += c[i];
}

double mana(long x)
{
	double d = a[x];
	for (long i = 1; i <= m; i++)
	  if (u[i] == x) d += a[v[i]];
	  else 
	  if (v[i] == x) d += a[u[i]];
	return d;
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> n >> m >> ngay;
		for (long i = 0; i < n; i++) cin >> a[i];
		for (long i = 1; i <= m; i++) cin >> u[i] >> v[i] >> p[i];
		for (long i = 1; i <= ngay; i++) thaydoi();
		double res = mana(0);
		for (long i = 1; i < n; i++)
		{
			double k = mana(i);
			if (k < res) res = k;
		}
		printf("%0.9lf\n", res);
	}
}