#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

const ll MAX = 1005;

ll res, n, x, y, c[2 * MAX] = {0}, p[2 * MAX + 1] = {0};

void Process(){
	res = 0;
	FOR(i, 1, 2 * MAX - 1) res += c[i] * (c[i] - 1) / 2;
	FOR(i, 2, 2 * MAX) res += p[i] * (p[i] - 1) / 2;
}

int main(){
//	FILEIN;
	cin >> n;
	FOR(i, 1, n){
		cin >> x >> y;
		p[x + y]++;
		c[x - y + MAX]++;
	}
	Process();
	cout << res;
}