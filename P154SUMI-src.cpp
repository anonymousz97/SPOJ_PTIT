#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
ll n, res;

ll min3(ll a, ll b, ll c)
{
	ll res = a;
	if (res > b) res = b;
	if (res > c) res = c;
	return res;
}

ll uc(ll a, ll b)
{
	if (b == 0) return a;
	return uc(b, a % b);
}

void Process()
{
	res = 0;
	for (int i = 1; i <= sqrt(n); i++)
	  for (int j = i + 1; j <= sqrt(n); j++)
	  {
	  	ll x = j * j - i * i;
	  	ll y = 2 * i * j;
	  	ll z = j * j + i * i;
	  	if (x > n || y > n || z > n) continue;
	  	if (uc(uc(x, y), z) != 1) continue;
		res += n / z;
	  }	
}
main()
{
	cin >> n;
	Process();
	cout << res;
}
