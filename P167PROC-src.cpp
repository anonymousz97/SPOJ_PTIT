#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

const ll MAX = 30;

int n, cx[MAX], x[MAX], f[MAX][MAX] = {0}, res = 1e9 + 7;
string s[MAX];
int p['Z' + 1];

ll dem(string a, string b){
	memset(p, 0, sizeof(p));
	FOR(i, 0, a.length() - 1) p[a[i]]++;
	FOR(i, 0, b.length() - 1) p[b[i]]++;
	int d = 0;
	
	FOR(i, 'A', 'Z'){
		if (p[i] > 1) d++;
	}
	
	return d;
}

void Init(){
	FOR(i, 1, n) cx[i] = true;
	FOR(i, 1, n - 1){
		FOR(j, i + 1, n){
			f[i][j] = dem(s[i], s[j]);
			f[j][i] = f[i][j];
		}
	}
}

void Update(){
	ll s = 0;
	FOR(i, 2, n) s += f[x[i - 1]][x[i]];
	
	if (res > s) res = s;
}

void Try(int i){
	FOR(j, 1, n){
		if (cx[j]){
			x[i] = j;
			cx[j] = false;
			if (i == n) Update();
			else Try(i + 1);
			cx[j] = true;
		}
	}
}

void Process(){
	Try(1);
}

int main(){
	cin >> n;
	FOR(i, 1, n) cin >> s[i];
	Init();
	Process();
	cout << res;
}