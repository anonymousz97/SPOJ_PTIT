#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
const ll nmax = 3005;
ll n, a[nmax], b[nmax], f[nmax][nmax] = {0}, res;
main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[n - i + 1] = a[i];
	}
	res = -99999999999999;
	for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
	 	if (i != n - j +1) 
		 {
	        f[i][j] = max(f[i][j], a[i]*b[j]);
	        int rj = n - j + 1;
	        if (fabs(rj - i) > 1) f[i][j] = max(f[i][j], f[i-1][j-1] + a[i]*b[j]);
	        if (res < f[i][j]) res = f[i][j];
	     }
	cout << res;
}

