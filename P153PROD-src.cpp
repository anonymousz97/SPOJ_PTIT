#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 200;
ll n, a[MAX][MAX], p[MAX], f[MAX];
ll g, res[MAX];

ll FIND(){
	FOR(i, 1, n){
		ll d = 0;
		FOR(j, 1, n){
			if (a[i][j] == i) d++;
		}
		if (d == n) return i;
	}
}

void Process(){
	ll cx[MAX], t = 0;
	memset(f, 0, sizeof(f));
	FOR(i, 1, n) cx[i] = 1;
	
	f[g] = ++t;
	ll OK = 1;
	while (OK < n){
		t++;
		FOR(i, 1, n){
			if (!f[i]){
				ll c[MAX];
				memset(c, 0, sizeof(c));
				FOR(j, 1, n){
					if (cx[a[i][j]]) c[a[i][j]] = 1;
				}
				ll cnt = count(c + 1, c + 1 + n, 1);
				if (cnt == 2){
					FOR(j, 1, n){
						if (cx[a[i][j]] && a[i][j] != i){
							res[i] = a[i][j];
							f[i] = t;
							OK++;
							break;
						}
					}
				}
			}
		}
		FOR(i, 1, n){
			if (f[i] == t) cx[res[i]] = 0;
		}
	}
}

int main(){
//	freopen("in.txt", "r", stdin);
	cin >> n;
	FOR(i, 1, n){
		FOR(j, 1, n) cin >> a[i][j];
	}
	g = FIND();
	Process();
	FOR(i, 1, n) cout << res[i] << " ";
}