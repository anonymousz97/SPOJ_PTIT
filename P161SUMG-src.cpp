#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FO(i, a, b) for (ll i = a; i < b; i++)
#define FILEIN freopen("in.txt", "r", stdin)
#define fi first
#define se second
 
using namespace std;
int a, b = 0;
 
int main(){
	FOR(i, 1, 5){
		cin >> a;
		b += a;
	}
	if (b % 5 || !b) cout << "-1";
	else cout << b / 5;
}