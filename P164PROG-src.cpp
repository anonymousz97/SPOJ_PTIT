#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

const ll MAX = 1e4 + 10;

int n, t = 0, s = 0, res;

void Process(){
	FOR(i, 1, n){
		t += i;
		s += t;
		if (s >= n){
			res = i;
			if (s > n) res--;			
			break;
		}
	}
	
	cout << res;
}

int main(){
	cin >> n;
	Process();
}