#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

const ll MAX = 1000;

ll n, m, a[MAX], b[MAX], c[MAX], A, B, res;

void Build(ll a[], ll &t, ll n){
	t = 0;
	while (n != 0){
		a[++t] = n % 3;
		n /= 3;
	}
	
	
//	FOR(i, 1, t) cout << a[i]; cout << endl;
}

void Process(){
	Build(a, n, A);
	Build(b, m, B);
	
	while (n < m) a[++n] = 0;
	while (m < n) b[++m] = 0;
	
	FORD(i, n, 1) c[i] = (b[i] - a[i] + 3) % 3, res = res * 3 + c[i];
}

int main(){
	cin >> A >> B;
	Process();
	cout << res;
}