#include <iostream>
#include <math.h>
#define ll long long
using namespace std;
ll n, k;
main()
{
	cin >> n >> k;
	ll l, r, p = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l >> r;
		p += (r - l);
	}
	ll res = (k - (p % k)) % k;
	cout << res;
}