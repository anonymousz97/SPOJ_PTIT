#include <bits/stdc++.h>
#define ll unsigned long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

const ll MAX = 1e15 + 7;
const ll mod = 1e9 + 7;

struct Matrix{
	ll a[4];
};

Matrix I;

ll n, k;

void Init(){
	I.a[0] = 1;
	I.a[1] = 1;
	I.a[2] = 1;
	I.a[3] = 0;
}

Matrix Multi(Matrix A, Matrix B){
	Matrix C;
	
	C.a[0] = A.a[0] * B.a[0] + A.a[1] * B.a[2];
	C.a[1] = A.a[0] * B.a[1] + A.a[1] * B.a[3];
	C.a[2] = A.a[2] * B.a[0] + A.a[3] * B.a[2];
	C.a[3] = A.a[2] * B.a[1] + A.a[3] * B.a[3];
	
	FOR(i, 0, 3) C.a[i] %= mod;
	
	return C;
}

Matrix luyThua(Matrix I, ll n){
	if (n == 1) return I;
	
	ll p = n / 2;
	
	Matrix C = luyThua(I, p);
	
	Matrix B = Multi(C, C);
	
	if (n % 2){
		return Multi(B, I);
	}
	else return B;
}

ll nhanSo(ll n, ll m, ll k)
{
	if (!m) return 0;
	if (m % 2 == 0) return nhanSo(n * 2 % k, m / 2, k) % k;
	else
	return (nhanSo(n % k, m - 1, k) % k + n % k) % k;
}


void Process(){
	Init();
	I = luyThua(I, n);
	
//	FOR(i, 0, 3) cout << I.a[i] << endl;
	
	ll res = (I.a[0] + I.a[1] - 1);
	
	cout << nhanSo(res, k, mod);
}

int main(){
	
//	FILEIN;
	
	cin >> k >> n;
	
	Process();
}