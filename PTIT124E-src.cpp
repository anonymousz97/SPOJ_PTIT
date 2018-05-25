#include <iostream>
using namespace std;
long n, m, k, a[1001][1001], vt[101];
long d[1001], res;

void bfs(long s)
{
	long cx[1001], q[10001], l, r, v;
	for (long i = 1; i <= n; i++) cx[i] = 1;
	l = 1; r = 1;
	cx[s] = 0;
	q[1] = s;
	do
	{
		long u = q[l];
		l++;
		for (v = 1; v <= n; v++)
		  if ((a[u][v] == 1) && (cx[v]))
		  {
		  	cx[v] = 0;
		  	d[v]++;
		  	r++;
		  	q[r] = v;
		  }
	} while (l <= r);
}
main()
{
	cin >> k >> n >> m;
	for (long i = 1; i <= k; i++) cin >> vt[i];
	for (long i = 1; i <= n; i++)
	  for (long j = 1; j <= n; j++) a[i][j] = 0;
	long x, y;
	for (long i = 1; i <= m; i++)
	{
		cin >> x >> y;
		a[x][y] = 1;
	}
	for (long i = 1; i <= n; i++) d[i] = 0;
	for (long i = 1; i <= k; i++)
	{
		d[vt[i]]++;
		bfs(vt[i]);
	}
	res = 0;
	for (long i = 1; i <= n; i++)
	  if (d[i] == k) res++;
	cout << res;
}