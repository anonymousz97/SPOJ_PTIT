#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, a[101];
int res, t;
main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	  for (int j = i; j <= n; j++)
	  {
	  	t = a[i];
	  	for (int k = i + 1; k  <= j; k++) t = t ^ a[k];
	  	if (t > res) res = t;
	  }
	cout << res;
}