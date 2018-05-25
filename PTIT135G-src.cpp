#include <iostream>
using namespace std;
long n, m, a[101], res, s;
main()
{
	cin >> n >> m;
	for (long i = 1; i <= n; i++) cin >> a[i];
	res = 0;
	for (long i = 1; i <= n - 2; i++)
	  for (long j = i + 1; j <= n - 1; j++)
	    for (long k = j + 1; k <= n; k++)
	      {
	      	s = a[i] + a[j] + a[k];
	      	if ((s > res) && (s <= m)) res = s;
	      }
	cout << res;
}