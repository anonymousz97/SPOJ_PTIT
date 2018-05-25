#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 2 * (1e5) + 10;
string s;
ll n, a[MAX], ia[MAX];
ll dmax, res;

void BuildA(){
	a[0] = 0;
	FOR(i, 1, n){
		if (s[i] > 90) s[i] -= 32;
		if (s[i] == 'U' || s[i] == 'E' || s[i] == 'O' || s[i] == 'A' || s[i] == 'I') a[i] = a[i - 1] + (-1);
		else a[i] = a[i - 1] + 2;
	}
	ia[0] = 0;
	ia[1] = 1;
	FOR(i, 2, n){
		if (a[i] < a[ia[i - 1]]) ia[i] = i;
		else ia[i] = ia[i - 1];
	}
//	FOR(i, 1, n) cout << a[i];
}

ll Find(ll x){
	ll l = 0, r = x - 1;
	ll mid, ans = x;
	while (l <= r){
		mid = (l + r) / 2;
		if (a[x] >= a[ia[mid]]){
			ans = ia[mid];
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void Process(){
	dmax = 1;
	FOR(i, 2, n){
		ll x = Find(i);
		if (i - x > dmax) dmax = i - x;
	}
	res = 0;
	FOR(i, dmax, n){
		if (a[i] >= a[i - dmax]) res++;
	}
	if (res) cout << dmax << " " << res;
	else cout << "No solution";
}

int main(){
	cin >> s;
	n = s.length();
	s = "*" + s;
	BuildA();
	Process();
}