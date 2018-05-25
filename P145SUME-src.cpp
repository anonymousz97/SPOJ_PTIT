#include <iostream>
#include <math.h>
using namespace std;
long n, x[100001];
long pos[100001];

void demSoUoc(long vt)
{
	long n = x[vt];
	long res = 0;
	for (long i = 1; i <= sqrt(n); i++)
	  if (n % i == 0)
	  {
	  	res++;
	  	pos[i] = vt;
	  	if (i * i == n) continue;
	  	long k = n / i;
	  	res++;
	  	pos[k] = vt;
	  }
	cout << res << endl;
}

void truyVan(long vt, long kc)
{
	long res = 0;
	long n = x[vt];
	for (long i = 1; i <= sqrt(n); i++)
	  if (n % i == 0)
	  {
	  	if (pos[i] < (vt - kc)) res++;
	  	pos[i] = vt;
	  	long k = n / i;
	  	if (k == i) continue;
	  	if (pos[k] < (vt - kc)) res++;
	  	pos[k] = vt;
	  }
	cout << res << endl;
}

main()
{
	cin >> n;
	for (long i = 1; i <= n; i++) pos[i] = 0;
	for (long i = 1; i <= n; i++)
	{
		long d;
		cin >> x[i] >> d;
		if (!d) demSoUoc(i);
		else truyVan(i, d);
	}
}