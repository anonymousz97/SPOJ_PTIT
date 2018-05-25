#include <iostream>
using namespace std;
long t, n, m, xuatPhat, ketThuc;
long a[101][101];

long docDL()
{
	cin >> n >> m >> xuatPhat >> ketThuc;
	for (long i = 1; i <= n; i++)
	  for (long j = 1; j <= n; j++) a[i][j] = 0;
	long u, v;
	for (long i = 1; i <= m; i++)
	{
		cin >> u >> v;
		a[u][v] = 1;
	}
}

long bfs(long x)
{
	long cx[101];
	for (long i = 1; i <= n; i++) cx[i] = 1;
	cx[xuatPhat] = 0;
	long q[1001], l, r;
	q[1] = xuatPhat;
	l = 1; r = 1;	
	do
	{
		long u = q[l];
		l++;
		for (long v = 1; v <= n; v++)
		 if (v != x)
		 {
		 	if ((cx[v]) && (a[u][v] == 1))
		 	{
		 		if (v == ketThuc) return 1;
		 		r++;
		 		q[r] = v;
		 		cx[v] = 0;
		 	}
		 }
	}
	while (l <= r);
	return 0;
}

long ketQua()
{
	long res = 0;
	for (long i = 1; i <= n; i++)
	  if ((i != xuatPhat) && (i != ketThuc))
	    if (!bfs(i)) res++;
	return res;
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		docDL();
		cout << ketQua() << endl;
	}
}