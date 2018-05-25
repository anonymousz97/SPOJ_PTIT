#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

ll j, k , l;
ll a, b, c, s;

int main(){
	int test;
	cin >> test;
	
	while (test--){
	
	cin >> a >> b >> c;
	s = sqrt(a * b * c);
	j = s / a;
	k = s / b;
	l = s / c;
	
	cout << (j + k + l) * 4 << endl;
}
}