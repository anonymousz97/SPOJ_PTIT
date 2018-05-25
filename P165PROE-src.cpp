#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
#define fi first
#define se second
using namespace std;

const ll MAX = 1e5 + 10;

ll n, m, r, res = 0, s;

typedef pair <ll, ll> record;
record a[MAX];

bool tmp(record a, record b){
	return (a.se <= b.se);
}

void Process(){
	sort(a + 1, a + 1 + n, tmp);
	s = r * n;
	ll sum = 0;
	FOR(i, 1, n) sum += a[i].first;
	s -= sum;
	
	FOR(i, 1, n){
		if (s <= 0) break;
		ll k = (m - a[i].fi);
		if (s >= k){
			res += k * a[i].se;
			s -= k;
		}
		else{
			res += s * a[i].se;
			s = 0;
		}
	}
}

int main(){
	cin >> n >> m >> r;
	FOR(i, 1, n) cin >> a[i].fi >> a[i].se;
	Process();
	cout << res;
}