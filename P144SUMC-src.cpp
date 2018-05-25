#include <iostream>
#define ll long long
const ll e = 1e9 + 7;
using namespace std;
ll n, a, b, res, t;
ll snt[1000001], p[80000];

long dep(ll n)
{
	while (n != 0)
	{
		ll x = n % 10;
		n /= 10;
		if ((x != a) && (x != b)) return 0;
	}
	return 1;	
}

void sangNto()
{
	for (long i = 2; i <= n; i++) snt[i] = 1;
	t = 0;
	for (long i = 2; i <= n; i++)
	  if (snt[i])
	  {
	  	t++;
	  	p[t] = i;
	  	ll j = i;
	  	j *= i;
	  	while (j <= n)
	  	{
	  		snt[j] = 0;
	  		j += i;
	  	}
	  }
}

void ptich(ll n, long a[])
{
	for (long i = 1; i <= t; i++)
	{
		ll k = p[i];
		while (k <= n)
		{
			a[i] += n / k;
			k *= p[i];
		}
	}
}

ll tinh(long k)
{
	ll res = 1;
	long a[80000], b[80000];
	for (long i = 1; i <= t; i++)
	{
		a[i] = 0;
		b[i] = 0;
	}
	ptich(n, a);
	ptich(k, b);
	ptich(n - k, b);
	for (long i = 1; i <= t; i++)
	  for (long j = 1; j <= a[i] - b[i]; j++) res = (res * p[i]) % e;
	return res;
}

main()
{
	cin >> a >> b >> n;
	sangNto();
	res = 0;
	for (long i = 0; i <= n; i++)
	{
		ll sum = i * a + (n - i) * b;
		if (dep(sum)) 
			res = (res + tinh(i)) % e;
	}
	cout << res;
}