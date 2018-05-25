#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

const ll MAX = 600;

int n, nt[MAX], t = 0, a[MAX], b[MAX], c[MAX];

string cong(string a, string b)
{
	string s = "";
	long l1 = a. length(),
		 l2 = b. length();
	for (long i = l1 + 1; i <= l2; i++) a = "0" + a;
	for (long i = l2 + 1; i <= l1; i++) b = "0" + b;
	long nho = 0;
	l2 = b.length();
	for (long i = l2 - 1; i >= 0; i--)
		{
			long x = int (a[i]) + int (b[i]) - 96 + nho;
			nho = x / 10;
			x = x % 10;
			s = char (x + 48) + s;
		}
	if (nho) s = "1" + s;
	return s;
}

string nhan(string a, string b)
{
	string s = "";
	long k = 0;
	long l2 = b.length(), l1 = a.length();
	for (long i = l2 - 1; i >= 0;  i--)
	{
		long nho = 0;
		long p = int (b[i]) - 48;
		string ss = "";
		for (long j = l1 - 1; j >= 0; j--)
		{
			long x = int (a[j]) - 48;
			x = x * p + nho;
			nho = x / 10;
			x = x % 10;
			ss = char (x + 48) + ss;
		}
		if (nho != 0) ss = char (nho + 48) + ss;
		for (long j = 1; j <= k; j++) ss += "0";
		k++;
		s = cong(s, ss);
	}
	return s;
} 

bool ngto(int n){
	if (n < 2) return false;
	FOR(i, 2, sqrt(n)){
		if (n % i == 0) return false;
	}
	return true;
}

void Prime(int n){
	FOR(i, 2, n){
		if (ngto(i)) nt[++t] = i;
	}
	
//	FOR(i, 1, t) cout << nt[i] << endl;
}

string convert(int n){
	string s = "";
	while (n > 0){
		s = char (n % 10 + '0') + s;
		n /= 10;
	}
	return s;
}

void PT(int a[], int n){
	FOR(i, 1, t){
		int p = nt[i];
		int m = n;
		while (m >= p){
			a[nt[i]] += m / p;
			p *= nt[i];
		}
	}
	
//	cout << "*" << n << endl;
//	FOR(i, 1, 20) cout << nt[i] << " " << a[nt[i]] << endl;
}

string RES(int n, int k){
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	PT(a, n + k - 1);
	PT(b, n - 1);
	PT(b, k);
	
	FOR(i, 1, t) c[nt[i]] = a[nt[i]] - b[nt[i]];
	
	string res = "1";
	
	FOR(i, 1, t){
		if (c[nt[i]]){
			string s = convert(nt[i]);
			FOR(j, 1, c[nt[i]])  res = nhan(res, s);
		}
	}
	
	return res;
}

void Process(){

	
	string res1 = RES(n, 6);
	string res2 = RES(n, 2);
	
	cout << nhan(res1, res2); 
}

int main(){
//	FILEIN;
	cin >> n;
	Prime(550);
	Process();
}