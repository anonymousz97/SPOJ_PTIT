#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
ll l, r;

ll uc(ll a, ll b)
{
	if (b == 0) return a;
	return uc(b, a % b);
}

void Process()
{
	ll res = 0;
	for (ll i = l; i < r - 1; i++)
	  for (ll j = i + 1; j < r; j++)
	    for (ll k = j + 1; k <= r; k++)	
	    {
	    	if (uc(i, j) == 1 && uc(j, k) == 1 && uc(i, k) != 1)
	    	{
	    		cout << i << " " << j << " " << k;
	    		return;
	    	}
	    }
	if (!res) cout << -1;
}

main()
{
	cin >> l >> r;
	Process();
}
