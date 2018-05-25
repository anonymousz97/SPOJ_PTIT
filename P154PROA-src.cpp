#include <iostream>
#define ll unsigned long long
using namespace std;
ll t, n, m, k;

ll nhan(ll n, ll m, ll k)
{
	if (!m) return 0;
	if (m % 2 == 0) return nhan(n * 2 % k, m / 2, k) % k;
	else
	return (nhan(n % k, m - 1, k) % k + n % k) % k;
}

ll luyThua(ll n, ll m, ll k)
{
	if (!m) return 1;
	ll p = luyThua(n, m / 2, k);
	ll res = nhan(p, p, k);
	if (m % 2 != 0) res = nhan(res, n, k) % k;
	return res;
}

main()
{
//	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		cout << luyThua(n, m, k) << endl;
	}
}
