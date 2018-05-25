#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
#define pb push_back
#define lb lower_bound
using namespace std;

const ll MAX = 1e5 + 10;

vector <int> v;
vector <int> :: iterator it;

int n, x;

int main(){
	
//	FILEIN;
	
	cin >> n;
	FOR(i, 1, n){
		cin >> x;
		it = lb(v.begin(), v.end(), x);
		if (it == v.end()){
			v.pb(x);
		}
		else *it = x;
	}
	
	cout << v.size();
}