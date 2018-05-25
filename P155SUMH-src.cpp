#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
ll a, b, c, x;
ll st[10000], t = 0;

ll s(ll x)
{
	ll res = 0;
	while (x > 0)
	{
		res += x % 10;
		x /= 10;
	}
	return res;	
}

main()
{
	cin >> a >> b >> c;
	for (int i = 0; i <= 81; i++)
	{
		x = b * pow(i, a) + c;
		if (x > 0 && x < 1e9 && s(x) == i) st[++t] = x;
	}
	cout << t << endl;
	for (int i = 1; i <= t; i++) cout << st[i] << " ";
}
