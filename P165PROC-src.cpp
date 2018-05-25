#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

ll n, m, t;

int main(){
	cin >> n >> m >> t;
	
	cout << ((m - 1) / t + 1) * ((m - 1) % t + 1) * ((n - 1) / t + 1) * ((n - 1) % t + 1);
}