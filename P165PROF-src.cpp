#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

const ll MAX = 1e6 + 10;

ll f[MAX], a[MAX], ia[MAX], res, n;

void Process(){
	memset(f, 0, sizeof(f));
	sort(a + 1, a + 1 + n);
	FOR(i, 1 , n) f[a[i]] = a[i];
	a[0] = 0;
	FOR(i, 1, n - 1){
		FOR(j, a[i] + 1, a[i + 1] - 1) f[j] = a[i];
	}
//	FOR(i, 1, a[n]) cout << f[i] << " "; cout << endl;
	res = -1;
	FOR(i, 1, n){
		FOR(j, 2, a[n]/a[i] + 1){
			int p = min(a[i] * j - 1, a[n]);
			res = max(res, f[p] % a[i]);
		}
	}
}

int main(){
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	Process();
	cout << res;
}