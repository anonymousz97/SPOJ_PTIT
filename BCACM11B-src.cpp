#include <iostream>
using namespace std;
long t, n, x, y, d;
long xtt, ytt, xpt, ypt, xpd, ypd, xtd, ytd;
long stop;
long a[101][101];

void build( long xtt, long ytt, long xpt, long ypt, long xpd, long ypd, long xtd, long ytd)
{
	for (long j = ytt; j < ypt; j++)
		{
			d++;
			a[xtt][j] = d;
		}
	for (long i = xpt; i <= xpd; i++)
		{
			d++;
			a[i][ypt] = d;
		}
	for (long j = ypd - 1; j >= ytd; j--)
		{
			d++;
			a[xtd][j] = d;
		}
	for (long i = xtd - 1; i >= xtt + 1; i--)
		{
			d++;
			a[i][ytt] = d;
		}
	if (d == n * n) stop = 1;
}
main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> n >> x >> y;
		d = 0; stop = 0;
		xtt = 1; ytt = 1;
		xpt = 1; ypt = n;
		xpd = n; ypd = n;
		xtd = n; ytd = 1;
		while (not stop)
		{
			build(xtt, ytt, xpt, ypt, xpd, ypd, xtd, ytd);
			xtt++; ytt++;
			xpt++; ypt--;
			xpd--; ypd--;
			xtd--; ytd++;
		}
	/* for (long i = 1; i <= n; i++)
		 {
		 	for (long j = 1; j <= n; j++) cout << a[i][j] << " ";
		 	cout << endl;
		 } */
		 cout << a[x][y] << endl;
	}
}