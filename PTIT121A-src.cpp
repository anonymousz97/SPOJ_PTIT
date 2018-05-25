#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FO(i, a, b) for (ll i = a; i < b; i++)
#define FORD(i, a, b) for (ll i = a; i >=b; i--)

#define fi first
#define se second

using namespace std;
const ll MAX = 1e5 + 10;

set <ll> sx, sy;
map <ll, ll> mx, my;
ll bx[MAX], by[MAX], xet[100][100] = {0}; 
ll xa[MAX], xb[MAX], ya[MAX], yb[MAX];

int main(){
	ll n, x, y, u, v;
	cin >> n;
	FOR(i, 1, n){
		cin >> x >> y >> u >> v;
		sx.insert(x); sx.insert(u); xa[i] = x; xb[i] = u;
		sy.insert(y); sy.insert(v); ya[i] = y; yb[i] = v;
	}
	
	int cntX = 0;
	set <ll> :: iterator it1;
	for (it1 = sx.begin(); it1 != sx.end(); it1++){
		bx[++cntX] = *it1;
		mx[*it1] = cntX;
	}
	
	int cntY = 0;
	set <ll> :: iterator it2;
	for (it2 = sy.begin(); it2 != sy.end(); it2++){
		by[++cntY] = *it2;
		my[*it2] = cntY;
	}
	
	FOR(k, 1, n){
		int u = mx[xa[k]], x = mx[xb[k]];
		int y = my[ya[k]], v = my[yb[k]];
		FOR(i, u, x - 1){
			FOR(j, v, y - 1){
				xet[i][j] = 1;
			}
		}
	}
	
	ll res = 0;
	FOR(i, 1, cntX - 1){
		FOR(j, 1, cntY - 1){
			if (xet[i][j]){
				res += (bx[i + 1] - bx[i]) * (by[j + 1] - by[j]);	
			}	
		}
	}
	
	cout << res;
}