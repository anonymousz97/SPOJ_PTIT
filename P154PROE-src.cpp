#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#define pb push_back
#define ll long long
using namespace std;
int n, m, cx[100], p[100], d;
vector <int> ke[100];
ll res;

void BFS(int u, int type)
{
	queue <int> q;
	q.push(u);
	cx[u] = 0;
	p[u] = d;
	do
	{
		int s = q.front();
		q.pop();
		for (int i = 0; i < ke[s].size(); i++)
		{
		  int t = ke[s][i];	
		  if (cx[t])
		  {
		  	q.push(t);
		  	cx[t] = 0;
		  	p[t] = type;
		  }
		}
	}	
	while (!q.empty());
}

main()
{
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		ke[u].pb(v);
		ke[v].pb(u);
	}
	for (int i = 1; i <= n; i++) cx[i] = 1;
	d = 0;
	for (int i = 1; i <= n; i++) p[i] = 0;
	for (int i = 1; i <= n; i++)
	  if (cx[i])
	  {
	  	d++;
	  	BFS(i, d);
	  }
	res = 0;
	int k;
	for (int i = 1; i <= d; i++)
	{
		k = 0;
		for (int j = 1; j <= n; j++)
		  if (p[j] == i) k++;
		res += k - 1;
	}
	ll r = 1;
	for (int i = 1; i <= res; i++) r *= 2;
	cout << r;
}
