#include <iostream>
#define x first
#define y second
using namespace std;
int n;
typedef pair <int, int> record;
record a[200005];
int b[200005], c[200005], next[1000005], prev[1000005];
int res[200005], type[1000005];
int cx[200005];

void BuildB()
{	
	b[0] = 0;
	cx[type[0]] = 0;
	int t = 0;
	while (next[b[t]] != 0)
	{
		int x = next[b[t]];
		cx[type[x]] = 0;
		b[++t] = x;
	}
	int k = 0;
	for (int i = 1; i <= t; i++)
	{
		k += 2;
		res[k] = b[i];
	}
}

void BuildC()
{
	int k;
	for (int i = 1; i <= n; i++)
	  if (cx[i])
	  {
	  	k = i;
	  	break;
	  }
	int sau[200005], truoc[200005];
	sau[1] = a[k].y;
	int t = 1;
	while (next[sau[t]] != 0)
	{
		int x = next[sau[t]];
		sau[++t] = x;
	}
	truoc[1] = a[k].x;
	int p = 1;
	while (prev[truoc[p]] != 0)
	{
		int x = prev[truoc[p]];
		truoc[++p] = x;
	}
	int l = 0;
	for (int i = p; i > 0; i--) c[++l] = truoc[i];
	for (int i = 1; i <= t; i++) c[++l] = sau[i]; 
	int m = -1;
	for (int i = 1; i <= l; i++)
	{
		m += 2;
		res[m] = c[i];
	}
}

void Init()
{
	for (int i = 0; i < 1000005; i++)
	{
		next[i] = 0;
		prev[i] = 0;
		type[i] = 0;
	}	
	for (int i = 1; i <= n; i++)
	{
		next[a[i].x] = a[i].y;
		prev[a[i].y] = a[i].x;
		type[a[i].x] = i;
	}
	for (int i = 1; i <= n; i++) cx[i] = 1;
}

main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	Init();
	BuildB();
	BuildC();
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
}
