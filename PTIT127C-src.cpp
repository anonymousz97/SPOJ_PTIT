#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define fi first
#define se second

using namespace std;
const ll MAX = 10010;

typedef pair <ll, ll> rr;
rr a[MAX];
int n, res;

void Swap(rr &a, rr &b){
	rr t = a;
	a = b;
	b = t;
}

void Sort(){
	FORD(i, n - 1, 1){
		FOR(j, 1, i){
			if (a[j].se > a[j + 1].se) Swap(a[j], a[j + 1]);
		}
	}
}

void process(){
	int ia = 1;
	res = 1;
	FOR(i, 2, n){
		if (a[i].first >= a[ia].second){
			res++;
			ia = i;
		}
	}
}

int cmp(rr a, rr b){
	return (a.second < b.second);
}

int main(){
	cin >> n;
	FOR(i, 1, n) cin >> a[i].fi >> a[i].se;
	//FOR(i, 1, n) cin >> a[i].se;
//	Sort();
	sort(a + 1, a + 1 + n, cmp);
	process();
	cout << res;
}