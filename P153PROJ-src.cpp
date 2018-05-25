#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define X first
#define Y second
using namespace std;
const ll MAX = 1e5;
const ll QMAX = 1e5 * 4 + 100;
typedef pair <ll, ll> record;
record b[MAX + 5];

ll n, k, a[MAX + 5], t[QMAX], res;

void AnhXa(){
	sort(b + 1, b + 1 + n);
	ll t;
	a[b[1].Y] = 1;
	FOR(i, 2, n){
		if (b[i].Y == b[i - 1].Y) a[b[i].Y] = a[b[i - 1].Y];
		else a[b[i].Y] = a[b[i - 1].Y] + 1; 
	}
//	FOR(i, 1, n) cout << a[i] << " ";
}

void Insert(ll x, ll l, ll r, ll k){
	if (x < l || r < x) return;
	if (l > r) return;
	if (l == r){
		t[k]++;
		return;
	}
	t[k]++;
	ll m = (l + r) / 2;
	Insert(x, l, m, 2 * k);
	Insert(x, m+1, r, 2 * k + 1);
}

void Export(ll x, ll l, ll r, ll k){
	if (x < l || r < x) return;
	if (l > r) return;
	if (l == r){
		t[k]--;
		return;
	}
	t[k]--;
	ll m = (l + r) / 2;
	Export(x, l, m, 2 * k);
	Export(x, m+1, r, 2 * k + 1);
}

ll TV2(ll i, ll j, ll l, ll r, ll k){
	if (j < l || r < i) return 0;
	if (l > r) return 0;
	if (i <= l && r <= j) return t[k];
	ll m = (l + r) / 2;
	ll p1 = TV2(i, j, l, m, 2 * k);
	ll p2 = TV2(i, j, m + 1, r, 2 * k + 1);
	return p1+p2;
}

void Process(){
	
	memset(t, 0, sizeof(t));
	AnhXa();
	
	res = 0;
	ll cnt = 0;
	ll front;
	
	FORD(i, n, 1){
		Insert(a[i], 1, MAX, 1);
		cnt += TV2(1, a[i] - 1, 1, MAX, 1);
		front = i;
		if (cnt >= k) break;
	}
	
	ll last = n;
	while (front >= 1){
		while (cnt >= k){
			res += front;
			cnt -= TV2(a[last] + 1, MAX, 1, MAX, 1);
			Export(a[last], 1, MAX, 1);
			last--;
		}
		if (front == 1) return;
		while (front > 1 && cnt < k){
			front--;
			Insert(a[front], 1, MAX, 1);
			cnt += TV2(1, a[front] - 1, 1, MAX, 1);
		}
	}
}

int main(){
//	freopen("in.txt", "r", stdin);
	
	cin >> n >> k;
	FOR(i, 1, n){
		cin >> b[i].X;
		b[i].Y = i;
	}
	
	if (k) Process();
	else res = n * (n + 1) / 2;
	
	cout << res;
}