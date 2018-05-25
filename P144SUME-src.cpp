#include <iostream>
#define x first
#define y second
using namespace std;

typedef pair <int, int> record;
record q[100005];
int m, n, a[100005];
int xh[100005] = {0};
int d[100005] = {0};
int f[100005];

void BuildF(int x)
{
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	  if (a[i] == x) f[i] = f[i - 1] + 1;
	  else f[i] = f[i - 1];	
}

main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] <= n) xh[a[i]]++;
	}
	for (int i = 1; i <= m; i++) cin >> q[i].x >> q[i].y;
	for (int i = 1; i <= n; i++)
	  if (xh[i] >= i)
	  {
	  	BuildF(i);
	  	for (int j = 1; j <= m; j++)
	  	{
	  		int l = q[j].x;
	  		int r = q[j].y;
	  		if (f[r] - f[l - 1] == i) d[j]++; 
	  	}
	  }
	for (int i = 1; i <= m; i++) cout << d[i] << endl;
}