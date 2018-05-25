#include <iostream>
#include <string>
using namespace std;
typedef pair <int, int> pii;
pii st[10002];
struct record
{
	int x;
	int y;
	int h;
};
record q[100001];
int n, m, t, test;
string s[105];
int a[105][105];
int block[105][105][4];
int xpx, xpy, ktx, kty;
long dx[4] = {1, 0, -1, 0};
long dy[4] = {0, -1, 0, 1};

void timPhao()
{
	t = 0;
	for (long i = 1; i <= n; i++)
	  for (long j = 1; j <= m; j++)
	    if ((0 <= a[i][j]) && (a[i][j] <= 3))
	    {
	    	t++;
	    	st[t].first = i;
	    	st[t].second = j;
	    }
}

void buildA()
{
	for (int i = 1; i <= n; i++)
	  for (int j = 1; j <= m; j++)
	  {
	  	if (s[i][j] == '.') a[i][j] = -1;
	  	if (s[i][j] == '#') a[i][j] = 4;
	  	if (s[i][j] == 'v') a[i][j] = 0;
	  	if (s[i][j] == '<') a[i][j] = 1;
	  	if (s[i][j] == '^') a[i][j] = 2;
	  	if (s[i][j] == '>') a[i][j] = 3;
	  }
	timPhao();
}

void init()
{
	for (long i = 1; i <= n; i++)
	  for (long j = 1; j <= m; j++)
	    if (s[i][j] == 'S')
		{
			xpx = i;
			xpy = j;
			s[i][j] = '.';
		}	
		else
		if (s[i][j] == 'G')
		{
			ktx = i;
			kty = j;
			s[i][j] = '.';
		}
}

void rebuildA()
{
	int u, v;
	for (long i = 1; i <= t; i++)
	{
		u = st[i].first;
		v = st[i].second;
		a[u][v] = (a[u][v] + 1) % 4;
	}
}

void fire(int u, int v, int h, int k)
{
	
	if (h == 0)
	{
		for (int i = u + 1; i <= n; i++)
		  if (block[i][v][k] == -1) return;
		  else block[i][v][k] = 1;
	}
	if (h == 1)
	{
		for (int j = v - 1; j > 0; j--)
		  if (block[u][j][k] == -1) return;
		  else block[u][j][k] = 1;
	}
	if (h == 2)
	{
		for (int i = u - 1; i > 0; i--)
		  if (block[i][v][k] == -1) return;
		  else block[i][v][k] = 1;
	}
	if (h == 3)
	{
		for (int j = v + 1; j <= m; j++)
		  if (block[u][j][k] == -1) return;
		  else block[u][j][k] = 1;
	}
}

void buildTime(int k)
{
	int u, v;
	for (long i = 1; i <= t; i++)
	{
		u = st[i].first;
		v = st[i].second;
		block[u][v][k] = -1;
	}
	for (long i = 1; i <= t; i++)
	{
		u = st[i].first;
		v = st[i].second;
		fire(u, v, a[u][v], k);
	}
/*	for (long i = 1; i <= n; i++)
	{
		for (long j = 1; j <= m; j++) cout << block[i][j][k] << " ";
		cout << endl;
	}
	cout << endl; */
}

void BuildBlock()
{
	for (long i = 1; i <= n; i++)
	  for (long j = 1; j <= m; j++)
	    for (long k = 0; k < 4; k++) block[i][j][k] = 0;
	for (long i = 1; i <= n; i++)
	  for (long j = 1; j <= m; j++)
	    if (a[i][j] == 4)
	    {
	    	for (long k = 0; k < 4; k++) block[i][j][k] = -1;
	    }
	for (long i = 0; i < 4; i++)
	{
		if (i > 0) rebuildA();
		buildTime(i);
	}
}

long bfs(long u, long v)
{
	long cx[105][105][4];
	long d[105][105][4];
	for (long i = 1; i <= n; i++)
	  for (long j = 1; j <= m; j++)
	    for (long k = 0; k < 4; k++)
	    {
	    	cx[i][j][k] = 1;
	    	d[i][j][k] = 0;
	    }
	long l = 1, r = 1;
	q[1].x = u;
	q[1].y = v;
	q[1].h = 0;
	cx[u][v][0] = 0;
	d[u][v][0] = 0;
	do
	{
		int s, t, g;
		s = q[l].x;
		t = q[l].y;
		g = q[l].h;
		l++;
		for (long i = 0; i < 4; i++)
		{
			int ss, tt, gg;
			ss = s + dx[i];
			tt = t + dy[i];
			gg = (g + 1) % 4;
			if ((ss <= 0) || (ss > n) || (tt <= 0) || (tt > m)) continue;
			if ((cx[ss][tt][gg]) && (!block[ss][tt][gg]))
			{
				cx[ss][tt][gg] = 0;
				d[ss][tt][gg] = d[s][t][g] + 1;
				r++;
				q[r].x = ss;
				q[r].y = tt;
				q[r].h = gg;
			}
		}
	}
	while (l <= r);
/*	for (long i = 1; i <= r; i++) cout << q[i].x << " " << q[i].y << " " << q[i].h << endl;
	for (long k = 0; k < 4; k++)
	{
		for (long i = 1; i <= n; i++)
		{
			for (long j = 1; j <= m; j++) cout << d[i][j][k] << " ";
			cout << endl;
		}
		cout << endl;
	} */
	long res = 99999999;
	for (long i = 0; i < 4; i++)
	  if ((d[ktx][kty][i] != 0) && (d[ktx][kty][i] < res)) res = d[ktx][kty][i];
	if (res == 99999999) res = 0;
	return res;
}

main()
{
//	freopen("in1.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	cin >> test;
	for (int q = 1; q <= test; q++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
			s[i] = "*" + s[i];
		}
		init();
		buildA();
		BuildBlock();
		int res = bfs(xpx, xpy);
		cout << "Case #" << q << ": ";
		if (res > 0) cout << res; else cout << "impossible";
		cout << endl; 
	}
}