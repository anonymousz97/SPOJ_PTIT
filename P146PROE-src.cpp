#include <iostream>
#include <string>
#define ll long long
using namespace std;
const ll nmax = 105;
const ll oo = 1e9;
const ll mmax = 10004;
ll n, m, a[nmax][mmax], l[nmax][mmax] , r[nmax][mmax];
ll ans;
ll xn[nmax][3] = {0};

void BuildL()
{
	for (int i = 1; i <= n; i++) l[i][0] = 0;
	
	for (int i = 1; i <= n; i++)
	{
		int ok = 0;
		for (int j = 1; j <= m; j++)
		  if (a[i][j]) 
		  {
		     l[i][j] = j;
		     if (!ok)
		     {
		     	ok = 1;
		     	xn[i][1] = j;
		     }
		  }
		  else l[i][j] = l[i][j - 1];
	}
}

void BuildR()
{
	for (int i = 1; i <= n; i++) r[i][m + 1] = m + 1;
	
	for (int i = 1; i <= n; i++)
	{
		int ok = 0;
		for (int j = m; j > 0; j--)
		  if (a[i][j]) 
		  {
		  	r[i][j] = j;
		  	if (!ok)
		  	{
		  		xn[i][2] = j;
		  		ok = 1;
		  	}
		  }
		  else r[i][j] = r[i][j + 1];
	}
}

main()
{
//	freopen("in.txt", "r", stdin);
	string s;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		s = "*" + s;
		for (int j = 1; j <= m; j++) a[i][j] = s[j] - '0'; 
	}
	
	BuildL();
	BuildR();
	
	ans = oo;
	
	for (int j = 1; j <= m; j++)
	{
		ll res = 0;
		for (int i = 1; i <= n; i++)
		{
			ll k1, k2;
			if (!l[i][j]) k1 = oo;
			else k1 = j - l[i][j];
			if (r[i][j] == m + 1) k2 = oo;
			else k2 = r[i][j] - j;
			ll kk = min(k1, k2);
			
			ll p1, p2;
			if (!xn[i][1]) p1 = oo;
			else p1 = xn[i][1] + m - j;
			if (!xn[i][2]) p2 = oo;
			else p2 = m - xn[i][2] + j;
			ll pp = min(p1, p2);
			
			res += min(kk, pp);
		//	if (!res) cout << i << " " << j << endl;
		}
		if (res < ans) ans = res;
	}
	
	if (ans == oo) ans = -1;
	cout << ans;
}