#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define X first
#define Y second
using namespace std;
const ll MAX = 1e5 + 5;
const ll oo = MAX + 1;
struct record{
	ll r1, r2, r3;
};
ll n, res, t[MAX];
record a[MAX];

int cmp(record a, record b){
	if (a.r1 < b.r1) return 1;
	return 0;
}

void Insert(int i){
	ll x = a[i].r2;
	for (; x <= n; x += (x & (-x))) t[x] = min(t[x], a[i].r3);
}

int OK(int i){
	ll x = a[i].r2 - 1;
	for(; x > 0; x &= (x - 1)){
		if (t[x] < a[i].r3) return 0;
	}
	return 1;
}

void Process(){
	sort(a + 1, a + 1 + n, cmp);
	FOR(i, 0, n) t[i] = oo;
	FOR(i, 1, n){
		if (OK(i)) res++;
		Insert(i);
	}
}

int main(){
//	freopen("in.txt", "r", stdin);
	cin >> n;
	FOR(i, 1, n) cin >> a[i].r1 >> a[i].r2 >> a[i].r3;
	
	Process();
	
	cout << res;
}