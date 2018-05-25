#include <iostream>
#include <cmath>
#include <cstdio>
#define ll long long
using namespace std;
ll t, n, nt[500005], f[5000005], P[500005], Q[500005], cx[5000005];
ll a, b;

void SangNT()
{
	n = 0;
	for (int i = 2; i <= 5000000; i++) cx[i] = 0;
	for (int i = 2; i <= 5000000; i++)
	  if (!cx[i])
	  {
	  	cx[i] = i;
	  	ll j = i;
		j *= i;
		while (j <= 5000000)
		{
			cx[j] = i;
			j += i;
		}
	  }
//	for (int i = 1; i <= 20; i++) cout << cx[i] << " ";
}


ll SM(ll A)
{
	ll res = 0;
	while (A > 1)
	{
		res++;
		A /= cx[A];
	}
	return res;
}

void Init2()
{
	f[1] = 0;
	for (int i = 2; i <= 5000000; i++) 
		f[i] = f[i- 1] + SM(i);
}

main()
{
	SangNT();
	Init2();
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << (f[a] - f[b]) << endl;
	}
}