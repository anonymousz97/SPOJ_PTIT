#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

string a, b, c, z;

int get(int n, int k){
	int d = 0;
	int x;
	while (d++ < k){
		x = n % 10;
		n /= 10;
	}
	return x;
}

ll stol(string s){
	int l = s.length();
	ll res = 0;
	FOR(i, 0, l - 1){
		res = res * 10 + s[i] - '0';
	}
		
	return res;
}

void Process(){
	
	if (a.find("?") >= 0 && a.find("?") < a.length()){
		ll z = stol(c) - stol(b);
		ll k = a.find("?");
		cout << get(z, a.length() - k);
	}
	else if (b.find("?") >= 0 && b.find("?") < b.length()){
		ll z = stol(c) - stol(a);
		ll k = b.find("?");
		cout << get(z, b.length() - k);
	}
	else if (c.find("?") >= 0 && c.find("?") < c.length()){
		ll z = stol(a) + stol(b);
		ll k = c.find("?");
		cout << get(z, c.length() - k);
	}
}

int main(){
//	FILEIN;
	cin >> a >> b >> c;
	Process();		
}