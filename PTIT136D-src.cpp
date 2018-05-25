#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FO(i, a, b) for (ll i = a; i < b; i++)
#define FILEIN freopen("in.txt", "r", stdin)
#define fi first
#define se second

using namespace std;

const ll MAX = 5005;
const ll pl = 5e5;

ll n, a[MAX], res;

ll dd[pl * 2];

void danhDau(ll s, ll j){
	if (!dd[s + pl]) dd[s + pl] = j;
			else dd[s + pl] = min(dd[s + pl], j);
}

void Build_dd(){
	memset(dd, 0, sizeof(dd));
	
	FOR(i, 1, n){
		FOR(j, i, n){
			ll s = a[i] + a[j];
			danhDau(s, j);
		}
	}	
}

bool OK(int i){
	FOR(j, 1, i - 1){
		ll t = a[i] - a[j];
		if (dd[t + pl] && dd[t + pl] < i) return 1;
	}
	return 0;
}

void process(){
	
	res = 0;
	FOR(i, 2, n){
		res += OK(i);
	}
}

int main(){
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	
	Build_dd();
	
	process();
	
	cout << res;
}
