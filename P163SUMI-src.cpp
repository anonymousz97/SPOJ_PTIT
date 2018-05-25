#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FO(i, a, b) for (ll i = a; i < b; i++)

#define fi first
#define se second

using namespace std;

string s;

int n;

string chuoi(int n){
	string ans = "";
	while (n > 0){
		ans = char (n % 10 + 48) + ans;
		n /= 10;
	}
	return ans;
}

void process(){
	s = "";
	int k = 0;
	
	while (s.length() < n){
		k++;
		s += chuoi(k);
	}
	
	n--;
}

int main(){
	cin >> n;
	process();
	cout << s[n];
}