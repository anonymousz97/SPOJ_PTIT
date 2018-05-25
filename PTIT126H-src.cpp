#include <iostream>
using namespace std;
typedef pair <long, long> record;
long h[1001][1001], cx[1001][1001], l, r, docao, hmax, d[1001], n, m, res;
record q[1000001];
long dx[4] = {-1, 0, 1, 0},
	 dy[4] = {0, -1, 0, 1};
long tran;

void nhap()
{
	cin >> m >> n;
	hmax = 0;
	for (long i = 0; i < 1001; i++) d[i] = 0;
	for (long i = 1; i <= m; i++)
	  for (long j = 1; j <= n; j++)
		{
			cin >> h[i][j];
			if (h[i][j] > hmax) hmax = h[i][j];
			d[h[i][j]] ++;
		}
}   

void xuat()
{
	cout << res;
}

void bfs(long s, long t)
{
	l = 1; r = 1;
	q[1].first = s;
	q[1].second = t;
	cx[s][t] = 0;
	do
	{
		long u = q[l].first, v = q[l].second;
		l++;
		for (long i = 0; i < 4; i++)
		{
			long uu = u + dx[i], vv = v + dy[i];
			if ((uu > 0) && (uu <= m) && (vv > 0) && (vv <= n))
			{
				if (h[uu][vv] == 0) tran = 1;
				if ((cx[uu][vv]) && (h[uu][vv] == docao))
				{
					r++;
					q[r].first = uu;
					q[r].second = vv;
					cx[uu][vv] = 0;
				}
			}
		}
	}
	while (l <= r);
}

void xuli()
{
	docao = 0;
	res = 0;
	while (docao <= hmax)
	{
		if (d[docao] == 0) docao++;
		else
		{
			for (long i = 1; i <= m; i++)
			  for (long j = 1; j <= n; j++) cx[i][j] = 1;
			for (long x = 1; x <= m; x++)
			  for (long y = 1; y <= n; y++)
			    if ((cx[x][y]) && (h[x][y] == docao))
			    {
			    	tran = 0;
			    	bfs(x, y);
			    	for (long i = 1; i <= r; i++)
			    	 if ((q[i].first == 1) || (q[i].first == m) || (q[i].second == 1) || (q[i].second == n))
			    	 {
			    	 	tran = 1;
			    	 	break;
			    	 }
			    	if (tran)
			    	{
			    		for (long i = 1; i <= r; i++) h[q[i].first][q[i].second] = 0;
			    		d[docao] -= r;
			    	}
			    	else
			    	{
			    		for (long i = 1; i <= r; i++) h[q[i].first][q[i].second]++;
			    		d[docao] -= r;
			    		d[docao + 1] += r;
			    		res += r;
			    	}
			    }
		}
	}
}

main()
{
	nhap();
	xuli();
	xuat();
}