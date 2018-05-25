#include <iostream>
#define ll long long
using namespace std;
ll n, A, cnt[2000] = {0};
ll res = 0, pow[13];

ll mask(ll A)
{
	ll res = 0;
	while (A > 0)
	{
		ll x = A % 10;
		A /= 10;
		res = res | pow[x];
	}
	return res;
}

void Init()
{
	pow[0] = 1;
	for (int i = 1; i <= 10; i++) pow[i] = pow[i - 1] * 2;
}

main()
{
	cin >> n;
	Init();
	for (int i = 1; i <= n; i++)
	{
		cin >> A;
		cnt[mask(A)]++;
	}

	for (int i = 1; i <= pow[10]; i++)
	{
		res += cnt[i] * (cnt[i] - 1) / 2;
		if (i == pow[10]) break;
		for (int j = i + 1; j <= pow[10]; j++)
		  if (i & j) res += cnt[i] * cnt[j];
	}
	cout << res;
}
