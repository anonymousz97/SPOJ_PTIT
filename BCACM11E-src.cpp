#include <iostream>
using namespace std;
int n, t, a[200][200], cx[200];

void dfs(int u)
{
	for (int v = 1; v <= n; v++)
	  if (cx[v] && a[u][v])
	  {
	  	cx[v] = 0;
	  	dfs(v);
	  }
}

int khop(int u)
{
	int d = 0;
	for (int i = 1; i <= n; i++) cx[i] = 1;
	cx[u] = 0;
	for (int i = 1; i <= n; i++)
	  if (cx[i])
	  {
	  	d++;
	  	dfs(i);
	  }
	return d;
}

void Process()
{
	int res = 0;
	int ires;
	for (int i = 1; i <= n; i++)
	{
		int d = khop(i); // so tplt neu ban vao i
		if (d > res)
		{
			res = d;
			ires = i;
		}
	}	
	if (res == 1) cout << 0;
	else cout << ires;
	cout << endl;
}

main()
{
	cin >> t;
	
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		  for (int j = 1; j <= n; j++) cin >> a[i][j];
		Process();
	}
}