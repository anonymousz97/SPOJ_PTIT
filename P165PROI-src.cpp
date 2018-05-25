#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

const ll MAX = 1e6 + 10;

int n, f[MAX] = {0}, g[MAX] = {0};
string s;

void Process(){
	FOR(i, 1, s.length()){
		if (s[i] == 'A'){
			f[i] = f[i - 1];
			g[i] = min(f[i - 1], g[i - 1]) + 1;
		}
		else
		{
			g[i] = g[i - 1];
			f[i] = min(f[i - 1], g[i - 1]) + 1;
		}
	}
}

int main(){
	cin >> n >> s;
	s = "*" + s;
	Process();
	cout << f[n];
}