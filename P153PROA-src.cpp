#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define X first
#define Y second
using namespace std;
const ll nmax = 100005;
const ll mod = 1000000007;
ll n, a[nmax];
map <ll, ll> m;
ll res = 0;

int Find(int a, int b)
{
	int r, xm, xn, m, n, q, xr;
    m = a; xm = 1;
    n = b; xn = 0;
    while (n) {
        q = m / n;
        r = m - q * n;
        xr = xm - q*xn;
        m = n; xm = xn;
        n = r; xn = xr;
    }
    if (xm < 0) xm += mod;
    return xm;
}

int main(){
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n){
		ll x = Find(a[i], mod);
		if (m[x]){
			m[x]--;
			res++;
		}
		else m[a[i]]++;
	}
	cout << res << endl;
	return 0;
}