#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FO(i, a, b) for (ll i = a; i < b; i++)
#define FILEIN freopen("in.txt", "r", stdin)
#define fi first
#define se second
 
using namespace std;
 
string s;
ll res, n, k;
ll d['Z' + 1];
 
bool cmp(ll a, ll b){
	return (a > b);
}
 
ll ketQua(){
	ll ans = 0;
	FOR(i, 1, 'Z'){
		if (!k) break;
		if (k >= d[i]){
			ans += d[i] * d[i];
			k -= d[i];
		}
		else{
			ans += k * k;
			k = 0;
		}
	}
	return ans;
}
 
void Process(){
	memset(d, 0, sizeof(d));
	res = 0;
	FO(i, 0, s.length()){
		d[s[i]]++;
	}
	sort(d + 1, d + 1 + 'Z', cmp);
	res = ketQua();
}
 
int main(){
	cin >> n >> k >> s;
	Process();
	cout << res;
}