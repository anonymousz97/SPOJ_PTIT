#include <iostream>
#include <cstdio>
#include <cmath>
#define ll unsigned long long
using namespace std;
int t;
ll l, r, e[70];

void Init()
{
	e[0] = 1;
	for (int i = 1; i <= 63; i++) e[i] = e[i - 1] * 2;
}

ll Find(ll r)
{
	for (int i = 63; i >= 0; i--)
	  if (e[i] <= r) return i;
}

ll F(ll l , ll r)
{
	if (l == r) return r;
	ll b = Find(r);
	ll k = e[b];
	if (k <= l) return (F(l - k, r - k) + k);
	if (e[b + 1] - 1 <= r) return e[b + 1] - 1;
	return (k - 1);
}

main()
{
	Init();
	cin >> t;
	while (t--)
	{
		cin >> l >> r;
		cout << F(l, r) << endl;
	}
}