#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
const int oo = 9999999;
using namespace std;
int a[25][25], n, m, cx[25], x[25];
int res;

void dfs(int u)
{
	cx[u] = 0;
	for (int v = 1; v <= n; v++)
	  if (x[v] && cx[v] && a[u][v]) dfs(v);
}

void Update()
{
	for (int i = 1; i <= n; i++) cx[i] = 1;
	dfs(1);
	if (cx[2]) return;
	
	for (int i = 1; i <= n; i++) cx[i] = 1;
	dfs(2);
	if (cx[1]) return;
	
	int d = 0;
	for (int i = 1; i <= n; i++) d += x[i];
	res = min(res, d);
}

void Try(int i)
{
	for (int j = 0; j < 2; j++)
	{
		x[i] = j;
		if (i == n) Update();
		else Try(i + 1);
	}
}

main()
{
//	freopen("in.txt", "r", stdin);
	int test;
	cin >> test;
	while (test--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		  for (int j = 1; j <= n; j++) a[i][j] = 0;
		for (int i = 1; i <= m;  i++)
		{
			int x, y;
			cin >> x >> y;
			a[x][y] = 1;
		}
		res = oo;
		x[1] = 1;
		x[2] = 1;
		Try(3);
		cout << res << endl;
	}
}