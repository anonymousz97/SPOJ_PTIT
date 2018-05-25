#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FO(i, a, b) for (ll i = a; i < b; i++)

#define fi first
#define se second

using namespace std;

int a, b;
int ra, rb, rc;

int main(){
	cin >> a >> b;
	
	ra = 0; rb = 0; rc = 0;
	
	FOR(i, 1, 6){
		int k1 = fabs(a - i);
		int k2 = fabs(b - i);
		
		if (k1 < k2) ra++;
		else if (k1 == k2) rb++;
		else rc++;
	}
	
	cout << ra << " " << rb << " " << rc;
}