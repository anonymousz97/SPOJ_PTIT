#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
#define fi first
#define se second

using namespace std;

const ll MAX = 1010;
const ll INF = 1e9 + 7;

ll n, res, c[MAX][MAX], cx[MAX];

void process(){
	FOR(i, 1, n) cx[i] = 1;
	res = 0;
	int d = 1;
	cx[1] = 0;
	int u = 1;
	
	while (d != n){
		ll cmin = INF;
		ll iv;
		
		FOR(v, 1, n){
			if (cx[v] && c[u][v]){
				if (c[u][v] < cmin){
					cmin = c[u][v];
					iv = v;
				}
			}
		}	
		
		res += c[u][iv];
		cx[iv] = false;
		u = iv;
		d++;
	}
	
	res += c[u][1];
}

int main(){
//	FILEIN;
	
	cin >> n;
	FOR(i, 1, n){
		FOR(j, 1, n) cin >> c[i][j];
	}
	process();
	
	cout << res;
}