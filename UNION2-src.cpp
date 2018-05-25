#include <iostream>
#include <algorithm>
using namespace std;
long n, res;
long long b, p[1001], q[1001], s[1001];
main()
{
	cin >> n >> b;
	for (long i = 1; i <= n; i++)
	{
		cin >> p[i] >> q[i];
		s[i] = p[i] + q[i];
	}
	for (long i = n - 1; i >= 1; i--)
	  for (long j = 1; j <= i; j++)
	 	if (s[j] > s[j + 1])
	 	{
	 		swap(s[j], s[j + 1]);
	 		swap(p[j], p[j + 1]);
	 		swap(q[j], q[j + 1]);
	 	}
	// sau khi sap xep duoc mang tang dan theo s[];
	long res = 0;
	for (long k = 1; k <= n; k++)
	{
		long long m = b;
		if (m < (p[k] / 2 + q[k])) continue;
		long d = 1;
		m -= (p[k] / 2 + q[k]);
		for (long i = 1; i <= n; i++)
		  if (i != k)
		  {
		  	if (m < s[i]) break;
		  	d++;
		  	m -= s[i];
		  }
		if (d > res) res = d;
	}
	cout << res;
}