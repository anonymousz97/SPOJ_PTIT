#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FO(i, a, b) for (ll i = a; i < b; i++)

#define fi first
#define se second

using namespace std;

const ll MAX = 105;

ll n;

string a[MAX][MAX];

string f[MAX][MAX] = {""};

void process(){
	f[1][1] = a[1][1];
	FOR(i, 2, n){
		f[i][1] = f[i - 1][1] + a[i][1];
		f[1][i] = f[1][i - 1] + a[1][i];
	}
	FOR(i, 2, n){
		FOR(j, 2, n){
			f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
		}
	}
}

char convert(string t){
	int k = 0;
	FO(i, 0, t.length()) k = k * 2 + t[i] - '0';
	if (k < 10) return (k + '0');
	return (k - 10 + 'A');
}

void output(string s){
	string res = "";
	while (s.length() % 4) s = "0" + s;
	int l = s.length();
	s = "*" + s;
	for (int i = 1; i < l; i += 4){
		string t = s.substr(i, 4);
		res += convert(t);
	}
	
	while (res.length() > 0 && res[0] == '0') res.erase(0, 1);
	if (res == "") res = "0";
	cout << res;
}

int main(){
	cin >> n;
	FOR(i, 1, n){
		FOR(j, 1, n) cin >> a[i][j];
	}
	process();
	output(f[n][n]);
}