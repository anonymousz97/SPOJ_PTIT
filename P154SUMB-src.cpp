#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long
#define x first
#define y second
using namespace std;
const ll nmax = 100000;

typedef pair <ll, ll> record;
record b[nmax + 5];

ll n, s[nmax + 5], a[nmax + 5];
ll res;

void BuildA()
{
	sort(b + 1, b + 1 + n);
	a[b[1].y] = 1;
	for (int i = 2; i <= n; i++)
	  if (b[i - 1].x == b[i].x) a[b[i].y] = a[b[i - 1].y];
	  else a[b[i].y] = a[b[i - 1].y] + 1;
//	for (int i = 1; i <= n; i++) cout << a[i] << " ";
}

void Insert(ll x)
{
	while (x <= 1e5)
	{
		s[x]++;
		x = x + (x & (-x));
	}
}

ll sum(ll x)
{
	ll rr = 0;
	while (x > 0)
	{
		rr += s[x];
		x = x & (x - 1);
	}
	return rr;
}

main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i].x;
		b[i].y = i;
	}
	BuildA();
	for (int i = 0; i <= nmax; i++) s[i] = 0;
	res = 0;
	Insert(a[n]);
	for (int i = n - 1; i > 0; i--)
	{
		Insert(a[i]);
		res += sum(a[i] - 1);
	}
	cout << res;
}
