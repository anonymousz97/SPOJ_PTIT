#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FO(i, a, b) for (ll i = a; i < b; i++)
#define FILEIN freopen("in.txt", "r", stdin)
#define fi first
#define se second

using namespace std;
const ll MAX = 1e5 + 10;
int n, k, a[MAX], ires;
int m, b[MAX], f[MAX] = {0};

void process(){
	b[++m] = a[1];
	FOR(i, 2, n){
		if (a[i] != a[i - 1]) b[++m] = a[i];
	}	
	FOR(i, 1, n){
		if (a[i - 1] == a[i + 1]) f[a[i]]+= 2;
		else f[a[i]]++;
	}
	
	ires = 1;
	FOR(i, 2, n){
		if (f[i] > f[ires]) ires = i;
	}
//	FOR(i, 1, k) cout << f[i];
}

int main(){
	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];
	process();
	cout << ires;
}
