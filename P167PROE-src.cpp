#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

ll test, n, res;

void Process(){
	
	res = 0;
	
	FOR(x, n + 1, 2 * n){
		ll p = x * n;
		ll q = x - n;
		if (p % q == 0) res++;
	}
	
	res = res * 2 - 1;
	
	cout << res << endl;
}

int main(){
	cin >> test;
	while (test--){
		cin  >> n;
		Process();
	}
}