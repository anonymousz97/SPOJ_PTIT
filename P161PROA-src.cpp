#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

const ll MAX = 1e6 + 10;

int n;

ll x, nt[MAX];

void SNT(){
	FOR(i, 1, MAX - 1) nt[i] = 1;
	nt[1] = 0;
	FOR(i, 2, MAX - 1){
		if (nt[i]){
			ll j = i * i;
			while (j < MAX){
				nt[j] = 0;
				j += i;
			}
		}
	}
}

bool OK(ll x){
	if (x == 1) return false;
	ll k = sqrt(x);
	return (nt[k] && k * k == x);
}

int main(){
	cin >> n;
	SNT();
	FOR(i, 1, n){
		cin >> x;
		if (OK(x)) cout << "YES";
		else cout << "NO";
		
		cout << endl;
	}
}