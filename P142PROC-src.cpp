#include  <iostream>
#include <math.h>
using namespace std;
long s, t, u, v;

long xe()
{
	if ((s == u) && (t == v)) return 0;
	if ((s != u) && (t != v)) return 2;
	return 1;
}
long kiemTra(long uu, long vv)
{
	if ((1 <= uu) && (uu <= 8) && ((1 <= vv)&& (vv <= 8))) return 1;
	return 0;
}
long tuong()
{
	long a[9][9];
	long k = 1;
	for (long i = 1; i <= 8; i++)
	{
	  for (long j = 1; j <= 8; j++)
	  {
	  	a[i][j] = k;
	  	k *= -1;
	  }
	  k *= -1;
	}
	if (a[s][t] != a[u][v]) return 0;
	if (fabs(s - u) == fabs(t - v)) return 1;
	return 2;
}
long vua()
{
	long d[10][10], cx[10][10];
	typedef pair<long, long> record;
	record q[100];
	long l, r;
	long dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
	long dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
	for (long i = 1; i <= 8; i++)
	  for (long j = 1; j <= 8; j++) cx[i][j] = 1;
	d[s][t] = 0;
	l = 1; r = 1;
	q[1].first = s;
	q[1].second = t;
	cx[s][t] = 0;
	do
	{
		long x = q[l].first;
		long y = q[l].second;
		l++; 
		for (long i = 0; i < 8; i++)
		{
			long uu = x + dx[i];
			long vv = y + dy[i];
			if (kiemTra(uu, vv))
			  if (cx[uu][vv])
			  {
			  	r++;
			  	q[r].first = uu;
			  	q[r].second = vv;
			  	cx[uu][vv] = 0;
			  	d[uu][vv] = d[x][y] + 1;
			  	if ((uu == u) && (vv == v)) return (d[uu][vv]);
			  }
		}
	}
	while (l <= r);
}
main()
{
	cin >> s >> t >> u >> v;
	cout << xe() << " " << tuong() << " " << vua();
}
