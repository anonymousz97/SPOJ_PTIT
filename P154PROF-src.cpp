#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 1e6 + 10;
ll n, a[MAX], res;
ll L[MAX], R[MAX], t[MAX];

map <ll, ll> m;

void BuildL(){
	m.clear();
	FOR(i, 1, n) L[i] = ++m[a[i]];
}

void BuildR(){
	m.clear();
	FORD(j, n, 1) R[j] = ++m[a[j]];
}

ll sum(ll x){
	ll ans = 0;
	for(; x > 0; x &= (x - 1)) ans += t[x];
	return ans;
}

void Insert(ll x){
	for(; x <= n; x += (x & (-x))) t[x]++;
}

void Process(){
	memset(t, 0, sizeof(t));
	res = 0;
	
	FORD(i, n, 1){
		res += sum(L[i] - 1);
		Insert(R[i]);
	}
}

int main(){
//	freopen("in.txt", "r", stdin);
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	
	BuildL();		// L[i] = f(1, i, a[i]), R[i] = f(j, n, a[j])
	BuildR();
	
	Process();
	
	cout << res;
}