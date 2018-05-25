#include <iostream>
using namespace std;
long n,m,a[1001],f[10001];
long infi = 200000000;
main()
{
	cin >> n >> m;
	for (long i = 1; i <= n; i++) cin >> a[i];
	for (long i = 1; i <= m; i++) f[i] = infi;
	f[0]=0;
	for (long i = 1; i <= m; i++)
	  for (long j = n; j >= 1; j--)
	    if (i >= a[j])
	      if ( f[i] > f[i - a[j]] + 1) f[i] = f[i- a[j]] + 1;
	if (f[m] == infi) f[m] = -1;
	cout << f[m];
}