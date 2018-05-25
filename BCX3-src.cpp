#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
ll res, t, k, n;

void Process(ll n, ll k)
{
	ll f[200][200][5];
	for (int i = 0; i <= n; i++)
	  for (int j = 0; j <= k; j++)
	    for (int k = 0; k <= 1; k++)	f[i][j][k] = 0;
	f[1][0][0] = 1;
	f[1][0][1] = 1;
	
	for (int i = 2; i <= n; i++)
	  for (int j = 0; j <= k; j++)
	  {
	  	f[i][j][1] = f[i - 1][j][0];
	  	if (j > 0) f[i][j][1] += f[i - 1][j - 1][1];
	  	f[i][j][0] = f[i - 1][j][1] + f[i - 1][j][0];
	  }
	res = f[n][k][0] + f[n][k][1];
}

main()
{
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int ord;
		
		cin >> ord >> n >> k;
		Process(n, k);
		cout << ord << " " << res << endl;
	}
}