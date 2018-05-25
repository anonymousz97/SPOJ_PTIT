#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long
#define nmax 1000000
using namespace std;
ll n, d[nmax + 6] = {0}, f[nmax + 6];
main()
{
	cin >> n;
	ll x;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		d[x]++;
	}
	f[0] = 0;
	f[1] = d[1];
	for (int i = 2; i <= nmax; i++) f[i] = max(f[i - 2] + i * d[i], f[i - 1]);
	cout << f[nmax];
}