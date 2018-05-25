#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FO(i, a, b) for (ll i = a; i < b; i++)
#define FILEIN freopen("in.txt", "r", stdin)
#define fi first
#define se second

using namespace std;

const ll MAX = 5e5 + 10;

ll n, res, f[200][200];

string a[MAX];

void process(){
	memset(f, 0, sizeof(f));
	
	FOR(k, 1, n){
		int m = a[k].length();
		FOR(i, 'a', 'z')
		  if (f[i][a[k][0]] > 0)
			{
				f[i][a[k][m - 1]] = max(f[i][a[k][m - 1]], f[i][a[k][0]] + m);
			}
		if (f[a[k][0]][a[k][m - 1]] < m)   f[a[k][0]][a[k][m - 1]] = m;
	}
	
	res = f['a']['a'];
	
	FOR(i, 'b', 'z') res = max(res, f[i][i]);
}

int main(){
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	
	process();
	
	cout << res;
}
