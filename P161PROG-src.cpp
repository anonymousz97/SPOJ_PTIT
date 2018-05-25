#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FO(i, a, b) for (ll i = a; i < b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)

#define pb push_back

using namespace std;

ll n, res = 0;

bool OK(ll x){
	FOR(i, 2, sqrt(x)){
		if (x % (i * i) == 0) return 0;
	}
	return 1;
}

void process(){
	FOR(i, 1, sqrt(n)){
		if (n % i == 0){
			ll k = n / i;
			
			if (OK(i)) res = max(res, i);
			if (OK(k)) res = max(res, k);
		}
	}
}

int main(){
	cin >> n;
	process();
	cout << res;
}