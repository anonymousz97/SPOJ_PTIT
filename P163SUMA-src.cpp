#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FO(i, a, b) for (ll i = a; i < b; i++)

#define fi first
#define se second

using namespace std;

ll n, k, res = 0;
string s;
ll d[200] = {0};

bool cmp(ll a, ll b){
	return (a > b);
}

void process(){
	sort(d + 'A', d + 'Z' + 1, cmp);
	FOR(i, 'A', 'Z'){
		if (!k) return;
		if (k > d[i]){
			res += d[i] * d[i];
			k -= d[i];
		}
		else{
			res += k * k;
			k = 0;
		} 
	}
}

int main(){
	cin >> n >> k >> s;
	FO(i, 0, s.length()) d[s[i]]++;
	process();
	cout << res;
}