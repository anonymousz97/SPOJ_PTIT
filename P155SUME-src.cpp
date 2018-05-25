#include <iostream>
#include <cmath>
#include <string>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
string s;
ll k, l;
ll res;

ll luyThua(ll a, ll b)
{
	if (b == 0) return 1;
	ll k = luyThua(a, b/2);
	ll d = k * k % mod;
	if (b % 2) d = d * a % mod;
	return d;	
}

ll Tinh(ll a, ll b)
{
	ll c = luyThua(b, mod - 2);
	return (a * c % mod);
}

main()
{
	cin >> s >> k;
	l = s.length();
	s = "*" + s;
	res = 0;
	for (int i = l; i > 0; i--) 
	  if (s[i] == '0' || s[i] == '5') res = (res + luyThua(2, i - 1)) % mod;
	ll a = (luyThua(2, l * k) - 1 + mod) % mod;
	ll b = (luyThua(2, l) - 1 + mod) % mod;
	ll d = Tinh(a, b);
	res = res * d % mod;
	cout << res;
}
